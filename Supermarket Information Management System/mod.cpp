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
void mod()             //ʵ����Ʒ��Ϣ�޸Ĺ��ܵĺ���
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
	fp=fopen("goods.txt","w");
	if(fp==NULL)
	{
		printf("ϵͳ���������ԡ�������\n");
		exit(0);
	}
	system("cls");
	printf("������Ҫ�޸���Ϣ��Ʒ�ı��:");
	scanf("%d",&ID);
	for(j=0;j<index;j++)
	{
		if(i[j].id!=ID)
		{
			fwrite(&i[j],sizeof(struct goods),1,fp);
		}
		else
		{
			printf("�޸ĺ���Ʒ����:");
			scanf("%s",&i[j].name);
			printf("�޸ĺ���Ʒ�۸�(Ԫ):");
			scanf("%lf",&i[j].price);
			printf("�޸ĺ���Ʒʣ������:");
			scanf("%d",&i[j].num);
			printf("�޸ĺ���Ʒ���:");
			scanf("%s",&i[j].type);
			fwrite(&i[j],sizeof(struct goods),1,fp);
		}
	}
	fclose(fp);
	system("cls");
	printf("��Ʒ��Ϣ���޸�!!!\n");
	printf("���Ƿ�Ҫ�����޸ģ�(y/n)\n");
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