/**************************************************/
/*���ƣ�QSort
/*��������������Ϣ��LINK ID����С����˳���������
/*�������ڣ� 12/05/01 
/*���ߣ�
/***************************************************/
#include<stdio.h>
#include"struct.h"
#include<string.h>

/**************************************************/
/*���ƣ�SelSort
/*����������ѡ�񷨽�������
/*�������ڣ�12/05/01 
/*������
        ����1��pslow����������struct mapָ�롢����/����������ṹ�����
        ����2��pfast����������struct mapָ�롢����/����������ṹ�����
		����3��current����������struct mapָ�롢����/����������ṹ�����
		����4��tempname�������������顢����������洢��·��Ϣ����������
		����5��temp����������unsigned int������/����������洢���ݵı���
/*����ֵ��VOID
/*���ߣ�
/***************************************************/
void SelSort(MAPLINK Head)
{
	MAPLINK pslow;
	MAPLINK pfast;
	MAPLINK current;
	char tempname[30]={'\0'};
	unsigned int temp=0;
	
	/*����forѭ�������ݽ�������*/
	printf("���Եȣ�������......");
	for(pslow=Head; (pslow->next) != NULL; pslow=pslow->next)
		{
		   current=pslow;
			for(pfast=pslow->next; (pfast->next) != NULL; pfast=pfast->next)
			{
				if( (current->LinkID) > (pfast->LinkID) )
				{
					current=pfast;
				}
	
				if(current != pslow)
				{		
					temp=pslow->LinkID;
					pslow->LinkID=current->LinkID;
					current->LinkID=temp;
				
					temp=pslow->flag;
					pslow->flag=current->flag;
					current->flag=temp;
	
					temp=pslow->branch;
					pslow->branch=current->branch;
					current->branch=temp;
	
					temp=pslow->roadclass;
					pslow->roadclass=current->roadclass;
					current->roadclass=temp;
					
					strcpy(tempname,pslow->name);
					strcpy(pslow->name,current->name);
					strcpy(current->name,tempname);
				}
		
			}
		}
}