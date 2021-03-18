/*��Ŀ����ԭ��:���ֲ��ҵ����ã�
��ת�������С����
Description
��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
����һ���ǵݼ�����������һ����ת�������ת�������СԪ�ء�
��������{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1��
NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0������Ԫ�ظ���Ϊ10��
Input
���������԰�����һ�а���10��Ԫ�ص����顣
Output
���һ����ת�������Сֵ
*/

#include<stdio.h>
#include<iostream>
#include<cstdlib>

using namespace std;

int MinNum(int array[])
{
    int low,high,mid,i,j;
    low=0;
    high=9;
    while(low<high)
    {
        mid=(low+high)/2;
        if(array[mid]==array[high])
            high=high-1;
        else
           if(array[mid]>array[high])
               low=mid+1;
           else
               high=mid;
    }
    return array[high];
}

int main()
{
    int array[10],i,z;
    while(cin>>array[0])
    {
        for(i=1;i<10;i++)
        cin>>array[i];
        z=MinNum(array);
        cout<<z<<endl;
    }
}
