//��1:

#include<stdio.h>
#include<iostream>
#include<cstdlib>
#include<string.h>
#include<algorithm>

#define MAX 100

using namespace std;

int Multiply(char str1[],char str2[])
{
   int i,j,len1,len2;
   int num1[MAX]={0},num2[MAX]={0},num3[MAX*2+10]={0};  //num3[]����λ�����������λ��������

   num3[0]=0;
   len1=strlen(str1);
   len2=strlen(str2);
   for(i=len1-1,j=0;i>=0;i--,j++)      //��ת��������
       num1[j]=str1[i]-'0';
   for(i=len2-1,j=0;i>=0;i--,j++)      //��ת��������
       num2[j]=str2[i]-'0';
   for(i=0;i<len1;i++)
      for(j=0;j<len2;j++)
         num3[i+j]=num3[i+j]+num1[i]*num2[j];   //�ȳ�����������ͳһ���н�λ
   for(i=0;i<MAX*2+9;i++)         //��λ      //i=MAX*2+9��i=MAX*2+8...һ����֤iС�ڿ�ʼ��MAX*2+10����Ϊ��0�±꿪ʼ
       if(num3[i]>=10)
       {
           num3[i+1]=num3[i+1]+num3[i]/10;
           num3[i]=num3[i]%10;
       }
   cout<<"��˺�Ľ��Ϊ:";

   for(i=MAX*2+9;i>=0;i--)   //ɾ��ǰ׺0����1��  //i=MAX*2+9��i=MAX*2+8...һ����֤iС�ڿ�ʼ��MAX*2+10����Ϊ��0�±꿪ʼ
       if(num3[i]==0)
          continue;
       else
           break;

   //��
   //for(i=MAX*2+9;i>=0 && num3[i]==0;i--); //ɾ��ǰ׺0����2��//i=MAX*2+9��i=MAX*2+8...һ����֤iС�ڿ�ʼ��MAX*2+10����Ϊ��0�±꿪ʼ
   if(i>0)
       for(j=i;j>=0;j--)
          cout<<num3[j];
}

int main()
{
    char str1[MAX],str2[MAX];
    cout<<"��������������:";
    cin>>str1>>str2;
    cout<<"ԭ����Ϊ:"<<str1<<" "<<str2<<endl;
    Multiply(str1,str2);
}

/*
//��2:ʹ��memset()ͳһ��ʼ������ֵΪ0��memset()һ�����ڴ���0�ĳ�ʼ��������ʹ�ã�
#include<stdio.h>
#include<iostream>
#include<cstdlib>
#include<string.h>
#include<algorithm>

#include<math.h>

#define MAX 100

using namespace std;

int Multiply(char str1[],char str2[])
{
   int i,j,len1,len2,len3;
   int num1[MAX],num2[MAX],num3[MAX*MAX];  //num3[]����λ�����������λ��������
   memset(num1,0,sizeof(num1));
   memset(num2,0,sizeof(num2));
   memset(num3,0,sizeof(num3));
   len1=strlen(str1);
   len2=strlen(str2);
   len3=len1+len2;
   for(i=len1-1,j=0;i>=0;i--,j++)      //��ת��������
       num1[j]=str1[i]-'0';
   for(i=len2-1,j=0;i>=0;i--,j++)      //��ת��������
       num2[j]=str2[i]-'0';
   for(i=0;i<len1;i++)
      for(j=0;j<len2;j++)
         num3[i+j]=num3[i+j]+num1[i]*num2[j];   //�ȳ�����������ͳһ���н�λ
   for(i=0;i<len3;i++)         //��λ
       if(num3[i]>=10)
       {
           num3[i+1]=num3[i+1]+num3[i]/10;
           num3[i]=num3[i]%10;
       }
   cout<<"��˺�Ľ��Ϊ:";

   for(i=len3;i>=0;i--)   //ɾ��ǰ׺0����1��
       if(num3[i]==0)
          continue;
       else
           break;

   //��
   //for(i=len3;i>=0 && num3[i]==0;i--); //ɾ��ǰ׺0����2��//i=MAX*2+9��i=MAX*2+8...һ����֤iС�ڿ�ʼ��MAX*2+10����Ϊ��0�±꿪ʼ


   /*while(num3[len3]==0)     //ɾ��ǰ׺0����3��
        len3--;
   if(len3>0)
       for(j=len3;j>=0;j--)
          cout<<num3[j];*/

   /*if(i>0)
       for(j=i;j>=0;j--)
          cout<<num3[j];
}

int main()
{
    char str1[MAX],str2[MAX];
    cout<<"��������������:";
    cin>>str1>>str2;
    cout<<"ԭ����Ϊ:"<<str1<<" "<<str2<<endl;
    Multiply(str1,str2);
}
*/


//��3:ֱ����main��������������һ�������ʽ
/*
#include<stdio.h>
#include<iostream>
#include<cstdlib>
#include<string.h>
#include<cstring>
#include<algorithm>

#define MAX 1000

using namespace std;

int main()
{
   char str1[MAX],str2[MAX];
   cout<<"��������������:";
   cin>>str1>>str2;
   cout<<"ԭ����Ϊ:"<<str1<<" "<<str2<<endl;
   int i,j,len1,len2;
   int num1[MAX]={0},num2[MAX]={0},num3[MAX*2+10]={0};  //num3[]����λ�����������λ��������
   len1=strlen(str1);
   len2=strlen(str2);
   for(i=len1-1,j=0;i>=0;i--,j++)      //��ת��������
       num1[j]=str1[i]-'0';
   for(i=len2-1,j=0;i>=0;i--,j++)      //��ת��������
       num2[j]=str2[i]-'0';
   for(i=0;i<len1;i++)
      for(j=0;j<len2;j++)
         num3[i+j]=num3[i+j]+num1[i]*num2[j];   //�ȳ�����������ͳһ���н�λ
   for(i=0;i<MAX*2+9;i++)         //��λ     //i=MAX*2+9��i=MAX*2+8...һ����֤iС�ڿ�ʼ��MAX*2+10����Ϊ��0�±꿪ʼ
       if(num3[i]>=10)
       {
           num3[i+1]=num3[i+1]+num3[i]/10;
           num3[i]=num3[i]%10;
       }
   cout<<"��˺�Ľ��Ϊ:";*/

   /*for(i=MAX*2+9;i>=0;i--)   //ɾ��ǰ׺0����1��
       if(num3[i]==0)          //i=MAX*2+9��i=MAX*2+8...һ����֤iС�ڿ�ʼ��MAX*2+10����Ϊ��0�±꿪ʼ
          continue;
       else
           break;*/

   //��
   //for(i=MAX*2+9;i>=0 && num3[i]==0;i--);   //ɾ��ǰ׺0����2��
   /*if(i>0)
       for(j=i;j>=0;j--)
          cout<<num3[j];*/
    //��
    /*for(i=MAX*2+9;i>=0;i--)     //i=MAX*2+9��i=MAX*2+8...һ����֤iС�ڿ�ʼ��MAX*2+10����Ϊ��0�±꿪ʼ
    {
        if(num3[i]!=0)
        {
            for(j=i;j>=0;j--)
                cout<<num3[j];
            break;
        }
    }
    if(i==-1)
        cout<<"0";
}
*/







