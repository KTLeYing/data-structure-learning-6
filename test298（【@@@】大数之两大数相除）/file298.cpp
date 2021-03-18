//法1:
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
    cout<<"请输入两个大数:";
    cin>>str1>>str2;
    cout<<"原大数为:"<<str1<<" "<<str2<<endl;
    len1=strlen(str1);
    len2=strlen(str2);
    for(i=len1-1,j=0;i>=0;j++,i--)
        num1[j]=str1[i]-'0';
    for(i=len2-1,j=0;i>=0;j++,i--)
        num2[j]=str2[i]-'0';
    k=len2;
    if(len1<len2)
    {
        cout<<"商是:0\n";
        cout<<"余数是:"<<str1;
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
        cout<<"商是:";
        for(i=len;i>0;i--)
            if(result[i])
                break;
        for(j=i;j>=0;j--)
           cout<<result[j];
        cout<<endl;
        cout<<"余数是:";
        for(i=len1;i>0;i--)
            if(num1[i])
               break;
        for(j=i;j>=0;j--)
            cout<<num1[j];
        cout<<endl;
    }
}
*/


//法2：（与法1原理一样，两种方法只是设计上有点差别）

#include<iostream>
#include<string.h>
#include<stdio.h>
#include<cstdlib>

using namespace std;

#define MAX 1000

/*
  函数SubStract功能：
  用长度为len1的大整数p1减去长度为len2的大整数p2
  结果存在p1中，返回值代表结果的长度
  不够减：返回-1 ， 正好够：返回0
*/
int SubStract(int *pNum1, int len1, int *pNum2, int len2)
{
    int i;
    if(len1 < len2)
        return -1;
    else
      if(len1 == len2 )
      {                        // 判断p1 > p2
          for(i = len1-1; i >= 0; i--)
          {
            if(pNum1[i] > pNum2[i])   // 若大，则满足条件，可做减法
                break;
            else
                if(pNum1[i] < pNum2[i]) // 否则返回-1
                   return -1;
         }
     }
    for(i = 0; i <= len1-1; i++)  // 从低位开始做减法
    {
        pNum1[i] -= pNum2[i];         // 相减
        if(pNum1[i] < 0)           // 若是否需要借位
        {   // 借位
            pNum1[i] += 10;
            pNum1[i+1]--;
        }
    }
    for(i = len1-1; i >= 0; i--)  // 查找结果的最高位
    {
        if( pNum1[i] )             //最高位第一个不为0
            return (i+1);       //得到位数并返回
    }
    return 0;                   //两数相等的时候返回0
}

/*
  大数除法---结果不包括小数点
  num1 被除数
  num2 除数
  sum  商，存放计算的结果，即：num1/num2=sum
  返回数组sum的有效长度，即商的位数
*/
int Division(char str1[], char str2[], char sum[])
{
    int i, j;
    int len1, len2, len=0;     //大数位数
    int dValue;                //两大数相差位数
    int temp;                 //Subtract函数返回值
    int num1[MAX] = {0};      //被除数
    int num2[MAX] = {0};      //除数
    int result[MAX] = {0};      //商

    len1 = strlen(str1);       //获得大数的位数
    len2 = strlen(str2);

    //将数字字符转换成整型数，且翻转保存在整型数组中
    for( j = 0, i = len1-1; i >= 0; j++, i-- )
        num1[j] = str1[i] - '0';
    for( j = 0, i = len2-1; i >= 0; j++, i-- )
        num2[j] = str2[i] - '0';

    if( len1 < len2 )          //如果被除数小于除数，直接返回-1，表示结果为0
        return -1;
    dValue = len1 - len2;      //相差位数
    for (i = len1-1; i >= 0; i--)    //将除数扩大，使得除数和被除数位数相等
    {
        if (i >= dValue)
            num2[i] = num2[i-dValue];
        else                         //低位置0
            num2[i] = 0;
    }
    len2 = len1;
    for(j = 0; j <= dValue; j++ )    //重复调用，同时记录减成功的次数，即为商
    {
        while((temp = SubStract(num1, len1, num2+j, len2-j)) >= 0)
        {
            len1 = temp;            //结果长度
            result[dValue-j]++;       //每成功减一次，将商的相应位加1
        }
    }
    // 计算商的位数，并将商放在sum字符数组中
    for(i = MAX-1; result[i] == 0 && i >= 0; i-- );  //跳过高位0，获取商的位数
    if(i >= 0)
        len = i + 1; // 保存位数
    for(j = 0; i >= 0; i--, j++)     // 将结果复制到sum数组中
        sum[j] = result[i] + '0';
    sum[j] = '\0';   // sum字符数组结尾置0
    return len;      // 返回商的位数
}

int main()
{
    int i;
    int len;                // 商的位数
    char str1[MAX],str2[MAX];
    char sum[MAX] = {0};    // 计算结果
    cout<<"请输入两个大数:";
    cin>>str1>>str2;         //以字符串形式读入大数
    cout<<"原大数为:"<<str1<<" "<<str2<<endl;
    len=Division(str1,str2,sum);              // 第二个大数
    //输出结果
    if(len>=0)
    {
        cout<<"商是:";
        for(i=0;i<len;i++)
           cout<<sum[i];
        cout<<endl;
    }
    else
    {
        cout<<"商是:0\n";
        cout<<"余数是:"<<str1;
    }
    return 0;
}

