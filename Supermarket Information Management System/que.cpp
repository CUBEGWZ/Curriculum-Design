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
void que()   //输出查询功能菜单
{
	int choice;
	system("cls");
	printf("\n");
	printf("                         **************************\n");
	printf("**************************欢迎使用超市信息管理系统******************************");
	printf(" ***                     **************************                         ***\n");
	printf("  ****************************商品信息查询功能********************************\n");
	printf("                             ******************\n\n\n\n\n");
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>请您选择商品查询条件<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n\n");
	printf("                            1.根据商品编号查询\n\n");
	printf("                            2.根据商品名称查询\n\n");
	printf("                            3.根据商品价格查询\n\n");
	printf("                            4.根据商品类别查询\n\n"); 
	printf("                            5.返回系统功能菜单\n\n");
	printf("请您输入条件代号:");
	scanf("%d",&choice);
	switch(choice)
	{	
	case 1: que_ID(); break;
	case 2: que_name(); break;
	case 3: que_price(); break;
	case 4: que_type(); break;
	default: menu(); break;
	}
}

void que_ID()     //实现根据商品编号进行查询功能的自定义函数
{
	FILE *fp;
	int ID;
	char choice;
	struct goods i;
	fp=fopen("goods.txt","r");
	if(fp==NULL)
	{
		printf("系统错误，请重试。。。。\n");
		exit(0);
	}
	system("cls");
	printf("请输入要查询信息的商品编号:");
	scanf("%d",&ID);
	fread(&i,sizeof(struct goods),1,fp);
	while(!feof(fp))
	{
		if(i.id==ID)
		{
			printf("\n\n");
			printf("商品编号   商品名称   商品价格(元)   商品数量   商品类别\n");
			printf("%-13d%-10s%-15.3lf%-10d%-15s\n",i.id,i.name,i.price,i.num,i.type);
			fclose(fp);
			printf("\n\n\n\n\n");
			printf("您是否要继续查询？(y/n)\n");
			getchar();
			scanf("%c",&choice);
			getchar();
			if(choice=='y'||choice=='Y')
			{
				que();
			}
			else
			{
				system("cls");
				menu();
			}
		}
		fread(&i,sizeof(struct goods),1,fp);
	}
	fclose(fp);
	printf("无此编号信息，请重试。。。\n");
	getchar();
	getchar();
	system("cls");
	que();
}

void que_name()              //实现根据商品名称进行查询功能的自定义函数
{
	FILE *fp;
	char name[20];
	char choice;
	struct goods i;
	fp=fopen("goods.txt","r");
	if(fp==NULL)
	{
		printf("系统错误，请重试。。。。\n");
		exit(0);
	}
	system("cls");
	printf("请输入要查询信息的商品名称:");
	scanf("%s",name);
	fread(&i,sizeof(struct goods),1,fp);
	while(!feof(fp))
	{
		if(strcmp(i.name,name)==0)
		{
			printf("\n\n");
			printf("商品编号   商品名称   商品价格(元)   商品数量   商品类别\n");
			printf("%-13d%-10s%-15.3lf%-10d%-15s\n",i.id,i.name,i.price,i.num,i.type);
			fclose(fp);
			printf("\n\n\n\n\n");
			printf("您是否要继续查询？(y/n)\n");
			getchar();
			scanf("%c",&choice);
			getchar();
			if(choice=='y'||choice=='Y')
			{
				que();
			}
			else
			{
				system("cls");
				menu();
			}
		}
		fread(&i,sizeof(struct goods),1,fp);
	}
	fclose(fp);
	printf("无此名称信息，请重试。。。\n");
	getchar();
	getchar();
	system("cls");
	que();
}

void que_price()            //实现根据商品价格进行查询功能的自定义函数
{
	int h=0;
	FILE *fp;
	double price;
	char choice;
	struct goods i;
	fp=fopen("goods.txt","r");
	if(fp==NULL)
	{
		printf("系统错误，请重试。。。。\n");
		exit(0);
	}
	system("cls");
	printf("请输入要查询信息的商品价格:");
	scanf("%lf",&price);
	printf("\n\n");
	printf("商品编号   商品名称   商品价格(元)   商品数量   商品类别\n");
	fread(&i,sizeof(struct goods),1,fp);
	while(!feof(fp))
	{
		if(i.price==price)
		{ 
			h=1;
			printf("%-13d%-10s%-15.3lf%-10d%-15s\n",i.id,i.name,i.price,i.num,i.type);
		}
	fread(&i,sizeof(struct goods),1,fp);
	}
	fclose(fp);
	if(h==0)
	{
		system("cls");
		printf("无此价格的商品，请重试。。。 \n");
	}
	else
	{
		printf("\n\n\n\n\n");
			printf("您是否要继续查询？(y/n)\n");
			getchar();
			scanf("%c",&choice);
			getchar();
			if(choice=='y'||choice=='Y')
			{
				que();
			}
			else
			{
				system("cls");
				menu();
			}
		
	}
	getchar();
	getchar();
	system("cls");
	que();
}

void que_type()               //实现根据商品类别进行查询功能的自定义函数
{
	int h=0;
	FILE *fp;
	char type[20];
	char choice;
	struct goods i;
	fp=fopen("goods.txt","r");
	if(fp==NULL)
	{
		printf("系统错误，请重试。。。。\n");
		exit(0);
	}
	system("cls");
	printf("请输入要查询信息的商品类别:");
	scanf("%s",&type);
	printf("\n\n");
	printf("商品编号   商品名称   商品价格(元)   商品数量   商品类别\n");
	fread(&i,sizeof(struct goods),1,fp);
	while(!feof(fp))
	{
	
		if(strcmp(i.type,type)==0)
		{
			h=1;
			printf("%-13d%-10s%-15.3lf%-10d%-15s\n",i.id,i.name,i.price,i.num,i.type);
			
		}
	    fread(&i,sizeof(struct goods),1,fp);
		
	}
	fclose(fp);
	if(h==0)
	{
		system("cls");
		printf("无此类别信息，请重试。。。\n");
	}
	else
	{
		printf("\n\n\n\n\n");
		printf("您是否要继续查询？(y/n)\n");
		getchar();
		scanf("%c",&choice);
		getchar();
		if(choice=='y'||choice=='Y')
		{
			que();
		}
		else
		{
			system("cls");
			menu();
		}
	}
	getchar();
	getchar();
	system("cls");
	que();
}