#include<stdio.h>
#include<math.h>
#include<iostream>

using namespace std;

/**法1:使用字符串数组（string str[N]），每个下标存储一个字符串
* eg:
Input:
4
sjd jsdhgh jsj jshdj
Output:
sjd jsdhgh jsj jshdj
*/
#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    string f[100];   //定义一个字符串数组
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>f[i];
    for(int i=0;i<n;i++)
        cout<<f[i]<<" ";
}



/**法2：用二维数组实现一个数组下标来存储多个连续的字母（一个字符串），以空格分开，表示一个字符串一次输入结束
Input:
3 2 1
Zhao Qian Sun
Li Zhou
Wan

Output:
Zhao Qian Sun
Li Zhou
Wan
**/
int main()
{
    char sa[1005][100],sb[1005][100],sc[1005][100];  //开一个二维数组来实现一个数组下标来存储多个连续的字母（一个字符串）
    int a,b,c;
    cin>>a>>b>>c;
    for(int i=0;i<a;i++)
    {
        cin>>sa[i];
    }
    for(int i=0;i<b;i++)
        cin>>sb[i];
    for(int i=0;i<c;i++)
        cin>>sc[i];

    for(int i=0;i<a;i++)
    {
        cout<<sa[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<b;i++)
        cout<<sb[i]<<" ";
    cout<<endl;
    for(int i=0;i<c;i++)
        cout<<sc[i]<<" ";
    cout<<endl;
}



/**区别:[平时的一维数组只能实现一个数组下标的存储一个字符，不是多个字符（字符串）]
Input1:
3 2 1
Zhao Qian Sun
Z h a
o Q
i

Output1:
Z h a
o Q
i

Input2:
A B C
d E
f

Output2:
A B C
d E
f
**/
int main()
{
    char sa[1005],sb[1005],sc[1005];  //开一个一维数组来实现平时的一个数组下标的位置只存储一个字符（平时用的）
    int a,b,c;
    cin>>a>>b>>c;
    for(int i=0;i<a;i++)
    {
        cin>>sa[i];
    }
    for(int i=0;i<b;i++)
        cin>>sb[i];
    for(int i=0;i<c;i++)
        cin>>sc[i];

    for(int i=0;i<a;i++)
    {
        cout<<sa[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<b;i++)
        cout<<sb[i]<<" ";
    cout<<endl;
    for(int i=0;i<c;i++)
        cout<<sc[i]<<" ";
    cout<<endl;
}
