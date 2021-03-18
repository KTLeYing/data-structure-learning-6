/**************************************************/
/*���ƣ�QuickSort
/*��������������Ϣ��LINK ID����С����˳���������
/*�������ڣ� 12/05/01 
/*���ߣ�
/***************************************************/
#include"struct.h"
#include<stdio.h>

/**************************************************/
/*���ƣ�BSort
/*���������ÿ������򷨽�������,�Ѵ������������Ϊ2��������ѡ������ĵ�һ���ڵ���Ϊ��׼��Ȼ����бȽϣ�
        �Ȼ�׼��ڵ�ķ���������������Ȼ�׼��ķ����ұߵ��������ڶԴ���������ɨ��һ��֮������������
		�Ľڵ�ֵ��С�ڻ�׼��ֵ���ұ��������ֵ�����ڻ�׼��ֵ��Ȼ��ѻ�׼���뵽�����У�����Ϊ��������������
		��������Ȼ����������������нڵ�����ѡ���С�Ľ��еݹ�������򣬶�����Ŀ�϶������е��ȴ�������
		������ܡ�
/*�������ڣ�12/05/01 
/*����ֵ��VOID
/*���ߣ�
/***************************************************/
void QListSort(MAPLINK *head,MAPLINK end) 
{  
	MAPLINK right;                    /*�ұ�������ĵ�һ���ڵ�*/
    MAPLINK *left_walk, *right_walk;  /*��Ϊָ�룬����ָ��Ľڵ���뵽��Ӧ����������*/
    MAPLINK pivot, old;               /*pivotΪ��׼, oldΪѭ�����������������ָ��*/
    int count, left_count, right_count;  

    if (*head == end)  
        return;  
    do
	{  
        pivot = *head;     
        left_walk = head;     
        right_walk = &right;  
        left_count = right_count = 0;  
       
		/*ȡ��һ���ڵ���Ϊ�ȽϵĻ�׼��С�ڻ�׼�����������������,���ڻ�׼�����ұߵ���������*/ 
        for(old = (*head)->next; old != end; old = old->next)
		{  
            if (old->LinkID < pivot->LinkID) 
			{                                 /*С�ڻ�׼,���뵽�����������,�����Ƚ�*/   
                ++left_count;  
                *left_walk = old;              /*�Ѹýڵ���뵽��ߵ�������*/    
               left_walk = &(old->next);  
            } 
			else 
			{                         /*���ڻ�׼,���뵽�ұߵ������������Ƚ� */  
                ++right_count;  
                *right_walk = old;             
                right_walk = &(old->next);  
            }  
        }  

       /*�ϲ����� */  
        *right_walk = end;       /*���������� */   
        *left_walk = pivot;      /*�ѻ�׼������ȷ��λ���� */   
        pivot->next = right;     /*������ϲ� */   

        /*�Խ�С����������п����򣬽ϴ����������е�������*/   
        if(left_walk > right_walk) 
		{  
			QListSort(&(pivot->next), end);  
            end = pivot;  
            count = left_count;  
        }
		else 
		{  
            QListSort(head, pivot);  
            head = &(pivot->next);  
            count = right_count;  
        }  
	} 
	while (count > 1); 
}  
