/******************************************************************************************
*FunctionName:Sort                                                                        *
*                                                                                         *
*Description:������ɶ�ȡ�ʹ洢�Ķ������ļ��Ļ����ϣ����ı��е��������ݽ�������           *
*                                                                                         *
*MakingDate:2019/7/20                                                                     *
*                                                                                         *
*Maker:������                                                                             *
******************************************************************************************/


#include<stdio.h>
#include<io.h>
#include<iostream>
#include<cstdlib>
#include<string.h>
#include "header.h"        //����ͷ�ļ�

using namespace std;

int Partition(ElecMap *eMap,int low,int high)           //����һ�������ҵ�����������λ��
{
    int pivot;
    eMap->roadRecord[0]=eMap->roadRecord[low];
    pivot=eMap->roadRecord[low].LinkID;
    while(low<high)
    {
        while(low<high && eMap->roadRecord[high].LinkID>=pivot)
            --high;
        eMap->roadRecord[low]=eMap->roadRecord[high];
        while(low<high && eMap->roadRecord[low].LinkID<=pivot)
            ++low;
        eMap->roadRecord[high]=eMap->roadRecord[low];
    }
    eMap->roadRecord[low]=eMap->roadRecord[0];
    return low;                //��������λ��
}

int QSort(ElecMap *eMap,int low,int high)        //��������
{
    int pivot;
    if(low<high)
    {
        pivot=Partition(eMap,low,high);
        QSort(eMap,low,pivot-1);
        QSort(eMap,pivot+1,high);
    }
}

int Sort(ElecMap *eMap)                    //������ɶ�ȡ�������ı��ĵ��ĵ�·��Ϣ��������
{
     if(eMap->roadNum==0)
        cout<<"���Ƚ��ж������ļ��Ķ�ȡ!";

     if(eMap->roadSort==1)
        cout<<"��·���������!\n";
     else
        if(eMap->roadSort==0)
        {
            cout<<"Sort start(Using LinkID to QuickSort)......\n";
            QSort(eMap,1,eMap->roadNum);
            ToWriteSort(eMap);
            cout<<"\nSort success!\n\n";
        }

}


int BubbleSort(ElecMap *eMap)            //ð������
{
	int i,n=eMap->roadNum-1;
    RoadRecord temp;
	if(eMap->roadNum==0)
        cout<<"���Ƚ��ж������ļ��Ķ�ȡ!";

    if(eMap->roadSort==1)
        cout<<"��·���������!\n";
    else
        if(eMap->roadSort==0)
        {
        	  cout<<"Sort start(Using LinkID to BubbleSort)......\n";
              while(n>0)
              {
                  for(i=1;i<=n;i++)
                  {
                      if(eMap->roadRecord[i].LinkID>eMap->roadRecord[i+1].LinkID)
                      {
                          temp=eMap->roadRecord[i];
                          eMap->roadRecord[i]=eMap->roadRecord[i+1];
                          eMap->roadRecord[i+1]=temp;
                      }
                  }
                  n--;
              }

              ToWriteSort(eMap);              //������������д���ı��ļ�
              cout<<"\nSort success!\n\n";
        }
}

int DirectInsertSort(ElecMap *eMap)               //ֱ�Ӳ�������
{
    int i,j;
    if(eMap->roadNum==0)
        cout<<"���Ƚ��ж������ļ��Ķ�ȡ!";

    if(eMap->roadSort==1)
        cout<<"��·���������!\n";
    else
        if(eMap->roadSort==0)
        {
        	  cout<<"Sort start(Using LinkID to DirectInsertSort)......\n";
        	  for(i=2;i<=eMap->roadNum;i++)
                  if(eMap->roadRecord[i].LinkID<eMap->roadRecord[i-1].LinkID)
                  {
                      eMap->roadRecord[0]=eMap->roadRecord[i];
                      eMap->roadRecord[i]=eMap->roadRecord[i-1];
                      for(j=i-2;eMap->roadRecord[0].LinkID<eMap->roadRecord[j].LinkID;j--)
                      eMap->roadRecord[j+1]=eMap->roadRecord[j];
                      eMap->roadRecord[j+1]=eMap->roadRecord[0];
                  }

               ToWriteSort(eMap);           //������������д���ı��ļ�
               cout<<"\nSort success!\n\n";
        }
}

int BinarySort(ElecMap *eMap)               //�۰�����
{
    int i,j,low,high,mid;
    if(eMap->roadNum==0)
        cout<<"���Ƚ��ж������ļ��Ķ�ȡ!";

    if(eMap->roadSort==1)
        cout<<"��·���������!\n";
    else
        if(eMap->roadSort==0)
        {
        	  cout<<"Sort start(Using LinkID to BinarySort)......\n";
        	  for(i=2;i<=eMap->roadNum;i++)
              {
                   eMap->roadRecord[0]=eMap->roadRecord[i];
                   low=1;
                   high=i-1;
                   while(low<=high)
                   {
                      mid=(low+high)/2;
                      if(eMap->roadRecord[0].LinkID<eMap->roadRecord[mid].LinkID)
                          high=mid-1;
                      else
                         low=mid+1;
                   }
                   for(j=i-1;j>=high+1;--j)
                       eMap->roadRecord[j+1]=eMap->roadRecord[j];
                   eMap->roadRecord[high+1]=eMap->roadRecord[0];
              }
              ToWriteSort(eMap);                      //������������д���ı��ļ�
              cout<<"\nSort success!\n\n";
        }
}


int SimpleElectSort(ElecMap *eMap)
{
	 int i,j,k;
     RoadRecord t;
     if(eMap->roadNum==0)
        cout<<"���Ƚ��ж������ļ��Ķ�ȡ!";

     if(eMap->roadSort==1)
        cout<<"��·���������!\n";
     else
        if(eMap->roadSort==0)
        {
        	  cout<<"Sort start(Using LinkID to SimpleElectSort)......\n";
        	  for(i=1;i<eMap->roadNum;i++)
              {
                  k=i;
                  for(j=i+1;j<=eMap->roadNum;j++)
                      if(eMap->roadRecord[j].LinkID<eMap->roadRecord[k].LinkID)
                         k=j;
                      if(k!=i)
                      {
                          t=eMap->roadRecord[i];
                          eMap->roadRecord[i]=eMap->roadRecord[k];
                          eMap->roadRecord[k]=t;
                      }
             }

			 ToWriteSort(eMap);              //������������д���ı��ļ�
             cout<<"\nSort success!\n\n";
        }
}


int ToWriteSort(ElecMap *e_eMap)               //������õĵ�·��Ϣд����һ���ı��ļ���
{
    FILE *fileWrite;                 //����ָ��FILE�ṹ��ָ�����fileWrite
    int  i=1;
    fileWrite=fopen("sortedresult.txt","w+");        //�ļ�ָ��ָ��Ŀ���ı��ļ�

    while(i<=e_eMap->roadNum)                 //�жϽṹ�������Ƿ�Ϊ�գ����ı��ļ��Ƿ��Ŀգ�
    {
        fprintf(fileWrite,"��Ϣ��С:%d\tLinkID:%d\t����Flag:%d\t�ֲ�·��:%d\t����:%d\t",e_eMap->roadRecord[i].recordSize,e_eMap->roadRecord[i].LinkID,
		e_eMap->roadRecord[i].flag,e_eMap->roadRecord[i].brunch,e_eMap->roadRecord[i].disclass);

        if(e_eMap->roadRecord[i].recordSize>12)
           fprintf(fileWrite,"��·����:%s\n",e_eMap->roadRecord[i].roadName);
        else
            fprintf(fileWrite,"�޵�·����\n");
        i++;
        fprintf(fileWrite,"\n\n\n");
    }
     cout<<"�������ѳɹ��洢���ı��ļ�!";
     return 0;

}


int TotalSort(ElecMap *eMap)            //���Ե�����ʽ�Ļ㼯��ѡ���Լ���Ҫ������ʽ��������
{
	int choose=1;
	cout<<"����ʽ����:\n";
	cout<<"\t1.��������\n\t2.ð������\n\t3.ֱ�Ӳ�������\n\t4.�۰�����\n\t5.��ѡ������\n\t0.����\n\n";
	while(choose)
	{
		cout<<"��ѡ������ʽ:";
		cin>>choose;
		switch(choose)
		{
			case 1:             //ѡ1��������
			  Sort(eMap);
			  break;
			case 2:
			  BubbleSort(eMap);       //ѡ2ð������
			  break;
			case 3:
			  DirectInsertSort(eMap);      //ѡ3ֱ�Ӳ�������
			  break;
			case 4:
			  BinarySort(eMap);           //ѡ4�۰�����
			  break;
			case 5:
			  SimpleElectSort(eMap);       //ѡ5��ѡ������
			  break;
			case 0:
				cout<<"�˳�����!\n";         //ѡ0�˳�����
				break;
			default:
				cout<<"�����д�������ѡ��!\n\n";
		}
	}
}






