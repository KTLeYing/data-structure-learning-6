#include<stdio.h>
#include<iostream>
#include<vector>    //ͷ�ļ�
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
    /*int a[6]={1,2,3,4,5,6};    //�����ʽ1
    vector<int> b(a,a+4);
    for(vector<int>::iterator it=b.begin();it!=b.end();it++)
    cout<<*it<<" ";*/

    /*int a[6]={1,2,3,4,5,6};    //�����ʽ2
    vector<int> b(a,a+4);
    for(int i=0;i<=b.size()-1;i++)
    cout<<b[i]<<" ";*/

    vector<int> a;
    int x,i;
    cout<<"������5����:";
    for(i=0;i<5;i++)
    {
        cin>>x;
        a.push_back(x);
    }
    for(int i=0;i<a.size();i++)  //ԭ�������ʽ1
        cout<<a[i]<<" ";
    cout<<endl;
    sort(a.begin(),a.end());      //����
    for(int i=0;i<a.size();i++)   //�����������ʽ1
       cout<<a[i]<<" ";
    cout<<endl;
    for(vector<int>::iterator i=a.begin();i!=a.end();i++) //�����������ʽ2
          cout<<*i<<" ";
    cout<<endl;
    /*for(auto i=a.cbegin;i!=a.cend;i++)   //����˳�����
        cout<<*i<<" ";
    cout<<endl;
    for(auto i=a.crbegin;i!=a.crend;i++)  //��ת���
        cout<<*i<<" ";
    */
    cout << a.front() << endl;  //���ص�һ��Ԫ��
    cout<<a.back()<<endl;    //�������һ��Ԫ��
    cout<<a.at(0)<<endl;    //����ָ��λ��Ԫ��
    cout<<a[0]<<endl;        //����ָ��λ��Ԫ��
    cout<<a.max_size()<<endl;    //��������ڴ��С
    cout<<a.empty()<<endl;      //�ж��Ƿ�Ϊ��
    a.push_back(99);
    for(vector<int>::iterator i=a.begin();i!=a.end();i++) //�����������ʽ2
          cout<<*i<<" ";
    cout<<endl;
    a.pop_back();
    for(vector<int>::iterator i=a.begin();i!=a.end();i++) //�����������ʽ2
          cout<<*i<<" ";
    cout<<endl;
    vector<int> a3;
    for(i=0;i<5;i++)
        a3.push_back(66);
    a.insert(a.begin()+1,a3.begin(),a3.end());
    for(vector<int>::iterator i=a.begin();i!=a.end();i++) //�����������ʽ2
          cout<<*i<<" ";
    cout<<endl;
    a.erase(a.begin()+1,a.end()-3);        //ɾ��ָ��λ�õ�Ԫ��
    for(vector<int>::iterator i=a.begin();i!=a.end();i++) //�����������ʽ2
          cout<<*i<<" ";
    cout<<endl;
    a.clear();    //���
    for(vector<int>::iterator i=a.begin();i!=a.end();i++) //�����������ʽ2
          cout<<*i<<" ";
    cout<<endl;
    a.insert(a.begin(),a3.begin(),a3.end());   //��a�Ŀ�ʼ��������
    for(vector<int>::iterator i=a.begin();i!=a.end();i++) //�����������ʽ2
          cout<<*i<<" ";
    cout<<endl;
    cout<<endl;





   //��ʼ����ֵ
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


   //����
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
   //ͨ��reserve����������ʽ��ָ��Ԥ���ռ�Ĵ�С��������vector�����Ľ����ڴ����·��䣬 �Ӷ����vector��ʹ��Ч�ʡ���reserve��
   //�ܼ�Сvector���������磬�Ѵ���vector.capacity = 100��ʹ��reserve(80)�������κ����á�
    cout<<endl;




    /*
    //����
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
    //vector�Ĺ��캯������������
    vector<int> c{ 1,2,3,4,5,6,7,8,9 };// initlist��ʼ��
	vector<int> c2(c.begin(), c.end());// ���ڵ������ĳ�ʼ��
	vector<int> c3 = move(c2); // Move���캯��
	for (const auto&elem : c3) // range-based forѭ��
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
    //���Ƶ��ʹ��vector�Ļ��������ڴ��˷ѻ��൱�ɹۡ�C++11�ṩ�����������Է��ϵ�ǰ����ĺ�����shrink_to_fit����
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
