
//����ĳ�����������ڼ�,�ж�ĳ��ĳ��һ�������ڼ�

//���÷���:
/*һ�����ù�ʽ
W = [Y-1] + [(Y-1)/4] - [(Y-1)/100] + [(Y-1)/400] + D
Y���������D����һ������һ���е��ۻ�������Ҳ������һ������һ�����ǵڼ��졣

�������գ�Zeller����ʽ
w=y+[y/4]+[c/4]-2c+[26(m+1)/10]+d-1
��ʽ�еķ��ź������£�w�����ڣ�c�����ͣ�y���꣨��λ������ m���£�m���ڵ���3��С�ڵ���14�����ڲ��չ�ʽ�У�ĳ���1��2��Ҫ������һ��
��13��14�������㣬����2003��1��1��Ҫ����2002���13��1�������㣩��d���գ�[ ]����ȡ������ֻҪ�������֡�
�����ͨ��ͨ�ü��㹫ʽ���ԣ����գ�Zeller����ʽ��󽵵��˼���ĸ��Ӷȡ�

�����Բ��գ�Zeller����ʽ�ĸĽ�
���������һ��ͨ��ͨ�ü��㹫ʽ���ԣ����գ�Zeller����ʽ��󽵵��˼���ĸ��Ӷȡ����������߸�����ͨ�ü��㹫ʽ�ƺ����Ӽ�ࣨ����������̣����ֽ���ʽ�������£�
W=[y/4]+r (y/7)-2r(c/4)+m��+d
��ʽ�еķ��ź������£�r ( )����ȡ�࣬��ֻҪ�������֣�m����m�����������ָ���1��12�µ�������1����12�����£���1����10����=6����2����3����11����
=2����4����7����=5��5��=0��6��=3��8��=1����9����12����=4��ע�⣺�ڱ��߸����Ĺ�ʽ�У�yΪ����ʱ1��=5��2��=1����������������գ�Zeller����ʽ�еĺ�����ͬ��

�ģ���ķ����ɭ���㹫ʽ
�����ʽ�������Ҹ������ģ�����ϣ����Ҳ�Ҫ���֡�
W= (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400) mod 7
�ڹ�ʽ��d��ʾ�����е�������m��ʾ�·�����y��ʾ������
*/


//��1:��ķ����ɭ���㹫ʽ:W= (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400) mod 7(�ڹ�ʽ��d��ʾ�����е�������m��ʾ�·�����y��ʾ����)
//ע�⣺�ڹ�ʽ���и���������ʽ��ͬ�ĵط�ע�⣺�ڹ�ʽ���и���������ʽ��ͬ�ĵط���
//��һ�ºͶ��¿�������һ���ʮ���º�ʮ���£����������2004-1-10����ɣ�2003-13-10�����빫ʽ���㡣
//�Թ�ԪԪ��Ϊ�ο�����ԪԪ��1��1��Ϊ����һ

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
        printf("\n���������ڣ�\n��ʽΪ��1900 1 1\n");
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
	case 0: cout << "����һ" << endl; break;
	case 1: cout << "���ڶ�" << endl; break;
	case 2: cout << "������" << endl; break;
	case 3: cout << "������" << endl; break;
	case 4: cout << "������" << endl; break;
	case 5: cout << "������" << endl; break;
	case 6: cout << "������" << endl; break;
	}
}
int main()
{
	int year, month, day;
	cout << "�������� �� ��" << endl;
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
     str_date="����һ";
     break;
    case 1:
     str_date="���ڶ�";
     break;
    case 2:
     str_date="������";
     break;
    case 3:
     str_date="������";
     break;
    case 4:
     str_date="������";
     break;
    case 5:
     str_date="������";
     break;
    case 6:
     str_date="������";
     break;
   }
   return str_date;
}

int main()
{
 int y, m, d;
 cout << "��������ģ�� 2012 03 30" << endl;
 scanf("%d-%d-%d", &y, &m,&d);
 cout << str_week(y, m, d) << endl;
}
*/


//eg4:
/*
�ڹ�ʽ��d��ʾ�����е�������m��ʾ�·�����y��ʾ������
ע�⣺�ڹ�ʽ���и���������ʽ��ͬ�ĵط���
��һ�ºͶ��¿�������һ���ʮ���º�ʮ���£����������2004-1-10����ɣ�2003-13-10�����빫ʽ���㡣
�Թ�ԪԪ��Ϊ�ο�����ԪԪ��1��1��Ϊ����һ</PRE><PRE>�������£�
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
      case 0: printf("����һ\n"); break;
      case 1: printf("���ڶ�\n"); break;
      case 2: printf("������\n"); break;
      case 3: printf("������\n"); break;
      case 4: printf("������\n"); break;
      case 5: printf("������\n"); break;
      case 6: printf("������\n"); break;
    }
}

int main()
{
    int year=0,month=0,day=0;
    printf("���������ڣ�\n��ʽΪ��1900 1 1\n");
    scanf("%d%d%d",&year,&month,&day);
    CaculateWeekDay(year,month,day);
}
*/

//eg5:
//��ʽ�������ģ�w = (y + y /4 + y / 400 - y / 100 + 2 * m + 3 * (m + 1)/5 + d) % 7;
//ע�������ʽ�У�w = 0��Ӧ��������һ��w = 7��Ӧ����������
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


//��2:���չ�ʽ: w=((c/4)-2c+y+y/4+(13(mon+1)/5)+d-1)%7
/*
���չ�ʽ ���գ�Zeller����ʽ����һ���������ڵĹ�ʽ��
����һ�����ڣ������������ʽ����������ڼ���
���չ�ʽ���£�
W = [C/4] - 2C + y + [y/4] + [13 * (M+1) / 5] + d - 1
������:w=y+[y/4]+[c/4]-2c+[26(m+1)/10]+d-1
��ʽ�еķ��ź������£�
w�����ڣ� w��7ȡģ�ã�0-�����գ�1-����һ��2-���ڶ���3-��������4-�����ģ�5-�����壬6-������
c������-1��ǰ��λ����
y���꣨����λ����
m���£�m���ڵ���3��С�ڵ���14�����ڲ��չ�ʽ�У�ĳ���1��2��Ҫ������һ���13��14�������㣬����2003��1��1��Ҫ����2002���13��1�������㣩
d���� [ ]����ȡ������ֻҪ�������֡�
�������л����񹲺͹�����100������������죨2049��10��1�գ������������ڼ����������£�
w=y+[y/4]+[c/4]-2c+[26(m+1)/10]+d-1
=49+[49/4]+[20/4]-2��20+[26��(10+1)/10]+1-1
=49+[12.25]+5-40+[28.6]
=49+12+5-40+28
=54 (����7��5)
��2049��10��1�գ�100������죩�������塣
�ٱ������2013��3��7�գ��������£�
w=y+[y/4]+[c/4]-2c+[26(m+1)/10]+d-1
=13+[13/4]+[20/4]-220+[26(3+1)/10]+7-1
=-3 (����7��4��ע��Ը�����ȡģ���㣡)
*/

//��ʽ���ֺ��Ĵ���:
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
	iWeek = y + y / 4 + c / 4 - 2 * c + 26 * ( m + 1 ) / 10 + d - 1;    //���չ�ʽ
	iWeek = iWeek >= 0 ? ( iWeek % 7 ) : ( iWeek % 7 + 7 );    //iWeekΪ��ʱȡģ
	if ( iWeek == 0 )    //�����ղ���Ϊһ�ܵĵ�һ��
	{
		iWeek = 7;
	}

	return iWeek;
}
*/

//eg1:
/*
��ʽΪ��w=((c/4)-2c+y+y/4+(13(mon+1)/5)+d-1)%7;
ע�����
1��m=1ʱ��ȡm=13��m=2ʱ��ȡm=14��
2��wҪ��7ȡģ��ȡģ��Ҫ��֤w��0-6�ķ�Χ������if�жϴ���
*/
/*
#include<stdio.h>
#include<iostream>
#include<cstdlib>

using namespace std;

//̩�չ�ʽ�������ڼ�
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
		case 6:cout<<"������";break;
		case 0:cout<<"������";break;
		case 1:cout<<"����һ";break;
		case 2:cout<<"���ڶ�";break;
		case 3:cout<<"������";break;
		case 4:cout<<"������";break;
		case 5:cout<<"������";break;
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
    printf ("����������\n");
    while (~scanf ("%d%d%d",&y,&m,&d))
    {
    c=y/100;
    n=y%100;
    w=n+floor(n*1.0/4)+floor(c*1.0/4)-2*c+floor(26*(m+1)*1.0/10)+d-1;
    printf ("%d��%d��%d��Ϊ����",y,m,d);
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
    printf ("����������\n");
    }
    return 0;
}
*/

/*
//��һ���е��ж��ٸ����ڼ�
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
//����HDU6112 ��Ϧ��Ϧ
//���⣺�������������һ�����ͬһ�����ӣ��ͽ����������һ����
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
    cout<<"������T:";
    scanf("%d",&T);
    int year,month,day;
    while(T--)
    {
       cout<<"������:";
       scanf("%d-%d-%d",&year,&month,&day);
       int week = Date(year,month,day);
       for(int i = year+1;i<10000;i++)//ö���ж�
       {
           if(judgeYear(year)&&month==2&&day==29&&!judgeYear(i))continue;//ע���ر��жϵ�һ������2��29�ڶ��겻���ڵ������
           if(week == Date(i,month,day)){
               printf("%d\n",i);
               break;
           }
       }
    }
    return 0;
}
*/
