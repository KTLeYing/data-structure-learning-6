#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>

using namespace std;    //目的：把所有盘子从A柱子移动到B柱子

int sum=1;

int hanoi(int n,char a,char b,char c)
{
    if(n==1)
    {
        cout<<n<<"号盘子:"<<a<<"->"<<b<<endl;
    }
    else
    {
         hanoi(n-1,a,c,b);   //A移到C，B做辅助（每一次调用看做一个整体，即起始点为A，终点为C）
         cout<<n<<"号盘子:"<<a<<"->"<<b<<endl;
         sum++;
         hanoi(n-1,c,b,a);  //C移到B，A做辅助（每一次调用看做一个整体，即起始点为C，终点为B）
         sum++;
    }
}

int main()
{
    int n;
    cin>>n;
    hanoi(n,'A','B','C');
    cout<<"移动次数为:"<<sum<<endl;
}
