/*��Ŀ:������˯��ʱ�����࣬�ֱ���С�¡�С�С�ţ����У�С��һ�������첻˯�����ֱ�����һ�����������ĺ����壻С��ÿ������β��Ϊ5��
������˯����С������ܹ��ɣ�ÿ�춼�ᰴʱ˯������������һ������������������ѳ�֮Ϊ������������ָ���һ����ݣ�����һ�����ǵ�����
�������͵��������˵ĺ����������*/

//���㵱���һ�������ڼ���һ����ʽ���˴��Ҳ�δʹ�ã���ʽ����
//��ķ����ɭ���㹫ʽ��W= (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400) mod 7

#include<stdio.h>
#include<iostream>
#include<cstdlib>

using namespace std;

int years[100],months[12];

int isLeapYear(int y)    //�ж��Ƿ�Ϊ����
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
      years[i]=(sum+years[i-1])%7; //����ÿ��ĵ�һ�������
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
