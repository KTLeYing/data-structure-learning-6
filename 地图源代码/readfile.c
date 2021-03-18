/********************************************************************************************
* �ļ�����:	readfile.c																    	*	
* ��������:	12/04/23																	    * 
* ����:																					*
* ��ʽ:		��ȡ��ͼ��Ϣ�ļ�																*
* ����:	    �����������㣬���ڵ�ͼ��Ϣ�ļ���ȡ������										*
            �ֱ�������еı����У������½�����뵥��										*
			��																				*
*********************************************************************************************/

#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<time.h>
#include<windows.h>
#include"struct.h"
#include<stdlib.h>
#include<BASETSD.H>
#include"header.h"

/***************************************************************************
��������: MAPLINK readfile(MAPLINK *Head)
����:   ����һ�������ȡ��ͼ��Ϣ�ļ���������������
                1�� ��ȡ��ͼ��Ϣ�ļ�
				   1:��ȡ��·ID����roadID; 
				   2:��ȡ��·��Ϣ���ݴ���uiinfo;
				   3:����·��Ϣ����uiinfo���ú궨��ȡ����·����flag;
				   4:����·��Ϣ����uiinfo���ú궨��ȡ����·brunch;
				   5:����·��Ϣ����uiinfo���ú궨��ȡ����·����class;
				   6:��ȡ��·���ƴ���roadname[]������
                2�� ����������
				   1:������������
				   2:���´����ĵ����������뵥������
��������:     12/04/23
����:        ����:Sourcep ����:FILE * ��ͼ��Ϣ�ļ�ָ��

             ����:Resultp ����:FILE * �����ļ�ָ��

			 ����:roadname ����:char���� ��·����

			 ����:def ����:char���� �޵�·����

			 ����:infosize ����:unsigned short ��Ϣ��С

			 ����:roadID ����:unsigned int ��·ID

			 ����:roadflag ����:unsigned int ��·flagֵ

  			 ����:uibrunch ����:unsigned int ��·��·��

    		 ����:marker ����:unsigned int ��¼��·���ƴ�С

      		 ����:uiinfo ����:unsigned int ��·��Ϣ����

      		 ����:roadClass ����:unsigned int ��·����

        	 ����:temp ����:int ��ʱ����

        	 ����:count ����:long int ������

          	 ����:newnodep ����:MAPLINK �½��ָ��
����:        H: �������ͷ���ָ��               
���:        VOID
����ֵ:      Head   
                            
����:    
*******************************************************************************/
void readfile(MAPLINK *head)
{
	FILE *Sourcep;
	FILE *Resultp;
	char roadname[3000] = {'\0'};
	char def[20] = "�޴˵�·��Ϣ";
	unsigned short infosize = 0;
	unsigned int roadID = 0;
	unsigned int roadflag = 0;
	unsigned int a = 0;
	unsigned int uibrunch = 0;
	unsigned int marker = 0;
	unsigned int uiinfo = 0; 
	unsigned int roadClass = 0;
	int i = 0,j = 0;
	int temp = 0;
	long int count = 0;

	MAPLINK newnodep;
	MAPLINK current;

	*head = (MAPLINK)malloc(sizeof(MAP));
	current = *head;
	newnodep = *head;
	Sourcep = fopen("d:\\GTBL.dat", "rb");
	Resultp = fopen("d:\\Result.txt", "w+");  //ָ���ļ���ָ��
	printf("����ͼ��Ϣȡ��...\n");
	//�ӵ�ͼ��Ϣ�ļ��ж�ȡ����
	while(!feof(Sourcep))
	{
		for(i=0;i<22;i++)
		{
			newnodep->name[i] = '\0';
		}
		count++;
		fread(&infosize, 2, 1, Sourcep);
		infosize = GET_SHORT(infosize);
		marker = infosize;
		fprintf(Resultp, "��Ϣ��С�� %d    ", infosize);//��ȡ��Ϣ��С

		fread(&roadID, 4, 1, Sourcep);
		roadID = GET_INT(roadID);
		fprintf(Resultp, "LinkID��%d   ", roadID);//��ȡ��·ID

		newnodep->LinkID=roadID;

		fread(&a, 2, 1, Sourcep);
		a = GET_SHORT(a);


		fread(&uiinfo, 4, 1, Sourcep);
		roadflag=GET_FLAG(GET_INT(uiinfo));//��ȡ��ͼ��Ϣ
		fprintf(Resultp, "Flag: %d   ", roadflag);

		newnodep->flag = roadflag;

		uibrunch = GET_CROSS(GET_INT(uiinfo));
		fprintf(Resultp, "��·��: %d   ", uibrunch);

		newnodep->branch = uibrunch;

		roadClass = GET_CLASS(GET_INT(uiinfo));
		fprintf(Resultp, "����Link�б�ʾClass����: %d   ", roadClass);

		newnodep->roadclass = roadClass;

		fprintf(Resultp,"��·����:");

		/*		             ��ȡ��·����                  */
		if((marker-12) == 0)
		{
		  fwrite(def, 12, 1, Resultp);
		  fprintf(Resultp, "\n\n");
		  strcpy(newnodep->name, def);
		}
		else
		{
			fread(roadname, (marker-12), 1, Sourcep);
			fwrite(roadname, (marker-12), 1, Resultp);
			fprintf(Resultp, "\n\n");
			strcpy(newnodep->name, roadname);
		}
		/*                   ����������                    */
		current->next = newnodep;
		newnodep->next = NULL;
		current = newnodep;
		newnodep = (MAPLINK)malloc(sizeof(struct map));
	}
	printf(".........\n");
	printf(".........\n");
	printf("��ȡ��...\n");
	printf("\n");
	printf(" /****************************************************************************\\ \n");
}