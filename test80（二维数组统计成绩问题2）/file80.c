#include<stdio.h>
int main()
{
    int i,j,x[3][5];
	float a;
	printf("请输入数据:");
	for(i=0;i<=2;i++)
	{
	   for(j=0;j<=4;j++)
		   scanf("%d",&x[i][j]);
	}
	for(i=0;i<=4;i++)
	{
		a=0;
		for(j=0;j<=2;j++)
			a=a+x[j][i];
		printf("第%d个同学的总平均成绩为%f:\n",i+1,a/3);
	}
	for(j=0;j<=2;j++)
	{
		a=0;
	    for(i=0;i<=4;i++)
		   a=a+x[j][i];
		printf("第%d个科的总平均成绩为%f:\n",j+1,a/5);
	}
	return 0;
}
