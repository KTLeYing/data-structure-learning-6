/************************************************************************************************/
//���ƣ�����
//���ܣ��������в���һ���ڵ㣬�洢Ҫ�����ͼ��Ϣ�����ݣ�������write�е�tobfwrite����д�ض������ļ�
//�������ڣ�4-26
//����������1��head��MAPLINK�����롢��������ͷ���
//      ����2��newnode��MAPLINK�����롢�½ڵ�
//      ����3��linkp��MAPLINK�����롢ָ������ÿ���ڵ㣬�����ж�
//����ֵ VOID
//���ߣ�
//�޸�����  12/05/01
/************************************************************************************************/
#include<stdio.h>
#include<malloc.h>
#include"struct.h"
#include"header.h"
#include"write.h"

void insert(MAPLINK head)
{
	MAPLINK newnode;
	MAPLINK linkp;
	char fname[30]="d:\\insertResult.txt";//����������ļ�·��

	linkp=head;
	newnode=(MAPLINK)malloc(sizeof(MAP));
	printf("           �������·ID��");
	scanf("%d",&(newnode->LinkID));
	while(linkp!=NULL)
	{
		if(newnode->LinkID==linkp->LinkID)
		{
			printf("\n");
			printf("        ��ID�Ѵ��ڣ�        ");//�ж������ID���Ƿ����
			printf("���������룺\n");
			printf("\n");
			insert(head);
			break;
		}
		linkp=linkp->next;
	}
	printf("           0����flag  1����flag\n          ��ѡ��");
	scanf("%d",&(newnode->flag));
	if(newnode->flag==1||newnode->flag==0)
	{
		printf("           �������·��·����");/*�����·��Ϣ*/
		scanf("%d",&(newnode->branch));
		printf("           �������·���ţ�");
		scanf("%d",&(newnode->roadclass));
		printf("           �������·���ƣ�");
		scanf("%s",(newnode->name));

		linkp=head;
		while(linkp!=NULL)					/*       ��ID����       */
		{
			if(newnode->LinkID>linkp->LinkID&&newnode->LinkID<linkp->next->LinkID)
			{
				newnode->next=linkp->next;
				linkp->next=newnode;
				break;
			}
			linkp=linkp->next;
		}
		tobfwrite(head);			//д�뵽��ͼ��Ϣ�ļ���
		tofwrite(&head,fname);		//д�뵽����õ��ı��ĵ���
	}
	else
	{
		printf("				������0��1\n");
		insert(head);
	}
}