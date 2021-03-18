//法1：用字符串实现

#include<stdio.h>
#include<iostream>
#include<cstdlib>
#include<string.h>
#include<algorithm>

using namespace std;

/*string EraseZero(string str)
{
    if(str.size()<=1)
        return str;
    if(*str.begin()!='0')
        return str;
    str.erase(str.begin());
    return EraseZero(str);      //用递归去掉0
}*/

/*string EraseZero(string str)
{
    if(str.size()<=1)
        return str;
    while(*str.begin()=='0')     //用for循环结构去掉0
        str.erase(str.begin());
    return str;
}
*/


string Minus(string str1,string str2)
{
    int flag=0,i,j;
    string temp;
    if(str1.size()<str2.size() || (str1.size()==str2.size() && str1<str2))
    {
        flag=1;
        temp=str1;
        str1=str2;
        str2=temp;
    }
    for(i=str1.size()-1,j=str2.size()-1;i>=0;i--,j--)
    {
        if(j>=0)
        {
            if(str1[i]<'0' || str1[i]<str2[j])
            {
                str1[i]=str1[i]+10-((j<0)?0:str2[j]-'0');
                str1[i-1]--;
                continue;
            }
        }
        str1[i]=str1[i]-((j<0)?0:str2[j]-'0');
    }
    if(str1.length()<=1)
    {
        if(flag)
            str1="-"+str1;
        cout<<str1<<endl;
    }
    else
    {
        while(*str1.begin()=='0')
           str1.erase(str1.begin());
        if(flag)
            str1="-"+str1;
        cout<<str1<<endl;
    }
}

int main()
{
    string str1,str2;
    cout<<"请输入两个字符串:";
    cin>>str1>>str2;
    cout<<"原字符串为:"<<str1<<" "<<str2<<endl;
    Minus(str1,str2);
}

/*
//法2：用数组实现
#include<stdio.h>
#include<iostream>
#include<cstdlib>
#include<string.h>
#include<algorithm>

#define MAX 100

using namespace std;

int Add(char str1[],char str2[])
{
   int i,j,flag,k,f=0,len1,len2;
   int num1[MAX]={0},num2[MAX]={0},num3[MAX];
   num3[0]=0;
   len1=strlen(str1);
   len2=strlen(str2);
   if(len1>len2)
        k=len1;
   else
      k=len2;
   if(len1>len2)
        flag=1;
   else
      if(len1==len2)
           flag=strcmp(str1,str2);
      else
         flag=-1;
   for(i=len1-1,j=0;i>=0;i--,j++)
       num1[j]=str1[i]-'0';
   for(i=len2-1,j=0;i>=0;i--,j++)
       num2[j]=str2[i]-'0';

   for(i=0;i<k;i++)
   {
       if(flag>=0)
       {
           if(num1[i]-num2[i]>=0)
               num3[i]=num1[i]-num2[i];
           else
           {
               num3[i]=num1[i]+10-num2[i];
               num1[i+1]--;
           }
       }
       else
       {
           if(num2[i]-num1[i]>=0)
               num3[i]=num2[i]-num1[i];
           else
           {
               num3[i]=num2[i]+10-num1[i];
               num2[i+1]--;
           }
       }
   }
   cout<<"相减后的结果为:";
   if(flag<0)
      cout<<"-";
    /*
   for(i=k-1;i>=0;i--)
       if(num3[i] || i==0)
             cout<<num3[i];
    */
    //或
  /* for(i=k-1;i>=0 && num3[i]==0;i--);
   if(i>0)
       for(j=i;j>=0;j--)
          cout<<num3[j];
   else
      cout<<"0";
}

int main()
{
    char str1[MAX],str2[MAX];
    cout<<"请输入两个大数:";
    cin>>str1>>str2;
    cout<<"原大数为:"<<str1<<" "<<str2<<endl;
    Add(str1,str2);
}
*/

