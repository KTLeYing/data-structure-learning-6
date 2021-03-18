//题目:给你一个高为n ，宽为m列的网格，计算出这个网格中有多少个矩形(递推矩形个数)

//法1:公式法(解题思路：两个对角点确定一个矩形寻找每行节点与之不同行不同列的节点 从左到右，从上到下，依次寻找，
//                 得公式：num=n*(n+1)/2*m*(m+1)/2 )

#include<stdio.h>
#include<iostream>
#include<cstdlib>

using namespace std;

int main()
{
    int n,m,i;
    scanf("%d",&i);
    while(i--)
    {
        scanf("%d%d",&n,&m);
        printf("%d\n",(n*n+n)/2*(m*m+m)/2);
    }
    return 0;
}


/*
//法2:间接法
#include<stdio.h>
#include<iostream>
#include<cstdlib>

using namespace std;

int fun(int x)
{
   int sum=0;
   for(;x>0;x--)
   sum+=x;
   return sum;
}

int main()
{
   int t,n,m,ans;
   scanf("%d",&t);
   while(t--)
   {
     scanf("%d%d",&n,&m);
     ans=fun(n)*fun(m);
     printf("%d\n",ans);
   }
   return 0;
}
*/
