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
int judge(int id)         //�ж�֮ǰ�Ƿ�洢����ͬ��Ʒ��ŵ��Զ��庯��
{
	FILE *fp;
	struct goods i;
	fp=fopen("goods.txt","r");
	if(fp==NULL)
	{
		printf("ϵͳ�����������ԡ�����������");
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

void add()              //��Ʒ��Ϣ��Ӻ�������ӵ���Ʒ��Ų�����֮ǰ����Ʒ����ظ�
{
	struct goods i;
	char choice;
	FILE *fp;
	fp=fopen("goods.txt","ab");      
	if(fp==NULL)
	{
		printf("ϵͳ���������ԡ�������������");
		exit(0);
	}
labID:
	system("cls");
	printf("��������Ҫ��ӵ���Ʒ��Ϣ.......\n");
	printf("��Ʒ���:");
	scanf("%d",&i.id);
	if(judge(i.id)==1)
	{
		printf("�˱���ѱ�ʹ�ã��������������������......\n");
		getchar();
		getchar();
		goto labID;
	}
	printf("��Ʒ����:");
	scanf("%s",&i.name);
	printf("��Ʒ�۸�(Ԫ):");
	scanf("%lf",&i.price);
	printf("��Ʒʣ������:");
	scanf("%d",&i.num);
	printf("��Ʒ���:");
	scanf("%s",&i.type);
	fwrite(&i,sizeof(struct goods),1,fp);
	fclose(fp);
	system("cls");
	printf("��Ʒ��Ϣ�ѳɹ����\n���Ƿ�Ҫ������ӣ���y/n��\n");
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
