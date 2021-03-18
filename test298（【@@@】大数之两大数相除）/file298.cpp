//��1:
/*
#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdio.h>
#include<cstdlib>

using namespace std;

#define MAX 100

int digit,num1[MAX],num2[MAX],result[MAX];
char str1[MAX],str2[MAX];

int Division(int num1[],int num2[],int len1,int len2)
{
    int i;
    for(i=0;i<len1;i++)
    {
        if(num1[i]<num2[i])
        {
            num1[i]=num1[i]+10-num2[i];
            num1[i+1]--;
        }
        else
            num1[i]=num1[i]-num2[i];
    }
    for(i=len1-1;i>=0;i--)
    {
        if(num1[i])
        {
            digit=i+1;
            break;
        }
    }
}

int Judge(int num1[],int num2[],int len1,int len2)
{
    int i;
    if(len1<len2)
        return -1;
    if(len1==len2)
    {
        for(i=len1-1;i>=0;i--)
        {
            if(num1[i]==num2[i])
                continue;
            else
                if(num1[i]>num2[i])
                    return 1;
                else
                    return -1;
        }
        return 0;
    }
}

int main()
{
    int i,j,k,temp,len1,len2,len;
    cout<<"��������������:";
    cin>>str1>>str2;
    cout<<"ԭ����Ϊ:"<<str1<<" "<<str2<<endl;
    len1=strlen(str1);
    len2=strlen(str2);
    for(i=len1-1,j=0;i>=0;j++,i--)
        num1[j]=str1[i]-'0';
    for(i=len2-1,j=0;i>=0;j++,i--)
        num2[j]=str2[i]-'0';
    k=len2;
    if(len1<len2)
    {
        cout<<"����:0\n";
        cout<<"������:"<<str1;
    }
    else
    {
        len=len1-len2;
        for(i=len1-1;i>=0;i--)
        {
            if(i>=len)
                num2[i]=num2[i-len];
            else
                num2[i]=0;
        }
        len2=len1;
        digit=len1;
        for(i=0;i<=len;i++)
        {
            result[len-i]=0;
            while(((temp=Judge(num1,num2,len1,len2))>=0) && digit>=k)
            {
                 Division(num1,num2,len1,len2);
                 result[len-i]++;
                 len1=digit;
                 if(len1<len2 && num2[len2-1]==0)
                     len2=len1;
            }
            if(temp<0)
            {
                for(j=1;j<len2;j++)
                    num2[j-1]=num2[j];
                num2[j-1]=0;
                if(len1<len2)
                    len2--;
            }
        }
        cout<<"����:";
        for(i=len;i>0;i--)
            if(result[i])
                break;
        for(j=i;j>=0;j--)
           cout<<result[j];
        cout<<endl;
        cout<<"������:";
        for(i=len1;i>0;i--)
            if(num1[i])
               break;
        for(j=i;j>=0;j--)
            cout<<num1[j];
        cout<<endl;
    }
}
*/


//��2�����뷨1ԭ��һ�������ַ���ֻ��������е���

#include<iostream>
#include<string.h>
#include<stdio.h>
#include<cstdlib>

using namespace std;

#define MAX 1000

/*
  ����SubStract���ܣ�
  �ó���Ϊlen1�Ĵ�����p1��ȥ����Ϊlen2�Ĵ�����p2
  �������p1�У�����ֵ�������ĳ���
  ������������-1 �� ���ù�������0
*/
int SubStract(int *pNum1, int len1, int *pNum2, int len2)
{
    int i;
    if(len1 < len2)
        return -1;
    else
      if(len1 == len2 )
      {                        // �ж�p1 > p2
          for(i = len1-1; i >= 0; i--)
          {
            if(pNum1[i] > pNum2[i])   // ������������������������
                break;
            else
                if(pNum1[i] < pNum2[i]) // ���򷵻�-1
                   return -1;
         }
     }
    for(i = 0; i <= len1-1; i++)  // �ӵ�λ��ʼ������
    {
        pNum1[i] -= pNum2[i];         // ���
        if(pNum1[i] < 0)           // ���Ƿ���Ҫ��λ
        {   // ��λ
            pNum1[i] += 10;
            pNum1[i+1]--;
        }
    }
    for(i = len1-1; i >= 0; i--)  // ���ҽ�������λ
    {
        if( pNum1[i] )             //���λ��һ����Ϊ0
            return (i+1);       //�õ�λ��������
    }
    return 0;                   //������ȵ�ʱ�򷵻�0
}

/*
  ��������---���������С����
  num1 ������
  num2 ����
  sum  �̣���ż���Ľ��������num1/num2=sum
  ��������sum����Ч���ȣ����̵�λ��
*/
int Division(char str1[], char str2[], char sum[])
{
    int i, j;
    int len1, len2, len=0;     //����λ��
    int dValue;                //���������λ��
    int temp;                 //Subtract��������ֵ
    int num1[MAX] = {0};      //������
    int num2[MAX] = {0};      //����
    int result[MAX] = {0};      //��

    len1 = strlen(str1);       //��ô�����λ��
    len2 = strlen(str2);

    //�������ַ�ת�������������ҷ�ת����������������
    for( j = 0, i = len1-1; i >= 0; j++, i-- )
        num1[j] = str1[i] - '0';
    for( j = 0, i = len2-1; i >= 0; j++, i-- )
        num2[j] = str2[i] - '0';

    if( len1 < len2 )          //���������С�ڳ�����ֱ�ӷ���-1����ʾ���Ϊ0
        return -1;
    dValue = len1 - len2;      //���λ��
    for (i = len1-1; i >= 0; i--)    //����������ʹ�ó����ͱ�����λ�����
    {
        if (i >= dValue)
            num2[i] = num2[i-dValue];
        else                         //��λ��0
            num2[i] = 0;
    }
    len2 = len1;
    for(j = 0; j <= dValue; j++ )    //�ظ����ã�ͬʱ��¼���ɹ��Ĵ�������Ϊ��
    {
        while((temp = SubStract(num1, len1, num2+j, len2-j)) >= 0)
        {
            len1 = temp;            //�������
            result[dValue-j]++;       //ÿ�ɹ���һ�Σ����̵���Ӧλ��1
        }
    }
    // �����̵�λ���������̷���sum�ַ�������
    for(i = MAX-1; result[i] == 0 && i >= 0; i-- );  //������λ0����ȡ�̵�λ��
    if(i >= 0)
        len = i + 1; // ����λ��
    for(j = 0; i >= 0; i--, j++)     // ��������Ƶ�sum������
        sum[j] = result[i] + '0';
    sum[j] = '\0';   // sum�ַ������β��0
    return len;      // �����̵�λ��
}

int main()
{
    int i;
    int len;                // �̵�λ��
    char str1[MAX],str2[MAX];
    char sum[MAX] = {0};    // ������
    cout<<"��������������:";
    cin>>str1>>str2;         //���ַ�����ʽ�������
    cout<<"ԭ����Ϊ:"<<str1<<" "<<str2<<endl;
    len=Division(str1,str2,sum);              // �ڶ�������
    //������
    if(len>=0)
    {
        cout<<"����:";
        for(i=0;i<len;i++)
           cout<<sum[i];
        cout<<endl;
    }
    else
    {
        cout<<"����:0\n";
        cout<<"������:"<<str1;
    }
    return 0;
}

