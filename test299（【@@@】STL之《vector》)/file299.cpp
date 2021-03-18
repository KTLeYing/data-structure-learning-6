#include<stdio.h>
#include<iostream>
#include<vector>    //头文件
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
    /*int a[6]={1,2,3,4,5,6};    //输出方式1
    vector<int> b(a,a+4);
    for(vector<int>::iterator it=b.begin();it!=b.end();it++)
    cout<<*it<<" ";*/

    /*int a[6]={1,2,3,4,5,6};    //输出方式2
    vector<int> b(a,a+4);
    for(int i=0;i<=b.size()-1;i++)
    cout<<b[i]<<" ";*/

    vector<int> a;
    int x,i;
    cout<<"请输入5个数:";
    for(i=0;i<5;i++)
    {
        cin>>x;
        a.push_back(x);
    }
    for(int i=0;i<a.size();i++)  //原来输出方式1
        cout<<a[i]<<" ";
    cout<<endl;
    sort(a.begin(),a.end());      //排序
    for(int i=0;i<a.size();i++)   //排序后的输出方式1
       cout<<a[i]<<" ";
    cout<<endl;
    for(vector<int>::iterator i=a.begin();i!=a.end();i++) //排序后的输出方式2
          cout<<*i<<" ";
    cout<<endl;
    /*for(auto i=a.cbegin;i!=a.cend;i++)   //正常顺序输出
        cout<<*i<<" ";
    cout<<endl;
    for(auto i=a.crbegin;i!=a.crend;i++)  //反转输出
        cout<<*i<<" ";
    */
    cout << a.front() << endl;  //返回第一个元素
    cout<<a.back()<<endl;    //返回最后一个元素
    cout<<a.at(0)<<endl;    //返回指定位置元素
    cout<<a[0]<<endl;        //返回指定位置元素
    cout<<a.max_size()<<endl;    //返回最大内存大小
    cout<<a.empty()<<endl;      //判断是否为空
    a.push_back(99);
    for(vector<int>::iterator i=a.begin();i!=a.end();i++) //排序后的输出方式2
          cout<<*i<<" ";
    cout<<endl;
    a.pop_back();
    for(vector<int>::iterator i=a.begin();i!=a.end();i++) //排序后的输出方式2
          cout<<*i<<" ";
    cout<<endl;
    vector<int> a3;
    for(i=0;i<5;i++)
        a3.push_back(66);
    a.insert(a.begin()+1,a3.begin(),a3.end());
    for(vector<int>::iterator i=a.begin();i!=a.end();i++) //排序后的输出方式2
          cout<<*i<<" ";
    cout<<endl;
    a.erase(a.begin()+1,a.end()-3);        //删除指定位置的元素
    for(vector<int>::iterator i=a.begin();i!=a.end();i++) //排序后的输出方式2
          cout<<*i<<" ";
    cout<<endl;
    a.clear();    //清空
    for(vector<int>::iterator i=a.begin();i!=a.end();i++) //排序后的输出方式2
          cout<<*i<<" ";
    cout<<endl;
    a.insert(a.begin(),a3.begin(),a3.end());   //在a的开始插入数据
    for(vector<int>::iterator i=a.begin();i!=a.end();i++) //排序后的输出方式2
          cout<<*i<<" ";
    cout<<endl;
    cout<<endl;





   //初始化赋值
    vector<int> a1=a;
    for(vector<int>::iterator i=a1.begin();i!=a1.end();i++)
        cout<<*i<<" ";
    cout<<endl;

    vector<int> a2;
    a2.assign(a.begin(),a.end());
    for(vector<int>::iterator i=a2.begin();i!=a2.end();i++)
        cout<<*i<<" ";
    cout<<endl;

    int a5[6]={1,2,3,4,5,6};
    vector<int> b;
    vector<int> c(a5,a5+4);
    for(vector<int>::iterator it=c.begin();it<c.end();it++)
       b.push_back(*it);
    for(vector<int>::iterator i=b.begin();i!=b.end();i++)
        cout<<*i<<" ";
    cout<<endl;
    cout<<endl;


   //容量
   vector<int> v;
   for (int i=0; i < 20; i++)
   {
       v.push_back(i);
       cout<<"i = "<<i<< " size = " << v.size()<< " capacity = " << v.capacity() << endl;
   }
   cout<<endl;


   vector<int> v1(100);
	cout<<v1.size()<<" "<<v1.capacity()<<endl;
	v1.reserve(80);
	cout<<v1.size()<<" "<<v1.capacity()<<endl;
   //通过reserve函数可以显式的指定预留空间的大小，而避免vector反复的进行内存重新分配， 从而提高vector的使用效率。但reserve不
   //能减小vector容量，比如，已存在vector.capacity = 100，使用reserve(80)不会有任何作用。
    cout<<endl;




    /*
    //交换
    vector<int> a3;
    for(i=0;i<5;i++)
        a3.push_back(66);
    for(vector<int>::iterator i=a3.begin();i!=a3.end();i++)
        cout<<*i<<" ";
    cout<<endl<<endl;
    a2.swap(a3);
    //swap(a2,a3);
    for(vector<int>::iterator i=a2.begin();i!=a2.end();i++)
        cout<<*i<<" ";
    cout<<endl;
    for(vector<int>::iterator i=a3.begin();i!=a3.end();i++)
        cout<<*i<<" ";
    cout<<endl<<endl;
    */


    /*
    //vector的构造函数和析构函数
    vector<int> c{ 1,2,3,4,5,6,7,8,9 };// initlist初始化
	vector<int> c2(c.begin(), c.end());// 基于迭代器的初始化
	vector<int> c3 = move(c2); // Move构造函数
	for (const auto&elem : c3) // range-based for循环
	{
		cout << elem << " ";
	}
     */

   /*
    vector<int> v2;
	cout<<"capacity = "<<v2.capacity()<<endl;
	v2.reserve(10);
	cout<<"capacity = "<<v2.capacity()<<endl;
	v2.shrink_to_fit();
	cout<<"capacity = "<<v2.capacity()<<endl;
    //如果频繁使用vector的话，这种内存浪费会相当可观。C++11提供了缩减容量以符合当前需求的函数，shrink_to_fit函数
     */


     /*
    vector<int> v1;
    v1.push_back(4);
    v1.push_back(6);
    v1.push_back(2);
    vector<int> v2;
    v2.push_back(3);
    v2.push_back(1);
    v2.push_back(5);
    vector<int> v3=merge(v1,v2);
    sort(v3.begin(),v3.end());
    for(vector<int>::iterator it=v3.begin();it!=v3.end();++it)
        cout<<*it<<endl;
    vector<int> merge(vector<int> v1,vector<int> v2)
   {
      v1.insert(v1.end(),v2.begin(),v2.end());
      return v1;
   }
   */




}
