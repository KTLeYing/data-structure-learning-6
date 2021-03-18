/*树，它要么是空的，要么是一组由满足以下性质的节点之间的有向边连接的一个或多个节点。这里正好有一个节点，叫做根，没有有向的边指向它。
除了根，每个节点都有一条边指向它。从根到每个节点有一个唯一的有向边序列。
提示:在此问题中，将给出由有向边连接的节点集合的若干描述。对于其中的每一个，您将确定集合是否满足树的定义。
Input
输入包含多组数据，每组数据格式为：多组空格分开的整数对，每个整数对j, k(1≤j, k≤10000)表示一条有向边从结点j指向结点k。两个空格分开的0，
表示一组数据的结束。最后一组数据后的两个空格分开的-1，表示所有输入数据的结束
Output
每组测试数据单独输出一行，输出"Case k is a tree."或者"Case k is not atree."，这里的k表示测试数据的组号，从1开始计数。
*/

//法1:借助G[i]、edge[i]全局数组变量来实现（两者可合在一起使用为结构体数组）
#include<stdio.h>
#include<iostream>
#include<cstdlib>

using namespace std;

#define Max 50

int G[Max];
int edge[Max];

int Find(int x)
{
    if(G[x]!=x)
        G[x]=Find(G[x]);
     return G[x];
}

int Judge(int t1,int t2)
{
    int a,b;
    a=Find(t1);
    b=Find(t2);
    if(a==b)
        return 0;
    G[b]=a;
    return 1;
}

int main()
{
    int i,j,sum=0,t1,t2,flag;
    cin>>t1>>t2;
    for(i=1;i<=Max;i++)
    {
        G[i]=i;
        edge[i]=0;
    }
    flag=1;
    while(!(t1==t2 && t2==0))
    {
        edge[t1]=1;
        edge[t2]=1;
        if(Find(t2)!=t2)
            flag=0;
        else
            if(!Judge(t1,t2))
                flag=0;
        cin>>t1>>t2;
    }
    for(i=1;i<Max;i++)
    {
        if(G[i]==i && edge[i]==1)
            sum++;
    }
    if(!(sum==0 || sum==1))
        flag=0;
    if(flag)
            cout<<"This is a tree.\n";
        else
            cout<<"This is not a tree.\n";
}


/*
//法2:(与法1的原理一样)
#include<stdio.h>
#include<iostream>
#include<cstdlib>

using namespace std;

#define re1(i,n) for(int i=(1);i<=(n);++i)
#define maxnum 100000+10

template<class T>

int Show(T *a,int n,int m)
{
    for(int i=n;i<=m;++i)
        cout<<a[i]<< ' ';
    cout<<endl;
}

int G[maxnum];
int yank[maxnum];
int edge[maxnum];

int Find(int x)
{
    if(G[x]!=x)
        G[x]=Find(G[x]);
    return G[x];
}

bool Judge(int a,int b)
{
    int x= Find(a);
    int y= Find(b);
    if(x==y)
        return false;
    G[y]=x;
    return true;
}

int main()
{
    int t1,t2,tcase=0;
    while(scanf("%d%d",&t1,&t2))
    {
        if(t1<0 || t2<0)
            break;
        re1(u,maxnum-1)
        {
            G[u]=u;
            edge[u]=0;
        }
        tcase++;
        bool flag=true;
        while(!(t1==t2 && t2==0))
        {
            edge[t1]=1;
            edge[t2]=1;
            if(Find(t2)!=t2)
                flag=false;
            else
                if(!Judge(t1,t2))
                    flag=false;
            scanf("%d%d",&t1,&t2);
        }
        //Show(G,1,5);
        int sum=0;
        re1(u,maxnum-1)
        {
            if(edge[u]&&G[u]==u)
                sum++;
        }
        if(!(sum==0 || sum==1))
            flag=false;
        if(flag)
            printf("Case %d is a tree.\n",tcase);
        else
            printf("Case %d is not a tree.\n",tcase);
    }
}
*/
