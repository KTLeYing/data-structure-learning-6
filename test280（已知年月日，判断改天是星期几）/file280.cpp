
//计算某个日期是星期几,判断某年某月一号是星期几

//常用方法:
/*一：常用公式
W = [Y-1] + [(Y-1)/4] - [(Y-1)/100] + [(Y-1)/400] + D
Y是年份数，D是这一天在这一年中的累积天数，也就是这一天在这一年中是第几天。

二：蔡勒（Zeller）公式
w=y+[y/4]+[c/4]-2c+[26(m+1)/10]+d-1
公式中的符号含义如下，w：星期；c：世纪；y：年（两位数）； m：月（m大于等于3，小于等于14，即在蔡勒公式中，某年的1、2月要看作上一年
的13、14月来计算，比如2003年1月1日要看作2002年的13月1日来计算）；d：日；[ ]代表取整，即只要整数部分。
相比于通用通用计算公式而言，蔡勒（Zeller）公式大大降低了计算的复杂度。

三：对蔡勒（Zeller）公式的改进
相比于另外一个通用通用计算公式而言，蔡勒（Zeller）公式大大降低了计算的复杂度。不过，笔者给出的通用计算公式似乎更加简洁（包括运算过程）。现将公式列于其下：
W=[y/4]+r (y/7)-2r(c/4)+m’+d
公式中的符号含义如下，r ( )代表取余，即只要余数部分；m’是m的修正数，现给出1至12月的修正数1’至12’如下：（1’，10’）=6；（2’，3’，11’）
=2；（4’，7’）=5；5’=0；6’=3；8’=1；（9’，12’）=4（注意：在笔者给出的公式中，y为润年时1’=5；2’=1）。其他符号与蔡勒（Zeller）公式中的含义相同。

四：基姆拉尔森计算公式
这个公式名称是我给命名的，哈哈希望大家不要见怪。
W= (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400) mod 7
在公式中d表示日期中的日数，m表示月份数，y表示年数。
*/


//法1:基姆拉尔森计算公式:W= (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400) mod 7(在公式中d表示日期中的日数，m表示月份数，y表示年数)
//注意：在公式中有个与其他公式不同的地方注意：在公式中有个与其他公式不同的地方：
//把一月和二月看成是上一年的十三月和十四月，例：如果是2004-1-10则换算成：2003-13-10来代入公式计算。
//以公元元年为参考，公元元年1月1日为星期一

//eg1:

#include<stdio.h>
#include<iostream>
#include<cstdlib>

using namespace std;

const char * getWeekdayByYearday(int iY, int iM, int iD)
{
    int iWeekDay = -1;
    if (1 == iM || 2 == iM)
    {
        iM += 12;
        iY--;
    }
    iWeekDay = (iD + 1 + 2 * iM + 3 * (iM + 1) / 5 + iY + iY / 4 - iY / 100 + iY / 400) % 7;
    switch(iWeekDay)
    {
        case 0 : return "Sunday"; break;
        case 1 : return "Monday"; break;
        case 2 : return "Tuesday"; break;
        case 3 : return "Wednesday"; break;
        case 4 : return "Thursday"; break;
        case 5 : return "Friday"; break;
        case 6 : return "Saturday"; break;
        default : return NULL; break;
    }

    return NULL;
}

int main()
{
    int year,month,day;
    char ch='1';
    while(ch != '\033')
    {
        printf("\n请输入日期：\n格式为：1900 1 1\n");
        scanf("%d %d %d",&year,&month,&day);
        const char * p = getWeekdayByYearday(year, month, day);
        printf("WeekDay : %s\n", p);
        ch = getchar();
        printf("\n");
    }
}



//eg2:
/*
#include<stdio.h>
#include<iostream>
#include<cstdlib>

using namespace std;

void CaculateWeekDay(int y, int m, int d)
{
	if (m == 1 || m == 2) {
		m += 12;
		y--;
	}
	int iWeek = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
	switch (iWeek)
	{
	case 0: cout << "星期一" << endl; break;
	case 1: cout << "星期二" << endl; break;
	case 2: cout << "星期三" << endl; break;
	case 3: cout << "星期四" << endl; break;
	case 4: cout << "星期五" << endl; break;
	case 5: cout << "星期六" << endl; break;
	case 6: cout << "星期日" << endl; break;
	}
}
int main()
{
	int year, month, day;
	cout << "请输入年 月 日" << endl;
	cin >> year;
	cin >> month;
	cin >> day;
	CaculateWeekDay(year, month, day);
	system("pause");
	return 0;
}
*/

//eg3:
/*
#include<stdio.h>
#include<iostream>
#include<cstdlib>

using namespace std;

string str_week(int y,int m,int d)
{
   int a=7;
   string str_date="";
   if((m==1)||(m==2))
   {
    m+=12;
    y--;
   }
   a=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;
   switch (a){
    case 0:
     str_date="星期一";
     break;
    case 1:
     str_date="星期二";
     break;
    case 2:
     str_date="星期三";
     break;
    case 3:
     str_date="星期四";
     break;
    case 4:
     str_date="星期五";
     break;
    case 5:
     str_date="星期六";
     break;
    case 6:
     str_date="星期日";
     break;
   }
   return str_date;
}

int main()
{
 int y, m, d;
 cout << "输入日期模板 2012 03 30" << endl;
 scanf("%d-%d-%d", &y, &m,&d);
 cout << str_week(y, m, d) << endl;
}
*/


//eg4:
/*
在公式中d表示日期中的日数，m表示月份数，y表示年数。
注意：在公式中有个与其他公式不同的地方：
把一月和二月看成是上一年的十三月和十四月，例：如果是2004-1-10则换算成：2003-13-10来代入公式计算。
以公元元年为参考，公元元年1月1日为星期一</PRE><PRE>程序如下：
*/
/*
#include<stdio.h>
#include<iostream>
#include<cstdlib>

using namespace std;

int CaculateWeekDay(int y,int m, int d)
{
     if(m==1||m==2)
     {
        m+=12;
        y--;
     }
     int iWeek=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;
     switch(iWeek)
     {
      case 0: printf("星期一\n"); break;
      case 1: printf("星期二\n"); break;
      case 2: printf("星期三\n"); break;
      case 3: printf("星期四\n"); break;
      case 4: printf("星期五\n"); break;
      case 5: printf("星期六\n"); break;
      case 6: printf("星期日\n"); break;
    }
}

int main()
{
    int year=0,month=0,day=0;
    printf("请输入日期：\n格式为：1900 1 1\n");
    scanf("%d%d%d",&year,&month,&day);
    CaculateWeekDay(year,month,day);
}
*/

//eg5:
//公式是这样的：w = (y + y /4 + y / 400 - y / 100 + 2 * m + 3 * (m + 1)/5 + d) % 7;
//注：这个公式中，w = 0对应的是星期一，w = 7对应的是星期日
/*
#include<iostream>
#include<string>
#include<stdio.h>
#include<cstdlib>

using namespace std;

string week[] = {"Mon","Tue","Wen","Thu","Fir","Sat","Sun"};
int y,m,d;

int main(){
    while(cin>>y>>m>>d){
        if(m < 3){
            m += 12;
            y--;
        }
        int w = (y + y /4 + y / 400 - y / 100 + 2 * m + 3 * (m + 1)/5 + d) % 7;
        cout<<week[w]<<endl;
    }
    return 0;
}
*/


//法2:蔡勒公式: w=((c/4)-2c+y+y/4+(13(mon+1)/5)+d-1)%7
/*
蔡勒公式 蔡勒（Zeller）公式：是一个计算星期的公式。
随便给一个日期，就能用这个公式推算出是星期几。
蔡勒公式如下：
W = [C/4] - 2C + y + [y/4] + [13 * (M+1) / 5] + d - 1
或者是:w=y+[y/4]+[c/4]-2c+[26(m+1)/10]+d-1
公式中的符号含义如下：
w：星期； w对7取模得：0-星期日，1-星期一，2-星期二，3-星期三，4-星期四，5-星期五，6-星期六
c：世纪-1（前两位数）
y：年（后两位数）
m：月（m大于等于3，小于等于14，即在蔡勒公式中，某年的1、2月要看作上一年的13、14月来计算，比如2003年1月1日要看作2002年的13月1日来计算）
d：日 [ ]代表取整，即只要整数部分。
下面以中华人民共和国成立100周年纪念日那天（2049年10月1日）来计算是星期几，过程如下：
w=y+[y/4]+[c/4]-2c+[26(m+1)/10]+d-1
=49+[49/4]+[20/4]-2×20+[26×(10+1)/10]+1-1
=49+[12.25]+5-40+[28.6]
=49+12+5-40+28
=54 (除以7余5)
即2049年10月1日（100周年国庆）是星期五。
再比如计算2013年3月7日，过程如下：
w=y+[y/4]+[c/4]-2c+[26(m+1)/10]+d-1
=13+[13/4]+[20/4]-220+[26(3+1)/10]+7-1
=-3 (除以7余4，注意对负数的取模运算！)
*/

//正式部分核心代码:
/*int ReturnWeekDay( unsigned int iYear, unsigned int iMonth, unsigned int iDay )
{
	int iWeek = 0;
	unsigned int y = 0, c = 0, m = 0, d = 0;
	if ( iMonth == 1 || iMonth == 2 )
	{
		c = ( iYear - 1 ) / 100;
		y = ( iYear - 1 ) % 100;
		m = iMonth + 12;
		d = iDay;
	}
	else
	{
		c = iYear / 100;
		y = iYear % 100;
		m = iMonth;
		d = iDay;
	}
	iWeek = y + y / 4 + c / 4 - 2 * c + 26 * ( m + 1 ) / 10 + d - 1;    //蔡勒公式
	iWeek = iWeek >= 0 ? ( iWeek % 7 ) : ( iWeek % 7 + 7 );    //iWeek为负时取模
	if ( iWeek == 0 )    //星期日不作为一周的第一天
	{
		iWeek = 7;
	}

	return iWeek;
}
*/

//eg1:
/*
公式为：w=((c/4)-2c+y+y/4+(13(mon+1)/5)+d-1)%7;
注意事项：
1、m=1时，取m=13；m=2时，取m=14；
2、w要对7取模，取模后要保证w在0-6的范围，增加if判断处理；
*/
/*
#include<stdio.h>
#include<iostream>
#include<cstdlib>

using namespace std;

//泰勒公式推算星期几
int weekday(int y,int m,int d)
{
	if(m==1)
	{
		m=13;y--;
	}
	if(m==2)
	{
		m=14;y--;
	}
	int c = y/100;
	y=y%100;
	return ((c/4)-2*c+y/4+y+(13*(m+1)/5)+d-1)%7;
}
int main()
{
	int y,m,d;
	while(cin>>y>>m>>d)
	{
		int wd=weekday(y,m,d);
		if(wd<0)
			wd+=7;
		switch(wd)
		{
		case 6:cout<<"星期六";break;
		case 0:cout<<"星期天";break;
		case 1:cout<<"星期一";break;
		case 2:cout<<"星期二";break;
		case 3:cout<<"星期三";break;
		case 4:cout<<"星期四";break;
		case 5:cout<<"星期五";break;
		}
		cout<<endl;
	}
	return 0;
}
*/

/*
//eg2:
#include<stdio.h>
#include<iostream>
#include<cstdlib>

using namespace std;

int main ()
{
   int c,n;
    int w;
    int y,m,d;
    printf ("输入年月日\n");
    while (~scanf ("%d%d%d",&y,&m,&d))
    {
    c=y/100;
    n=y%100;
    w=n+floor(n*1.0/4)+floor(c*1.0/4)-2*c+floor(26*(m+1)*1.0/10)+d-1;
    printf ("%d年%d月%d日为星期",y,m,d);
    switch (w%7)
    {
    case 1:
        printf ("1\n");break;
        case 2:
        printf ("2\n");break;
        case 3:
        printf ("3\n");break;
        case 4:
        printf ("4\n");break;
        case 5:
        printf ("5\n");break;
        case 6:
        printf ("6\n");break;
        case 0:
        printf ("7\n");break;
    }
    printf ("输入年月日\n");
    }
    return 0;
}
*/

/*
//求一年中的有多少个星期几
#include<stdio.h>
#include<iostream>
#include<cstdlib>

using namespace std;

int main()
{
	int y=2000,c,m=4,d=2,sum=0;
	for(int y=2000;y<2101;y++)
	{
		c=y/100;
		if(6==(y + y / 4 + c / 4 - 2 * c + 26 * (m + 1) / 10 + d - 1)%7)
		  sum++;
	}
	cout<<sum;
}
*/


/*
//例题HDU6112 今夕何夕
//题意：接下来最近的哪一年里的同一个日子，和今天的星期数一样？
#include<stdio.h>
#include<iostream>
#include<cstdlib>
#include <cstring>

using namespace std;

int Date(int y,int m,int d)
{
    if(m==1||m==2){
        m+=12;
        y--;
    }
    int week = (d + 2*m +3*(m+1)/5 + y + y/4 - y/100 + y/400 + 1)%7;
    return week;
}
bool judgeYear(int y)
{
    if((y%4==0&&y%100!=0)||y%400==0)
        return true;
    return false;

}
int main()
{
    int T;
    cout<<"请输入T:";
    scanf("%d",&T);
    int year,month,day;
    while(T--)
    {
       cout<<"请输入:";
       scanf("%d-%d-%d",&year,&month,&day);
       int week = Date(year,month,day);
       for(int i = year+1;i<10000;i++)//枚举判断
       {
           if(judgeYear(year)&&month==2&&day==29&&!judgeYear(i))continue;//注意特别判断第一年闰年2月29第二年不存在的情况！
           if(week == Date(i,month,day)){
               printf("%d\n",i);
               break;
           }
       }
    }
    return 0;
}
*/
