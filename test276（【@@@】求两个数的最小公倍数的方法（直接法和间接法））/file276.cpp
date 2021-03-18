#include <stdio.h>
#include <iostream>
#include <cstdlib>

using namespace std;

//法1:直接求
int main()
{
    int m, n, temp, i;
    printf("输入 m & n:");
    scanf("%d%d", &m, &n);
    if(m<n)  //比较大小，使得m中存储大数，n中存储小数
    {
        temp = m;
        m = n;
        n = temp;
    }
    for(i=m; i>0; i++)  //从大数开始寻找满足条件的自然数
        if(i%m==0 && i%n==0)
        {//输出满足条件的自然数并结束循环
            printf("The LCW of %d and %d is: %d\n", m, n, i);
            break;
        }

    return 0;
}


/*
//法2:直接求
int main()
{
    int a,b;
    cin >> a >> b;
    if(a > b)
    {
        int temp = a;
        a = b;
        b = a;
    }
    int i = 1;
    while(!(b * i % a == 0))
        i++;
    cout << i * b << endl;
    return 0;
}
*/


/*
//法3:直接求(用函数)
int LCM(int m,int n)
{
    int i;
    for(i=m;i<m*n+i;i+=m)
    {
        if((i%m==0) && (i%n==0))
            break;
    }
    return i;
}

int main()
{
    int m,n,sum;
    cin>>m>>n;
    sum=LCM(m,n);
    cout<<sum;
}
*/

/*
//法4：(间接求:用最小公约数来求)【公式:LCM=(m*n)/GCD->>最小公倍数=(数1*数2)/最大公约数】
int main()
{
    int m,n,temp,z,m1,n1;  //定义两个整数
    cout<<"请输入两个整数(用空格隔开):"<<endl;
    while(cin>>m>>n)
    {
        m1=m;
        n1=n;
        if(m!=0&&n!=0)  //判断输入中是否有零值
        {
            do
            {
                temp=m%n;
                m=n;
                n=temp;
            }
            while(temp);
             cout<<"最大公约数为："<<m<<endl;
             z=(m1*n1)/m;
             cout<<"最小公倍数为:"<<z<<endl<<endl;
        }
        else
            cout<<"输入有误，请重新输入"<<endl;  //无法求公约数则返回
    }
}
*/



