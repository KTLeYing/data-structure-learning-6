#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>

using namespace std;    //Ŀ�ģ����������Ӵ�A�����ƶ���B����

int sum=1;

int hanoi(int n,char a,char b,char c)
{
    if(n==1)
    {
        cout<<n<<"������:"<<a<<"->"<<b<<endl;
    }
    else
    {
         hanoi(n-1,a,c,b);   //A�Ƶ�C��B��������ÿһ�ε��ÿ���һ�����壬����ʼ��ΪA���յ�ΪC��
         cout<<n<<"������:"<<a<<"->"<<b<<endl;
         sum++;
         hanoi(n-1,c,b,a);  //C�Ƶ�B��A��������ÿһ�ε��ÿ���һ�����壬����ʼ��ΪC���յ�ΪB��
         sum++;
    }
}

int main()
{
    int n;
    cin>>n;
    hanoi(n,'A','B','C');
    cout<<"�ƶ�����Ϊ:"<<sum<<endl;
}
