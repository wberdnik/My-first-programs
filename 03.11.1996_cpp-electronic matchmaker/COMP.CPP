#include"comp.hpp"
Comp::Comp(long a,char b):Vector(a){
error(b>3,OPERATOR,"данная функция не реализована");
 deep=b;};

void Comp::run(SLOT& a,SLOT& b){
               // т.е. поле есть а требования нет
 if(a.others==-1) get().qme--;

 if(b.file==-1)return;

 error(a.file!=b.file,SYSTEM,"ошибочное сравнение в comp::run");

 if(b.others==-1) get().qyou--;

	if(deep==1){
  get().enable=1;
  get().enable1=1;
	if(a.others!=-1)
		if(a.treb==b.xar && a.treb!=-1 && b.xar!=-1)      get().forme+=1;
	if(b.others!=-1)
		if(b.treb==a.xar && b.treb!=-1 && a.xar!=-1)      get().foryou+=1;
			 }
	if(deep==2){
        // 1->2
         if(a.treb!=-1 && b.xar!=-1)
              switch(a.others){
                 case 0: if(b.weigx>=a.weightfb){
                          get().enable++;
                          get().forme+=float(a.weigt)/100;break;
                                                }
                 case 1: if(b.weigx<=a.weightfb){
                          get().enable++;
		                      get().forme+=float(a.weigt)/100;break;
                                                 }
                 case 2: if(b.xar==a.treb)       {
                          get().enable++;
								          get().forme+=a.weigt;    break;
                                                 }
                 case 3: if(b.xar==a.treb)       {
                          get().enable++;
		                      get().forme+=float(a.weigt)/100; break;
                                                 }
                            }
           
        // 2->1
         if(b.treb!=-1 && a.xar!=-1)
           switch(b.others){
                 case 0: if(a.weigx>=b.weightfb) {
                          get().enable1++;
                          get().foryou+=float(b.weigt)/100;break;
                                                 }
                 case 1: if(a.weigx<=b.weightfb) {
                          get().enable1++;
		                      get().foryou+=float(b.weigt)/100;break;
                                                 }
                 case 2: if(a.xar==b.treb)       {
                          get().enable1++;
								          get().foryou+=b.weigt; break;
                                                 }
                 case 3: if(a.xar==b.treb)       {
                          get().enable1++;
		                      get().foryou+=float(b.weigt)/100;break;
                                                 }
                            }

             	  }

	  //итого всего 4 метода

  }
