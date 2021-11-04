#include"time.hpp"

Time& Time::operator-(Time& a){
    one.ti_hour-=a.one.ti_hour;
    one.ti_min-=a.one.ti_min;
    one.ti_sec-=a.one.ti_sec;
    one.ti_hund-=a.one.ti_hund;

    if(one.ti_hund>100){one.ti_hund+=100;one.ti_sec-=1;}
    if(one.ti_sec>60){one.ti_sec+=60;one.ti_min-=1;}
    if(one.ti_min>60){one.ti_min+=60;one.ti_hour-=1;}
    if(one.ti_hour>24) one.ti_hour+=24;
return *this;
}

int Time::operator==(Time& a){
return  (one.ti_hour==a.one.ti_hour && one.ti_min==a.one.ti_min &&\
	 one.ti_sec==a.one.ti_sec && one.ti_hund==a.one.ti_hund)?1:0;

}
Time& Time::operator !(void){
gettime(&one);
return *this;	     }

int Time::operator>(Time& a){
if(one.ti_hour>a.one.ti_hour)return 1;
if(one.ti_hour<a.one.ti_hour)return 0;
if(one.ti_min>a.one.ti_min)return 1;
if(one.ti_min<a.one.ti_min)return 0;
if(one.ti_sec>a.one.ti_sec)return 1;
if(one.ti_sec<a.one.ti_sec)return 0;
if(one.ti_hund>a.one.ti_hund)return 1;
return 0;		     }

int Time::operator<(Time& a){
if(one.ti_hour>a.one.ti_hour)return 0;
if(one.ti_hour<a.one.ti_hour)return 1;
if(one.ti_min>a.one.ti_min)return 0;
if(one.ti_min<a.one.ti_min)return 1;
if(one.ti_sec>a.one.ti_sec)return 0;
if(one.ti_sec<a.one.ti_sec)return 1;
if(one.ti_hund<a.one.ti_hund)return 1;
return 0;		     }

Time& Time::operator=(Time& a){
one=a.one;
return *this;
}

