/*��Ŀ:����һ�����ƾ����������ļ���Ϸ��ֻҪ�����ڲ���������ͬ�������ڻ�����Χ����������ߣ�����������ͬ���������Ϳ��Խ���һ����ȥ��
���ܷ����һ����ȥ��
Input
��һ��ֻ����һ������t��t��500t��500������ʾ������������Ŀ��
����ÿ��������������һ�а�����������N��M��1��N��M��301��N��M��30����
�ڽ�������N���У�ÿһ�ж�����M��������j-th����i-th���б�ʾ�����ϵķ��ţ���ͬ�����ֱ�ʾ��������ͬ�ķ��ţ���
Output
����ÿ���������������ʱӦ����һ�С�
��Ӧ�������Case #x: y��������X����ţ���1��ʼ����Y�Ǳ�ʾ����𰸵��ַ��������������һ���������һ��ɾ������YΪ��Yes�����������ţ���
����YΪ��No����
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

