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
void bro()      //输出所有商品信息的自定义函数，这里主要实现链表建立
{
	void list(struct goods *head);  
	FILE *fp=fopen("goods.txt","r");
	struct goods *head=NULL,*p,*q;
	p=q=(struct goods *)malloc(sizeof(goods));	
	fread(p,sizeof(struct goods),1,fp);   //文件存放是二进制存放，以数据块方式进行读取
	while(!feof(fp))
	{
		if(head==NULL)
		{
			head=p;
		}
		else
		{
			q->next=p;
		}
		q=p;
		p=(struct goods *)malloc(sizeof(goods));
		fread(p,sizeof(struct goods),1,fp);
	}
	q->next=NULL;
	free(p);
	system("cls");
	printf("商品编号   商品名称   商品价格(元)   商品数量   商品类别\n");
	list(head);
	printf("\n\n\n\n\n输入任意键返回主菜单.....");
	getchar();
	getchar();
	system("cls");
	menu();
	fclose(fp);
}

void list(struct goods *head)    //遍历链表，并输出相应内容
{
	struct goods *p;
	p=head;
	while(p!=NULL)
	{
		printf("%-13d%-10s%-15.3lf%-10d%-15s\n",p->id,p->name,p->price,p->num,p->type);
		p=p->next;
	}
}