//��1��ϵͳĬ�ϴ�С����
/*
#include<iostream>
#include<algorithm>   //sort�����ͷ�ļ�

using namespace std;

int main()
{
  int a[10]={9,6,3,8,5,2,7,4,1,0};
  for(int i=0;i<10;i++)
  cout<<a[i]<<" ";
  cout<<endl;
  sort(a,a+10); //���Կ�������������Ϊ����ַ,aΪ��ʼ��a+10Ϊ����λ��
  for(int i=0;i<10;i++)
  cout<<a[i]<<" ";
  return 0;

}
*/

//��2:�Զ������򷽷����Ӵ�С��

#include<iostream>
#include<algorithm>    //sort�����ͷ�ļ�

using namespace std;

int Compare1(int a,int b)
{
    return a>b;   //�Զ���Ӵ�С����
}

int main()
{
  int a[10]={9,6,3,8,5,2,7,4,1,0};
  for(int i=0;i<10;i++)
  cout<<a[i]<<" ";
  cout<<endl;
  sort(a,a+10,Compare1); //���Կ�������������Ϊ����ַ,aΪ��ʼ��a+10Ϊ����λ�ã�Compare1Ϊ���򷽷�
  for(int i=0;i<10;i++)
  cout<<a[i]<<" ";
  return 0;

}


//��3����<vector>��<algorithm>�������ʵ��
/*
#include<stdio.h>
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

int Less(int a,int b)     //��С��������
{
    return a<b;
}

/*
int Great(int a,int b)  //�Ӵ�С����
{

    return a>b;
}
*/

/*
int main()
{
    int t,x;
    vector<int> a;
    cin>>t;
    while (t--)
    {
        int m;
        cin>>m;
        for (int i = 0;i < m;i++)
        {
            cin>>x;
            a.push_back(x);
        }
        sort(a.begin(),a.end(),Less);
        //sort(a.begin(),a.end(),Great);
        cout<<a[0];
        for (int i = 1;i <a.size();i++)
           cout<<" "<<a[i];
        cout<<endl;
        //a.clear();     //�������a��Ԫ��
        //��
        a.erase(a.begin(),a.end());
    }
}
*/


/*
//��4��������ʵ����
#include<stdio.h>
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int Less(int a,int b)     //��С��������
{
    return a<b;
}

int Great(int a,int b)  //�Ӵ�С����
{

    return a>b;
}


int main()
{
    int t;
    int a[1000];
    cin>>t;
    while (t--)
    {
        int m;
        cin>>m;
        for (int i = 0;i < m;i++)
            cin>>a[i];
        //sort(a,a+m,Less);
        sort(a,a+m,Great);
        cout<<a[0];
        for (int i = 1;i < m;i++)
           cout<<" "<<a[i];
        cout<<endl;
    }
}
*/
