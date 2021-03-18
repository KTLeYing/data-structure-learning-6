/*��Ŀ:���磬��������{pi}={5,  3,  8,  2,  9}��Huffman���Ĺ���������£�
1.�ҵ�{5,  3,  8,  2,  9}����С�����������ֱ���2��3����{pi}��ɾ�����ǲ�����5���룬�õ�{5,  8,  9,  5}������Ϊ5��
2.�ҵ�{5,  8,  9,  5}����С�����������ֱ���5��5����{pi}��ɾ�����ǲ�����10���룬�õ�{8,  9,  10}������Ϊ10��
3.�ҵ�{8,  9,  10}����С�����������ֱ���8��9����{pi}��ɾ�����ǲ�����17���룬�õ�{10,  17}������Ϊ17��
4.�ҵ�{10,  17}����С�����������ֱ���10��17����{pi}��ɾ�����ǲ�����27���룬�õ�{27}������Ϊ27��
5.���ڣ�������ֻʣ��һ����27��������̽������ܷ���Ϊ5+10+17+27=59��
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
    cout<<"������Ҷ�ӵ�Ȩֵ:";
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
    cout<<"�������������:\n";
    cout<<"���i\tweight\tparent\tlchild\trchild\n";
    for(i=1;i<=(2*n)-1;i++)
    {
        cout<<i<<"\t"<<HT[i].weight<<"\t"<<HT[i].parent<<"\t"<<HT[i].lchild<<"\t"<<HT[i].rchild<<endl;
    }
    cout<<"��������������!\n\n";
    return 0;
}*/

int SumTreeCost(HuffmanTree HT,int n)
{
    int i,sum=0;
    for(i=n+1;i<=(n*2)-1;i++)
        sum+=HT[i].weight;
    cout<<"�ܷ���Ϊ:";
    cout<<sum<<endl<<endl;
}

int main()
{
    HuffmanTree HT;
    int n,key;
    cout<<"������Ҷ����:";
    while(cin>>n)
    {
        if(n>0 && n<=100)
        {
            //cout<<"\n������������!\n";
            CreatHuffmanTree(HT,n);
            //cout<<"��������������!\n";
            //cout<<"������������ɹ�!\n\n";
            //cout<<"�����������������ϸ��Ϣ!\n";
            //PutoutHFuTree(HT,n);
            //cout<<"�����ܷ���!\n";
            SumTreeCost(HT,n);
        }
        cout<<"������Ҷ����:";
    }
    return 0;
}

