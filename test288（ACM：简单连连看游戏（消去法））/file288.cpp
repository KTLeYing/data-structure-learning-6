/*题目:这是一个类似经典连连看的简单游戏，只要矩阵内部有两个相同整数相邻或者外围（四条最外边）上有两个相同的整数，就可以进行一次消去，
问能否进行一次消去。
Input
第一行只包含一个整数t（t≤500t≤500），表示测试用例的数目。
对于每个测试用例，第一行包含两个整数N和M（1≤N，M≤301≤N，M≤30）。
在接下来的N行中，每一行都包含M个整数，j-th号在i-th线中表示网格上的符号（相同的数字表示网格上相同的符号）。
Output
对于每个测试用例，输出时应该有一行。
您应该输出“Case #x: y”，其中X是序号（从1开始），Y是表示问题答案的字符串。如果至少有一对网格可以一起删除，则Y为“Yes”（不含引号），
否则Y为“No”。
*/

#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<string.h>

using namespace std;

int main()
{
    int t,m,n,i,j,sum=1,flag,array[32][32];
    cin>>t;
    while(t--)
    {
        flag=0;
        memset(array,0,sizeof(array));
        cin>>m>>n;
        for(i=1;i<=m;i++)
            for(j=1;j<=n;j++)
               cin>>array[i][j];
        for(i=1;i<n;i++)
        {
            for(j=i+1;j<=n;j++)
                if(array[1][i]==array[1][j] || array[m][i]==array[m][j])
                {
                    flag=1;
                    break;
                }
            if(flag==1)
                break;
        }
        for(i=1;i<m;i++)
        {
            for(j=i+1;j<=m;j++)
                if(array[i][1]==array[j][1] || array[i][n]==array[j][n])
                {
                    flag=1;
                    break;
                }
            if(flag==1)
                break;
        }
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(j!=n && array[i][j]==array[i][j+1])
                {
                    flag=1;
                    break;
                }
                if(i!=m && array[i][j]==array[i+1][j])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
                break;
        }
        if(flag==1)
        {
            cout<<"Case #"<<sum<<": "<<"Yes"<<endl;
            sum++;
        }
        else
        {
            cout<<"Case #"<<sum<<": "<<"No"<<endl;
            sum++;
        }
    }
}

