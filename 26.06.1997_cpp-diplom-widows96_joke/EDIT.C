#include<stdio.h>
#include<alloc.h>
#include<conio.h>
#include<math.h>
#include"board.h"
#include<graphics.h>
char * name="netcad.stn";
FILE* file;
int far* ci, far* di, far* em;
float far* c,far* d;
strStation too;
int j;
int gdriver = VGA, gmode=VGAHI;
enum{
	sizeX	=	639,
	sizeY	=	479,
	sizeDy	=	16,

	};

int w=sizeX;
int h=sizeY-sizeDy;


main(){
float cosi,sini,con=(float)h/2,con2=(float)w/2;
float thecon=8*3.1415926/(w+h);
float wl=w/2,hl=h/2,i;
float oldcosi=wl,oldsini=0;

char string[100];
int x,y,p;
int num=0;

ci=(int*)farmalloc(8000); di=(int*)farmalloc(8000); em=(int*)farmalloc(8000);
c=(float*)farmalloc(16000); d=(float*)farmalloc(16000);
if(d==NULL){
    printf("��� �����");return 1;}

too.ncentre=too.number=0;
too.type=tRound;
too.mashty=too.mashtx=1.0;
too.doplam=1;        // �����⨬ �ய ᯮᮡ�����
too.add=0;

clrscr();

do{
printf("\n   ����� �窠 N\n"
       "   ��������    D\n"
       "   ��������    S\n"
       "   �⯥����  T\n"
       "   ��������    E\n"
       "   �����       A\n"
       "   c == ci     L\n"
       "   ���� ���� P\n"
       "   �࠭���     G\n"
       "   ���࠭���   F\n"
       "   ����㧨��   O\n"
       "   ��室       Q\n");

switch(getch()){
  case 'n' : printf("\n �ᥣ� %d \n x y p : ",too.number);
	     scanf("%d %d %d",&x,&y,&p);
     ci[too.number]=x;  c[too.number]=(float)too.mashtx*x/sizeX;
     di[too.number]=y;  d[too.number]=(float)too.mashty*y/(sizeY-sizeDy);
     em[too.number]=p;
     too.number+=1;
	      break;
  case 'g' :
     printf("�࠭��� %s Mx %f My %f Dp %d",too.type==tRound?"���":"��אַ�",\
     too.mashtx,too.mashty,too.doplam);
     printf("\n�࠭���_ ��_ ��_ Dp_");

	scanf("%d %f %f %d",&j,&(too.mashtx),&(too.mashty),&(too.doplam));
	too.type=j?tRound:tRectangle;
	break;
  case 'o' :file=fopen(name,"rb");
	if(file==NULL){ printf("��� 䠩��");break;}
	fread(&too,sizeof(strStation),1,file);
	if(too.number>5000){ printf("���� 䠩��");break;;}
	fread(ci,sizeof(int),too.number,file);
	fread(di,sizeof(int),too.number,file);
	fread(em,sizeof(int),too.number,file);
	fread(c,sizeof(float),too.number,file);
	fread(d,sizeof(float),too.number,file);
	fclose(file);
	 break;


  case 'f' : file=fopen(name,"wb");
	     rewind(file);
	     gettime(&(too.gtime));
	     getdate(&(too.gdate));
	     too.gtime2=too.gtime;
	     too.gdate2=too.gdate;

	     fwrite(&too,sizeof(strStation),1,file);
	     fwrite(ci,sizeof(int),too.number,file);
	     fwrite(di,sizeof(int),too.number,file);
	     fwrite(em,sizeof(int),too.number,file);
	     fwrite(c,sizeof(float),too.number,file);
	     fwrite(d,sizeof(float),too.number,file);
	     fclose(file);
	     break;
  case 'q' : farfree(ci); farfree(di); farfree(em); farfree(c); farfree(d);
		return 0;
  case 'd' :
	     too.number-=1;
	     ci[num]=ci[too.number];   di[num]=di[too.number];
	     c[num]=c[too.number];     d[num]=d[too.number];
	     em[num]=em[too.number];
	     break;
   case 's' :
	    initgraph(&gdriver, &gmode, "");

	    if (graphresult() == grOk){
	    setcolor(DARKGRAY);
	    for(i=0;i<21;i++)line(i*sizeX/20,0,i*sizeX/20,sizeY-sizeDy);
	    for(i=0;i<16;i++)line(0,(14-i)*(sizeY-sizeDy)/15,sizeX,\
		  (14-i)*(sizeY-sizeDy)/15);
	     setcolor(BROWN);
	   if(too.type==tRound){
	     for(i=0;i<thecon*((w+h)/16+2);i+=thecon){
	     cosi=cos(i)*wl;sini=sin(i)*hl;
	     line(con2+oldcosi,con+oldsini,con2+cosi,con+sini);
	     line(con2+oldcosi,con-oldsini,con2+cosi,con-sini);
	     line(con2-oldcosi,con+oldsini,con2-cosi,con+sini);
	     line(con2-oldcosi,con-oldsini,con2-cosi,con-sini);
	     oldcosi=cosi;oldsini=sini;
			   }
		      }
	   else rectangle(0,0,w,h);
	   for(j=0;j<too.number;j++){
	   sprintf(string,"%d",j+1);
	   putpixel(ci[j],di[j],YELLOW);
	   setcolor(RED);
	   outtextxy(ci[j]+2,di[j]+2,string);
				    }

	   getch();
	   closegraph();
	   break;             }

    case 'a': printf("�ᥣ� %d ����� �����",too.number);
	      scanf("%d",&num);if(num)num-=1;
	      break;
    case 'e':
	  printf("�窠 %d x: %d y: %d p:%d",num+1,ci[num],di[num],em[num]);
	  printf("\n�ᥣ� %d \n x y p : ",too.number);
	  scanf("%d %d %d",&x,&y,&p);
	  ci[num]=x;  c[num]=(float)too.mashtx*x/sizeX;
	  di[num]=y;  d[num]=(float)too.mashty*y/(sizeY-sizeDy);
	  em[num]=p;
	  if(num<too.number)num++;
	  break;
    case 't': clrscr();
	     fprintf(file,"%s\n","\n����\t\tX\t\tY\t\tP\n");
	     for(j=0;j<too.number;j++){
    printf("%d\t%d(%f)\t%d(%f)\t%d\n",j+1,ci[j],c[j],di[j],d[j],em[j]);
	      if(j && !(j%23))getch();     }
	      getch();
	      break;

    case 'p' :
		unlink("netcad.rpt");
		file =fopen("netcad.rpt","wt");
 fprintf(file,"%s\n","\n�६� ᮧ����� 䠩�� �⠭権:");
 fprintf(file,"��� - %d\t���� - %d\t����� - %d\n",too.gdate2.da_year,\
   too.gdate2.da_day,too.gdate2.da_mon);

  fprintf(file,"�� - %d\t���.- %d\tᥪ. - %d\n",too.gtime2.ti_hour,\
   too.gtime2.ti_min,too.gtime2.ti_sec);

  fprintf(file,"%s\n","\n\t\t���न���� 㧫��");
   fprintf(file,"%s\n","\n����\t\tX\t\tY\n");

   for(j=0;j<too.number;j++)
      fprintf(file,"%d\t%d(%f)\t%d(%f)\n",j+1,ci[j],c[j],di[j],d[j]);
   fprintf(file,"%s\n","\n����� 業�஢ ������樨");
   fprintf(file,"%s\n","\n�����\t\t�����\n");
   for(j=0;j<too.ncentre;j++)
      fprintf(file,"%d\t\t%d\n",i+1,too.centre[i]+1);

   fprintf(file,"\n%s\n","[����� � 誠��]");
   fprintf(file,"%s\n","\n����   ��஡��\n");

   for(j=0;j<too.number;j++)
     fprintf(file,"%d\t%d\n",j+1,em[j]);
   fclose(file);
     break;
     case 'l' : for(j=0;j<too.number;j++){
		c[j]=(float)too.mashtx*ci[j]/sizeX;
		d[j]=(float)too.mashty*di[j]/(sizeY-sizeDy);
				}
		  break;



	 }

     }while(1);

   }




