/***************************************************************************
 /*���ƣ�searchfind.c
 /*���������ļ�ʵ�ֶ��ļ����ݵļ�������                
 /*�������ڣ�  2012-04-23
 /*������void search(MAP *head);
         int LinkIDfind(MAP *hl);
         int Brunchfind(MAP *hb,int number);
         int Namefind(MAP *hn);                           
/*���ߣ�   
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "struct.h"

extern void search(MAPLINK head);
int LinkIDfind(MAPLINK hl);
int Brunchfind(MAPLINK hb,int number);
int Namefind(MAPLINK hn);

/***************************************************************************
 /*����: void search( MAP* head)
 /*����: ʵ�ּ�������
                1. �����������
				   1:���� LinkID����; 
				   2:���� road number����;
				   3:���� road name����;
				   4:���� class number����;
				   5:���� flag����;
                2. ÿ�ַ�������һ������
                3. ������֮��������߱��浽.txt�ļ���
 /*��������:          2012-04-23
 /*������ ����1��MAP* head   �Զ���Ľṹ������ָ��           
 /*����ֵ���޷���ֵ                            
 /*���ߣ�
*******************************************************************************/
void search(MAPLINK head)
{	  
	  MAPLINK nowp;                                        
	  int method;
	  int result;
	  extern void Choose();
	  extern void PrintEndFunction();
	
	  printf("   ��ӭ����������ܽ���   \n");
	  while(1)
	  {
		  nowp = head;  
	  
	      printf("\n");
	      printf("        ��ѡ������Ҫ�Ĺ���\n");	  
	      printf("           1������LinkID����...\n");
          printf("           2�����ݲ�·������...\n");
	  printf("           3�����ݵ�·���Ƽ���...\n");
          printf("           4�����ݽ���Link�б�ʾClass���ż���...\n");
          printf("           5������flag������...\n");
	  printf("\n");
          printf(" /****************************************************************************\\ \n");
	  printf("    ������Ҫ�����ķ������:");
	      
		  scanf("%d",&method);
          printf("\n");


	      switch(method)
	      {
              case 1:
			 
			      result = LinkIDfind(nowp);		               //����LinkID����		       			         				  
				  break;
			
              case 2:
			
			      result = Brunchfind(nowp,2);					   //���ղ�·������			 
				  break;
			
	          case 3:

		          result = Namefind(nowp);                         //���յ�·���Ƽ���					  				 
				  break;
	          case 4:

		          result = Brunchfind(nowp,4);					   //����class���ż���
				  break;
			  case 5:

                  result = Brunchfind(nowp,5);					  	//����flag������			  
				  break;
              default:

				 printf("�޴�ѡ�����,������ѡ�� \n");
				 search(head);
		         break;
		 }
		 if(2 == result)
		 {
			 continue;                                          //��������ѭ��
		 }
         		else if(3 == result)
		 {
              		PrintEndFunction();
			Choose(&head);                                  //����������
		 }
		 else
		 {
			 ;
		 }	
	  }
}

/***************************************************************************
/*����: int LinkIDfind(  map* head)
/*����: ����LinkID����
                1. ���� LinkIDͷָ��
                2. ˳�����
                3. ���Һ���� 
 /*��������:          2012-04-23
 /*����:   ����1��struct map* head  �Զ���Ľṹ������ָ��               
 /*����ֵ: ����ֵΪ2������ ���淵�ؼ�������
           ����ֵΪ3������ ���淵��������                            
 /*����:     
*******************************************************************************/
int LinkIDfind(MAPLINK hl)
{
	MAPLINK p;   
	FILE* fp;
	int ID,menunow;                                       
	int count = 0;
    int node;
	int save = 0;
	char roadname[50];
	
	fp = fopen("d:\\ResultSearchLinkID.txt","w+");                               //Ҫ������ļ�ָ��
    if(NULL == fp)
	{
		  printf("�ļ���ʧ��\n");
	      exit(1);
	}

	while(1)
	{	
	    printf("������Ҫ������LinkID��:");
	    scanf("%d",&node);
	    p = hl;
	   	   	   
	    while(p!=NULL)
		{		
		    ID = p->LinkID;                     
		    if(node == ID)                                                  //���������ΪҪ���ҵ�LinkID��ִ�����...
			{					
			    count++;

			    printf("LinkID:%d\n",p->LinkID);
			    printf("flag:%d\n",p->flag);
			    printf("��·��:%d\n",p->branch);
			    printf("����Link�б�ʾClass����:%d\n",p->roadclass);
			    printf("��·����:%s\n",p->name);
			
		        printf("\n");
			    printf("��ѡ���Ƿ������Ϣ������d:\\ResultSearchLinkID.txt�ı��ĵ���\n\n");
				printf("1:�� 2:�� \n");
			    printf("��ѡ��:");
			    scanf("%d",&save);

			    if(1==save)			
				{	
			        fprintf(fp,"LinkID:%d\n",p->LinkID);
			        fprintf(fp,"flag:%d\n",p->flag);
                    fprintf(fp,"��·��:%d\n",p->branch);
			        fprintf(fp,"����Link�б�ʾClass����:%d\n",p->roadclass);
			   
                    fprintf(fp,"��·����:");
			        strcpy(roadname,p->name);		
				    fwrite(roadname,(strlen(roadname)),1,fp);

			        fprintf(fp,"\n\n");
			        printf("�������!\n");
				}
				else if(2==save)
				{
					printf("�����Ϣû�б��浽�ı��ĵ���,����� \n");
					printf("\n");
				}
				else
				{
					printf("�������,δ���� \n");
					printf("\n");
				}
				break;
			}
			else 
				p = p->next;
		}
	    if(0 == count)
		{	
			printf("�޴˵�·���,��˶Ժ����¼��� \n");  
			printf("\n");
		}
		else 
		{
			printf("��LinkID�������\n");
			printf("\n");
		}  
        
		printf(" /****************************************************************************\\ \n");
		printf("��ѡ��: \n");
		printf("1����������LinkID����...\n");
		printf("2�����ؼ���Ŀ¼\n");
		printf("3��������Ŀ¼\n");
		printf("���������:");
		scanf("%d",&menunow);
		if(1 == menunow)
			continue;
		else if(2 == menunow)
			return 2;
		else if(3 == menunow)
			return 3;
		else
		{
			printf("�������!���ؼ���Ŀ¼\n");
			printf("\n");
			return 2;
		}
	}
}

/***************************************************************************
/*����: Brunchfind(MAP *hb,int number)
/*����: ���ݲ�·����class���š�flag������
                1. ����Ҫ������ͷָ�����������
                2. ˳�����
                3. ���Һ���������� 
 /*��������:          2012-04-23
 /*����:   ����1��struct map* head  �Զ���Ľṹ������ָ�� 
           ����2��number ���� ���������� 2 ���ݲ�·��������
				                         4 ����class���ż�����
							             5 ����flag��������
 /*����ֵ: ����ֵΪ2������ ���淵�ؼ�������
           ����ֵΪ3������ ���淵��������                            
 /*����:     
*******************************************************************************/
int Brunchfind(MAPLINK hb,int number)
{	
	MAPLINK p;  
	MAPLINK findcurrent;
    MAPLINK findhead;
    MAPLINK findnew;
    MAPLINK findprintf;
    MAPLINK findprintfdos;
	int ID,menunow;                                       
	int count = 0,countp = 0;
    int node;
	int numbera = 0;
	FILE *fp;
	char roadname[50];
	
	if(number == 2)
	{
	      fp = fopen("d:\\ResultSearchbrunch.txt","w+");                                          //Ҫ������ļ�ָ��
	}
	else if(number == 4)
	{
          fp = fopen("d:\\ResultSearchclass.txt","w+");
	}
	else if(number == 5)
	{
          fp = fopen("d:\\ResultSearchflag.txt","w+");
	}
	if(NULL == fp)
	{
		  printf("�ļ���ʧ��\n");
		  exit(1);
	}
	
	while(1)
	{		
	    count = 0;
	    numbera = number;
	    if(numbera == 2)
		{	
			printf("������Ҫ�����Ĳ�·��:");
		}
		else if(numbera == 4)
		{
			printf("������Ҫ������class����:");
		}
		else if(numbera == 5)
		{
			printf("������Ҫ������flag��:");
		}
		scanf("%d",&node);
		p = hb;
	 	   
		findhead = (MAPLINK)malloc(sizeof(MAP));                                         //���ݼ������ĵ�·��Ϣ�½�һ��������
		findprintf = findhead;
		findprintfdos = findhead;
		findcurrent = findhead;
		findnew = findhead;
		while(p!=NULL)
		{	
			if(numbera == 2)
			{		
	            ID = p->branch;
			}
			else if(numbera == 4)
			{
				ID = p->roadclass;
			}
			else if(numbera == 5)
			{
				ID = p->flag;
			}
	
			if(node == ID)
			{	
				count++;           

				findnew->LinkID = (p->LinkID);
                findnew->flag = (p->flag);
			    findnew->branch = (p->branch);
			    findnew->roadclass = (p->roadclass);
                strcpy(findnew->name,(p->name));

			    findcurrent->next = findnew;
	    	    findnew->next = NULL;
		        findcurrent = findnew;
		        findnew = (MAPLINK)malloc(sizeof(struct map));
			    p = p->next;
			}
			else
			{
				p = p->next;
			}
		}
	
	
		if(0==count)
		{	
			if(numbera ==2)
			{
				printf("�޴˲�·��,��˶Ժ����¼��� \n");  
			}
			else if(numbera ==4)
			{
				printf("�޴�class����,��˶Ժ����¼��� \n");
			}
			else if(numbera ==5)
			{
				printf("�޴�flag��,��˶Ժ����¼���.\n");
			}
		
			printf("\n");
		}
	   
		else if((0<count)&&(count<6))
		{
			if(numbera ==2)
			{
				printf("�˲�·���������\n");
			}
			else if(numbera ==4)
			{
				printf("��class���ż������\n");
			}
			else if(numbera ==5)
			{
				printf("��flag���������\n");
			}
			printf("\n");
			printf("��������%d����Ϣ\n",count);
			printf("\n");
			printf("����������ϢС������,���Խ���� \n");

			if(findhead!=NULL)                                                                        //���ʱ���յ��������
			{
				do
				{
					printf("LinkID:%d\n",findprintfdos->LinkID);
					printf("flag:%d\n",findprintfdos->flag);
					printf("��·��:%d\n",findprintfdos->branch);
					printf("����Link�б�ʾClass����:%d\n",findprintfdos->roadclass);
					printf("��·����:%s\n",findprintfdos->name);
					printf("\n");
					countp++;
					findprintfdos=findprintfdos->next;
				}while((findprintfdos!=NULL)&&(countp<5));
			}
		}
	   
		else
		{
			printf("��������%d����Ϣ\n",count);
			printf("\n");
			if(numbera ==2)
			{
				printf("�˲�·���������\n");
			}
			else if(numbera ==4)
			{
				printf("��class���ż������\n");
			}
			else if(numbera ==5)
			{
				printf("��flag���������\n");
			}
	
			printf("\n");
			printf("����������Ϣ��������,����ִ�б������.\n");
			if(findhead!=NULL)
			{
				do
				{
					fprintf(fp,"LinkID��%d\n",findprintf->LinkID);
					fprintf(fp,"flag:%d\n",findprintf->flag);
					fprintf(fp,"��·��:%d\n",findprintf->branch);
					fprintf(fp,"����Link�б�ʾClass����:%d\n",findprintf->roadclass);
		     
					fprintf(fp,"��·����:");
					strcpy(roadname,findprintf->name);		
					fwrite(roadname,(strlen(roadname)),1,fp);
			
					fprintf(fp,"\n\n");

					findprintf=findprintf->next;
				}while(findprintf!=NULL);
			}

			printf("\n");

			if(numbera ==2)
			{
				printf("�ѽ�����������Ϣ������d:\\ResultSearchbrunch.txt�ı��ĵ���\n");
			}
			else if(numbera ==4)
			{
				printf("�ѽ�����������Ϣ������d:\\ResultSearchclass.txt�ı��ĵ���\n");
			}
			else if(numbera ==5)
			{
				printf("�ѽ�����������Ϣ������d:\\ResultSearchflag.txt�ı��ĵ���\n");
			}
		} 
	   	   
		printf("��ѡ��: \n");

		if(numbera ==2)
		{
			printf("1:�������ݲ�·������...\n");
		}
		else if(numbera ==4)
		{
            printf("1:��������class���ż���...\n");
		}
		else if(numbera ==5)
		{
            printf("1:��������flag������...\n");
		}

		printf("2:���ؼ���Ŀ¼\n");
		printf("3:������Ŀ¼\n");
		printf("���������:");
		scanf("%d",&menunow);
		if(1==menunow)
			continue;
		else if(2==menunow)
			return 2;
		else if(3==menunow)
			return 3;
		else
		{
			printf("�������!���ؼ���Ŀ¼\n");
			printf("\n");
       		return 2;
		}
	}
}

/***************************************************************************
/*����: Namefind(MAP *hn)
/*����: ���ݵ�·���Ƽ���
                1. ����Ҫ������ͷָ��
                2. ˳�����
                3. ���Һ���������� 
 /*��������:          2012-04-23
 /*����:   ����1��struct map* head  �Զ���Ľṹ������ָ�� 
 /*����ֵ: ����ֵΪ2������ ���淵�ؼ�������
           ����ֵΪ3������ ���淵��������                            
 /*����:     
*******************************************************************************/
int Namefind(MAP *hn)
{
	MAPLINK p;  
	MAPLINK findcurrent;
    MAPLINK findhead;
    MAPLINK findnew;
    MAPLINK findprintf;
    MAPLINK findprintfdos;
	int menunow;  
	char ID[20];
	int count = 0,countp = 0;
	char node[20] = {0};
	FILE *fp;
	char ar[20] = "����";
    char ab[20] = {0};
	char roadname[50];
	
	fp = fopen("d:\\ResultSearchname.txt","w+");                                               //���ݼ������ĵ�·��Ϣ�½�һ��������
    if(NULL == fp)
	{	
		 printf("�ļ���ʧ��\0");
		 exit(1);
	}
    while(1)
	{
		count = 0;	   
		countp = 0;
		strcpy(ab,ar);
		printf("������Ҫ�����ĵ�·����:");  
	   
		scanf("%s",node);
		strcat(ab,node);
		p = hn;	   
	   
	    findhead = (MAPLINK)malloc(sizeof(MAP));
	    findprintf = findhead;
	    findprintfdos = findhead;
	    findcurrent = findhead;
        findnew = findhead;

	    while(p!=NULL)
		{	
			strcpy(ID,p->name);	
		  
			if(strcmp(ID,ab) == 0)
			{	
				count++;           

				findnew->LinkID = (p->LinkID);
				findnew->flag = (p->flag);
				findnew->branch = (p->branch);
				findnew->roadclass = (p->roadclass);
				strcpy(findnew->name,(p->name));

				findcurrent->next = findnew;
	    		findnew->next = NULL;
				findcurrent = findnew;
				findnew = (MAPLINK)malloc(sizeof(struct map));
				p = p->next;
			}
			else
			{
				p=p->next;
			}
		}
	
	
		if(0==count)
		{		  	      
			printf("�޴˵�·����,��˶Ժ����¼��� \n");  	      
			printf("\n");
		}	   
		else if((0<count)&&(count<6))
		{
			printf("��������%d����Ϣ\n",count);
			printf("\n");
          
			printf("�˵�·���Ƽ������\n");
			printf("\n");
			printf("����������ϢС������,���Խ���� \n");
			if(findhead!=NULL)                                                                   //���ʱ���յ��������
			{
				do
				{
					printf("LinkID:%d\n",findprintfdos->LinkID);
					printf("flag:%d\n",findprintfdos->flag);
					printf("��·��:%d\n",findprintfdos->branch);
					printf("����Link�б�ʾClass����:%d\n",findprintfdos->roadclass);
					printf("��·����:%s\n",findprintfdos->name);
					printf("\n");
					countp++;
					findprintfdos=findprintfdos->next;
				}while((findprintfdos!=NULL)&&(countp<5));
			}
		}	   
		else
		{
			printf("��������%d����Ϣ\n",count);
			printf("\n");
		  
			printf("�˵�·���Ƽ������\n");
			printf("\n");
			printf("����������Ϣ��������,����ִ�б������.\n");

			if(findhead!=NULL)
			{
				do
				{
					fprintf(fp,"LinkID��%d\n",findprintf->LinkID);
					fprintf(fp,"flag:%d\n",findprintf->flag);
					fprintf(fp,"��·��:%d\n",findprintf->branch);
					fprintf(fp,"����Link�б�ʾClass����%d\n",findprintf->roadclass);
		     
					fprintf(fp,"��·����:");
					strcpy(roadname,findprintf->name);		
					fwrite(roadname,(strlen(roadname)),1,fp);
		
					fprintf(fp,"\n\n");

					findprintf=findprintf->next;
				}while(findprintf!=NULL);	
			}

			printf("\n");
			printf("�ѽ�����������Ϣ������d:\\ResultSearchname.txt�ı��ĵ���\n");
		} 

		printf("��ѡ��: \n");
		printf("1:�������ݵ�·���Ƽ���...\n");
		printf("2:���ؼ���Ŀ¼\n");
		printf("3:������Ŀ¼\n");
		printf("���������:");
		scanf("%d",&menunow);
		if(1==menunow)
			continue;
		else if(2==menunow)
			return 2;
		else if(3==menunow)
			return 3;
		else
		{
			printf("�������!���ؼ���Ŀ¼\n");
			printf("\n");
       		return 2;
		}
	}
}






















