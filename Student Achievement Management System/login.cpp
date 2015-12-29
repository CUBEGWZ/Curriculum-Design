#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<io.h>
#include<conio.h>
#include<windows.h>
#include "header.h"
#include "login.h"
#include "about_stu.h"
#include "about_tea.h"
#include "choose.h"
#include "about_file.h"
void judge_login_time()
{
	if(access("tp.txt",0) == -1)
	{
		printf("--------------------------------------------------------------------------------------------------------\n");
		printf("--------------------------------------------------------------------------------------------------------\n");
		printf("                               这是您第一次使用该学生信息管理系统！\n");
		printf("--------------------------------------------------------------------------------------------------------\n");
		printf("--------------------------------------------------------------------------------------------------------\n");
		printf("******************* 请 注 意 ！ ************ 请 注 意 ！ ************ 请 注 意 ！ **********************\n");
		printf("******************* 请 注 意 ！ ************ 请 注 意 ！ ************ 请 注 意 ！ **********************\n");
		printf("--------------------------------------------------------------------------------------------------------\n");
		printf("--------------------------------------------------------------------------------------------------------\n");
		printf("-------------------------||  学生入口的登录   ||-----||   教师入口的登录    ||--------------------------\n");
		printf("-------------------------||  账户：student    ||-----||   账户：teacher     ||--------------------------\n");
		printf("-------------------------||  密码：student    ||-----||   密码：teacher     ||--------------------------\n");
		printf("--------------------------------------------------------------------------------------------------------\n");
		printf("********************************************************************************************************\n");
		struct timepass{//不想添加无谓的类型，不优化该结构体
    		char login_name[20];
			char login_pass[20];
			double num;
			int login_time;
		};
		FILE *fp1 = fopen("test.txt","wb");
		fclose(fp1);
		FILE *fp = fopen("tp.txt","wb");
		struct timepass student={"student","student",0,0}; 
		struct timepass teacher={"teacher","teacher",0,0};
		fwrite(&student,sizeof(student),1,fp);
		fwrite(&teacher,sizeof(teacher),1,fp);
		fclose(fp);
		printf("\n\n+++++++++++++++++++++++++如果您已详细了解上述信息，请按回车键进入该系统！+++++++++++++++++++++++++++++++\n");
		getchar();
		system("cls");
		login();
	}
	system("cls");
	login();
}
void login()
{
	int n;
	char ch1[]="学生",ch2[]="教师";
	printf("\n    ------------------------------------------------------------------------------------------------\n");
	printf("    ---------------             欢 迎 登 录 学 生 信 息 管 理 系 统 ！                --------------\n");
	printf("    ------------------------------------------------------------------------------------------------\n");
	printf("    ---------------                    （请选择您的入口！）                           --------------\n");
	printf("    ------------------------------------------------------------------------------------------------\n");
	printf("    ---------------------||  1.学生登录入口          2.教师登录入口      ||-------------------------\n");
	printf("    ----------------------------------||  3.退出系统   ||-------------------------------------------\n");
	printf("    ------------------------------------------------------------------------------------------------\n");
	printf("\n    您选择的序号:");
	n=judge_num(3);
	system("cls");
	switch(n)
	{
		case 1:login_merge(1,ch1);break;
		case 2:login_merge(2,ch2);break;
		case 3:exit(0);printf("\n");
	}
}
void login_merge(int n,char ch[])
{
	char  name[20],pass[20];
	int a;
	struct timepass{//不想添加无谓的类型，不优化该结构体
		char login_name[20];
		char login_pass[20];
		double num;
		int login_time;
	}teacher,student;
	FILE *fp1 = fopen("tp.txt","rb+");
	fread(&student,sizeof(student),1,fp1);
 	fread(&teacher,sizeof(teacher),1,fp1);
	fclose(fp1);
	printf("--------------------------------------------------------------------------------------------------------\n");
	printf("*********************************这里是%s登录入口登录界面*********************************************\n",ch);
	printf("\n请输入您的用户名：");
	scanf("%s",name);
	printf("请输入您的登录密码：");
	scanf("%s",pass);
	if(n==1)
	{
		if(strcmp(name,student.login_name)==0&&strcmp(pass,student.login_pass)==0)
		{
			system("cls");
			add_login_time(1);
			menu_s();
		}
		else
		{
			system("cls");
			login_wrong(n,ch);
		}
	}
	else
	{
		if(strcmp(name,teacher.login_name)==0&&strcmp(pass,teacher.login_pass)==0)
		{
			system("cls");
			add_login_time(2);
			menu_t();
		}
		else
		{
			system("cls");
			login_wrong(n,ch);
		}
	}
}
void login_wrong(int n,char ch[])
{
	int a;
	system("cls");
	printf("--------------------------------------------------------------------------------------------------------\n");
	printf("************************************对不起！您的身份匹配错误！******************************************\n\n");
	printf("系统两秒后即将跳转....\n");
	Sleep(2000);
	system("cls");
	printf("************************************请选择您接下来执行的操作!*******************************************\n");
	printf("********************************************************************************************************\n");
	printf("----------------             1.重新输入登录信息          2.返回入口选择            ---------------------\n");
	printf("--------------------------------------||  3.退出系统   ||-----------------------------------------------\n");
	printf("\n您的选择:");
	a=judge_num(3);
	system("cls");
	switch(a)
	{
	 	case 1:login_merge(n,ch);break;
	 	case 2:login();break;
	 	case 3:exit(0);printf("\n");
	}
}
void modify_login(int n)
{
	int a;
	printf("\n*************************************这里是登录信息修改窗口*********************************************\n");
	printf("**************************************请输入您要修改的选项！********************************************\n");
	printf("-----------------           1.修改登录账户名        2.修改登录密码            --------------------------\n");
	printf("-----------------           3.返回管理界面          4.返回登录选择界面        --------------------------\n");
	printf("-------------------------------------||   5.退出系统   ||-----------------------------------------------\n");
	printf("--------------------------------------------------------------------------------------------------------\n");
	printf("\n请输入您的选择：");
	a=judge_num(5);
	printf("%d\n",a);
	system("cls");
	switch(a)
	{
		case 1:
		if(n==1)
			modify_login_all(1,11);
		else
			modify_login_all(2,21);
		break;
		case 2:
		if(n==1)
			modify_login_all(1,12);
		else
			modify_login_all(2,22);
		break;
		case 3:
		if(n==1)
			menu_s();
		else
			menu_t();
		break;
		case 4:login();break;
		case 5:exit(0);break;
	}
}
void modify_login_all(int n,int m)
{
	char ch[20],c;
	struct timepass{//不想添加无谓的类型，不优化该结构体
		char login_name[20];
		char login_pass[20];
		double num;
		int login_time;
	}teacher,student;
	FILE *fp1 = fopen("tp.txt","rb+");
	fread(&student,sizeof(student),1,fp1);
 	fread(&teacher,sizeof(teacher),1,fp1);
 	system("cls");
 	if(m==11||m==21)
 	{
 		printf("\n请输入您的新用户名：");
		scanf("%s",ch);
		if(n==1)
		{ 
			printf("\n是否将原用户名 %s 修改为新用户名 %s （y/n）？",student.login_name,ch);
			c=judge_ch();
			if(c=='y'||c=='Y')
				strcpy(student.login_name,ch);
		}
		else
		{
			printf("\n是否将原用户名 %s 修改为新用户名 %s （y/n）？",teacher.login_name,ch);
			c=judge_ch();
			if(c=='y'||c=='Y')
				strcpy(teacher.login_name,ch);
		}
 	}
 	else
 	{
	 	printf("\n请输入您的新密码：");
		scanf("%s",ch);
		if(n==1)
		{
			printf("\n是否将原密码 %s 修改为新密码 %s （y/n）？",student.login_pass,ch);
			c=judge_ch();
			if(c=='y'||c=='Y')
				strcpy(student.login_pass,ch);
		}
		else
		{
			printf("\n是否将原密码 %s 修改为新密码 %s （y/n）？",teacher.login_pass,ch);
			c=judge_ch();
			if(c=='y'||c=='Y')
				strcpy(teacher.login_pass,ch);
		}
	 }
	if(c=='y'||c=='Y')
         printf("\n******************************************信息修改成功!*************************************************\n");
 	else
 		 printf("\n******************************************信息修改失败!*************************************************\n");
	fclose(fp1);
	FILE *fp = fopen("tp.txt","wb+");
	fwrite(&student,sizeof(student),1,fp);
	fwrite(&teacher,sizeof(teacher),1,fp);
	fclose(fp1);
	printf("\n\n系统将在两秒之后进行跳转.....\n");
	Sleep(2000);
	system("cls");
	modify_login(n);
}
void add_login_time(int n)
{
	struct timepass{//不想添加无谓的类型，不优化该结构体
		char login_name[20];
		char login_pass[20];
		double num;
		int login_time;
	}teacher,student;
	FILE *fp1 = fopen("tp.txt","rb+");
	fread(&student,sizeof(student),1,fp1);
 	fread(&teacher,sizeof(teacher),1,fp1);
	fclose(fp1);
	if(n==1)
		student.login_time++;
	else
		teacher.login_time++;
	FILE *fp = fopen("tp.txt","wb");
	fwrite(&student,sizeof(student),1,fp);
	fwrite(&teacher,sizeof(teacher),1,fp);
	fclose(fp);
}
