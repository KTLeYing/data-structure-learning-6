/*
��Ŀ����
����һ������0�Ĵ�����N�����Ȳ�����100λ��Ҫ����������13�õ����̺�������

����
һ������0�Ĵ����������Ȳ�����100λ��

���
���У��ֱ�Ϊ���������õ����̺�������
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
    cout<<"������һ������:";
    cin>>str1;
    len1=strlen(str1);
    for(i=1;i<=len1;i++)
        num1[i]=str1[i-1]-'0';
    for(i=1;i<=len1;i++)
    {
        num2[i]=(x*10+num1[i])/13;   //������
        x=(x*10+num1[i])%13;         //��������
    }
    cout<<"��Ϊ:";
    while(num2[len2]==0 && len2<len1)   //ȥ��ǰ���0
        len2++;
    for(i=len2;i<=len1;i++)
        cout<<num2[i];
    cout<<"\n����Ϊ:";
        cout<<x;
}
