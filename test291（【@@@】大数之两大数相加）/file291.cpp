//��1����string���������(��㣬�����)
#include<stdio.h>
#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

string clear(string str)
{
    if(str.empty())
        str="0";
    while(str[0]=='0')
        str.erase(0,1);
    if(str.empty())
        str="0";
    return str;
}

string add(string str1,string str2)
{
    int i,j;
    string str;
    while(str1.size()<str2.size())
        str1="0"+str1;
    while(str1.size()>str2.size())
        str2="0"+str2;
    str1="0"+str1;
    str2="0"+str2;
    for(i=str1.length()-1;i>0;i--)
    {
        str1[i]=str1[i]+str2[i]-'0';
        if(str1[i]>'9')
        {
            str1[i]-=10;
            str1[i-1]++;
        }
    }
    str=clear(str1);
    cout<<"��Ӻ���ַ���(����)Ϊ:"<<str<<endl;  //�����ʽ1��ֱ�������
    //for(i=0;i<str.length();i++)  //�����ʽ2
        //cout<<str[i];
}

int main()
{
    int i,j;
    string str1,str2;
    cin>>str1>>str2;
    cout<<"ԭ�ַ���Ϊ:"<<str1<<" "<<str2<<endl;
    add(str1,str2);
}

/*
//��2��
#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>

using namespace std;

string Add(string str1,string str2)
{
    string str,temp;
    int i,j;
    if(str1.size()<str2.size())     //�ѽϳ�������str1���������
    {
        temp=str1;
        str1=str2;
        str2=temp;
    }
    for(i=str1.size()-1,j=str2.size()-1;i>=0;i--,j--)
    {
        str1[i]=str1[i]+(j>=0?str2[j]-'0':0);
        if(str1[i]>'9')
        {
            str1[i]-=10;
            if(i)
               str1[i-1]++;
            else
                str1='1'+str1;
        }
    }
    cout<<"��Ӻ�Ľ��Ϊ:"<<str1;
}

int main()
{
    string str1,str2;
    cout<<"��������������:";
    cin>>str1>>str2;
    cout<<"ԭ�ַ���Ϊ:"<<str1<<"  "<<str2<<endl;
    Add(str1,str2);
}
*/


//��3:������洢ʵ��
/*
#include<stdio.h>
#include<iostream>
#include<cstdlib>
#include<string.h>
#include<algorithm>

#define MAX 100

using namespace std;

int Add(char str1[],char str2[])
{
   int i,j,len1,len2;
   int num1[MAX]={0},num2[MAX]={0};
   len1=strlen(str1);
   len2=strlen(str2);
   for(i=len1-1,j=0;i>=0;i--,j++)   //������洢����������ͬʱת��Ϊ���Σ��ٴ���
       num1[j]=str1[i]-'0';
   for(i=len2-1,j=0;i>=0;i--,j++)   //������洢����������ͬʱת��Ϊ���Σ��ٴ���
       num2[j]=str2[i]-'0';
   for(i=0;i<MAX;i++)
   {
       num1[i]=num1[i]+num2[i];
       if(num1[i]>9)
       {
           num1[i]=num1[i]-10;
           num1[i+1]++;
       }
   }
   for(i=MAX-1;i>=0 && num1[i]==0;i--);
   if(i>0)
      for(j=i;j>=0;j--)
         cout<<num1[j];
   else
      cout<<"0";
}

int main()
{
    char str1[MAX],str2[MAX];
    cout<<"�����������ַ���:";
    cin>>str1>>str2;
    cout<<"ԭ�ַ���Ϊ:"<<str1<<" "<<str2<<endl;
    Add(str1,str2);
}
*/


//��4:
/*
#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>

using namespace std;

/*string clear(string str1)
{
    if(str1.empty())
        str1="0";
    while(str1[0]=='0')
        str1.erase(0,1);
    if(str1.empty())
        str1="0";
    return str1;
}*/
/*
string add(string str1,string str2)
{
    int i;
    string str;
    while(str1.length()<str2.length())
        str1="0"+str1;
    while(str1.length()>str2.length())
        str2="0"+str2;
    str1="0"+str1;
    str2="0"+str2;
    for(i=str1.length()-1;i>0;i--)
    {
        str1[i]=str1[i]+str2[i]-'0';
        if(str1[i]>'9')
        {
            str1[i-1]++;
            str1[i]=str1[i]-10;
        }
    }
    /*
    str=clear(str1);
    cout<<str;     //�����ʽ1��ֱ�����
    //for(i=0;i<str.length();i++)  //�����ʽ2
        //cout<<str[i];
    */
    /*
    if(str1[0]=='0')
    {
        for(i=1;i<str1.length();i++)
            cout<<str1[i];

    }
    else
        for(i=0;i<str1.length();i++)
            cout<<str1[i];
}

int main()
{
   string str1,str2;
   cin>>str1>>str2;
   add(str1,str2);
}
*/


