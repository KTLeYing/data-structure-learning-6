//��Ŀ:��һ���ж��ٸ����ڼ�

#include<stdio.h>
#include<iostream>
#include<cstdlib>
#include<string.h>

using namespace std;

int main()
{
     int y,w,i/*,a1,a2,a3*/;
     char week[7][3]={"��","һ","��","��","��","��","��"};
     cout<<"���������:";
     scanf("%d",&y);
     w=(y+y/4-y/100+y/400)%7;
     for(i=w;i<=w+(y%4==0&&y%100||y%400==0);i++)
     {
         printf("%d����53������%s\n",y,week[i%7]);
         /*if(strcmp(week[i%7],"��"))
             a1=53;
         else
            if(strcmp(week[i%7],"��"))
                a2=53;
            else
                if(strcmp(week[i%7],"��"))
                    a3=53;*/
     }
     for(;i<w+7;i++)
     {
         printf("%d����52������%s\n",y,week[i%7]);
         /*if(strcmp(week[i%7],"��"))
             a1=52;
         else
            if(strcmp(week[i%7],"��"))
                a2=52;
            else
                if(strcmp(week[i%7],"��"))
                    a3=52;*/
     }
     /*cout<<"\n��������ڶ�����Ϊ"<<a1;
     cout<<"\n���������������Ϊ"<<a2;
     cout<<"\n����������ո���Ϊ"<<a3;*/
     return 0;
}

