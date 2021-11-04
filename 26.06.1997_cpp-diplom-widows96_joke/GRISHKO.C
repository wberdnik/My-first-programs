/*
Userbreak - прерывание пользователя
Con2StCount- отображение на экране матрицы стоимости
MakeLink - создание карта связей
Boolean link_read(Nstancii,Nconcent)
Boolean link_write(Nstancii,Nconcent)- работа с картой связей
link_tmp_wr
link_tmp_rd - временные функции

addition{

link_base=new int[nam_konc];
num_link=new int[nam_term];
num_link_tmp=new int{nam_trm];

// первоначально все станции подключаются к эвм
for(i=0;<nam_term;i++){
link_write(i,1,1);
for(j=1;j<nam_konc;j++)link_write(i,j,0);
		      }

// инициализация вектора включения концентратора
for(i=0;i<nam_konc;i++)link_tmp_wr(link_base,i,0);
for(i=0;i<nam_term;i++)link_tmp_wr(num_link,i,0);
for(i=0;i<nam_term;i++)link_tmp_wr(num_link_tmp,i,0);

// расчет первоначальной стоимости сети
min_cost=0;
for(i=0;i<nam_term;i++) min_cost+=cost_read(cost,i,1);


do{
  for(j=1;j<nam_konc;j++){
    if(link_tmp_rd(link_base,j)<max_term){
     for(k=0;k<(max_term-link_tmp_rd(link_base,j));k++){
	sub_max=0;index=0;
	for(i=0;i<nam_term;i++){
	 if(link_read(i,j)==1)||(link_tmp_rd(num_link,i)!=0))continue;

	 if(link_read(i,1)==1)sub=cost_read(cost,i,1)-cost_read(cost,i,j);
	      // для условия включенности станции
	 else{
for(m=1;m<nam_konc;m++)
 if(link_tmp_rd(link_base,m)!=0 && link_read(i,m)==1){nam=m;break;}
       sub=cost_read(cost,i,nam)-cost_read(cost,i,j)
	     }

     if(sub>sub_max){index=i;sub_max=sub;}
				}

  if(index!=0)link_tmp_wr(num_link,index,j);else break; }

     // подсчет цены сети cost_tmp
 cost_tmp=link_tmp_rd(link_base,j)==0)?cost_konc:0;

 for(i=1;i<nam_konc;i++)if(link_tmp_rd(link_base,i))cost_tmp+=cost_konc;

 for(i=0;i<nam_term;i++)
  if(link_tmp_rd(num_link,i)==0){
for(k=0;k<nam_konc;j++)
	 if(link_read(i,k)==1){cost_tmp+=cost_read(cost,i,k);break;}
				 }
  else cost_tmp+=cost_read(cost,i,j);
			 }     //для условия вкл концентратора

 if(cost_tmp<min_cost){
 for(i=0;i<nam_term;i++)link_tmp_wr(num_link_tmp,i,link_tmp_rd(num_link,i));
  min_cost=cost_tmp;  }

  for(i=0;i<nam_term;i++) link_tmp_wr(num_link,i,0);
			 } //по j

 // подключение нового концентратора
 index=0;
 for(i=0;i<nam_term;i++)
   if(link_tmp_rd(num_link_tmp,i)){
     index=1;
     for(j=0;j<nam_konc;j++)
       if(link_tmp_rd(num_link_tmp,i)!=j){
     if(link_read(i,j)){link_write(i,j,0);
			link_tmp_wr(link_base,j,link_tmp_rd(link_base,j)-1);
				   }     }
   else{
   link_write(i,j,1);link_tmp_wr(link_base,j,link_tmp_rd(link_base,j)+1);
       }                           }
  for(i=1;i<nam_term;i++)link_tmp_wr(num_link_tmp,i,0);

  }while(index==0);  // условие выхода : нет уменьшения стоимости



*/

  Алгоритм удаления  !!!!!!!!!!!!!!!!!!

cost,link -массивы
long cost_net;- cтоимость сети
int nam_term; - число станций
int nam_konc; - число концентраторов
int max_term; - число станций подключенных к 1 концентраторов
int cost_konc - цена одного концентратора
 cost - матрица стоимости линий
link - матрица связей

char link_read(int x,int y){
long a=x*y;
char bt=link[a/8];
return (bt>>a%8)&0x01;     }

char write_read(int x,int y, char i){
long a=x*y;
char bt=link[a/8];
bt=(bt>>(a%8));
if(i)bt=bt|1;else bt=bt&0;
bt=(bt<<(a%8));
link[a/8]=bt;  }




     }


main(){
link_base=new int[nam_konc];
sum_cost=new int[nam_term];
int i,j;
 for(i=0;i<nam_term;i++){
 link_write(i,0,0); // соединение с центральной
 for(j=1;j<nam_konc;j++) link_write(i,j,0);//связей нет
			 }
// инициализация вектора включения
for(i=0;i<nam_konc;i++)link_base[i]=0;
 // фаза инициализации- подключение станции к ближайшему концентратору
 //?

 for(j=1;j<nam_term;j++)sum_cost[i]=0;

