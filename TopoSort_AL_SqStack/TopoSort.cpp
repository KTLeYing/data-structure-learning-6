#include<stdio.h>
#include<iostream>
#include<cstdlib>

using namespace std;

#define MVNum 100
#define MAX 100
#define OVERFLOW -1
#define ERROR 0

typedef int SElemType;

typedef struct ArcNode
{
    int adjvex;
    struct ArcNode *nextarc;
}ArcNode;

typedef struct VNode
{
    int data;
    ArcNode *firstarc;
}AdjList[MVNum];

typedef struct
{
    int vexnum,arcnum;
    AdjList vertices;
}ALGraph;

typedef struct
{
    SElemType *base;
    SElemType *top;
    int stsize;
}SqStack;

int MakeStack(SqStack &S)
{
    S.base=new SElemType[MAX];
    if(!S.base)
        exit(OVERFLOW);
    S.top=S.base;
    S.stsize=MAX;
}

int Push(SqStack &S,SElemType x)
{
    if(S.top-S.base==S.stsize)
        return ERROR;
    *S.top++=x;
}

int Pop(SqStack &S,SElemType &x)
{
    if(S.top==S.base)
        return ERROR;
        x=*--S.top;
}

int StackEmpty(SqStack S)
{
    if(S.top==S.base)
        return 1;
    else
        return 0;
}

int LocateVex(ALGraph G,int v)
{
    int i;
    for(i=0;i<G.vexnum;i++)
        if(v==G.vertices[i].data)
            return i;
}

int CreateGraph(ALGraph &G)
{
    int i,j,s,t,key,v1,v2;
    cout<<"�����붥�����ͱ���:";
    cin>>G.vexnum>>G.arcnum;
    cout<<"������"<<G.vexnum<<"�������ֵ:";
    for(i=0;i<G.vexnum;i++)
    {
        cin>>G.vertices[i].data;
        G.vertices[i].firstarc=NULL;
    }
    cout<<"������"<<G.arcnum<<"�ߵ���Ϣ:\n";
    for(j=0;j<G.arcnum;j++)
    {
        cout<<"�����"<<j+1<<"������Ϣ(��1 ��2):";
        cin>>v1>>v2;
        s=LocateVex(G,v1);
        t=LocateVex(G,v2);
        ArcNode *p1=new ArcNode;
        p1->adjvex=t;
        p1->nextarc=G.vertices[s].firstarc;
        G.vertices[s].firstarc=p1;
    }
    return 0;
}

int DisGraph(ALGraph G)
{
    int i;
    cout<<"�ڽӱ��������:\n";
    for(i=0;i<G.vexnum;i++)
    {
        cout<<i;
        ArcNode *p;
        p=G.vertices[i].firstarc;
        while(p)
        {
            cout<<"->";
            cout<<p->adjvex;
            p=p->nextarc;
        }
        cout<<endl;
    }
    return 0;
}

int FindInDegree(ALGraph G,int indegree[])
{
    int i,j;
    for(i=0;i<G.vexnum;i++)
        indegree[i]=0;
    for(i=0;i<G.vexnum;i++)
    {
        ArcNode *p;
        p=G.vertices[i].firstarc;
        while(p)
        {
            indegree[p->adjvex]++;
            p=p->nextarc;
        }
    }
    cout<<"indegree[]�����е�����Ϊ:\n";
    for(i=0;i<G.vexnum;i++)
       cout<<i<<" ";
    cout<<endl;
    for(i=0;i<G.vexnum;i++)
       cout<<indegree[i]<<" ";
    cout<<endl;
}

int TopoSort(ALGraph G)
{
    SqStack S;
    ArcNode *p;
    int i,j,m,k,indegree[MVNum],topo[MVNum];
    FindInDegree(G,indegree);
    MakeStack(S);
    for(i=0;i<G.vexnum;i++)
       if(!indegree[i])
          Push(S,i);
    m=0;
    while(!StackEmpty(S))
    {
        Pop(S,i);
        topo[m]=i;
        m++;
        p=G.vertices[i].firstarc;
        while(p)
        {
            k=p->adjvex;
            indegree[k]--;
            if(indegree[k]==0)
                Push(S,k);
            p=p->nextarc;
        }
    }

    if(m<G.vexnum)
        cout<<"������ͼ�л�·!����ʵ����������!\n";
    else
    {
        cout<<"�����������Ϊ(���):";
        for(i=0;i<m;i++)
           cout<<topo[i]<<" ";
        cout<<endl;
        cout<<"�����������Ϊ(����):";
        for(i=0;i<m;i++)
           cout<<G.vertices[topo[i]].data<<" ";
        cout<<endl;
    }
}

int main()
{
    ALGraph G;
    cout<<"�����ڽӱ�!\n";
    CreateGraph(G);
    cout<<"�ɹ������ڽӱ�!\n\n";
    cout<<"����ڽӱ�(������)!\n";
    DisGraph(G);
    cout<<"ʵ����������!\n";
    TopoSort(G);
    return 0;
}
