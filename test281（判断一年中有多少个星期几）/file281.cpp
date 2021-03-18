//题目:算一年有多少个星期几

#include<stdio.h>
#include<iostream>
#include<cstdlib>
#include<string.h>

using namespace std;

int main()
{
     int y,w,i/*,a1,a2,a3*/;
     char week[7][3]={"日","一","二","三","四","五","六"};
     cout<<"请输入年份:";
     scanf("%d",&y);
     w=(y+y/4-y/100+y/400)%7;
     for(i=w;i<=w+(y%4==0&&y%100||y%400==0);i++)
     {
         printf("%d年有53个星期%s\n",y,week[i%7]);
         /*if(strcmp(week[i%7],"二"))
             a1=53;
         else
            if(strcmp(week[i%7],"六"))
                a2=53;
            else
                if(strcmp(week[i%7],"日"))
                    a3=53;*/
     }
     for(;i<w+7;i++)
     {
         printf("%d年有52个星期%s\n",y,week[i%7]);
         /*if(strcmp(week[i%7],"二"))
             a1=52;
         else
            if(strcmp(week[i%7],"六"))
                a2=52;
            else
                if(strcmp(week[i%7],"日"))
                    a3=52;*/
     }
     /*cout<<"\n此年的星期二个数为"<<a1;
     cout<<"\n此年的星期六个数为"<<a2;
     cout<<"\n此年的星期日个数为"<<a3;*/
     return 0;
}

