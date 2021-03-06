/********************************************************************************************
* 文件名称:	Electronic.c																	*	
* 作成日期:	12/04/23																	    * 
* 作者:																					*
* 样式:		界面																			*
* 描述:	    整个系统的界面显示																*
* 修改日期  12/05/01						                                            	*
*********************************************************************************************/

#include<stdio.h>
#include<windows.h>
#include"struct.h"
#include"Update.h"
#include"searchfind.h"
#include"sort.h"
#include"readf.h"
#include"myexit.h"

void Choose();
void PrintEndFunction();
void PrintHeadFunction();
/***************************************************************************
函数名称: void Choose(MAPLINK *H)
描述:   在主菜单中选择功能
                1、 输入选择的数字
				   1:载入地图信息文件; 
				   2:将单链表排序;
				   3:检索功能;
				   4:对地图信息文件进行更新;
				   5:退出本系统;
                2. 每个选项调用对应的功能函数
作成日期:     12/04/23
参数:        名称:userchoose 类型:int 输入参数
输入:        H: 单链表的头结点指针               
输出:        系统提示
返回值:      无返回值   
                            
作者:    
修改日期  12/05/01
*******************************************************************************/
void Choose(MAPLINK *H)
{
	int userchoose;
	scanf("%d", &userchoose);
		switch(userchoose)
		{
		case 1:
			printf("\n");
			printf(" /****************************************************************************\\ \n");
			readf(H);
			PrintEndFunction();
			Choose(H);
			break;
		case 2:
			if(*H == NULL)
			{
				printf("               请先载入地图信息文件！\n");
				printf("               请选择：");
				Choose(H);
			}
			printf("\n");
			printf(" /****************************************************************************\\ \n");
			Msort(H);
			PrintEndFunction();
			Choose(H);
			break;
		case 3:
			if(*H == NULL)
			{
				printf("               请先载入地图信息文件！\n");
				printf("               请选择：");
				Choose(H);
			}
			printf("\n");
			printf(" /****************************************************************************\\ \n");
     		search(*H);
			break;
		case 4:
			if(*H == NULL)
			{
				printf("               请先载入地图信息文件！\n");
				printf("               请选择：");
				Choose(H);
			}
			printf("\n");
			printf(" /****************************************************************************\\ \n");
			update(*H);
			printf("\n\n\n\n\n\n");
			PrintEndFunction();
			Choose(H);
			break;
		case 5:
			myexit();
			break;
		default :
			printf("无此项服务，请重新输入：");
			Choose(H);
		}
}
/***************************************************************************
函数名称: void PrintEndFunction()
描述:   在屏幕上打印服务的种类
			   1:读取地图信息文件; 
			   2:排序并输出排序结果;
			   3:检索道路信息;
			   4:更新（插入信息，删除信息等）;
			   5:退出本系统;
作成日期:     12/04/23
参数:        VOID
输入:        VOID              
输出:        用户提示信息
返回值:      无返回值   
                            
作者:    
*******************************************************************************/

void PrintEndFunction()
{
	printf("          请选择服务的种类：\n");
	printf("                1、读取地图信息文件\n");
	printf("                2、排序并输出排序结果\n");
	printf("                3、检索道路信息\n");
	printf("                4、更新（插入信息，删除信息等）\n");
	printf("                5、退出本系统\n");
	printf("           请选择：");
}
/***************************************************************************
函数名称: void PrintHeadFunction()
描述:   在屏幕上打印信息
作成日期:     12/04/23
参数:        VOID
输入:        VOID              
输出:        用户提示信息
返回值:      无返回值   
                            
作者:    
*******************************************************************************/

void PrintHeadFunction()
{
	// Show the information of the system.
	printf("/************************ 欢迎使用! Welcome to use! *************************/\n");
	printf("/*****                                                                  *****/\n");
	printf("/*****                                                                  *****/\n");
	printf("/*****                     电子地图数据管理系统                         *****/\n");
	printf("/*****              Electronic Map Date Management System               *****/\n");
	printf("/*****                                                                  *****/\n");
	printf("/*****                                                                  *****/\n");
	printf("/*****                                                                  *****/\n");
	printf("/*****                                 版本号（Version）：V1.0          *****/\n");
	printf("/*****                                 开发者（Developer）：第五组      *****/\n");
	printf("/*****                                 发布日期（Date）：2012-4-24      *****/\n");
	printf("/****************************************************************************/\n\n");

}	
/***************************************************************************
函数名称: void main()
描述:   调用PrintHeadFunction()和PrintEndFunction()在屏幕上显示
		用户提示信息，并通过Choose(&H)函数让用户输入所选服务
作成日期:     12/04/23
参数:        参数名:H 类型:MAPLINK 单链表的头节点指针
输入:        VOID              
输出:        用户提示信息
返回值:      无返回值   
                            
作者:    
*******************************************************************************/

void main()
{
	MAPLINK H = NULL;
	PrintHeadFunction();
	PrintEndFunction();
	Choose(&H);
	
}