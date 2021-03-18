/*������Ҫô�ǿյģ�Ҫô��һ���������������ʵĽڵ�֮�����������ӵ�һ�������ڵ㡣����������һ���ڵ㣬��������û������ı�ָ������
���˸���ÿ���ڵ㶼��һ����ָ�������Ӹ���ÿ���ڵ���һ��Ψһ����������С�
��ʾ:�ڴ������У�����������������ӵĽڵ㼯�ϵ������������������е�ÿһ��������ȷ�������Ƿ��������Ķ��塣
Input
��������������ݣ�ÿ�����ݸ�ʽΪ������ո�ֿ��������ԣ�ÿ��������j, k(1��j, k��10000)��ʾһ������ߴӽ��jָ����k�������ո�ֿ���0��
��ʾһ�����ݵĽ��������һ�����ݺ�������ո�ֿ���-1����ʾ�����������ݵĽ���
Output
ÿ��������ݵ������һ�У����"Case k is a tree."����"Case k is not atree."�������k��ʾ�������ݵ���ţ���1��ʼ������
*/

//��1:����G[i]��edge[i]ȫ�����������ʵ�֣����߿ɺ���һ��ʹ��Ϊ�ṹ�����飩
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
//��2:(�뷨1��ԭ��һ��)
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
