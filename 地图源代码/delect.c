/************************************************************************************************
* ���ƣ�ɾ��
* ���ܣ�ͨ�������·ID����������ɾ��һ���·��Ϣ����д�ض������ļ�
* �������ڣ�4-26
* ����������1��p1��MAPLINK������ָ��
*       ����2��p2��MAPLINK������ָ��
* ����ֵ VOID
* ���ߣ�
*************************************************************************************************/
#include<stdio.h>
#include"struct.h"
#include"write.h"

void delect(MAPLINK Head)
{
   MAPLINK p1,p2;
   int delID,n;
   char fname[30]="d:\\deleteResult.txt";			//ɾ������д���ı��ĵ���·��
   
   printf("������Ҫɾ���ĵ�·ID:");

   scanf("%d",&delID);

   p1=Head;
   n=0;
   p2=p1;
	   
   if (delID==p1->LinkID)      /*    ����ѭ���ҵ��û���Ҫɾ����ID������ɾ��    */
   {
	   Head=p2;
   }
   else
   {
		while(p1->next!=NULL)
		{
		 if (delID==p2->LinkID)
         p1->next=p2->next;
         p1=p2;

         p2=p2->next;
		}
		p1=p1->next;
	}
   tobfwrite(Head);					//д�뵽��ͼ��Ϣ�ļ���
   tofwrite(&Head,fname);			//д�뵽����õ��ı��ĵ���
}