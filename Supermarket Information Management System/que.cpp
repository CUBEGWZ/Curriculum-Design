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
void que()   //�����ѯ���ܲ˵�
{
	int choice;
	system("cls");
	printf("\n");
	printf("                         **************************\n");
	printf("**************************��ӭʹ�ó�����Ϣ����ϵͳ******************************");
	printf(" ***                     **************************                         ***\n");
	printf("  ****************************��Ʒ��Ϣ��ѯ����********************************\n");
	printf("                             ******************\n\n\n\n\n");
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>����ѡ����Ʒ��ѯ����<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n\n");
	printf("                            1.������Ʒ��Ų�ѯ\n\n");
	printf("                            2.������Ʒ���Ʋ�ѯ\n\n");
	printf("                            3.������Ʒ�۸��ѯ\n\n");
	printf("                            4.������Ʒ����ѯ\n\n"); 
	printf("                            5.����ϵͳ���ܲ˵�\n\n");
	printf("����������������:");
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

void que_ID()     //ʵ�ָ�����Ʒ��Ž��в�ѯ���ܵ��Զ��庯��
{
	FILE *fp;
	int ID;
	char choice;
	struct goods i;
	fp=fopen("goods.txt","r");
	if(fp==NULL)
	{
		printf("ϵͳ���������ԡ�������\n");
		exit(0);
	}
	system("cls");
	printf("������Ҫ��ѯ��Ϣ����Ʒ���:");
	scanf("%d",&ID);
	fread(&i,sizeof(struct goods),1,fp);
	while(!feof(fp))
	{
		if(i.id==ID)
		{
			printf("\n\n");
			printf("��Ʒ���   ��Ʒ����   ��Ʒ�۸�(Ԫ)   ��Ʒ����   ��Ʒ���\n");
			printf("%-13d%-10s%-15.3lf%-10d%-15s\n",i.id,i.name,i.price,i.num,i.type);
			fclose(fp);
			printf("\n\n\n\n\n");
			printf("���Ƿ�Ҫ������ѯ��(y/n)\n");
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
	printf("�޴˱����Ϣ�������ԡ�����\n");
	getchar();
	getchar();
	system("cls");
	que();
}

void que_name()              //ʵ�ָ�����Ʒ���ƽ��в�ѯ���ܵ��Զ��庯��
{
	FILE *fp;
	char name[20];
	char choice;
	struct goods i;
	fp=fopen("goods.txt","r");
	if(fp==NULL)
	{
		printf("ϵͳ���������ԡ�������\n");
		exit(0);
	}
	system("cls");
	printf("������Ҫ��ѯ��Ϣ����Ʒ����:");
	scanf("%s",name);
	fread(&i,sizeof(struct goods),1,fp);
	while(!feof(fp))
	{
		if(strcmp(i.name,name)==0)
		{
			printf("\n\n");
			printf("��Ʒ���   ��Ʒ����   ��Ʒ�۸�(Ԫ)   ��Ʒ����   ��Ʒ���\n");
			printf("%-13d%-10s%-15.3lf%-10d%-15s\n",i.id,i.name,i.price,i.num,i.type);
			fclose(fp);
			printf("\n\n\n\n\n");
			printf("���Ƿ�Ҫ������ѯ��(y/n)\n");
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
	printf("�޴�������Ϣ�������ԡ�����\n");
	getchar();
	getchar();
	system("cls");
	que();
}

void que_price()            //ʵ�ָ�����Ʒ�۸���в�ѯ���ܵ��Զ��庯��
{
	int h=0;
	FILE *fp;
	double price;
	char choice;
	struct goods i;
	fp=fopen("goods.txt","r");
	if(fp==NULL)
	{
		printf("ϵͳ���������ԡ�������\n");
		exit(0);
	}
	system("cls");
	printf("������Ҫ��ѯ��Ϣ����Ʒ�۸�:");
	scanf("%lf",&price);
	printf("\n\n");
	printf("��Ʒ���   ��Ʒ����   ��Ʒ�۸�(Ԫ)   ��Ʒ����   ��Ʒ���\n");
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
		printf("�޴˼۸����Ʒ�������ԡ����� \n");
	}
	else
	{
		printf("\n\n\n\n\n");
			printf("���Ƿ�Ҫ������ѯ��(y/n)\n");
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

void que_type()               //ʵ�ָ�����Ʒ�����в�ѯ���ܵ��Զ��庯��
{
	int h=0;
	FILE *fp;
	char type[20];
	char choice;
	struct goods i;
	fp=fopen("goods.txt","r");
	if(fp==NULL)
	{
		printf("ϵͳ���������ԡ�������\n");
		exit(0);
	}
	system("cls");
	printf("������Ҫ��ѯ��Ϣ����Ʒ���:");
	scanf("%s",&type);
	printf("\n\n");
	printf("��Ʒ���   ��Ʒ����   ��Ʒ�۸�(Ԫ)   ��Ʒ����   ��Ʒ���\n");
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
		printf("�޴������Ϣ�������ԡ�����\n");
	}
	else
	{
		printf("\n\n\n\n\n");
		printf("���Ƿ�Ҫ������ѯ��(y/n)\n");
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