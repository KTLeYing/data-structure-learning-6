#include <stdio.h>
#include <iostream>
#include <cstdlib>

using namespace std;

//��1:ֱ����
int main()
{
    int m, n, temp, i;
    printf("���� m & n:");
    scanf("%d%d", &m, &n);
    if(m<n)  //�Ƚϴ�С��ʹ��m�д洢������n�д洢С��
    {
        temp = m;
        m = n;
        n = temp;
    }
    for(i=m; i>0; i++)  //�Ӵ�����ʼѰ��������������Ȼ��
        if(i%m==0 && i%n==0)
        {//���������������Ȼ��������ѭ��
            printf("The LCW of %d and %d is: %d\n", m, n, i);
            break;
        }

    return 0;
}


/*
//��2:ֱ����
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
//��3:ֱ����(�ú���)
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
//��4��(�����:����С��Լ������)����ʽ:LCM=(m*n)/GCD->>��С������=(��1*��2)/���Լ����
int main()
{
    int m,n,temp,z,m1,n1;  //������������
    cout<<"��������������(�ÿո����):"<<endl;
    while(cin>>m>>n)
    {
        m1=m;
        n1=n;
        if(m!=0&&n!=0)  //�ж��������Ƿ�����ֵ
        {
            do
            {
                temp=m%n;
                m=n;
                n=temp;
            }
            while(temp);
             cout<<"���Լ��Ϊ��"<<m<<endl;
             z=(m1*n1)/m;
             cout<<"��С������Ϊ:"<<z<<endl<<endl;
        }
        else
            cout<<"������������������"<<endl;  //�޷���Լ���򷵻�
    }
}
*/



