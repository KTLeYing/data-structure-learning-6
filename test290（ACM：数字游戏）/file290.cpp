/*
������Ϸ
��Ϸ��һ������A��ʼ��ֻҪ����λ������1���ͼ�������λ�ĺͣ����Ҳ����ظ�������̡����磺���Ǵ�45��ʼ��4+ 5 = 9��9��1λ����������
�ٱ��磺�����334��ʼ��3 +3 +4 = 10��1 + 0= 1�����õ�1��ע�⣬����A���ܻ�ܴ�Ŷ��
����
������������ÿ������1����������0������
���
���������ÿ���������ڵ���һ������������
*/

#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>

using namespace std;

string clear(string a)
{
	if(a.empty())
        a="0";
	while(a[0]=='0')
		a.erase(0,1);
	if(a.empty())
	    a="0";
	return a;
}

string add(string a,string b)
{
	int i;
	while(a.size()<b.size())
		a="0"+a;
	while(a.size()>b.size())
		b="0"+b;
	a="0"+a;
	b="0"+b;
	for(i=a.size()-1;i>0;i--)
	{
		a[i]=a[i]+b[i]-'0';
		if(a[i]>'9')
		{
            a[i]-=10;
		    a[i-1]++;
		}
	}
	a=clear(a);
	return a;
}

int main()
{
	string a;
	string sum,a1;
	int i;
	while(cin>>a&&a!="0")
    {
         while(1&&a.length()>1)
         {
              sum="0";
              for(i=0;i<a.length();i++)
              {
                  a1=a[i];
                  sum=add(sum,a1);
              }
              a=sum;
         }
         cout<<a<<endl;
    }
    return 0;
}



//����汾����Ϊ�Ǹ����ֺܴ���������������װ����(����string�������һ����ͨ����ʽ)
/*
#include<iostream>
#include<string>
#include<math.h>
#include <algorithm>
using namespace std;

long long sz(long long a)
{long long sum=0;
	while(a>9)
		{
			sum+=a%10;
			a/=10;
		}
	sum+=a;
	return sum;

}

int main()
{
	long long a;
	while(cin>>a&&a!=0)
	{
		while(1)
		{
			if(a>9) a=sz(a);
			else break;
		}
		cout<<a<<endl;

	}


    return 0;
}
*/
