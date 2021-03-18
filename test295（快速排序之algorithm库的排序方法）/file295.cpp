//法1：系统默认从小到大
/*
#include<iostream>
#include<algorithm>   //sort排序的头文件

using namespace std;

int main()
{
  int a[10]={9,6,3,8,5,2,7,4,1,0};
  for(int i=0;i<10;i++)
  cout<<a[i]<<" ";
  cout<<endl;
  sort(a,a+10); //可以看出，两个参数为均地址,a为起始，a+10为结束位置
  for(int i=0;i<10;i++)
  cout<<a[i]<<" ";
  return 0;

}
*/

//法2:自定义排序方法（从大到小）

#include<iostream>
#include<algorithm>    //sort排序的头文件

using namespace std;

int Compare1(int a,int b)
{
    return a>b;   //自定义从大到小排序
}

int main()
{
  int a[10]={9,6,3,8,5,2,7,4,1,0};
  for(int i=0;i<10;i++)
  cout<<a[i]<<" ";
  cout<<endl;
  sort(a,a+10,Compare1); //可以看出，两个参数为均地址,a为起始，a+10为结束位置，Compare1为排序方法
  for(int i=0;i<10;i++)
  cout<<a[i]<<" ";
  return 0;

}


//法3：用<vector>和<algorithm>容器结合实现
/*
#include<stdio.h>
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

int Less(int a,int b)     //从小到大排序
{
    return a<b;
}

/*
int Great(int a,int b)  //从大到小排序
{

    return a>b;
}
*/

/*
int main()
{
    int t,x;
    vector<int> a;
    cin>>t;
    while (t--)
    {
        int m;
        cin>>m;
        for (int i = 0;i < m;i++)
        {
            cin>>x;
            a.push_back(x);
        }
        sort(a.begin(),a.end(),Less);
        //sort(a.begin(),a.end(),Great);
        cout<<a[0];
        for (int i = 1;i <a.size();i++)
           cout<<" "<<a[i];
        cout<<endl;
        //a.clear();     //清空数组a的元素
        //或
        a.erase(a.begin(),a.end());
    }
}
*/


/*
//法4：（典型实例）
#include<stdio.h>
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int Less(int a,int b)     //从小到大排序
{
    return a<b;
}

int Great(int a,int b)  //从大到小排序
{

    return a>b;
}


int main()
{
    int t;
    int a[1000];
    cin>>t;
    while (t--)
    {
        int m;
        cin>>m;
        for (int i = 0;i < m;i++)
            cin>>a[i];
        //sort(a,a+m,Less);
        sort(a,a+m,Great);
        cout<<a[0];
        for (int i = 1;i < m;i++)
           cout<<" "<<a[i];
        cout<<endl;
    }
}
*/
