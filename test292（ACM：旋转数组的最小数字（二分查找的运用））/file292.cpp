/*题目：（原理:二分查找的运用）
旋转数组的最小数字
Description
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0，数组元素个数为10。
Input
输入多个测试案例，一行包含10个元素的数组。
Output
输出一个旋转数组的最小值
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
