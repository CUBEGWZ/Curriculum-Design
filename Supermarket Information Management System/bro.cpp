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
void bro()      //���������Ʒ��Ϣ���Զ��庯����������Ҫʵ��������
{
	void list(struct goods *head);  
	FILE *fp=fopen("goods.txt","r");
	struct goods *head=NULL,*p,*q;
	p=q=(struct goods *)malloc(sizeof(goods));	
	fread(p,sizeof(struct goods),1,fp);   //�ļ�����Ƕ����ƴ�ţ������ݿ鷽ʽ���ж�ȡ
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
	printf("��Ʒ���   ��Ʒ����   ��Ʒ�۸�(Ԫ)   ��Ʒ����   ��Ʒ���\n");
	list(head);
	printf("\n\n\n\n\n����������������˵�.....");
	getchar();
	getchar();
	system("cls");
	menu();
	fclose(fp);
}

void list(struct goods *head)    //���������������Ӧ����
{
	struct goods *p;
	p=head;
	while(p!=NULL)
	{
		printf("%-13d%-10s%-15.3lf%-10d%-15s\n",p->id,p->name,p->price,p->num,p->type);
		p=p->next;
	}
}