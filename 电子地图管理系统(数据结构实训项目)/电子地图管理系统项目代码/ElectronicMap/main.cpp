/******************************************************************************************
*FunctionName:Main                                                                        *
*                                                                                         *
*Description:����������ϵͳ����ڣ��Ը���ģ�麯�����е���                                 *
*                                                                                         *
*MakingDate:2019/7/17                                                                     *
*                                                                                         *
*Maker:������                                                                             *
******************************************************************************************/


#include<stdio.h>
#include<io.h>
#include<cstdlib>
#include<iostream>
#include "header.h"     //����headerͷ�ļ�

using namespace std;

ElecMap eMap;      //����һ���ṹ���Ա����

int main()
{
    int choose=1;
    eMap.roadNum=0;      //��ʼ����·����
    eMap.roadSort=0;      //��ʼ����·δ����
    cout<<endl;
    cout<<"/**********************---Welcome!---**********************\n";
    cout<<"/***\t\t���ӵ�ͼ��Ϣͳ��ϵͳ\t\t\t***/\n";
    cout<<"/***\t\t\t\t������ 2019��7��17��\t" "" "" "" "***/\n";
    cout<<"/**********************************************************\n";

    while(choose)
    {
    	cout<<"\n��ѡ���������:\n";
        cout<<"\t1.��ȡ�ļ�(��./data/GTBL.dat��)\n\t2.����(��������)�����������(��./data/GTBL.dat��)\n\t3.����\n\t0.�˳�\n";
        cout<<"��ѡ��:";
        fflush(stdin);     //ǿ�ƽ��������е�����д���ļ�
        cin>>choose;
        switch(choose)
        {
           case 1:
               ReadFile(&eMap);       //ѡ��1ʱ���ж������ļ���ȡ
               break;
           case 2:
               TotalSort(&eMap);         //ѡ��2ʱ���Ѵ����ı��ļ����е�·����
               break;
           case 3:
               Search(&eMap);            //ѡ��3ʱ���е�·����
               break;
           case 0:                         //ѡ��0ʱ�˳�ϵͳ
               break;
           default:
             cout<<"��������!������ѡ��!\n";
        }
    }
    cout<<"\n......\n......\n\n�ɹ��˳����ӵ�ͼ��Ϣͳ��ϵͳ!��л��ʹ�ñ�����!\n";

    return 0;
}

