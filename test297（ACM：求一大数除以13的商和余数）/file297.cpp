/*
题目描述
输入一个大于0的大整数N，长度不超过100位，要求输出其除以13得到的商和余数。

输入
一个大于0的大整数，长度不超过100位。

输出
两行，分别为整数除法得到的商和余数。
*/

#include<stdio.h>
#include<iostream>
#include<cstdlib>
#include<string.h>

using namespace std;

#define MAX 1000

int main()
{
    char str1[MAX];
    int num1[MAX],num2[MAX],len1,len2=1,i,x=0;
    cout<<"请输入一个大数:";
    cin>>str1;
    len1=strlen(str1);
    for(i=1;i<=len1;i++)
        num1[i]=str1[i-1]-'0';
    for(i=1;i<=len1;i++)
    {
        num2[i]=(x*10+num1[i])/13;   //计算商
        x=(x*10+num1[i])%13;         //更新余数
    }
    cout<<"商为:";
    while(num2[len2]==0 && len2<len1)   //去掉前面的0
        len2++;
    for(i=len2;i<=len1;i++)
        cout<<num2[i];
    cout<<"\n余数为:";
        cout<<x;
}
