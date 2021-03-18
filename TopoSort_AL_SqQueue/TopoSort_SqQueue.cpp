#include<stdio.h>
#include<iostream>
#include<cstdlib>

using namespace std;

#define MVNum 100
#define ERROR 0
#define MAXSIZE 100
#define OVERFLOW -1

typedef int ElemType;

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
    ElemType *base;
    int fron;
    int rear;
}SqQueue;

int CreateQueue(SqQueue &Q)
{
    Q.base=new ElemType{MAXSIZE};
    if(!Q.base)
        exit(OVERFLOW);
    Q.fron=Q.rear=0;
}

int EnQueue(SqQueue &Q,ElemType x)
{
    if((Q.rear+1)%MAXSIZE==Q.fron)
        return ERROR;
    Q.base[Q.rear]=x;
    Q.rear=(Q.rear+1)%MAXSIZE;
}

int DeQueue(SqQueue &Q,ElemType &x)
{
    if(Q.fron==Q.rear)
        return ERROR;
    x=Q.base[Q.fron];
    Q.fron=(Q.fron+1)%MAXSIZE;
}

int QueueEmpty(SqQueue Q)
{
    if(Q.fron==Q.rear)
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
    cout<<"请输入顶点数和边数:";
    cin>>G.vexnum>>G.arcnum;
    cout<<"请输入"<<G.vexnum<<"个顶点的值:";
    for(i=0;i<G.vexnum;i++)
    {
        cin>>G.vertices[i].data;
        G.vertices[i].firstarc=NULL;
    }
    cout<<"请输入"<<G.arcnum<<"边的信息:\n";
    for(j=0;j<G.arcnum;j++)
    {
        cout<<"输入第"<<j+1<<"条边信息(边1 边2):";
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
    cout<<"邻接表输出如下:\n";
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
    cout<<"indegree[]数组中的数据为:\n";
    for(i=0;i<G.vexnum;i++)
       cout<<i<<" ";
    cout<<endl;
    for(i=0;i<G.vexnum;i++)
       cout<<indegree[i]<<" ";
    cout<<endl;
}

int TopoSort(ALGraph G)
{
    SqQueue Q;
    ArcNode *p;
    int i,j,m,k,indegree[MVNum],topo[MVNum];
    FindInDegree(G,indegree);
    CreateQueue(Q);
    for(i=0;i<G.vexnum;i++)
       if(!indegree[i])
          EnQueue(Q,i);
    m=0;
    while(!QueueEmpty(Q))
    {
        DeQueue(Q,i);
        topo[m]=i;
        m++;
        p=G.vertices[i].firstarc;
        while(p)
        {
            k=p->adjvex;
            indegree[k]--;
            if(indegree[k]==0)
                EnQueue(Q,k);
            p=p->nextarc;
        }
    }

    if(m<G.vexnum)
        cout<<"该有向图有回路!不能实现拓扑排序!\n";
    else
    {
        cout<<"输出拓扑序列为(序号):";
        for(i=0;i<m;i++)
           cout<<topo[i]<<" ";
        cout<<endl;
        cout<<"输出拓扑序列为(顶点):";
        for(i=0;i<m;i++)
           cout<<G.vertices[topo[i]].data<<" ";
        cout<<endl;
    }
}

int main()
{
    ALGraph G;
    cout<<"创建邻接表!\n";
    CreateGraph(G);
    cout<<"成功创建邻接表!\n\n";
    cout<<"输出邻接表(输出序号)!\n";
    DisGraph(G);
    cout<<"实现拓扑排序!\n";
    TopoSort(G);
    return 0;
}
