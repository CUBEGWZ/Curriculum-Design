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
void mod()             //实现商品信息修改功能的函数
{
	int index=0;
	int ID,j;
	char choice;
	struct goods i[1000];
	struct goods temp;
	FILE *fp;
	fp=fopen("goods.txt","r");
	if(fp==NULL)
	{
		printf("系统错误，请重试。。。。\n");
		exit(0);
	}
	fread(&temp,sizeof(struct goods),1,fp);
	while(!feof(fp))
	{
		i[index]=temp;
		index++;
		fread(&temp,sizeof(struct goods),1,fp);
	}
	fclose(fp);
	fp=fopen("goods.txt","w");
	if(fp==NULL)
	{
		printf("系统错误，请重试。。。。\n");
		exit(0);
	}
	system("cls");
	printf("请输入要修改信息商品的编号:");
	scanf("%d",&ID);
	for(j=0;j<index;j++)
	{
		if(i[j].id!=ID)
		{
			fwrite(&i[j],sizeof(struct goods),1,fp);
		}
		else
		{
			printf("修改后商品名称:");
			scanf("%s",&i[j].name);
			printf("修改后商品价格(元):");
			scanf("%lf",&i[j].price);
			printf("修改后商品剩余数量:");
			scanf("%d",&i[j].num);
			printf("修改后商品类别:");
			scanf("%s",&i[j].type);
			fwrite(&i[j],sizeof(struct goods),1,fp);
		}
	}
	fclose(fp);
	system("cls");
	printf("商品信息已修改!!!\n");
	printf("您是否要继续修改？(y/n)\n");
	getchar();
	scanf("%c",&choice);
	getchar();
	if(choice=='y'||choice=='Y')
	{
		mod();
	}
	else
	{
		system("cls");
		menu();
	}
}