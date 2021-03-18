/******************************************************************************************
*FunctionName:ReadFile                                                                    *
*                                                                                         *
*Description:��ȡ�������ļ��������洢���ı��ĵ���                                         *
*                                                                                         *
*MakingDate:2019/7/19                                                                     *
*                                                                                         *
*Maker:������                                                                             *
******************************************************************************************/


#include<stdio.h>
#include<iostream>
#include<io.h>
#include<fstream>
#include<cstdlib>
#include<string.h>        //����string������

#include "header.h"          //����headerͷ�ļ�

using namespace std;

#define ERROR 0

int ReadFile(ElecMap *eMap)
{
    FILE *fp,*fileWrite;     //����ָ��FILE�ṹ��ָ�����*pf��fileWrite
    int roadNum=0;               //��ʼ����·����Ϊ0
    unsigned short e_recordSize;       //ʹ��ȫ�ֱ����Ľṹ�������������
    unsigned int e_LinkID;
    unsigned short e_roadNameLen;
    unsigned int e_roadInfo;              //��·��Ϣ
    char e_roadName[30];            //����洢��·����

    unsigned int e_disclass;      //����
    unsigned int e_brunch;       //��֧
    int e_flag;                   //��־

    if((fp=fopen("GTBL.dat","rb"))==NULL)      //�ж�GTBL�ļ��Ƿ�Ϊ�գ���Ϊ�����ʧ��
    {
       cout<<"�ļ���ʧ��!\n";
       exit(0);
    }
    cout<<"�ļ��򿪳ɹ�!\n";                    //�ļ����ܿգ���ɹ����ļ�������ȡ�������ļ�

    fileWrite=fopen("Map.txt","w+");         //�ļ�ָ��fileWriteָ��Ҫ�洢��ȥ��Ŀ���ı��ļ�����д���ı��ļ���
    cout<<"�ļ���ȡ��......\n";
    while(1)
    {
        fread(&e_recordSize,2,1,fp);    //��ȡһ��short int��2���ֽڣ��ĵ�·��¼��С����ȡ��ַ
        if(feof(fp))                                  //�����ȡ���������ļ��Ľ�βʱ��������ȡ
            break;
        fread(&e_LinkID,4,1,fp);          //��ȡһ��long��4���ֽڣ��ĵ�·LinkID����ȡ���ַ
        fread(&e_roadNameLen,2,1,fp);            //��ȡһ��short int��2���ֽڣ���·���ֵĳ��ȣ���ȡ���ַ
        fread(&e_roadInfo,4,1,fp);                  //��ȡһ��long��4���ֽڣ���·��Ϣ����ȡ���ַ

        e_recordSize=M_CHG_INT16(e_recordSize);                    //���ú귴ת�����͵�16λ�����룬��ת��·��¼��С
        e_LinkID=M_CHG_INT32(e_LinkID);                          //���ú귴ת�����͵�32λ�����룬��תLinkID
        e_roadNameLen=M_CHG_INT16(e_roadNameLen);               //���ú귴ת�����͵�16λ�����룬��ת��·���ĳ���
        e_roadInfo=M_CHG_INT32(e_roadInfo);                     //���ú귴ת�����͵�32λ�����룬��ת��·��Ϣ

        e_flag=GET_FLAG(e_roadInfo);                      //��ȡ������޵�·���Ƶ�flag
        e_brunch=GET_BRUNCH(e_roadInfo);                  //��ȡ��·��֧����
        e_disclass=GET_DISPCLASS(e_roadInfo);               //��ȡ��·����

        if(e_recordSize>12)                        //�����¼��С����12��ǰ�����õ��ڴ棩���������ڴ���·��������ȡ��·��
        {
            fread(e_roadName,e_recordSize-12,1,fp);  //roadName��һ�����飬���ǵ�ַ����������ȡַ���š�&��
            strcpy(eMap->roadRecord[eMap->roadNum].roadName,e_roadName);     //�Ѷ������ı��ĵ�·���Ƹ��ƽṹ������ĵ�·�����½����ı���
        }
        eMap->roadRecord[eMap->roadNum].recordSize=e_recordSize;             //�ѻ�ȡ�ļ�¼��С��ֵ���ṹ������ļ�¼��С
        eMap->roadRecord[eMap->roadNum].LinkID=e_LinkID;          //�ѻ�ȡ��LinkID��ֵ���ṹ������LinkID
        eMap->roadRecord[eMap->roadNum].roadInfo=e_roadInfo;         //�ѻ�ȡ�ĵ�·��Ϣ��ֵ���ṹ������ĵ�·��Ϣ

        eMap->roadRecord[eMap->roadNum].brunch=e_brunch;           //�ѻ�ȡ���ķ�֧���ṹ������ķ�֧
        eMap->roadRecord[eMap->roadNum].disclass=e_disclass;        //�ѻ�ȡ���ķ��Ÿ��ṹ������ķ���
        eMap->roadRecord[eMap->roadNum].flag=e_flag;                //�ѻ�ȡ���ĵ�·��־���ṹ������ĵ�·��־


        fprintf(fileWrite,"%d\t��Ϣ��С:%d\tLinkID:%d\t����Flag:%d\t�ֲ�·��:%d\t����:%d\t",  //�ѻ�ȡ��һ����·�ĸ�����Ϣд��ȥ�ı��ĵ���
                eMap->roadNum+1,e_recordSize,e_LinkID,e_flag,e_brunch,e_disclass);
        if(e_recordSize>12)                         //�����¼��С����12�����пռ�洢��·���ƣ�
           fprintf(fileWrite,"��·����:%s\n",e_roadName);            //�ѻ�ȡ�ĵ�·��д���ļ�
        else
            fprintf(fileWrite,"�޵�·����\n");                  //�����¼��СС�ڴ���12�������ڴ�ռ�洢��·��
        eMap->roadNum++;                        //ѭ��һ�Σ�д��һ����·����·������1�����ṹ������������1��
    }
    cout<<"��ȡ��¼һ��Ϊ:"<<eMap->roadNum<<endl;     //�����·������

    fclose(fp);             //�ر��ļ�
    cout<<"�ļ���ȡ�ɹ�!\n";
    return 0;
}





