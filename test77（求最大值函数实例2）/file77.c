#include<stdio.h>
int int_max();
int main()
{
	printf("����9��11�����Ϊ:%d\n",int_max(9,11));
	return 0;
}
int int_max(int m,int n)
{
 	int max=m;
	if(max<n)
		max=n;
	return max;
}
