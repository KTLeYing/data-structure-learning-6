#include<stdio.h>
int int_max(int m,int n);
int main()
{
    int i,j,m;
	printf("输入2个整数:");
	scanf("%d%d",&i,&j);
	m=int_max(i,j);
	printf("最大数为:%d\n",m);
	return 0;
}
int int_max(int m,int n)
{
    int max=m;
	if(max<n)
		max=n;
	return max;
}

