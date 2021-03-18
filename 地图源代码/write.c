/********************************************************************************************
* �ļ�����:	write.c																	    	*	
* ��������:	12/04/25																	    * 
* ����:																					*
* ��ʽ:		�Ե�ͼ��Ϣ�ļ�����д����														*
* ����:	    ������д��ͼ��Ϣ�ļ��ķ�ʽ														*													*
				1:�Ե�ͼ��Ϣ�ļ�����д														*
				2:�������ļ���.txt��д														*
* �޸�����  12/05/01											          																				*
*********************************************************************************************/
#include<stdio.h>
#include<string.h>
#include<windows.h>
#include"struct.h"
#include"header.h"

/***************************************************************************
��������: void tobfwrite(MAPLINK H)
����:   ���ͼ��Ϣ�������ļ��н���д����
��������:     12/04/25
����:        ����:current ����:MAPLINK ָ��ǰ����ָ��
			 
			 ����:fp, tp ����:FILE *  ָ���ļ���ָ��

			 ����:m, mm ����:short int ��Ϣ��С

			 ����:id ����:int ��·ID

����:        H: �������ͷ���ָ��               
���:        �û���ʾ��Ϣ
����ֵ:      VOID   
                            
����:    
*******************************************************************************/
void tobfwrite(MAPLINK H)
{
	MAPLINK current;
	FILE *fp, *tp;
	int k;
    short int m, mm;
	short int size;
	int id;

	current = H;

	fp = fopen("e:\\GTBL.dat", "wb");
	tp = fopen("e:\\GTBL.dat", "ab");

	while(current!=NULL)
	{
		m = (short)strlen(current->name);//��ȡ��·���ִ�С

		mm = m+1;

		size = (short)(12+strlen(current->name)+1);//��ȡ��Ϣ��С

		k = ((current->flag << 7) | (current->branch << 4) | current->roadclass);//��flag��brunch��roadclassת��Ϊ��·��Ϣ

		size = GET_SHORT(size);//ת��Ϊ���ֽ�

		id = GET_INT(current->LinkID);//ת��Ϊ���ֽ�
	
		m = GET_SHORT(m);//ת��Ϊ���ֽ�

		k = GET_INT(k);//ת��Ϊ���ֽ�

		//����д�����
		fwrite(&size, 2, 1, tp);
		fwrite(&id, 4, 1, tp);
		fwrite(&m, 2, 1, tp);
		fwrite(&k, 4, 1, tp);
		fwrite((current->name), mm, 1, tp);

		current = current->next;
	}
	printf("          ��ϲ�㣡    ���³ɹ���\n");
	fclose(fp);
	fclose(tp);
}

/***************************************************************************
��������: void tofwrite(MAPLINK* head, char fname[])
����:   ���ͼ��Ϣ�����ļ��н���д����
��������:     12/04/25
����:        ����:current ����:MAPLINK ָ��ǰ����ָ��
			 
			 ����:Resultp ����:FILE * ָ���ļ���ָ��

����:        head: ���浥�����ͷ���ָ���ָ��
			 fname: �����ͼ��Ϣ���ļ���               
���:        �û���ʾ��Ϣ
����ֵ:      VOID   
                            
����:    
*******************************************************************************/
void tofwrite(MAPLINK* head, char fname[])
{
	FILE *Resultp;
	MAPLINK current;

	current = *head;

	Resultp = fopen(fname, "w");
	if(Resultp == NULL)
	{
		printf("���ļ�ʧ�ܣ�");
		exit(0);
	}
	//���ı��ĵ��д�����Ϣ
	while(current->next != NULL)
	{
		fprintf(Resultp, "LinkID: %d   ", current->LinkID);
		fprintf(Resultp, "Flag: %d    ", current->flag);
		fprintf(Resultp, "��·��: %d   ", current->branch);
		fprintf(Resultp, "����Link�б�ʾClass����: %d   ", current->roadclass);
		fprintf(Resultp, "��·����: %s  ", current->name);
		fprintf(Resultp, "\n\n");
		current = current->next;
	}
	fclose(Resultp);
}
