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
	struct timepass{//���������ν�����ͣ����Ż��ýṹ��
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
		printf("*************************�������ǵ�һ�ν���ѧ��ϵͳ���밴��ϵͳ��ʾ���У�*******************************\n\n");
		printf("����������ѧ��ѧ�ţ�");
		scanf("%lf",&num);
		struct timepass{//���������ν�����ͣ����Ż��ýṹ��
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
		printf("\n********************************ϵͳ�Ա�������ѧ����Ϣ��*********************************************\n\n\n");
		printf("ϵͳ��������֮�������ת......\n");
		Sleep(2000);
		system("cls");
	}
	printf("--------------------------------------------------------------------------------------------------------\n");
	printf("*********��ѧ���ˡ�*************************************************************************************\n");
	printf("*********************************   ѧ  ��  ��  Ϣ  ��  ��  ϵ  ͳ   *************   ��ӭ����%8s\n",student.login_name);
	printf("**********************************************************************************   ��¼����:��%3d��\n",student.login_time);
	printf("********************************************************************************************************\n");
	printf("||--------------           1.�� �� �� �� �� Ϣ    ||    2.�� ѯ �� �� �� Ϣ          -----------------||\n");
	printf("||------------------       3.�� �� �� ¼ �� Ϣ    ||    4.���ص�¼����               -----------------||\n");
	printf("||--------------------------------------|| 5.�� �� ϵ ͳ ||-------------------------------------------||\n");
	printf("\n����ѡ��Ϊ��");
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
	printf("\n*********************************�����ڽ����˴������ĸ�����Ϣ�Ľ��棡***********************************\n\n");
	char c;
	p0=( StuManage *)malloc(LEN);
	struct timepass{//���������ν�����ͣ����Ż��ýṹ��
		char login_name[20];
		char login_pass[20];
		double num;
		int login_time;
	}teacher,student;
	FILE *fp = fopen("tp.txt","rb+");
	fread(&student,sizeof(student),1,fp);
	p0->num=student.num;
	fclose(fp);
	printf("����������������");
	scanf("%s",p0->name);
	printf("�������������䣺");
	scanf("%d",&p0->age);
	printf("�����������Ա�");
	scanf("%s",p0->sex);
	printf("�������������壺");
	scanf("%s",p0->nation);
	printf("�������������֤���룺");
	scanf("%s",p0->idcard);
	printf("����������ѧԺ��");
	scanf("%s",p0->college);
	printf("���������İ༶��");
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
		p1=head;                   //p1 ָ���ͷ���
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
	printf("***********************************ϵͳ�ѽ�������Ϣ������Ϣ���У�***************************************\n\n\n");
	printf("ϵͳ��������֮�������ת......\n");
	Sleep(2000);
	system("cls");
	menu_s();
	
}
void student_search()
{
	printf("\n****************************************�����Ϣ������ʾ��**********************************************\n\n");
	StuManage *p,*head=read();
	int n=countnode(head),i,a,b=1,c=1,d=0;
	double num;
	struct timepass{//���������ν�����ͣ����Ż��ýṹ��
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
				printf("�������ҵ�ѧ�Ŷ�Ӧ��ѧ����ϢΪ��\n\n");
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
		printf("\n****************************************��ѡ�����������Ĳ�����******************************************\n");
		printf("--------------------------------------------------------------------------------------------------------\n");
		printf("------------------            1.����ѧ��ϵͳ����         2.���ص�¼����               ------------------\n");
		printf("------------------------------------------||  3.�˳�ϵͳ  ||--------------------------------------------\n");
		printf("********************************************************************************************************\n");
		printf("\n����ѡ��Ϊ��");
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
		printf("\n****************************************ѧ����Ϣ����û��������Ϣ��**************************************\n\n");
		printf("ϵͳ��������֮�������ת.......\n");
		Sleep(2000);
		system("cls");
		int m;
		printf("\n******************************************��ѡ�����������Ĳ�����****************************************\n");
		printf("----------------               1.����ѧ��ϵͳ����        2.���ص�¼����             --------------------\n");
		printf("------------------------------------------||  3.�˳�ϵͳ  ||--------------------------------------------\n");
		printf("********************************************************************************************************\n");
		printf("\n����ѡ��Ϊ��");
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
