#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include"add.h"
#include"bro.h"
#include"del.h"
#include"menu.h"
#include"mod.h"
#include"que.h"
#include"quit.h"
void menu();                               
void judge();
void add();
void del();
void mod();
void que();
void que_ID();
void que_name();
void que_price();
void que_type();
void bro();
void quit();
void list();
void menu()                    //输出系统功能菜单的自定义函数
{
	int choice;
	printf("\n");
	printf("                         **********************************\n");
	printf("                         *****欢迎使用超市信息管理系统*****\n");
	printf("                         *****        计软1404        *****\n");
	printf("                         **********************************\n\n\n\n\n\n");
	printf("-------------------------------您可以使用以下功能-------------------------------\n\n");
	printf("                  1.商品信息浏览       |       2.商品信息查询\n\n");
	printf("                  3.商品信息添加       |       4.商品信息删除\n\n");
	printf("                  5.商品信息修改       |       6.退出管理系统\n\n");
	printf("\n\n请输入功能代号:");
	scanf("%d",&choice);
	switch(choice)
	{	
	case 1: bro(); break;
	case 2: que(); break;
	case 3: add(); break;
	case 4: del(); break;
	case 5: mod(); break;
	default : quit(); break;
	}  
}
