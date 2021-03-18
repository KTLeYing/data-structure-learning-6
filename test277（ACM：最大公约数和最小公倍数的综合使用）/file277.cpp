//问题:输入2个正整数x0，y0（2<=x0<100000，2<=y0<=1000000），求出满足下列条件的P，Q的个数。
//条件：1. P，Q是正整数；2. 要求P，Q以x0为最大公约数，以y0为最小公倍数。
//试求：满足条件的所有可能的两个正整数的个数。


//法1:(效率高)
/*
#include<stdio.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include <cstdlib>

using namespace std;

int main()
{
    int x,y,num,ans,a,n,m=5,r;
    while(m--)
    {
        ans=0;
        cin>>x>>y;
        if(x>=2 && x<100000 && y>=2 && y<=1000000)
        {
            num=x*y;   //num即为两数乘积
            for(int i=x;i*i<num;i+=x)
            {                 //可以证明当i*i<num，出现的满足条件数字组合是i*i<m中满足条件的数字组合的相反组合，
                       //i*i=num肯定的是不满足的。i一定要是最大公因数的x倍，所以直接+=x
               if(num%i==0)
               {            //保证num/i是一个整数
                   a=num/i;  //另一个数
                   if(a%x==0)
                   {         //保证a可以除尽最大公因数
                      n=i/x;
                      a=a/x;
                      r=n%a;
                      while(r!=0)
                      {
                         r=n%a;
                         n=a;
                         a=r;
                      }//判断同时除以n后两数是否还有其他公因数
                      if(n==1||i/x==1)//互质
                         ans+=2;//因为是正反两种所以直接加二
                   }
               }
           }
           cout<<ans<<endl;
        }
    }
    return 0;
}
*/

//法2:(效率高)
/*
#include<stdio.h>
#include<cstdio>
#include<iostream>

using namespace std;

int gcd(int x,int y)
{
    if(x%y==0)
    {
        return y;
    }
    else
    {
        return gcd(y,x%y);
    }
}
int main()
{
    int x,y,n=5;
    while(n--)
    {
        scanf("%d%d",&x,&y);
        int ans=0;
        if(x>=2 && x<100000 && y>=2 && y<=1000000)
        {
            for(int i=x;i<=x*y;i+=x)
            {
                if((x*y)%i==0&&gcd(i,(x*y)/i)==x)
                    ans++;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
*/

//法3:(效率高)
/*
#include <stdio.h>
#include <iostream>
#include <cstdlib>

using namespace std;

#define MAX 10000

int LCM(int min, int max, int ev)
{
    int temp;
    while(min!=0)
    {
        temp = min;
        min = max%min;
        max = temp;
    }
    if(max==ev)
        return 1;
    else
        return 0;
}

int main()
{
    int num[MAX];
    int x,y,n=0;
    while(n<5)
    {
        cin>>x>>y;
        if(x>=2 && x<100000 && y>=2 && y<=1000000)
        {
            int p[MAX],q[MAX];
            int count=0;
            for(int i=x;i<=y;i+=x)
            {
               if(y%i==0)
               {
                   num[count] = i;
                 //cout << num[count] << " ";
                   count++;
               }
            }
           //cout << endl;
            int a,b,k=0;
            if(y%x==0)
            {
               p[0]=x;q[0]=y;
             //cout << x << " " << y << endl;
               k++;
            }
            for(int i=1;i<count;i++)
            {
               a = num[i];
               for(int j=i+1;j<count;j++)
               {
                  b = num[j];
                  if((LCM(a,b,x)) && (a*b/x == y))
                  {
                     p[k] = a;
                     q[k] = b;
                     k++;
                    //cout << a << " " << b << endl;
                  }
              }
           }
           cout << (k<<1)<<endl;
        }
        n++;
    }
    return 0;
}
*/

/*
//法4:(效率低，两个for循环)
#include<stdio.h>
#include<iostream>
#include<cstdlib>

using namespace std;

int gcd(int m,int n)
{
	int i,j;
	for(i=0;n!=m;i++)
	{
		if(n>m)
	    {
		     j=m;
		     m=n;
		     n=j;
	    }
		m=m-n;
	}
	return m;
}

int lcm(int m,int n)
{
	int i=1,temp;
	if(m>n)
    {
       temp=m;
       m=n;
       n=temp;
    }
    while(!(n*i%m==0))
        i++;
    return i*n;
}

int main()
{
	int m,n,a=0,i,j;
	cin>>m>>n;
	for(i=m;i<=n;i++)
	{
		for(j=m;j<=n;j++)
		{
			if((gcd(i,j)==m)&&(lcm(i,j)==n))
			   a++;
		}
	}
	cout<<a;
  return 0;
}
*/

//法5:

#include<stdio.h>
#include<iostream>
#include<cstdlib>

using namespace std;

int gcd(int a, int b)
{

   if(a%b==0)
      return b;
   else;
   return gcd(b,a%b);
}

int main()
{
   int i,p,q;
   while(scanf("%d %d",&p,&q)!=EOF)
   {
      int sum=0;
      for(i=p;i<=q;i+=p)
      if(p<=p*q/i && p*q/i<=q && gcd(i,p*q/i)==p && q%i==0)
         sum++;
      printf("%d\n",sum);
   }
   return 0;
}


//法6:(效率低，两个for循环)
/*
#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>

using namespace std;

int GCD(int x,int y)
{
    int a=x,b=y;
    if(a<b)
    {
       int t=a;
       a=b;
       b=t;
    }
    int c;
    while(b)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}

int num,p,q;

int main()
{
   scanf("%d%d",&p,&q);
   for(int i=p;i<=q;i++)
   {
       for(int j=i;j<=q;j++)
       {
           if(GCD(i,j)==p)
           {
               if(i*j/p==q)
                   num+=2;
           }
       }
   }
   cout<<num<<endl;
}
*/
