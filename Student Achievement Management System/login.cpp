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
		printf("                               ��������һ��ʹ�ø�ѧ����Ϣ����ϵͳ��\n");
		printf("--------------------------------------------------------------------------------------------------------\n");
		printf("--------------------------------------------------------------------------------------------------------\n");
		printf("******************* �� ע �� �� ************ �� ע �� �� ************ �� ע �� �� **********************\n");
		printf("******************* �� ע �� �� ************ �� ע �� �� ************ �� ע �� �� **********************\n");
		printf("--------------------------------------------------------------------------------------------------------\n");
		printf("--------------------------------------------------------------------------------------------------------\n");
		printf("-------------------------||  ѧ����ڵĵ�¼   ||-----||   ��ʦ��ڵĵ�¼    ||--------------------------\n");
		printf("-------------------------||  �˻���student    ||-----||   �˻���teacher     ||--------------------------\n");
		printf("-------------------------||  ���룺student    ||-----||   ���룺teacher     ||--------------------------\n");
		printf("--------------------------------------------------------------------------------------------------------\n");
		printf("********************************************************************************************************\n");
		struct timepass{//���������ν�����ͣ����Ż��ýṹ��
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
		printf("\n\n+++++++++++++++++++++++++���������ϸ�˽�������Ϣ���밴�س��������ϵͳ��+++++++++++++++++++++++++++++++\n");
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
	char ch1[]="ѧ��",ch2[]="��ʦ";
	printf("\n    ------------------------------------------------------------------------------------------------\n");
	printf("    ---------------             �� ӭ �� ¼ ѧ �� �� Ϣ �� �� ϵ ͳ ��                --------------\n");
	printf("    ------------------------------------------------------------------------------------------------\n");
	printf("    ---------------                    ����ѡ��������ڣ���                           --------------\n");
	printf("    ------------------------------------------------------------------------------------------------\n");
	printf("    ---------------------||  1.ѧ����¼���          2.��ʦ��¼���      ||-------------------------\n");
	printf("    ----------------------------------||  3.�˳�ϵͳ   ||-------------------------------------------\n");
	printf("    ------------------------------------------------------------------------------------------------\n");
	printf("\n    ��ѡ������:");
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
	printf("--------------------------------------------------------------------------------------------------------\n");
	printf("*********************************������%s��¼��ڵ�¼����*********************************************\n",ch);
	printf("\n�����������û�����");
	scanf("%s",name);
	printf("���������ĵ�¼���룺");
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
	printf("************************************�Բ����������ƥ�����******************************************\n\n");
	printf("ϵͳ����󼴽���ת....\n");
	Sleep(2000);
	system("cls");
	printf("************************************��ѡ����������ִ�еĲ���!*******************************************\n");
	printf("********************************************************************************************************\n");
	printf("----------------             1.���������¼��Ϣ          2.�������ѡ��            ---------------------\n");
	printf("--------------------------------------||  3.�˳�ϵͳ   ||-----------------------------------------------\n");
	printf("\n����ѡ��:");
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
	printf("\n*************************************�����ǵ�¼��Ϣ�޸Ĵ���*********************************************\n");
	printf("**************************************��������Ҫ�޸ĵ�ѡ�********************************************\n");
	printf("-----------------           1.�޸ĵ�¼�˻���        2.�޸ĵ�¼����            --------------------------\n");
	printf("-----------------           3.���ع������          4.���ص�¼ѡ�����        --------------------------\n");
	printf("-------------------------------------||   5.�˳�ϵͳ   ||-----------------------------------------------\n");
	printf("--------------------------------------------------------------------------------------------------------\n");
	printf("\n����������ѡ��");
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
	struct timepass{//���������ν�����ͣ����Ż��ýṹ��
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
 		printf("\n�������������û�����");
		scanf("%s",ch);
		if(n==1)
		{ 
			printf("\n�Ƿ�ԭ�û��� %s �޸�Ϊ���û��� %s ��y/n����",student.login_name,ch);
			c=judge_ch();
			if(c=='y'||c=='Y')
				strcpy(student.login_name,ch);
		}
		else
		{
			printf("\n�Ƿ�ԭ�û��� %s �޸�Ϊ���û��� %s ��y/n����",teacher.login_name,ch);
			c=judge_ch();
			if(c=='y'||c=='Y')
				strcpy(teacher.login_name,ch);
		}
 	}
 	else
 	{
	 	printf("\n���������������룺");
		scanf("%s",ch);
		if(n==1)
		{
			printf("\n�Ƿ�ԭ���� %s �޸�Ϊ������ %s ��y/n����",student.login_pass,ch);
			c=judge_ch();
			if(c=='y'||c=='Y')
				strcpy(student.login_pass,ch);
		}
		else
		{
			printf("\n�Ƿ�ԭ���� %s �޸�Ϊ������ %s ��y/n����",teacher.login_pass,ch);
			c=judge_ch();
			if(c=='y'||c=='Y')
				strcpy(teacher.login_pass,ch);
		}
	 }
	if(c=='y'||c=='Y')
         printf("\n******************************************��Ϣ�޸ĳɹ�!*************************************************\n");
 	else
 		 printf("\n******************************************��Ϣ�޸�ʧ��!*************************************************\n");
	fclose(fp1);
	FILE *fp = fopen("tp.txt","wb+");
	fwrite(&student,sizeof(student),1,fp);
	fwrite(&teacher,sizeof(teacher),1,fp);
	fclose(fp1);
	printf("\n\nϵͳ��������֮�������ת.....\n");
	Sleep(2000);
	system("cls");
	modify_login(n);
}
void add_login_time(int n)
{
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
	if(n==1)
		student.login_time++;
	else
		teacher.login_time++;
	FILE *fp = fopen("tp.txt","wb");
	fwrite(&student,sizeof(student),1,fp);
	fwrite(&teacher,sizeof(teacher),1,fp);
	fclose(fp);
}
