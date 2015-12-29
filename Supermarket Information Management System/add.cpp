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
int judge(int id)         //判断之前是否存储过相同商品编号的自定义函数
{
	FILE *fp;
	struct goods i;
	fp=fopen("goods.txt","r");
	if(fp==NULL)
	{
		printf("系统错误，请您重试。。。。。。");
		exit(0);
	}
	fread(&i,sizeof(struct goods),1,fp);
	while(!feof(fp))
	{
		if(i.id==id)
		{
			fclose(fp);
			return 1;
			break;
		}
		fread(&i,sizeof(struct goods),1,fp);
	}
	fclose(fp);
	return 0;
}

void add()              //商品信息添加函数，添加的商品编号不能与之前的商品编号重复
{
	struct goods i;
	char choice;
	FILE *fp;
	fp=fopen("goods.txt","ab");      
	if(fp==NULL)
	{
		printf("系统错误，请重试。。。。。。。");
		exit(0);
	}
labID:
	system("cls");
	printf("请您输入要添加的商品信息.......\n");
	printf("商品编号:");
	scanf("%d",&i.id);
	if(judge(i.id)==1)
	{
		printf("此编号已被使用，请您摁任意键重新输入......\n");
		getchar();
		getchar();
		goto labID;
	}
	printf("商品名称:");
	scanf("%s",&i.name);
	printf("商品价格(元):");
	scanf("%lf",&i.price);
	printf("商品剩余数量:");
	scanf("%d",&i.num);
	printf("商品类别:");
	scanf("%s",&i.type);
	fwrite(&i,sizeof(struct goods),1,fp);
	fclose(fp);
	system("cls");
	printf("商品信息已成功添加\n您是否要继续添加？（y/n）\n");
	getchar();
	scanf("%c",&choice);
	getchar();
	if(choice=='y'||choice=='Y')
	{
		add();
	}
	else
	{
		system("cls");
		menu();
	}
}
