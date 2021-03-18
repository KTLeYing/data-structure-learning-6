/******************************************************************************************
*FunctionName:Header                                                                      *
*                                                                                         *
*Description:��ͷ�ļ��ﶨ������ĺꡢ�ṹ��ͺ���                                         *
*                                                                                         *
*MakingDate:2019/7/17                                                                     *
*                                                                                         *
*Maker:������                                                                             *
******************************************************************************************/


#ifndef HEADER_H_INCLUDED      //�ظ��������ظ����壩
#define HEADER_H_INCLUDED

#define MAXSIZE 64000         //�궨����������ֵ��MAXSIZE


typedef struct RoadRecord          //�ṹ��RoadRecord����·��¼���洢·��8����Ϣ��8����Ա������
{
    unsigned short int recordSize;      //��¼�Ĵ�С
    unsigned int LinkID;                 //��·��ID
    unsigned int roadInfo;                 //��·��Ϣ
    unsigned short roadNameLen;            //��·���ֵĳ���
    char roadName[30];                     //����洢��·����ֻ�������ֳ��Ȳ���30��

    unsigned int disclass;             //������Ϣ
    unsigned int brunch;                 //��֧
    int flag;                            //��flag��ʾ��·�Ƿ������ƣ�1�����У�0�����ޣ�
}RoadRecord;

typedef struct ElecMap           //�ṹ��ElecMap�洢ȫ����·����Ϣ��3����Ա��������������·��¼��Ϣ��·�������͵�·�Ƿ�����õı�־
{
    RoadRecord roadRecord[MAXSIZE];      //�ṹ������洢��·�ļ�¼��Ϣ��������������洢�ռ�Ϊ6400
    int roadNum,roadSort;               //roadNum��ʾ��·��������roadSort��ʾ�Ƿ�����ã�1����������0����δ����
}ElecMap;

#define M_CHG_INT16(__data__) ((__data__>>8)|(__data__<<8))          //��ת�����ε�16λ������
#define M_CHG_INT32(__data__) ((__data__>>24)|((__data__&0xff0000)>>8)|((__data__&0xff00)<<8)|(__data__<<24))
//��ת�����͵�16������
#define GET_FLAG(__data__) ((__data__&0x80)>>7)               //��ȡ�Ƿ��е�·����
#define GET_BRUNCH(__data__) ((__data__&0x70)>>4)            //��ȡ��֧��
#define GET_DISPCLASS(__data__) (__data__&0x0f)                    //��ȡ�����


//�Ѻ��溯��ģ����Ҫ�õ��ĺ�����ͷ�ļ��ﶨ��һ��
int ReadFile(ElecMap *eMap);     //��ȡ�������ļ�����ת���洢���ı��ĵ���
int TotalSort(ElecMap *eMap);      //����
int Search(ElecMap *eMap);       //����

int Sort(ElecMap *eMap);
int QSort(ElecMap *eMap,int left,int high);      //��������
int Partition(ElecMap *eMap,int left,int high);     //����һ�������ҵ�����������λ��
int BubbleSort(ElecMap *eMap);           //ð������
int DirectInsertSort(ElecMap *eMap);       //ֱ�Ӳ�������
int BinarySort(ElecMap *eMap);               //��������
int SimpleElectSort(ElecMap *eMap);             //��ѡ������
int ToWriteSort(ElecMap *eMap);                    //������õĵ�·��Ϣд���ı��ĵ���

int BinarySearch_LinkID(ElecMap *eMap);         //�ö�������Ե�·LinkID���м���
int LinearSearch_RoadName(ElecMap *eMap);     //��ֱ�Ӳ��������·�����м���
int LinearSearch_RoadBrunchNum(ElecMap *eMap,int key);       //��ֱ�Ӳ�������Ե�·��֧�����м���
int LinearSearch_Class(ElecMap *eMap,int key);               //��ֱ�Ӳ�������Է��Ž��м���


#endif HEADER_H_INCLUDED

