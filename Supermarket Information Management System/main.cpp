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
void main()          //��������ֻ���ò˵�������
{
	printf("\n\n\n\n\n\n\n\n");
	printf("                         **************************\n");
	printf("**************************��ӭʹ�ó�����Ϣ����ϵͳ******************************");
	printf(" ***                     **************************                         ***\n");
	printf("  ****************************�����������ʼ**********************************\n");
	printf("                             ****************\n");
	getchar();
	system("cls");
	menu();
}