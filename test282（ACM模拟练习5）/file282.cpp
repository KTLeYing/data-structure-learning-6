#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
   int n,i,j,k,flag,sum;
   int arr[3000],mark[3000];
   while(cin>>n)
   {
       k=0;
       sum=1;
       for(i=0;i<n;i++)
       {
           cin>>arr[i];
       }
       mark[k]=arr[0];
       for(i=1;i<n;i++)
       {
           flag=0;
           for(j=0;j<=k;j++)
           {
               if(arr[i]<mark[j])
               {
                   mark[j]=arr[i];
                   flag=1;
                   break;
               }
           }
           if(flag==0)
           {
               mark[++k]=arr[i];
               sum++;
           }
       }
       cout<<sum<<endl;
   }
}
