#include<stdio.h>
#include"struct.h"
#include"QuickSort.h"
#include"Qsort.h"
#include"BubbleSort.h"

void Msort(MAPLINK *H)
{
	int userChoose;
	char quickfname[30] = "d:\\QuickSortedResult.txt";
	char Selfname[30] = "d:\\SelSortedResult.txt";
	char Bubfname[30] = "d:\\BudSortedResult.txt";

	printf("\n");
    printf(" /****************************************************************************\\ \n");
	printf("           ��ѡ������ʽ��\n");
	printf("               1����������\n");
	printf("               2��ѡ������\n");
	printf("               3��ð������\n\n");
	printf("           ��������ѡ���֣�");
	scanf("%d",&userChoose);
	switch(userChoose)
	{
	case 1:
		QListSort(H, NULL);
		tofwrite(H, quickfname);
		printf("����ɹ����洢��D��QuickSortedResult.txt�ļ��У�\n");
		printf("\n");
		printf(" /****************************************************************************\\ \n");
		break;
	case 2:
		SelSort(*H);
		tofwrite(H, Selfname);
		printf("����ɹ����洢��D��SelSortedResult.txt�ļ��У�\n");
		printf("\n");
		printf(" /****************************************************************************\\ \n");
		break;
	case 3:
		BSort(*H);
		tofwrite(H, Bubfname);
		printf("����ɹ����洢��D��BudSortedResult.txt�ļ��У�");
		printf("\n");
		printf(" /****************************************************************************\\ \n");
		break;
	default :
		printf("�޴���������������룺\n");
		Msort(H);
	}
}