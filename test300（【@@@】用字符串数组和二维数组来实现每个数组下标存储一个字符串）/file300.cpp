#include<stdio.h>
#include<math.h>
#include<iostream>

using namespace std;

/**��1:ʹ���ַ������飨string str[N]����ÿ���±�洢һ���ַ���
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
    string f[100];   //����һ���ַ�������
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>f[i];
    for(int i=0;i<n;i++)
        cout<<f[i]<<" ";
}



/**��2���ö�ά����ʵ��һ�������±����洢�����������ĸ��һ���ַ��������Կո�ֿ�����ʾһ���ַ���һ���������
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
    char sa[1005][100],sb[1005][100],sc[1005][100];  //��һ����ά������ʵ��һ�������±����洢�����������ĸ��һ���ַ�����
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



/**����:[ƽʱ��һά����ֻ��ʵ��һ�������±�Ĵ洢һ���ַ������Ƕ���ַ����ַ�����]
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
    char sa[1005],sb[1005],sc[1005];  //��һ��һά������ʵ��ƽʱ��һ�������±��λ��ֻ�洢һ���ַ���ƽʱ�õģ�
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
