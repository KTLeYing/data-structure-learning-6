#include<stdio.h>
int main()
{
    int i,j,x[3][5];
	float a=0,z[5],y[3];
	printf("请输入数据:");
	for(i=0;i<=2;i++)
	{
	   for(j=0;j<=4;j++)
		   scanf("%d",&x[i][j]);
	}
	for(i=0;i<=4;i++)
	{
		z[i]=0;
		for(j=0;j<=2;j++)
			z[i]=z[i]+x[j][i];
		printf("第%d个同学的总平均成绩为%f:\n",i+1,z[i]/3);
	}
	for(j=0;j<=2;j++)
	{
		y[j]=0;
	    for(i=0;i<=4;i++)
			y[j]=y[j]+x[j][i];
		printf("第%d个科的总平均成绩为%f:\n",j+1,y[j]/5);
	}
	return 0;
}
