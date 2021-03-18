/*题目:有多个测试样例，输入数据的第一行是  m  n  两个整数（3  <   m,  n  <   100），表示正方形格子的行数和列数。接下来是  m  行数据。
每行数据为  n  个被空格分开的数字。0  表示白格，1  表示黑格。接下来是一行数据：x  y  s  k,  其中x  y为整数，表示蚂蚁所在行号和列号（行
号从上到下增长，列号从左到右增长，都是从0开始编号）。s  是一个大写字母，表示蚂蚁头的朝向，我们约定：上下左右分别用：UDLR表示。k  表示蚂
蚁走的步数。最后输出数据为一个空格分开的整数  p  q,  分别表示蚂蚁在k步后，所处格子的行号和列号。

蚂蚁的移动规则十分简单：
若蚂蚁在黑格，右转90度，将该格改为白格，并向前移一格；
若蚂蚁在白格，左转90度，将该格改为黑格，并向前移一格。
规则虽然简单，蚂蚁的行为却十分复杂。刚刚开始时留下的路线都会有接近对称，像是会重复，但不论起始状态如何，蚂蚁经过漫长的混乱活动后，会
开辟出一条规则的“高速公路”。
*/

//法1:用循环数组取模求方向法
/*
#include<stdio.h>
#include<iostream>
#include<cstdlib>

using namespace std;

#define N 100

int main()
{
    int array[N][N];
    int i,j,m,n,p,q,x,y,k,pos;
    char ch[4]={'U','L','D','R'};  //初始化顺序为上、左、下、右；为一个圈，方便后面的取模求方向运算
    char s;
    while(cin>>m>>n)
    {
        for(i=0;i<m;i++)      //初始化表格
           for(j=0;j<n;j++)
              cin>>array[i][j];
        cin>>x>>y>>s>>k;
        for(i=0;i<k;i++)
        {
            if(array[x][y]==1)   //在黑格
            {
                 array[x][y]==0;
                 for(j=0;j<4;j++)
                    if(ch[j]==s)
                    {
                        pos=(j+3)%4; //蚂蚁在黑格，右转90度,例如开始在左,后来变成上,1->0,所以取模公式为(j+3)%4，也可(j-1)%4;
                        break;
                    }
             }
             else
                if(array[x][y]==0)    //在白格
                {
                    array[x][y]=1;
                    for(j=0;j<4;j++)
                      if(ch[j]==s)
                      {
                         pos=(j+1)%4;  ////蚂蚁在白格，左转90度,例如开始在左,后来变成下,1->2,所以取模公式为(j+1)%4，也可(j+5)%4;
                         break;
                      }
                }
            if(pos==0)    //利用方向，重新赋值蚂蚁每次移动后的位置
                x=x-1;
            else
               if(pos==1)
                  y=y-1;
               else
                  if(pos==2)
                     x=x+1;
                  else
                     if(pos==3)
                        y=y+1;
           s=ch[pos];    //重新赋值方向，再进行新一轮的移动
        }
        cout<<x<<" "<<y<<endl;
    }
    return 0;
}
*/

//法2:用switch-case循环结构直接判断方向并实现位置的改变(操作简单方便)

#include<stdio.h>
#include<iostream>
#include<cstdlib>

using namespace std;

#define N 100

int main()
{
    int m,n,i,j,x,y,k;
    int array[N][N];
    char s;
    while(cin>>m>>n)
    {
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
               cin>>array[i][j];
        cin>>x>>y>>s>>k;
        while(k)
        {
            if(array[x][y]==0)   //在白格
            {
                switch(s)
                {
                     case 'L':        //如果开始朝左
                        array[x][y]=1;   //白格变黑格
                        x=x+1;       //在白格，左转90度，即后来朝下，x轴+1,y轴不变
                        k--;       //步数-1（从总步数开始计算）
                        s='D';     //若蚂蚁在白格，左转90度，后来朝下，改变方向，重新进行下一轮的移动
                        break;
                     case 'D':         //如果开始朝下
                        array[x][y]=1;
                        y=y+1;           //在白格，左转90度，即后来朝右，y轴+1,x轴不变
                        k--;
                        s='R';
                        break;
                     case 'R':
                        array[x][y]=1;
                        x=x-1;
                        k--;
                        s='U';
                        break;
                     case 'U':
                        array[x][y]=1;
                        y=y-1;
                        k--;
                        s='L';
                        break;
                }
            }
            else
               if(array[x][y]==1)    //在黑格
               {
                   switch(s)
                   {
                       case 'L':          //如果开始朝左
                         array[x][y]=0;    //黑格变白格
                         x=x-1;          //在黑格，右转90度，即后来朝上，x轴-1,y轴不变
                         k--;            //步数-1（从总步数开始计算）
                         s='U';     //若蚂蚁在黑格，右转90度，后来朝上，改变方向，重新进行下一轮的移动
                         break;
                       case 'U':         //如果开始朝上
                         array[x][y]=0;
                         y=y+1;          //在黑格，右转90度，即后来朝右，y轴+1,x轴不变
                         k--;
                         s='R';
                         break;
                      case 'R':
                         array[x][y]=0;
                         x=x+1;
                         k--;
                         s='D';
                         break;
                      case 'D':
                         array[x][y]=1;
                         y=y-1;
                         k--;
                         s='L';
                         break;
                   }
               }
        }
        cout<<x<<" "<<y<<endl;
    }
}



