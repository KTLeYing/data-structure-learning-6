//法1:用数组实现[数组的每个数据前移形式] 【公式:k=0时,k=(k+m)%n;k!=0时,k=(k+m-1)%n   其中k为开始报数的人,n为总人数,m为报到m的人出列】
/*ACM题目:n个人（0,1,2,3,4...n-1），围成一圈，从编号为k的人开始报数，报数报到m的人出队（报数是1,2,...m这样报的）
下次从出队的人之后开始重新报数，循环往复，当队伍中只剩最后一个人的时候，那个人就是大王。现在，给定n，k，m
*/
/*
#include<stdio.h>
#include<iostream>
#include<cstdlib>

using namespace std;

int func(int N,int k,int m)
{
		int *array=new int[N];            //创建N个人
		int n=N;						   //剩余人数
		for(int i=0;i<N;i++)
        {  //让每个人拿着最初编号
			array[i]=i+1;
		}
		for(int i=0;i<N-1;i++)
		{           //淘汰N-1个人
			if(k==0)
				k=(k+m)%n;       //k=0时,用之使k改变
			else
				k=(k+m-1)%n;     //k改变，实现删除报到为2的数据
			for(int j=k;k!=0 && j<n;j++)  //一个人被淘汰，后面的补上来;k>=1,因为j-1>=0;j是k的位置,即每一轮准备要输出的位置;j<n为
				array[j-1]=array[j];    //删除的元素之后的数据均前移一个位置                                每一轮将要前移的数量
			n--;        //一个人出去，人数n减
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

//法2:用数组和指针实现[数组的每个数据不前移形式] (从第一个人开始报,报到3的人退出,后面又重新从1开始报,输出只剩下最后一个人的编号)
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
     *(p+i)=i+1;  //为z个数编号
   x=0; //退出的人数
   y=0; //按123报数时的计数变量
   m=0; //每次循环计数一次
   while(x<z-1)
   {
       m=m%z;
      if(*(p+m)!=0) //用0作为辅助，标记
		  y++;    //计数报数为3的过程
      if(y==3)
	  {
	     *(p+m)=0;   //报数3的人置为0
		 y=0;        //1个人出列后,重新计数报数
		 x++;   //人数+1
	  }
	  m++;     //使下标+1,到时候去要去下一个位置的内容
	 //if(m==z)  //若m已达5，已超过数组的范围，重新回到数组的0位置，一个圆圈循环(76行和77行可用66行的 m=m%z直接代换)
	   // m=0;

   }
   while(*p==0)
	   p++;
   printf("the last one is NO.%d\n",*p);
   return 0;
}
*/

//法3:用双向链表实现 (从第一个人开始报,报到m的人退出,后面又重新从1开始报,直到全部人都出列,输出每次出队的人的编号)

#include<stdio.h>
#include<iostream>
#include<cstdlib>
#include<malloc.h>

using namespace std;

typedef struct LNODE{
    int ctr;
    struct LNODE *next,*perior;//用双向链表的原因在下面阐述
}LNODE;

int creat(LNODE *L,int n){
    LNODE *p=L,*pn;//头指针很重要
    int i;
    for(i=1;i<=n;i++){
        pn=(LNODE *)malloc(sizeof(LNODE));
        pn->ctr=i;
        pn->perior=p;
        p->next=pn;
        p=pn;
    }//构造过程见图
    p->next=L->next;    //最后一个节点指向第一个节点
    L->next->perior=p;  //P这个时候是最后一个节点，这是用第一个结点的前驱指向最后
}

int main()
{
    int m,n,i,j;
    LNODE *L=(LNODE *)malloc(sizeof(LNODE)),*p,*t;//L还是要给空间的，因为在构造时我们会用到它的NEXT
    while(cin>>n>>m)
    {
        L->next=L;
        creat(L,n);
        p=L->next;              //保护头节点
        for(i=0;i<n;i++)
        {
            for(j=0;j<m-1;j++)  //想一想M为什么要减一
                p=p->next;      //报数过程
                cout<<p->ctr;
            if(p->next!=p)      //判断是不是最后一个，还有一种判断是p->perior!=p;
                cout<<" ";      //因为要求是两个间有空格，所以最后一个不能有空格
            t=p;                //因为一会儿要删除p,但p一直是我们循环核心，所以找个替死鬼
            p=p->next;          //p指向下一个结点，也就是为什么m-1
            t->perior->next=t->next;    //这是用双向表的原因，单向表找前驱复杂度是O(n)
            t->next->perior=t->perior;  //交代后事ing
            delete(t);                  //GG
        }
        cout<<endl;             //多组测试，换行！
    }
}


/*
//法4:用循环链表实现（输出有点错误）  //(对任意n个人，密码为m，实现约瑟夫环问题。约瑟夫环是一个数学的应用问题：已知n个人（以编号1，2，3...n分别表示）围坐在一张圆
            //桌周围。从编号为1的人开始报数，数到m的那个人出列；他的下一个人又从1开始报数，数到m的那个人又出列；依此规律重复下去，直
            //到圆桌周围的人全部出列,并且输出每次出队的人的编号)
#include<stdio.h>
#include<iostream>
#include<cstdlib>

using namespace std;

typedef struct LNode
{
    int data;
    struct LNode *link;
}LNode, *LinkList;

void Josephus(int n, int k, int m) // n个人，从第k个人开始报数，m为出列者喊到的数
{
    LinkList p, r, cur; // p为当前结点，r为p的前驱
    p = new LNode;
    if(!p)
       cout << "The failure of memory allocated!" << endl;
    p->data = n;
    p->link = p; //循环链表
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
    //移动当前指针到k
    while(k--)
    {
        r = p;
        p = p->link;
    }
    //报数为m的人出列
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
//法5:用循环链表  (选择一个人作为起点，然后顺时针从1到k（k为起点人手中的密码值）数数。数到 k 的人退出圈子，然后从下一个人开始继续
    //从 1 到 j （j为刚退出圈子的人的密码）数数，数到 j 的人退出圈子。重复上面的过程，直到剩下最后一个人，每次输出出队人的编号)
#include<stdio.h>
#include<iostream>
#include<cstdlib>

using namespace std;

#define N 9  //环中人的个数
#define OVERFLOW 0

int KeyW[N]={4,7,5,9,3,2,6,1,8};  //每个人手中的密码

typedef struct LNode{  //定义循环链表
    int keyword;
    struct LNode * next;
}LNode,*LinkList;

int Joseph(LinkList p,int m,int x)
{  //x为总人数，m为删除的那个人手中的密码，起始的m为第一个人手中的密码
    LinkList q;
    int i;
    if(x==0)
      return 0;
    q=p;
    m%=x;
    if(m==0)
        m=x;
    for(i=1;i<=m;++i)
    {        //找到第m个人  p指向要删除的人的前一人 q指向要删除的人
        p=q;
        q=p->next;
    }
    p->next=q->next;  //删除q
    i=q->keyword;  //得到下一个要删除的人的位置
    printf("%d",q->keyword);
    free(q);
    Joseph(p,i,x-1);  //递归调用 总人数减1，输入新的密码
}

int main()
{
    int i,m;
    LinkList Lhead,p,q;  //Lhead指向头，p指向尾指针，q指向新建指针
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
        q->keyword=KeyW[i];  //对q的keyword进行赋值
        p->next=q;  //将q赋给p的next
        p=q;  //p要指向尾部，将q赋给p
    }
    p->next=Lhead;  //构造循环链表
    printf("请输入第一次计数值m :\n");
    scanf("%d",&m);
    printf("输出的队列是：\n");
    Joseph(p,m,N);
    return 0;
}
*/

//法6:用java实现【循环链表】(设有n个人（以编号为1,2,3…….n分别表示）围坐在圆桌周围，从编号为k的人开始报数，数到m的人就站出来，他
            //的下一个人又从1开始报数，数到m的人就站出来，依此规律重复下去，知道全部的人都站出来为止，并且输出每次出队的人的编号)
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
     linklist() //利用构造函数对循环链表进行初始化
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
  for(int i=2;i<=n;i++)    //建立循环链表(编号为1，2，3..........N)
  {
    node *p=new node();
    p->data=i;
    p->next=q->next;
    q->next=p;
    q=p;
  }
   //---------找到第一个报数的人,p记录当前报数的位置，r为报数的前一个位置----------
  node *p=first;
  node *r;
  while(--k)
  {
    r=p;;
    p=p->next;
  }

  //----------把这n个元素依次出列--------
  cout<<"n个元素依次出列：";
  while(n--)
  {
    for(int s=1;s<m;s++)  //从当前元素开始报数，报数为m的元素出列，p指向出列元素
    {
        r=p;
        p=p->next;
    }
      r->next=p->next;
      cout<<p->data<<" ";
      p=r->next;          //此时p指向被删元素的下一个元素
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

//法7://出圈的方法,围一圈人n个，每隔k个椅子出去一个,输出最后一个剩余的人
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
    int *a=new int[n];  //定义一个未知长度的数组
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
          m++;//使得置0的数是n-1个
          cout<<m<<endl;
          if(m==n-1)
             break;
       }
       if(i==n-1)//前几次循环没有使得剩余一个
         i=-1;
    }
    for(int j=0;j<n;j++)//输出最后一个留在座位上的人
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


//法8:循环链表实现   (//循环链表报数问题,n个人编号分别为1,2,3,……n，从第k个编号开始数1,2到m个然后删除第m个人，然后下
                  //一个人再从1开始数数到第m个，然后再删除m人)
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
//n为总人数，k为第一个开始报数的人，m为出列者喊道的数
//p为当前节点，r为辅助节点，指向p的的前驱节点，list为头节点
//建立循环链表
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
//把当前指针移动到第一个报数的人
  r=curr;
  while(r->data!=k)r=r->link;
  while(n--)
  {
    for(int i=1;i<m-1;i++)
    r=r->link;//当数到m-1的时候
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
