//��Ŀ:����һ����Ϊn ����Ϊm�е����񣬼��������������ж��ٸ�����(���ƾ��θ���)

//��1:��ʽ��(����˼·�������Խǵ�ȷ��һ������Ѱ��ÿ�нڵ���֮��ͬ�в�ͬ�еĽڵ� �����ң����ϵ��£�����Ѱ�ң�
//                 �ù�ʽ��num=n*(n+1)/2*m*(m+1)/2 )

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
//��2:��ӷ�
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
