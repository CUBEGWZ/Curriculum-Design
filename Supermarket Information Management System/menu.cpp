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
void menu()                    //���ϵͳ���ܲ˵����Զ��庯��
{
	int choice;
	printf("\n");
	printf("                         **********************************\n");
	printf("                         *****��ӭʹ�ó�����Ϣ����ϵͳ*****\n");
	printf("                         *****        ����1404        *****\n");
	printf("                         **********************************\n\n\n\n\n\n");
	printf("-------------------------------������ʹ�����¹���-------------------------------\n\n");
	printf("                  1.��Ʒ��Ϣ���       |       2.��Ʒ��Ϣ��ѯ\n\n");
	printf("                  3.��Ʒ��Ϣ���       |       4.��Ʒ��Ϣɾ��\n\n");
	printf("                  5.��Ʒ��Ϣ�޸�       |       6.�˳�����ϵͳ\n\n");
	printf("\n\n�����빦�ܴ���:");
	scanf("%d",&choice);
	switch(choice)
	{	
	case 1: bro(); break;
	case 2: que(); break;
	case 3: add(); break;
	case 4: del(); break;
	case 5: mod(); break;
	default : quit(); break;
	}  
}
