#include<stdio.h>
#include"struct.h"
#include"insert.h"
#include"delect.h"

void update(MAPLINK H)
{
	int userchoose;

	printf("\n");
	printf("        1������");
	printf("        2��ɾ��\n\n");
	printf("      ��������ѡ��Ŀ��");

	scanf("%d", &userchoose);

	switch(userchoose)
	{
	case 1:
		insert(H);
		PrintEndFunction();
		Choose(H);
		break;
	case 2:
		delect(H);
		PrintEndFunction();
		Choose(H);
		break;
	default :
		printf("�޴���������������룺\n");
		update(H);
	}
}