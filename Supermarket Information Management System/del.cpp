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
void del()             //实现商品信息删除功能的函数
{
	struct goods i[1000];
	struct goods temp;
	int delID;
	char choice;
	int index=0;
	int j=0;
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
	system("cls");
	printf("请输入要删除商品的编号:");
	scanf("%d",&delID);
	fopen("goods.txt","w");
	if(fp==NULL)
	{
		printf("系统错误，请重试。。。。\n");
		exit(0);
	}
	for(j=0;j<index;j++)
	{
		if(i[j].id!=delID)
		{
			fwrite(&i[j],sizeof(struct goods),1,fp);
		}
	}
	fclose(fp);
	system("cls");
	printf("商品信息已清除!!!\n");
	printf("你是否要继续删除？(y/n)\n");
	getchar();
	scanf("%c",&choice);
	getchar();
	if(choice=='y'||choice=='Y')
	{
		del();
	}
	else
	{
		system("cls");
		menu();
	}
}