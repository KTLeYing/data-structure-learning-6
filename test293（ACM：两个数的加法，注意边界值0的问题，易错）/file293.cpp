/*
问题描述
你的任务是计算一些整数的总和。
输入
输入在第一行中包含整数N，然后是N行。每行以整数M开头，然后M个整数在同一行中。
输出
对于每组输入整数，您应该在一行中输出它们的总和，并且您必须注意输出之间有一个空行
样本输入
3
4 1 2 3 4
5 1 2 3 4 5
3 1 2 3

样本输出
10

15

6

*/


#include<stdio.h>
#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    int n,m,x,sum;
    while(cin>>n)
    {
        while(n--)
        {
            cin>>m;
            sum = 0;
            while(m--)
            {
                cin>>x;
                sum+=x;
            }
            cout<<sum<<endl;
            if(n!=0)  //注意n=0的时候，此时不执行也需换一行，然后在进行下一个测试压力，注意ACM的严谨性和细节性
                cout<<"\n";
        }
    }
    return 0;
}

