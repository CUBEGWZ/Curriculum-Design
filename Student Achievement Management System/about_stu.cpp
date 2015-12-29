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
void menu_s()
{
	int a;
	double num;
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
	system("cls");
	if(student.num==0)
	{
		printf("--------------------------------------------------------------------------------------------------------\n");
		printf("*************************由于您是第一次进入学生系统，请按照系统提示进行！*******************************\n\n");
		printf("请输入您的学生学号：");
		scanf("%lf",&num);
		struct timepass{//不想添加无谓的类型，不优化该结构体
			char login_name[20];
			char login_pass[20];
			double num;
			int login_time;
		}teacher,student;
		FILE *fp = fopen("tp.txt","rb");
		fread(&student,sizeof(student),1,fp);
		fread(&teacher,sizeof(student),1,fp);
		student.num=num;
		fclose(fp);
		FILE *fp1 = fopen("tp.txt","wb");
		fwrite(&student,sizeof(student),1,fp1);
		fwrite(&teacher,sizeof(student),1,fp1);
		fclose(fp1); 
		printf("\n********************************系统以保存您的学号信息！*********************************************\n\n\n");
		printf("系统将在两秒之后进行跳转......\n");
		Sleep(2000);
		system("cls");
	}
	printf("--------------------------------------------------------------------------------------------------------\n");
	printf("*********【学生端】*************************************************************************************\n");
	printf("*********************************   学  生  信  息  管  理  系  统   *************   欢迎您：%8s\n",student.login_name);
	printf("**********************************************************************************   登录次数:第%3d次\n",student.login_time);
	printf("********************************************************************************************************\n");
	printf("||--------------           1.创 建 自 己 信 息    ||    2.查 询 自 己 信 息          -----------------||\n");
	printf("||------------------       3.修 改 登 录 信 息    ||    4.返回登录界面               -----------------||\n");
	printf("||--------------------------------------|| 5.退 出 系 统 ||-------------------------------------------||\n");
	printf("\n您的选择为：");
	a=judge_num(5);
	system("cls");
	switch(a)
	{
		case 1:student_creat();break;
		case 2:student_search();break;
		case 3:modify_login(1);break;
		case 4:login();break;
		case 5:exit(0);break;
	}
}
void student_creat()
{
	StuManage  *p0 , *p1 , *p2 ,*head;
	FILE *fp5 = fopen("test.txt","rb+");
	char ch;
	int size;
	fseek(fp5,0,SEEK_END);
	size=ftell(fp5);
	fclose(fp5);
	printf("\n*********************************您现在进入了创建您的个人信息的界面！***********************************\n\n");
	char c;
	p0=( StuManage *)malloc(LEN);
	struct timepass{//不想添加无谓的类型，不优化该结构体
		char login_name[20];
		char login_pass[20];
		double num;
		int login_time;
	}teacher,student;
	FILE *fp = fopen("tp.txt","rb+");
	fread(&student,sizeof(student),1,fp);
	p0->num=student.num;
	fclose(fp);
	printf("请输入您的姓名：");
	scanf("%s",p0->name);
	printf("请输入您的年龄：");
	scanf("%d",&p0->age);
	printf("请输入您的性别：");
	scanf("%s",p0->sex);
	printf("请输入您的民族：");
	scanf("%s",p0->nation);
	printf("请输入您的身份证号码：");
	scanf("%s",p0->idcard);
	printf("请输入您的学院：");
	scanf("%s",p0->college);
	printf("请输入您的班级：");
	scanf("%s",p0->cla);
	getchar();
	p0->next = NULL;
	if(size==0)
	{
		savefile_wb(p0);
	}
	else
	{
		head=read();
		p1=head;                   //p1 指向表头结点
		while((p0->num>p1->num)&&(p1->next!=NULL))
		{
			p2=p1;
			p1=p1->next;
		}
		if(p0->num<=p1->num)
		{
			if(head==p1)
				head=p0;
			else
				p2->next=p0;
			p0->next=p1;
		}
		else
			p1->next=p0;
		savefile_wb(head);
	
	}
	Sleep(2000);
	printf("***********************************系统已将您的信息存入信息库中！***************************************\n\n\n");
	printf("系统将在两秒之后进行跳转......\n");
	Sleep(2000);
	system("cls");
	menu_s();
	
}
void student_search()
{
	printf("\n****************************************你的信息如下所示！**********************************************\n\n");
	StuManage *p,*head=read();
	int n=countnode(head),i,a,b=1,c=1,d=0;
	double num;
	struct timepass{//不想添加无谓的类型，不优化该结构体
		char login_name[20];
		char login_pass[20];
		double num;
		int login_time;
	}teacher,student;
	FILE *fp = fopen("tp.txt","rb");
	fread(&student,sizeof(student),1,fp);
	num=student.num;
	fclose(fp);
	p=head;
	for(i=1;i<=n;i++)
	{
		if(p->num==num)
		{
			if(b==1)
			{
				printf("您所查找的学号对应的学生信息为：\n\n");
			}
			if(c==1)
			{
				list_one(p);
				d=1;
			}
			b=2;
		}
		p=p->next;
	}
	if(d!=0)
	{
		int m;
		printf("\n****************************************请选择您接下来的操作！******************************************\n");
		printf("--------------------------------------------------------------------------------------------------------\n");
		printf("------------------            1.返回学生系统窗口         2.返回登录窗口               ------------------\n");
		printf("------------------------------------------||  3.退出系统  ||--------------------------------------------\n");
		printf("********************************************************************************************************\n");
		printf("\n您的选择为：");
		m=judge_num(3);
		printf("%d\n",m);
		system("cls");
		switch(m)
		{
			case 1:menu_s();break;
			case 2:login();break;
			case 3:exit(0);break;
		}
	}
	else
	{
		system("cls");
		printf("\n****************************************学生信息库中没有您的信息！**************************************\n\n");
		printf("系统将在两秒之后进行跳转.......\n");
		Sleep(2000);
		system("cls");
		int m;
		printf("\n******************************************请选择您接下来的操作！****************************************\n");
		printf("----------------               1.返回学生系统窗口        2.返回登录窗口             --------------------\n");
		printf("------------------------------------------||  3.退出系统  ||--------------------------------------------\n");
		printf("********************************************************************************************************\n");
		printf("\n您的选择为：");
		m=judge_num(3);
		printf("%d\n",m);
		system("cls");
		switch(m)
		{
			case 1:menu_s();break;
			case 2:login();break;
			case 3:exit(0);break;
		}
	}
}
