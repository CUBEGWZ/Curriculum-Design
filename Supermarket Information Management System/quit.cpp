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
void quit()          //ʵ��ϵͳ�˳����ܵĺ���
{
	char choice;
	system("cls");
	printf("\n\n\n\n\n\n\n\n");
	printf("********************************************************************************");
	printf("***                    ����������뿪���𣾩n��    (y/n)                     ***");               
	printf("********************************************************************************");
	getchar();
	scanf("%c",&choice);
	getchar();
	if(choice=='y'||choice=='Y')
	{
		printf("лл����ʹ�áݨy��\n");
		exit(0);
	}
	else
	{
		system("cls");
		menu();
	}
}