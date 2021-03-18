/********************************************************************************************
* 文件名称:	readf.c																	    	*	
* 作成日期:	12/04/24																	    * 
* 作者:																					*
* 样式:		供用户选择服务																	*
* 描述:	    有两种读取地图信息文件的方式													*
				1:读取系统默认地图信息文件													*
				2:读取用户地图信息文件														*
            																				*
*********************************************************************************************/
#include<stdio.h>
#include<BASETSD.H>
#include"struct.h"
#include"readfile.h"
#include"readnewfile.h"

/***************************************************************************
函数名称: MAPLINK readfile(MAPLINK *Head)
描述:   按照一定规则读取地图信息文件，并创建单链表
                1、 读取地图信息文件
				   1:读取道路ID存入roadID; 
				   2:读取道路信息数据存入uiinfo;
				   3:将道路信息数据uiinfo利用宏定义取出道路有无flag;
				   4:将道路信息数据uiinfo利用宏定义取出道路brunch;
				   5:将道路信息数据uiinfo利用宏定义取出道路番号class;
				   6:读取道路名称存入roadname[]数组中
                2、 创建单链表
				   1:创建单链表结点
				   2:将新创建的单链表结点联入单链表中
作成日期:     12/04/23
参数:        名称:userchoose 类型:int 存储用户选项

输入:        H: 保存了单链表的头结点指针的指针               
输出:        用户提示信息
返回值:      VOID   
                            
作者:    
*******************************************************************************/
void readf(MAPLINK *head)
{
	int userchoose;

	printf("          1、读取系统地图信息文件\n");
	printf("          2、读取其他地图信息文件\n");
	printf("         请选择：");

	scanf("%d", &userchoose);
//  通过用户选择进行函数调用
	switch(userchoose)
	{
	case 1:
		printf("\n");
		printf(" /****************************************************************************\\ \n");
		readfile(head);
		break;
	case 2:
		printf("\n");
		printf(" /****************************************************************************\\ \n");
		readnewfile(head);
		break;
	default :
		printf("无此项服务，请重新输入：\n");
		readf(head);
	}

}