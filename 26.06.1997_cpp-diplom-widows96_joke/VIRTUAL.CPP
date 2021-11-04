#include"virtual.hpp"
#include"base.hpp"
#include"sourse.hpp"
#include"xms.hpp"
#include"error.hpp"
#include<alloc.h>
#include<mem.h>

extern "C"  void exit(int);


Mem* Virtual::myalloc(v_size n, int b)
 {
  Mem& a=*new Mem;
  cursize=b;
  a.flag=vNo;
  a.memstart=0;
  a.memend=0;
  a.xmsstart=0;
  a.xmsend=0;
  a.diskstart=0;
  a.diskend=0;
  a.FILEoffset=0;
  a.XMSoffset=0;
  a.light=0;
  a.sizeblock=cursize;
  if(n<9 &&farcoreleft()>100000L)
   {
    a.flag=vRam;
    a.memstart=0;
    a.memend=n-1;
    a.MEMoffset=new char[cursize*(int)n];

   }
  else
   {
    a.flag=vXmsDisk;
    a.flaginc=vNo;
    ramfree=tt->XMSQueryTotalFree();//получаем результат в Кбайтах
    if(ramfree>64&&tt->XMSError==NOERROR)
      {
       ramfree/=cursize;                //переводим в количество единиц
       ramfree*=1024;
       v_size bufer=65535L;

       if(n>=(ramfree-(bufer/cursize)))
	 a.xmsend=ramfree-(bufer/cursize)-1;
       else
	 a.xmsend=n-1;

       int result;

       result=(int)((v_size)(a.xmsend+1)*cursize/1024);  //узнаем сколько килобайт
				      //занимает массив
       if( (result*1024/cursize)<(a.xmsend+1))
	 result++;

       tt->light_memory=result;
       a.light=result;

       a.XMSoffset=tt->XMSAllocateEMB();  //выделяем память в XMS
       tt->Handle=(unsigned)a.XMSoffset;
       tt->XMSLockEMB();         //фиксируем блок для работы с ним
	//      freexms(a);
      }

    if(a.xmsend<(n-1))              //если не хватило разместить элементы
      {                             //в XMS то используем диск
	a.diskstart=a.xmsend+1;
	if(a.xmsend==0) a.diskstart=0;
	a.diskend=n-1;

	delete file;
	file=new File("netlog.swp");
	a.FILEoffset=file->end;
	file->sbrosstart();
	(*file)+=(ulong)a.FILEoffset;
	(*file)%(unsigned)((a.diskend-a.diskstart+1)*cursize);//?
	(*file)+1;
       }
      a.MEMoffset=new char[cursize*2];
   }

  return &a;
 }

Mem* Virtual::destroy(Mem* a){
if(a->flag==vNo){
	   error("\nУдаляется несуществующий массив");
	   a=NULL;
	   return a;
		};
if(a==NULL){error("\nWarning: Повторный вызов деструктора");return a;}
if(a==curmem) flag=vNo;   // текущая установка удаляется
 freeblock(a);
  delete  a;
  a=NULL;
  return a;
		  }

void Virtual::freeblock(Mem* a){
switch(a->flag){
	case vRam     : delete  a->MEMoffset; break;
	case vXmsDisk : delete  a->MEMoffset;
			if (a->xmsend!=0)
			 {
			  tt->Handle=(unsigned)a->XMSoffset;
			  tt->XMSUnLockEMB();
			  tt->XMSDelete();
			 }
			 break;
/*? */	default   : error(" Это не реализовано !!! ");  exit(33);
		 }
			      }


void Virtual::freexms(Mem* b){
 int a=0;
 if(b->xmsend==0) return;
 for(v_size i=0;i<=b->xmsend;i++)
   {
    tt->set(cursize,i*cursize,b->light);
    (*tt)[0]<<(void*)&a;
   }
			      }


void Virtual::freekesh(void){
  if(curmem->flaginc==vYes)
    {
//     v_size a;
     error("Это не реализовано");
//     operator[](curmem->memstart);
//     memcpy(&a,(char*)curmem->MEMoffset,cursize);
//     operator<<(a);
    }
  return;
			    }


Virtual::Virtual(){
//v_size size_mem=farcoreleft();
tt=new Xms();
ramfree=tt->XMSQueryTotalFree();
if(ramfree>64&&tt->XMSError==NOERROR)
  tt->XMSGlobalEnableA20();
unlink("netlog.swp");
file=new File("netlog.swp");
((*file)%10)+1;   // anti error
flag=vNo;
//  size_mem=farcoreleft();
	 }

Virtual::~Virtual(){
delete file;
unlink("netlog.swp");
delete tt;
//v_size size_mem=farcoreleft();
}

Virtual& Virtual::operator()(Mem* a,unsigned int b){
if(a->flag==vNo){
       curmem=a;
       error("\nДля данного массива память не выделена");
       return *this;
		     }
if(flag!=vNo && a==curmem){cursize=b;return *this;}
//if(flag!=vNo && a!=curmem && a->flag!=vRam) freekesh();
//необходимо ли проверять на нахождение массива только в ОЗУ
flag= vYes;
curmem=a;
cursize=b;
return *this;
					}

Virtual& Virtual::operator()(Mem* a){
if(a==NULL) return *this;
cursize=a->sizeblock;
return operator()(a,cursize);              }


Virtual& Virtual::operator[](v_size a){

if(flag==vNo) error("\n Неккоректный доступ");

where=vNo;
     // проверяем а не в КЭШе нужный блок ?
if(a>=curmem->memstart && a<=curmem->memend && curmem->flag!=vXmsDisk) where=vRam;

  else
    if(curmem->flag==vXmsDisk){
       if(a>=curmem->xmsstart && a<=curmem->xmsend && curmem->xmsend!=0) where=vOnlyXms;
	 else
	    if(a>=curmem->diskstart && a<=curmem->diskend && curmem->diskend!=0) where=vOnlyDisk;
	      else error("Сбой в виртуальной памяти");
			       }
    else where=vNo;


 switch(where){
  case vNo      : error("\nУстановлен несушествующий массив!!!");
		  break;
  case vRam     : curnumber=a;
		  break;

  case vOnlyXms :    // загружаем нужный блок в КЭШ
		   curnumber=a;
		   tt->Handle=(unsigned)(curmem->XMSoffset);
		   break;

  case vOnlyDisk:
		   curnumber=a-curmem->diskstart;
		   oldcurnumber=a;
		   file->sbrosstart();
		   (*file)+=(ulong)curmem->FILEoffset+cursize*curnumber;
		   (*file)%cursize;
		   curnumber=0;

		   break;

	      }


return *this;
				 };//func




int Virtual::operator ! (void){
 if(flag==vNo)return vYes;
 return curmem->flag?vNo:vYes;         }



void Virtual::write(void* a){
//float b;
if(curmem->flag==vNo){
       error("\nВы обращаетесь к несуществующему массиву");
       return ;
		     }
 if(flag==vNo) error(" Неккоректный доступ");
//  if(cursize!=sizeof(int)) error(" Неккоректный доступ");

 switch(where){
  case vNo      : error("\nУстановлен несушествующий массив!!!");
		  break;
  case vRam     :
		  _fmemcpy( (((char*)curmem->MEMoffset)+(unsigned int)curnumber*cursize),a,cursize);
		  break;

  case vOnlyXms :
		   if(curmem->memstart==curnumber)
		     {
		      _fmemcpy( (char*)curmem->MEMoffset,a,cursize);
		      curmem->flaginc=vYes;
		     }
		   else
		     {
		      if(curmem->flaginc==vYes)
			{
			 _fmemcpy(((char*)curmem->MEMoffset)+cursize,(char*)curmem->MEMoffset,cursize);
			}
		      _fmemcpy((char*)curmem->MEMoffset,a,cursize);
		      v_size old=curnumber;
		      if(curmem->flaginc==vYes)
			{
			 _fmemcpy(a,((char*)curmem->MEMoffset)+cursize,cursize);
			 if(curmem->memstart>=curmem->diskstart&&curmem->diskend!=0)
			   {
			    curnumber=curmem->memstart-curmem->diskstart;
			    file->sbrosstart();
			    (*file)+=(ulong)curmem->FILEoffset+cursize*curnumber;
			    (*file)%cursize;
			    (*file)[0]<<(void*)a;
			   }
			 else
			   {
			    curnumber=curmem->memstart;
			    tt->set(cursize,(ulong)curnumber*cursize,curmem->light);
			    (*tt)[0]<<(void*)a;
			   }
			}
		      curmem->flaginc=vYes;
		      curnumber=old;
		      curmem->memstart=curnumber;		
		     }
		   break;



  case vOnlyDisk:

		   if(curmem->memstart==oldcurnumber)
		     {
		      _fmemcpy((char*)curmem->MEMoffset,a,cursize);
		      curmem->flaginc=vYes;
		     }
		   else
		     {
		      if(curmem->flaginc==vYes)
			{
			 _fmemcpy(((char*)curmem->MEMoffset)+cursize,(char*)curmem->MEMoffset,cursize);
			}
		      _fmemcpy((char*)curmem->MEMoffset,a,cursize);
		      if(curmem->flaginc==vYes)
			{
			 _fmemcpy(a,((char*)curmem->MEMoffset)+cursize,cursize);
			 if(curmem->memstart<=curmem->xmsend&&curmem->xmsend!=0)
			   {
			     curnumber=curmem->memstart;
			     tt->Handle=(unsigned)(curmem->XMSoffset);
			     tt->set(cursize,(ulong)curnumber*cursize,curmem->light);
			     (*tt)[0]<<(void*)a;
			   }
			 else
			   {
			     curnumber=curmem->memstart-curmem->diskstart;
			     file->sbrosstart();
			     (*file)+=(ulong)curmem->FILEoffset+cursize*curnumber;
			     (*file)%cursize;
			     (*file)[0]<<(void*)a;  // здесь возникает сбой
			   }
			}
		      curmem->flaginc=vYes;
		      curmem->memstart=oldcurnumber;
		     }
		   break;


	      }


   return ;
				   }




void Virtual::read(void * a){
//float b;
if(curmem->flag==vNo){
       error("\nВы обращаетесь к несуществующему массиву");
       return ;
		     }
 if(flag==vNo) error(" Неккоректный доступ");
//  if(cursize!=sizeof(int)) error(" Неккоректный доступ");

 switch(where){
  case vNo      : error("\nУстановлен несушествующий массив!!!");
		  break;
  case vRam     :
		  _fmemcpy(a,(((char*)curmem->MEMoffset)+(unsigned int)curnumber*cursize),cursize);
		  break;

  case vOnlyXms :
		   if(curmem->memstart==curnumber)
		     _fmemcpy(a,(char*)curmem->MEMoffset,cursize);
		   else
		     {
		      if(curmem->flaginc==vYes)
			{
			 _fmemcpy(((char*)curmem->MEMoffset)+cursize,(char*)curmem->MEMoffset,cursize);
			}
		      tt->set(cursize,(ulong)curnumber*cursize,curmem->light);
		      (*tt)[0]>>(void*)a;
		      _fmemcpy((char*)curmem->MEMoffset,a,cursize);
		      v_size old=curnumber;
		      if(curmem->flaginc==vYes)
			{
			 _fmemcpy(a,((char*)curmem->MEMoffset)+cursize,cursize);
			 if(curmem->memstart>=curmem->diskstart&&curmem->diskend!=0)
			   {
			    curnumber=curmem->memstart-curmem->diskstart;
			    file->sbrosstart();
			    (*file)+=(ulong)curmem->FILEoffset+cursize*curnumber;
			    (*file)%cursize;
			    (*file)[0]<<(void*)a;
			   }
			 else
			   {
			    curnumber=curmem->memstart;
			    tt->set(cursize,(ulong)curnumber*cursize,curmem->light);
			    (*tt)[0]<<(void*)a;
			   }
			 _fmemcpy(a,(char*)curmem->MEMoffset,cursize);
			}
		      curmem->flaginc=vNo;
		      curnumber=old;
		      curmem->memstart=curnumber;
		     }
		   break;
  case vOnlyDisk:
		   if(curmem->memstart==oldcurnumber)
		     _fmemcpy(a,(char*)curmem->MEMoffset,cursize);
		   else
		     {
		      if(curmem->flaginc==vYes)
			{
			 _fmemcpy(((char*)curmem->MEMoffset)+cursize,(char*)curmem->MEMoffset,cursize);
			}
		      (*file)[0]>>(void*)a;
		      _fmemcpy((char*)curmem->MEMoffset,a,cursize);
		      if(curmem->flaginc==vYes)
			{
			 _fmemcpy(a,((char*)curmem->MEMoffset)+cursize,cursize);
			 if(curmem->memstart<=curmem->xmsend&&curmem->xmsend!=0)
			   {
			     curnumber=curmem->memstart;
			     tt->Handle=(unsigned)(curmem->XMSoffset);
			     tt->set(cursize,(ulong)curnumber*cursize,curmem->light);
			     (*tt)[0]<<(void*)a;
			   }
			 else
			   {
			     curnumber=curmem->memstart-curmem->diskstart;
			     file->sbrosstart();
			     (*file)+=(ulong)curmem->FILEoffset+cursize*curnumber;
			     (*file)%cursize;
			     (*file)[0]<<(void*)a;
			   }
			 _fmemcpy(a,(char*)curmem->MEMoffset,cursize);
			}
		      curmem->flaginc=vNo;
		      curmem->memstart=oldcurnumber;
		     }
		   break;
	      }


  return ;
				   }



