//��1:������ʵ��[�����ÿ������ǰ����ʽ] ����ʽ:k=0ʱ,k=(k+m)%n;k!=0ʱ,k=(k+m-1)%n   ����kΪ��ʼ��������,nΪ������,mΪ����m���˳��С�
/*ACM��Ŀ:n���ˣ�0,1,2,3,4...n-1����Χ��һȦ���ӱ��Ϊk���˿�ʼ��������������m���˳��ӣ�������1,2,...m�������ģ�
�´δӳ��ӵ���֮��ʼ���±�����ѭ����������������ֻʣ���һ���˵�ʱ���Ǹ��˾��Ǵ��������ڣ�����n��k��m
*/
/*
#include<stdio.h>
#include<iostream>
#include<cstdlib>

using namespace std;

int func(int N,int k,int m)
{
		int *array=new int[N];            //����N����
		int n=N;						   //ʣ������
		for(int i=0;i<N;i++)
        {  //��ÿ��������������
			array[i]=i+1;
		}
		for(int i=0;i<N-1;i++)
		{           //��̭N-1����
			if(k==0)
				k=(k+m)%n;       //k=0ʱ,��֮ʹk�ı�
			else
				k=(k+m-1)%n;     //k�ı䣬ʵ��ɾ������Ϊ2������
			for(int j=k;k!=0 && j<n;j++)  //һ���˱���̭������Ĳ�����;k>=1,��Ϊj-1>=0;j��k��λ��,��ÿһ��׼��Ҫ�����λ��;j<nΪ
				array[j-1]=array[j];    //ɾ����Ԫ��֮������ݾ�ǰ��һ��λ��                                ÿһ�ֽ�Ҫǰ�Ƶ�����
			n--;        //һ���˳�ȥ������n��
		}
		return array[0];
}

int main()
{
    int n,k,m,result;
    while(cin>>n>>k>>m)
       if(n>=1 && n<=100 && k>=1 && k<=n-1 && m>=1 &&m<=100)
       {
           result=func(n,k,m);
           cout<<result<<endl;
       }
}
*/

//��2:�������ָ��ʵ��[�����ÿ�����ݲ�ǰ����ʽ] (�ӵ�һ���˿�ʼ��,����3�����˳�,���������´�1��ʼ��,���ֻʣ�����һ���˵ı��)
/*
#include<stdio.h>
#include<iostream>
#include<cstdlib>

using namespace std;

int main()
{
   int z,x,y,m,*p,num[50],i;
   printf("please intput the number of people:");
   scanf("%d",&z);
   p=num;
   for(i=0;i<z;i++)
     *(p+i)=i+1;  //Ϊz�������
   x=0; //�˳�������
   y=0; //��123����ʱ�ļ�������
   m=0; //ÿ��ѭ������һ��
   while(x<z-1)
   {
       m=m%z;
      if(*(p+m)!=0) //��0��Ϊ���������
		  y++;    //��������Ϊ3�Ĺ���
      if(y==3)
	  {
	     *(p+m)=0;   //����3������Ϊ0
		 y=0;        //1���˳��к�,���¼�������
		 x++;   //����+1
	  }
	  m++;     //ʹ�±�+1,��ʱ��ȥҪȥ��һ��λ�õ�����
	 //if(m==z)  //��m�Ѵ�5���ѳ�������ķ�Χ�����»ص������0λ�ã�һ��ԲȦѭ��(76�к�77�п���66�е� m=m%zֱ�Ӵ���)
	   // m=0;

   }
   while(*p==0)
	   p++;
   printf("the last one is NO.%d\n",*p);
   return 0;
}
*/

//��3:��˫������ʵ�� (�ӵ�һ���˿�ʼ��,����m�����˳�,���������´�1��ʼ��,ֱ��ȫ���˶�����,���ÿ�γ��ӵ��˵ı��)

#include<stdio.h>
#include<iostream>
#include<cstdlib>
#include<malloc.h>

using namespace std;

typedef struct LNODE{
    int ctr;
    struct LNODE *next,*perior;//��˫�������ԭ�����������
}LNODE;

int creat(LNODE *L,int n){
    LNODE *p=L,*pn;//ͷָ�����Ҫ
    int i;
    for(i=1;i<=n;i++){
        pn=(LNODE *)malloc(sizeof(LNODE));
        pn->ctr=i;
        pn->perior=p;
        p->next=pn;
        p=pn;
    }//������̼�ͼ
    p->next=L->next;    //���һ���ڵ�ָ���һ���ڵ�
    L->next->perior=p;  //P���ʱ�������һ���ڵ㣬�����õ�һ������ǰ��ָ�����
}

int main()
{
    int m,n,i,j;
    LNODE *L=(LNODE *)malloc(sizeof(LNODE)),*p,*t;//L����Ҫ���ռ�ģ���Ϊ�ڹ���ʱ���ǻ��õ�����NEXT
    while(cin>>n>>m)
    {
        L->next=L;
        creat(L,n);
        p=L->next;              //����ͷ�ڵ�
        for(i=0;i<n;i++)
        {
            for(j=0;j<m-1;j++)  //��һ��MΪʲôҪ��һ
                p=p->next;      //��������
                cout<<p->ctr;
            if(p->next!=p)      //�ж��ǲ������һ��������һ���ж���p->perior!=p;
                cout<<" ";      //��ΪҪ�����������пո��������һ�������пո�
            t=p;                //��Ϊһ���Ҫɾ��p,��pһֱ������ѭ�����ģ������Ҹ�������
            p=p->next;          //pָ����һ����㣬Ҳ����Ϊʲôm-1
            t->perior->next=t->next;    //������˫����ԭ�򣬵������ǰ�����Ӷ���O(n)
            t->next->perior=t->perior;  //��������ing
            delete(t);                  //GG
        }
        cout<<endl;             //������ԣ����У�
    }
}


/*
//��4:��ѭ������ʵ�֣�����е����  //(������n���ˣ�����Ϊm��ʵ��Լɪ�����⡣Լɪ����һ����ѧ��Ӧ�����⣺��֪n���ˣ��Ա��1��2��3...n�ֱ��ʾ��Χ����һ��Բ
            //����Χ���ӱ��Ϊ1���˿�ʼ����������m���Ǹ��˳��У�������һ�����ִ�1��ʼ����������m���Ǹ����ֳ��У����˹����ظ���ȥ��ֱ
            //��Բ����Χ����ȫ������,�������ÿ�γ��ӵ��˵ı��)
#include<stdio.h>
#include<iostream>
#include<cstdlib>

using namespace std;

typedef struct LNode
{
    int data;
    struct LNode *link;
}LNode, *LinkList;

void Josephus(int n, int k, int m) // n���ˣ��ӵ�k���˿�ʼ������mΪ�����ߺ�������
{
    LinkList p, r, cur; // pΪ��ǰ��㣬rΪp��ǰ��
    p = new LNode;
    if(!p)
       cout << "The failure of memory allocated!" << endl;
    p->data = n;
    p->link = p; //ѭ������
    cur = p;
    for(int i=1; i<n; i++)
    {
        LinkList t = new LNode;
        if(!t)
           cout << "The failure of memory allocated!" << endl;
        t->data = i;
        cur->link = t;
        cur = t;
    }
    //�ƶ���ǰָ�뵽k
    while(k--)
    {
        r = p;
        p = p->link;
    }
    //����Ϊm���˳���
    while(n--)
    {
        for(int s=m-1; s--; r=p, p = p->link);
        if(n==0)
        {
            cout<<p->data<<endl;
        }
        else
        {
           cout << p->data <<" ";
           r->link = p->link;
           LinkList d = new LNode;
           d = p;
           p = r->link;
           delete d;
        }
   }
}

int main()
{
   int a,b;
   while(cin>>a)
   {
      cin>>b;
      Josephus(a,1,b);
   }
  return 0;
}
*/

/*
//��5:��ѭ������  (ѡ��һ������Ϊ��㣬Ȼ��˳ʱ���1��k��kΪ��������е�����ֵ������������ k �����˳�Ȧ�ӣ�Ȼ�����һ���˿�ʼ����
    //�� 1 �� j ��jΪ���˳�Ȧ�ӵ��˵����룩���������� j �����˳�Ȧ�ӡ��ظ�����Ĺ��̣�ֱ��ʣ�����һ���ˣ�ÿ����������˵ı��)
#include<stdio.h>
#include<iostream>
#include<cstdlib>

using namespace std;

#define N 9  //�����˵ĸ���
#define OVERFLOW 0

int KeyW[N]={4,7,5,9,3,2,6,1,8};  //ÿ�������е�����

typedef struct LNode{  //����ѭ������
    int keyword;
    struct LNode * next;
}LNode,*LinkList;

int Joseph(LinkList p,int m,int x)
{  //xΪ��������mΪɾ�����Ǹ������е����룬��ʼ��mΪ��һ�������е�����
    LinkList q;
    int i;
    if(x==0)
      return 0;
    q=p;
    m%=x;
    if(m==0)
        m=x;
    for(i=1;i<=m;++i)
    {        //�ҵ���m����  pָ��Ҫɾ�����˵�ǰһ�� qָ��Ҫɾ������
        p=q;
        q=p->next;
    }
    p->next=q->next;  //ɾ��q
    i=q->keyword;  //�õ���һ��Ҫɾ�����˵�λ��
    printf("%d",q->keyword);
    free(q);
    Joseph(p,i,x-1);  //�ݹ���� ��������1�������µ�����
}

int main()
{
    int i,m;
    LinkList Lhead,p,q;  //Lheadָ��ͷ��pָ��βָ�룬qָ���½�ָ��
    Lhead=(LinkList)malloc(sizeof(LNode));
    if(!Lhead)
        return OVERFLOW;
    Lhead->keyword=KeyW[0];
    Lhead->next=NULL;
    p=Lhead;
    for(i=1;i<9;++i)
    {
        if(!(q=(LinkList)malloc(sizeof(LNode))))
            return OVERFLOW;
        q->keyword=KeyW[i];  //��q��keyword���и�ֵ
        p->next=q;  //��q����p��next
        p=q;  //pҪָ��β������q����p
    }
    p->next=Lhead;  //����ѭ������
    printf("�������һ�μ���ֵm :\n");
    scanf("%d",&m);
    printf("����Ķ����ǣ�\n");
    Joseph(p,m,N);
    return 0;
}
*/

//��6:��javaʵ�֡�ѭ������(����n���ˣ��Ա��Ϊ1,2,3����.n�ֱ��ʾ��Χ����Բ����Χ���ӱ��Ϊk���˿�ʼ����������m���˾�վ��������
            //����һ�����ִ�1��ʼ����������m���˾�վ���������˹����ظ���ȥ��֪��ȫ�����˶�վ����Ϊֹ���������ÿ�γ��ӵ��˵ı��)
/*
#include<stdio.h>
#include<iostream>
#include<cstdlib>

using namespace std;

struct node
{
  int data;
  node *next;
};
class linklist
{
public:
     linklist() //���ù��캯����ѭ��������г�ʼ��
     {
       node *p=new node();
       p->data=1;
       p->next=p;
       first=p;
     };
    void josephus(int n,int k,int m);
private:
    node *first;
};

void linklist::josephus(int n,int k,int m)
{
  node *q=first;
  for(int i=2;i<=n;i++)    //����ѭ������(���Ϊ1��2��3..........N)
  {
    node *p=new node();
    p->data=i;
    p->next=q->next;
    q->next=p;
    q=p;
  }
   //---------�ҵ���һ����������,p��¼��ǰ������λ�ã�rΪ������ǰһ��λ��----------
  node *p=first;
  node *r;
  while(--k)
  {
    r=p;;
    p=p->next;
  }

  //----------����n��Ԫ�����γ���--------
  cout<<"n��Ԫ�����γ��У�";
  while(n--)
  {
    for(int s=1;s<m;s++)  //�ӵ�ǰԪ�ؿ�ʼ����������Ϊm��Ԫ�س��У�pָ�����Ԫ��
    {
        r=p;
        p=p->next;
    }
      r->next=p->next;
      cout<<p->data<<" ";
      p=r->next;          //��ʱpָ��ɾԪ�ص���һ��Ԫ��
  }
  cout<<endl;

}
int main()
{
  linklist L;
  L.josephus(9,1,5);
  system("pause");
  return 0;
}
*/

//��7://��Ȧ�ķ���,ΧһȦ��n����ÿ��k�����ӳ�ȥһ��,������һ��ʣ�����
/*
#include<stdio.h>
#include<iostream>
#include<cstdlib>

using namespace std;

int main()
{
    int n=0;
    int k;
    cout<<"Please input the all number:"<<endl;
    cin>>n;
    cout<<"Please input the number:out"<<endl;
    cin>>k;
  //int a[n];
    int *a=new int[n];  //����һ��δ֪���ȵ�����
  //int a[n]=*pointer;
    for(int i=0;i<n;i++)
      a[i]=1;
    int sum = 0;
    int m = 0;
    for(int i = 0;i<n;i++)
    {
       sum+=a[i];
       if(sum==k)
       {
          sum = 0;
          a[i]=0;
          m++;//ʹ����0������n-1��
          cout<<m<<endl;
          if(m==n-1)
             break;
       }
       if(i==n-1)//ǰ����ѭ��û��ʹ��ʣ��һ��
         i=-1;
    }
    for(int j=0;j<n;j++)//������һ��������λ�ϵ���
    {
       if(1==a[j])
       {
           cout<<"The last one is :"<<j+1<<"st"<<endl;
              break;
       }
   }
   return 0;
}
*/


//��8:ѭ������ʵ��   (//ѭ������������,n���˱�ŷֱ�Ϊ1,2,3,����n���ӵ�k����ſ�ʼ��1,2��m��Ȼ��ɾ����m���ˣ�Ȼ����
                  //һ�����ٴ�1��ʼ��������m����Ȼ����ɾ��m��)
/*
#include<stdio.h>
#include<iostream>
#include<cstdlib>

using namespace std;

struct Lnode
{
  int data;
  Lnode *link;
};

void josephus(int n,int k,int m)
{
//nΪ��������kΪ��һ����ʼ�������ˣ�mΪ�����ߺ�������
//pΪ��ǰ�ڵ㣬rΪ�����ڵ㣬ָ��p�ĵ�ǰ���ڵ㣬listΪͷ�ڵ�
//����ѭ������
   Lnode *p,*r,*curr,*list;
   p=(Lnode*)malloc(sizeof(Lnode));
   p->data=1;
   p->link=p;
   curr=p;
   for(int i=2;i<=n;i++)
   {
      Lnode *ln=(Lnode*)malloc(sizeof(Lnode));
      ln->data=i;
      ln->link=curr->link;
      curr->link=ln;
      curr=curr->link;
  }
//�ѵ�ǰָ���ƶ�����һ����������
  r=curr;
  while(r->data!=k)r=r->link;
  while(n--)
  {
    for(int i=1;i<m-1;i++)
    r=r->link;//������m-1��ʱ��
    cout<<r->link->data<<"  ";
    p=r->link;
    r->link=r->link->link;
    free(p);
    p=r=r->link;
  }
}

int main()
{
    josephus(9,1,3);
    cout<<endl;
    system("pause");
}
*/
