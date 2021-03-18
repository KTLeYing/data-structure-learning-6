/*题目:有三人睡觉时会打呼噜，分别是小陈、小李、小张，其中，小陈一周有四天不睡觉，分别是周一、周三、周四和周五；小李每月日期尾数为5的
他都不睡觉；小张生活很规律，每天都会按时睡觉。其中三人一起打呼噜的声音被其舍友称之为呼噜合奏曲，现给你一个年份，问这一年他们的舍友
可以欣赏到几次三人的呼噜合奏曲。*/

//计算当年第一天是星期几有一个公式，此次我并未使用，公式如下
//基姆拉尔森计算公式：W= (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400) mod 7

#include<stdio.h>
#include<iostream>
#include<cstdlib>

using namespace std;

int years[100],months[12];

int isLeapYear(int y)    //判断是否为闰年
{
   if((y%4==0&&y%100!=0)||(y%400==0))
   {
      int month[12]={31,29,31,30,31,30,31,31,30,31,30,31},j;
      for(j=0;j<12;j++)
         months[j]=month[j];
      return 1;
   }
   else
   {
      int month[12]={31,28,31,30,31,30,31,31,30,31,30,31},j;
      for(j=0;j<12;j++)
         months[j]=month[j];
      return 0;
   }
}

int main()
{
   int i,j,s,n;
   years[0]=6;
   for(i=1;i<100;i++)
   {
      int sum=0;
      isLeapYear(2000+i-1);
      for(j=0;j<12;j++)
      sum+=months[j];
      years[i]=(sum+years[i-1])%7; //计算每年的第一天的日期
   }
   while(scanf("%d",&n)!=EOF)
   {
      int sum=0;
      s=years[n-2000]-1;
      isLeapYear(n);
      for(i=0;i<12;i++)
        for(j=1;j<=months[i];j++)
        {
            s=(s+1)%7;
            if(j==5 || j==15 || j==25 || s==1 || s==3 || s==4 || s==5)
                continue;
            else
              sum++;
        }
        printf("%d\n",sum);
  }
  return 0;
}
