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
void del()             //ʵ����Ʒ��Ϣɾ�����ܵĺ���
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
		printf("ϵͳ���������ԡ�������\n");
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
	printf("������Ҫɾ����Ʒ�ı��:");
	scanf("%d",&delID);
	fopen("goods.txt","w");
	if(fp==NULL)
	{
		printf("ϵͳ���������ԡ�������\n");
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
	printf("��Ʒ��Ϣ�����!!!\n");
	printf("���Ƿ�Ҫ����ɾ����(y/n)\n");
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