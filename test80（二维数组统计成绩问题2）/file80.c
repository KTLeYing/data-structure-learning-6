#include<stdio.h>
int main()
{
    int i,j,x[3][5];
	float a;
	printf("����������:");
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
		printf("��%d��ͬѧ����ƽ���ɼ�Ϊ%f:\n",i+1,a/3);
	}
	for(j=0;j<=2;j++)
	{
		a=0;
	    for(i=0;i<=4;i++)
		   a=a+x[j][i];
		printf("��%d���Ƶ���ƽ���ɼ�Ϊ%f:\n",j+1,a/5);
	}
	return 0;
}
