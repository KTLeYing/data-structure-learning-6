//法1:

#include<stdio.h>
#include<iostream>
#include<cstdlib>
#include<string.h>
#include<algorithm>

#define MAX 100

using namespace std;

int Multiply(char str1[],char str2[])
{
   int i,j,len1,len2;
   int num1[MAX]={0},num2[MAX]={0},num3[MAX*2+10]={0};  //num3[]积的位数最多是因数位数的两倍

   num3[0]=0;
   len1=strlen(str1);
   len2=strlen(str2);
   for(i=len1-1,j=0;i>=0;i--,j++)      //反转存入数组
       num1[j]=str1[i]-'0';
   for(i=len2-1,j=0;i>=0;i--,j++)      //反转存入数组
       num2[j]=str2[i]-'0';
   for(i=0;i<len1;i++)
      for(j=0;j<len2;j++)
         num3[i+j]=num3[i+j]+num1[i]*num2[j];   //先乘起来，后面统一进行进位
   for(i=0;i<MAX*2+9;i++)         //进位      //i=MAX*2+9或i=MAX*2+8...一定保证i小于开始的MAX*2+10，因为从0下标开始
       if(num3[i]>=10)
       {
           num3[i+1]=num3[i+1]+num3[i]/10;
           num3[i]=num3[i]%10;
       }
   cout<<"相乘后的结果为:";

   for(i=MAX*2+9;i>=0;i--)   //删除前缀0（法1）  //i=MAX*2+9或i=MAX*2+8...一定保证i小于开始的MAX*2+10，因为从0下标开始
       if(num3[i]==0)
          continue;
       else
           break;

   //或
   //for(i=MAX*2+9;i>=0 && num3[i]==0;i--); //删除前缀0（法2）//i=MAX*2+9或i=MAX*2+8...一定保证i小于开始的MAX*2+10，因为从0下标开始
   if(i>0)
       for(j=i;j>=0;j--)
          cout<<num3[j];
}

int main()
{
    char str1[MAX],str2[MAX];
    cout<<"请输入两个大数:";
    cin>>str1>>str2;
    cout<<"原大数为:"<<str1<<" "<<str2<<endl;
    Multiply(str1,str2);
}

/*
//法2:使用memset()统一初始化数组值为0（memset()一般用于处理0的初始化，谨慎使用）
#include<stdio.h>
#include<iostream>
#include<cstdlib>
#include<string.h>
#include<algorithm>

#include<math.h>

#define MAX 100

using namespace std;

int Multiply(char str1[],char str2[])
{
   int i,j,len1,len2,len3;
   int num1[MAX],num2[MAX],num3[MAX*MAX];  //num3[]积的位数最多是因数位数的两倍
   memset(num1,0,sizeof(num1));
   memset(num2,0,sizeof(num2));
   memset(num3,0,sizeof(num3));
   len1=strlen(str1);
   len2=strlen(str2);
   len3=len1+len2;
   for(i=len1-1,j=0;i>=0;i--,j++)      //反转存入数组
       num1[j]=str1[i]-'0';
   for(i=len2-1,j=0;i>=0;i--,j++)      //反转存入数组
       num2[j]=str2[i]-'0';
   for(i=0;i<len1;i++)
      for(j=0;j<len2;j++)
         num3[i+j]=num3[i+j]+num1[i]*num2[j];   //先乘起来，后面统一进行进位
   for(i=0;i<len3;i++)         //进位
       if(num3[i]>=10)
       {
           num3[i+1]=num3[i+1]+num3[i]/10;
           num3[i]=num3[i]%10;
       }
   cout<<"相乘后的结果为:";

   for(i=len3;i>=0;i--)   //删除前缀0（法1）
       if(num3[i]==0)
          continue;
       else
           break;

   //或
   //for(i=len3;i>=0 && num3[i]==0;i--); //删除前缀0（法2）//i=MAX*2+9或i=MAX*2+8...一定保证i小于开始的MAX*2+10，因为从0下标开始


   /*while(num3[len3]==0)     //删除前缀0（法3）
        len3--;
   if(len3>0)
       for(j=len3;j>=0;j--)
          cout<<num3[j];*/

   /*if(i>0)
       for(j=i;j>=0;j--)
          cout<<num3[j];
}

int main()
{
    char str1[MAX],str2[MAX];
    cout<<"请输入两个大数:";
    cin>>str1>>str2;
    cout<<"原大数为:"<<str1<<" "<<str2<<endl;
    Multiply(str1,str2);
}
*/


//法3:直接用main（）函数，增加一种输出方式
/*
#include<stdio.h>
#include<iostream>
#include<cstdlib>
#include<string.h>
#include<cstring>
#include<algorithm>

#define MAX 1000

using namespace std;

int main()
{
   char str1[MAX],str2[MAX];
   cout<<"请输入两个大数:";
   cin>>str1>>str2;
   cout<<"原大数为:"<<str1<<" "<<str2<<endl;
   int i,j,len1,len2;
   int num1[MAX]={0},num2[MAX]={0},num3[MAX*2+10]={0};  //num3[]积的位数最多是因数位数的两倍
   len1=strlen(str1);
   len2=strlen(str2);
   for(i=len1-1,j=0;i>=0;i--,j++)      //反转存入数组
       num1[j]=str1[i]-'0';
   for(i=len2-1,j=0;i>=0;i--,j++)      //反转存入数组
       num2[j]=str2[i]-'0';
   for(i=0;i<len1;i++)
      for(j=0;j<len2;j++)
         num3[i+j]=num3[i+j]+num1[i]*num2[j];   //先乘起来，后面统一进行进位
   for(i=0;i<MAX*2+9;i++)         //进位     //i=MAX*2+9或i=MAX*2+8...一定保证i小于开始的MAX*2+10，因为从0下标开始
       if(num3[i]>=10)
       {
           num3[i+1]=num3[i+1]+num3[i]/10;
           num3[i]=num3[i]%10;
       }
   cout<<"相乘后的结果为:";*/

   /*for(i=MAX*2+9;i>=0;i--)   //删除前缀0（法1）
       if(num3[i]==0)          //i=MAX*2+9或i=MAX*2+8...一定保证i小于开始的MAX*2+10，因为从0下标开始
          continue;
       else
           break;*/

   //或
   //for(i=MAX*2+9;i>=0 && num3[i]==0;i--);   //删除前缀0（法2）
   /*if(i>0)
       for(j=i;j>=0;j--)
          cout<<num3[j];*/
    //或
    /*for(i=MAX*2+9;i>=0;i--)     //i=MAX*2+9或i=MAX*2+8...一定保证i小于开始的MAX*2+10，因为从0下标开始
    {
        if(num3[i]!=0)
        {
            for(j=i;j>=0;j--)
                cout<<num3[j];
            break;
        }
    }
    if(i==-1)
        cout<<"0";
}
*/







