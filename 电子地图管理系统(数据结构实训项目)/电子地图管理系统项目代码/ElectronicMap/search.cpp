/******************************************************************************************
*FunctionName:Search                                                                      *
*                                                                                         *
*Description:�����������Ļ����Ͻ��в�ͬ��ʽ�ļ���                                       *
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

int BinarySearch_LinkID(ElecMap *eMap)      //��LinkID���ж��ֲ���
{

     int key,mid;
     cout<<"������Ҫ������Link��ID:";
     cin>>key;
     int low=1,high=eMap->roadNum;
     while(low<=high)
     {
         mid=(low+high)/2;
         if(key==eMap->roadRecord[mid].LinkID)
         {
         	cout<<"��ѯ���Ϊ:\n";
                   cout<<"**************************************************************************\n";
                   cout<<"#linkid="<<eMap->roadRecord[mid].LinkID<<";roadflag="<<eMap->roadRecord[mid].flag
                   <<";brunch="<<eMap->roadRecord[mid].brunch<<";disclass="<<eMap->roadRecord[mid].disclass
                   <<";roadName="<<eMap->roadRecord[mid].roadName<<"#\n";
                   cout<<"**************************************************************************\n";
            break;
          }
         else
            if(key<eMap->roadRecord[mid].LinkID)
                high=mid-1;
            else
                if(key>eMap->roadRecord[mid].LinkID)
                    low=mid+1;
     }
}

int SqSearch_RoadName(ElecMap *eMap)           //��·������˳�����
{
     FILE *pf;
     pf=fopen("searchroadnameresult.txt","w+");
     char r_name[30];
     cout<<"������Ҫ������·��:";
     cin>>r_name;
     int sum=0,i;
     for(i=eMap->roadNum;i>=1;i--)
        if(strcmp(eMap->roadRecord[i].roadName,r_name)==0)
           sum++;
     if(sum==0)
        cout<<"û�и����ֵĵ�·\n";
     else
        if(sum<5)
       {
            cout<<"��ѯ���Ϊ:(���С��5����ֱ�����)\n";
            for(i=eMap->roadNum;i>=1;i--)
              if(strcmp(eMap->roadRecord[i].roadName,r_name)==0)
               {
                    cout<<"**************************************************************************\n";
                    cout<<"#linkid="<<eMap->roadRecord[i].LinkID<<";roadflag="<<eMap->roadRecord[i].flag
                    <<";brunch="<<eMap->roadRecord[i].brunch<<";disclass="<<eMap->roadRecord[i].disclass
                    <<";roadName="<<eMap->roadRecord[i].roadName<<"#\n";
                    cout<<"**************************************************************************\n";
               }
       }
       else
          if(sum>=5)
          {
               cout<<"**************************************************************************\n";
               cout<<"\t�������5�����ѽ���ת�浽�ı��ļ�D:\\searchroadnameresult.txt\n";
               cout<<"**************************************************************************\n";
               for(i=eMap->roadNum;i>=1;i--)
                  if(strcmp(eMap->roadRecord[i].roadName,r_name)==0)
                  {
                      fprintf(pf,"linkid=%d\troadflag=%d\tbrunch=%d\t\tdisclass=%d\troadName=%s\n",eMap->roadRecord[i].LinkID,
                      eMap->roadRecord[i].flag,eMap->roadRecord[i].brunch,eMap->roadRecord[i].disclass,
                      eMap->roadRecord[i].roadName);
                  }
          }
     return 0;
}


int  SqSearch_RoadBrunchNum(ElecMap *eMap)       //�÷�֧������˳�����
{
    FILE *pf;
    pf=fopen("searchbrunchresult.txt","w+");
    int sum=0,i,key;
    cout<<"������Ҫ������·�ķ�֧��:";
    cin>>key;
    for(i=eMap->roadNum;i>=1;i--)
        if(eMap->roadRecord[i].brunch==key)
            sum++;
    if(sum==0)
        cout<<"û�иò�·���ĵ�·!\n";
    else
        if(sum<5)
        {
            cout<<"��ѯ���Ϊ:(���С��5����ֱ�����)\n";
            for(i=eMap->roadNum;i>=1;i--)
               if(eMap->roadRecord[i].brunch==key)
               {
                   cout<<"**************************************************************************\n";
                   cout<<"#linkid="<<eMap->roadRecord[i].LinkID<<";roadflag="<<eMap->roadRecord[i].flag
                   <<";brunch="<<eMap->roadRecord[i].brunch<<";disclass="<<eMap->roadRecord[i].disclass
                   <<";roadName="<<eMap->roadRecord[i].roadName<<"#\n";
                   cout<<"**************************************************************************\n";
               }
        }
        else
            if(sum>=5)
            {
                cout<<"**************************************************************************\n";
                cout<<"\t�������5�����ѽ���ת�浽�ı��ļ�D:\\searchbrunchresult.txt\n";
                cout<<"**************************************************************************\n";
                for(i=eMap->roadNum;i>=1;i--)
                   if(eMap->roadRecord[i].brunch==key)
                   {
                      fprintf(pf,"linkid=%d\troadflag=%d\tbrunch=%d\t\tdisclass=%d\troadName=%s\n",eMap->roadRecord[i].LinkID,
                      eMap->roadRecord[i].flag,eMap->roadRecord[i].brunch,eMap->roadRecord[i].disclass,
                      eMap->roadRecord[i].roadName);
                   }
            }
     return 0;
}

int SqSearch_Class(ElecMap *eMap)       //�÷��Ž���˳�����
{
    FILE *pf;
    pf=fopen("searchclassinforesult.txt","w+");
    int sum=0,i,key;
    cout<<"������Ҫ�����ķ���:";
    cin>>key;
    for(i=eMap->roadNum;i>=1;i--)
        if(eMap->roadRecord[i].disclass==key)
            sum++;
    if(sum==0)
        cout<<"û�и÷��ŵĵ�·!\n";
    else
        if(sum<5)
        {
            cout<<"��ѯ���Ϊ:(���С��5����ֱ�����)\n";
            for(i=eMap->roadNum;i>=1;i--)
               if(eMap->roadRecord[i].disclass==key)
               {
                   cout<<"**************************************************************************\n";
                   cout<<"#linkid="<<eMap->roadRecord[i].LinkID<<";roadflag="<<eMap->roadRecord[i].flag
                   <<";brunch="<<eMap->roadRecord[i].brunch<<";disclass="<<eMap->roadRecord[i].disclass
                   <<";roadName="<<eMap->roadRecord[i].roadName<<"#\n";
                   cout<<"**************************************************************************\n";
               }
        }
        else
            if(sum>=5)
            {
                cout<<"**************************************************************************\n";
                cout<<"\t�������5�����ѽ���ת�浽�ı��ļ�D:\\searchclassinforesult.txt\n";
                cout<<"**************************************************************************\n";
                for(i=eMap->roadNum;i>=1;i--)
                   if(eMap->roadRecord[i].disclass==key)
                   {
                      fprintf(pf,"linkid=%d\troadflag=%d\tbrunch=%d\t\tdisclass=%d\troadName=%s\n",eMap->roadRecord[i].LinkID,
                      eMap->roadRecord[i].flag,eMap->roadRecord[i].brunch,eMap->roadRecord[i].disclass,
                      eMap->roadRecord[i].roadName);
                   }
            }
    return 0;

}

int Search(ElecMap *eMap)       //���в��ҷ�ʽ�Ļ㼯��ѡ���Լ���Ҫ�ļ�����ʽ���м���
{
    int choose=1,key;
    char name[30];
    cout<<"������ʽ����:\n";
    cout<<"\t1.ָ��LinkID ����\n\t2.ָ����·���� ����\n\t3.���Ҳ�·�� ����\n\t4.ָ���Ľ���Link�б�ʾClass���� ����\n\t0.����\n";
    while(choose)
    {
        cout<<"\n��ѡ�������ʽ:";
        cin>>choose;
        switch(choose)
        {
           case 1:                        //ѡ1��LinkID�����۰����
             BinarySearch_LinkID(eMap);
             break;
           case 2:                         //ѡ2��·������˳�����
             SqSearch_RoadName(eMap);
             break;
           case 3:                          //ѡ3�÷�֧������˳�����
             SqSearch_RoadBrunchNum(eMap);
             break;
           case 4:                          //ѡ4�÷��Ž���˳�����
             SqSearch_Class(eMap);
             break;
           case 0:                       //ѡ0�˳�����
               cout<<"�˳�����!\n";
               break;
           default:
             cout<<"��������!������ѡ��!\n";
        }
    }
}

