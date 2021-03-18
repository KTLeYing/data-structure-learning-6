#include<stdio.h>
#include<iostream>
#include<cstdlib>
using namespace std;
typedef char ElemType;

typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

void CreateBiTree(BiTree &T)
{
    char ch;
    cin>>ch;
    if(ch=='#')
        T=NULL;
    else
    {
        T=new BiTNode;
        T->data=ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}

int PreOrder(BiTree T)
{
    if(T)
    {
       cout<<T->data<<" ";
       PreOrder(T->lchild);
       PreOrder(T->rchild);
    }
}

int InOrder(BiTree T)
{
    if(T)
    {
        InOrder(T->lchild);
        cout<<T->data<<" ";
        InOrder(T->rchild);
    }
}

int PostOrder(BiTree T)
{
        if(T)
        {
            PostOrder(T->lchild);
            PostOrder(T->rchild);
            cout<<T->data<<" ";
        }
}

int BiTreeDep(BiTree T)
{
    int m=0,n=0;
    if(T==NULL)
        return 0;
    else
    {
        m=BiTreeDep(T->lchild);
        n=BiTreeDep(T->rchild);
        if(m>n)
            return (m+1);
        else
            return (n+1);
    }
}

int DisLeaf(BiTree T)
{
    if(T->lchild && T->rchild)
    {
        DisLeaf(T->lchild);
        DisLeaf(T->rchild);
    }
     else
       cout<<T->data<<" ";

}

int SumNode(BiTree T)
{
    if(T==NULL)
        return 0;
    else
      return SumNode(T->lchild)+SumNode(T->rchild)+1;
}

int main()
{
    BiTree T;
    int choose=1;
    cout<<endl;
    cout<<"\t\t\t\t树子系统"<<endl;
    cout<<"\t\t*******************************************"<<endl;
    cout<<"\t\t*\t\t1-创建一课二叉树\t"<<" "<<" "<<"*"<<endl;
    cout<<"\t\t*\t\t2-先序遍历二叉树\t"<<" "" "<<"*"<<endl;
    cout<<"\t\t*\t\t3-中序遍历二叉树\t"<<" "" "<<"*"<<endl;
    cout<<"\t\t*\t\t4-后序遍历二叉树\t"<<" "" "<<"*"<<endl;
    cout<<"\t\t*\t\t5-显示树的高度\t\t"<<" "<<" "<<"*"<<endl;
    cout<<"\t\t*\t\t6-显示所有叶结点\t"<<" "" "<<"*"<<endl;
    cout<<"\t\t*\t\t7-计算结点数\t\t"<<" "" "<<"*"<<endl;
    cout<<"\t\t*\t\t0-返回\t\t\t"<<" "" "<<"*"<<endl;
    cout<<"\t\t*******************************************"<<endl;
    cout<<"\t\t请选择菜单号(0--7)"<<endl<<endl;
    while(choose)
    {
        cout<<"请选择:\n";
        cin>>choose;
        switch(choose)
        {
            case 1:
                cout<<"创建一棵二叉树:\n";
                cout<<"输入数据:";
                CreateBiTree(T);
                cout<<endl;
                break;
            case 2:
                cout<<"先序遍历二叉树:\n";
                PreOrder(T);
                cout<<endl<<endl;
                break;
            case 3:
                cout<<"中序遍历二叉树:\n";
                InOrder(T);
                cout<<endl<<endl;
                break;
            case 4:
                cout<<"后序遍历二叉树:\n";
                PostOrder(T);
                cout<<endl<<endl;
                break;
            case 5:
                cout<<"显示树的高度为:";
                cout<<BiTreeDep(T)<<endl<<endl;
                break;
            case 6:
                cout<<"显示所叶子为:";
                DisLeaf(T);
                cout<<endl<<endl;
                break;
            case 7:
                cout<<"计算结点数目为:";
                cout<<SumNode(T)<<endl<<endl;
                break;
            case 0:
                cout<<"\t\t\t\t树子系统"<<endl;
                cout<<"\t\t*******************************************"<<endl;
                cout<<"\t\t*\t\t1-创建一课二叉树\t"<<" "<<" "<<"*"<<endl;
                cout<<"\t\t*\t\t2-先序遍历二叉树\t"<<" "" "<<"*"<<endl;
                cout<<"\t\t*\t\t3-中序遍历二叉树\t"<<" "" "<<"*"<<endl;
                cout<<"\t\t*\t\t4-后序遍历二叉树\t"<<" "" "<<"*"<<endl;
                cout<<"\t\t*\t\t5-显示树的高度\t\t"<<" "<<" "<<"*"<<endl;
                cout<<"\t\t*\t\t6-显示所有叶结点\t"<<" "" "<<"*"<<endl;
                cout<<"\t\t*\t\t7-计算结点数\t\t"<<" "" "<<"*"<<endl;
                cout<<"\t\t*\t\t0-返回\t\t\t"<<" "" "<<"*"<<endl;
                cout<<"\t\t*******************************************"<<endl;
                cout<<"\t\t请选择菜单号(0--7)"<<endl<<endl;
                break;
        }
    }
}





