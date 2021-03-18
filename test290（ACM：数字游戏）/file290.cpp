/*
数字游戏
游戏从一个整数A开始，只要它的位数多于1，就计算它各位的和，并且不断重复这个过程。比如：我们从45开始，4+ 5 = 9，9是1位数，结束。
再比如：如果从334开始，3 +3 +4 = 10，1 + 0= 1，最后得到1。注意，整数A可能会很大哦！
输入
输入多个样例，每行输入1个整数，以0结束。
输出
对于输入的每个整数，在单独一行上输出结果。
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



//错误版本，因为那个数字很大，所以用整数类型装不下(不用string或数组的一般普通的形式)
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
