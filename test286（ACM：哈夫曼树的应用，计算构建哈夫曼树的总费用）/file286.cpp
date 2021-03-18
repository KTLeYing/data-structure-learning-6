/*题目:例如，对于数列{pi}={5,  3,  8,  2,  9}，Huffman树的构造过程如下：
1.找到{5,  3,  8,  2,  9}中最小的两个数，分别是2和3，从{pi}中删除它们并将和5加入，得到{5,  8,  9,  5}，费用为5。
2.找到{5,  8,  9,  5}中最小的两个数，分别是5和5，从{pi}中删除它们并将和10加入，得到{8,  9,  10}，费用为10。
3.找到{8,  9,  10}中最小的两个数，分别是8和9，从{pi}中删除它们并将和17加入，得到{10,  17}，费用为17。
4.找到{10,  17}中最小的两个数，分别是10和17，从{pi}中删除它们并将和27加入，得到{27}，费用为27。
5.现在，数列中只剩下一个数27，构造过程结束，总费用为5+10+17+27=59。
*/
#include<stdio.h>
#include<iostream>
#include<cstdlib>
#include<fstream>

using namespace std;

typedef struct
{
    int weight;
    int parent,lchild,rchild;
}HTNode,*HuffmanTree;

int Select(HuffmanTree HT,int len,int &s1,int &s2)
{
    int temp,i,min1,min2;
    min1=2147483647;
    min2=2147483647;
    for(i=1;i<=len;i++)
    {
        if(HT[i].weight<min1 && HT[i].parent==0)
        {
            min1=HT[i].weight;
            s1=i;
        }
    }
    temp=HT[s1].weight;
    HT[s1].weight=2147483647;
    for(i=1;i<=len;i++)
    {
        if(HT[i].weight<min2 && HT[i].parent==0)
        {
             min2=HT[i].weight;
             s2=i;
        }
    }
    HT[s1].weight=temp;
}

int CreatHuffmanTree(HuffmanTree &HT,int n)
{
    int i,key,s1,s2;
    HT=new HTNode[2*n];
    for(i=1;i<2*n;i++)
    {
        HT[i].parent=0;
        HT[i].lchild=0;
        HT[i].rchild=0;
    }
    cout<<"请输入叶子的权值:";
    for(i=1;i<=n;i++)
        cin>>HT[i].weight;
    for(i=n+1;i<=(2*n)-1;i++)
    {
        Select(HT,i-1,s1,s2);
        HT[s1].parent=i;
        HT[s2].parent=i;
        HT[i].lchild=s1;
        HT[i].rchild=s2;
        HT[i].weight=HT[s1].weight+HT[s2].weight;
    }
    return 0;
}

/*int PutoutHFuTree(HuffmanTree &HT,int n)
{
    int i;
    cout<<"请输出哈夫曼树:\n";
    cout<<"结点i\tweight\tparent\tlchild\trchild\n";
    for(i=1;i<=(2*n)-1;i++)
    {
        cout<<i<<"\t"<<HT[i].weight<<"\t"<<HT[i].parent<<"\t"<<HT[i].lchild<<"\t"<<HT[i].rchild<<endl;
    }
    cout<<"哈夫曼树输出完毕!\n\n";
    return 0;
}*/

int SumTreeCost(HuffmanTree HT,int n)
{
    int i,sum=0;
    for(i=n+1;i<=(n*2)-1;i++)
        sum+=HT[i].weight;
    cout<<"总费用为:";
    cout<<sum<<endl<<endl;
}

int main()
{
    HuffmanTree HT;
    int n,key;
    cout<<"请输入叶子数:";
    while(cin>>n)
    {
        if(n>0 && n<=100)
        {
            //cout<<"\n构建哈夫曼树!\n";
            CreatHuffmanTree(HT,n);
            //cout<<"哈夫曼树构造中!\n";
            //cout<<"哈夫曼树构造成功!\n\n";
            //cout<<"请输出哈夫曼树的详细信息!\n";
            //PutoutHFuTree(HT,n);
            //cout<<"计算总费用!\n";
            SumTreeCost(HT,n);
        }
        cout<<"请输入叶子数:";
    }
    return 0;
}

