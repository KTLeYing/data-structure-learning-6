#include<stdio.h>
#include<iostream>
#include<cstdlib>

using namespace std;

#define MaxInt 32767
#define MVNum 100
#define MAX 100
#define OVERFLOW -1
#define ERROR 0;

typedef int SElemType;

typedef struct
{
    int vexs[MVNum];
    int arcs[MVNum][MVNum];
    int vexnum,arcnum;
}AMGraph;

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

int LocateVertex(AMGraph G,int &v1,int &v2)
{
    int i;
    for(i=0;i<G.vexnum;i++)
    {
        if(G.vexs[i]==v1)
        {
            v1=i;
            break;
        }
    }
    for(i=0;i<G.vexnum;i++)
    {
        if(G.vexs[i]==v2)
        {
            v2=i;
            break;
        }
    }
}

int CreateGraph(AMGraph &G)
{
    cout<<"请输入顶点数和边数:";
    cin>>G.vexnum>>G.arcnum;
    int i,j,weight,v1,v2;
    for(i=0;i<G.vexnum;i++)
        for(j=0;j<G.vexnum;j++)
            G.arcs[i][j]=MaxInt;
    cout<<"请输入"<<G.vexnum<<"个顶点信息:";
    for(i=0;i<G.vexnum;i++)
        cin>>G.vexs[i];
    cout<<"请输入目标边信息:\n";
    for(i=0;i<G.arcnum;i++)
    {
        cout<<"输入第"<<i+1<<"条边(分别是:边1 边2 边权):";
        cin>>v1>>v2>>weight;
        LocateVertex(G,v1,v2);
        G.arcs[v1][v2]=weight;
    }
    return 0;
}

int PutGraph(AMGraph G)
{
    int i,j;
    cout<<G.vexnum<<"个点信息分别为:";
    for(i=0;i<G.vexnum;i++)
    {
        cout<<G.vexs[i]<<" ";
    }
    cout<<"\n邻接矩阵如下:\n";
    cout<<"\t";
    for(i=0;i<G.vexnum;i++)
    {
        cout<<i+1<<"\t";
    }
    cout<<"\n\n\n";
    for(i=0;i<G.vexnum;i++)
    {
        cout<<i+1<<"\t";
        for(j=0;j<G.vexnum;j++)
        {
            if(G.arcs[i][j]==MaxInt)
                cout<<"∞\t";
            else
                cout<<G.arcs[i][j]<<"\t";
        }
        cout<<"\n\n\n";
    }
    return 0;
}

int FindInDegree(AMGraph G,int indegree[])
{
    int i,j,k;
    for(i=0;i<G.vexnum;i++)
        indegree[i]=0;
    for(i=0;i<G.vexnum;i++)
       for(j=0;j<G.vexnum;j++)
           if(G.arcs[i][j]!=MaxInt)
               indegree[j]++;
    cout<<"indegree[]数组中的数据为:\n";
    for(i=0;i<G.vexnum;i++)
        cout<<i<<" ";
    cout<<endl;
    for(i=0;i<G.vexnum;i++)
        cout<<indegree[i]<<" ";
    cout<<endl;
}

int TopoSort(AMGraph G)
{
    SqStack S;
    int i,j,k,z,m,indegree[MVNum],topo[MVNum];
    FindInDegree(G,indegree);
    MakeStack(S);
    for(i=0;i<G.vexnum;i++)
       if(!indegree[i])
       {
           Push(S,i);
           indegree[i]=-1;
       }
    m=0;
    while(!StackEmpty(S))
    {
        Pop(S,i);
        topo[m]=i;
        m++;
        for(j=0;j<G.vexnum;j++)
        {
            if(G.arcs[i][j]!=MaxInt)
               indegree[j]--;
            if(indegree[j]==0)
            {
                Push(S,j);
                indegree[j]=-1;
            }
        }
    }
    if(m<G.vexnum)
        cout<<"该有向图有回路!不能实现拓扑排序!\n";
    else
    {
        cout<<"输出拓扑序列(下标)为:";
        for(i=0;i<G.vexnum;i++)
            cout<<topo[i]<<" ";
        cout<<endl;
        cout<<"输出拓扑序列(顶点)为:";
        for(i=0;i<G.vexnum;i++)
            cout<<G.vexs[topo[i]]<<" ";
        cout<<endl;
    }
}

int main()
{
    AMGraph G;
    cout<<"创建邻接矩阵!\n";
    CreateGraph(G);
    cout<<"\n\n输出邻接矩阵!\n";
    PutGraph(G);
    cout<<"实现拓扑排序!\n";
    TopoSort(G);
    return 0;
}
