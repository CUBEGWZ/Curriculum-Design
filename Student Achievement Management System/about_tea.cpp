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
void menu_t()
{
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
	printf("*********����ʦ�ˡ�*************************************************************************************\n");
	printf("*********************************   ѧ  ��  ��  Ϣ  ��  ��  ϵ  ͳ   *************   ��ӭ����%8s\n",teacher.login_name);
	printf("**********************************************************************************   ��¼����:��%3d��\n",teacher.login_time);
	printf("********************************************************************************************************\n");
	printf("||----------               1.�� �� ѧ �� �� Ϣ    ||    2.�� �� ѧ �� �� Ϣ                 -----------||\n");
	printf("||----------               3.ɾ �� ѧ �� �� Ϣ    ||    4.�� �� ѧ �� �� Ϣ                 -----------||\n");
	printf("||----------               5.�� ѯ ѧ �� �� Ϣ    ||    6.�� �� �� ½ �� ��                 -----------||\n");
	printf("||----------               7.�� ¼ �� Ϣ �� ��    ||    8.�� �� �� �� ϵ ͳ                 -----------||\n");
	printf("||-----------------------------------------------------------------------------------------------------||\n");
	printf("����ѡ��Ϊ:");
	a=judge_num(8);
	system("cls");
	switch(a)
	{
		case 1:creat();break;
		case 2:insert();break;
		case 3:del();break;
		case 4:modify();break;
		case 5:search();break;
		case 6:login();break;
		case 7:modify_login(2);break;
		case 8:printf("\n");exit(0);break;

	}
}
void creat()
{
	printf("\n*******************************�����ڽ����˴���ѧ����Ϣ�Ľ��棡*****************************************\n");
	printf("                   �������Ҫ��������,����ϵͳ��ʾ������ѧ�Ŵ�����0���س�����\n");
	printf("********************************************************************************************************\n");
	StuManage *head=NULL,*p1,*p2;
	int i=1,n;
	char a,c='c';
	p1=p2=(StuManage *)malloc(LEN);
	printf("\n�������%d��ѧ����ѧ�ţ�",i);
	scanf("%lf",&p1->num);
	while(p1->num!=0)
	{
		p1=input_stu(p1,i);
		if(head==NULL)
			head=p1;
		else
			p2->next=p1;
		p2=p1;
		p1=(StuManage *)malloc(LEN);
		i++;
		printf("�������%d��ѧ����ѧ�ţ�",i);
		scanf("%lf",&p1->num);
		getchar();
	}
	p2->next=NULL;
	system("cls");
	printf("\n����������ѧ����Ϣ������ʾ��\n");
	head=sort(head);
	list(head);
	printf("\n���������Ϣ�Ƿ���ȷ��y/n����");
	a=judge_ch();
	if(a=='y'||a=='Y')
	{
		savefile_ab(head);
		system("cls");
		printf("\n********************************************************************************************************\n");
		printf("***********************************��ѡ�����������Ĳ�����***********************************************\n");
		printf("------------        1.����������ѧ����Ϣ         2.�鿴������ѧ����Ϣ                      -------------\n");
		printf("------------        3.�޸Ľ�����ѧ����Ϣ         4.����ϵͳ���˵�                          -------------\n");
		printf("********************************************************************************************************\n");
		n=judge_num(4);
		system("cls");
		switch(n)
		{
			case 1:creat();break;
			case 2:
			head=read();
			head=sort(head);
			list(head);
			printf("\n********************************************************************************************************\n");
			printf("************************************��ѡ�����������Ĳ�����**********************************************\n");
			printf("---------------         1.�޸Ľ�����ѧ����Ϣ         2.����ϵͳ���˵�                  -----------------\n");
			printf("********************************************************************************************************\n");
			n=judge_num(2);
			system("cls");
			if(n==1)
				modify();
			else
				menu_t();
			break;
			case 3:modify();break;
			case 4:menu_t();break;
		}
	}
	else
	{
		system("cls");
		printf("**************************��������Ϊ���ղ�������Ϣ�������ڽ�����Ϣ�޸ģ�******************************\n");
		head=sort(head);
		list(head);
		savefile_ab(head);
		modify();
	}
}
void del()
{
	StuManage *head=NULL,*p1,*p2;
	int a=judge_null(),b;
	double num;
	char c;
	if(!a)
	{
		system("cls");
		printf("**********************�洢ѧ����Ϣ�ļ�test.txt��ѧ����ϢΪ�գ��޷�ִ��ɾ��������************************\n");
		printf("----------------             1.����ѧ����Ϣ              2.�������˵�               --------------------\n");
		printf("--------------------------------------------------------------------------------------------------------\n");
		printf("\n���ѡ��Ϊ��");
		a=judge_num(2);
		switch(a)
		{
			case 1:system("cls");creat();break;
			case 2:system("cls");menu_t();break;
		}
	}
	else
	{
		head=read();
		printf("********************************************************************************************************\n");
		printf("**********************************�����ڽ�����ɾ��ѧ����Ϣ�Ľ��棡**************************************\n");
		printf("***************************************��ѡ�����������Ĳ�����*******************************************\n");
		printf("------------------              1.���ѧ����Ϣ          2.ֱ�ӽ���ɾ������            ------------------\n");
		printf("------------------              3.����ϵͳ���˵�        4.�˳�ϵͳ                    ------------------\n");
		printf("********************************************************************************************************\n");
		printf("����ѡ��Ϊ:");
		b=judge_num(4);
		printf("%d\n",b);
		system("cls");
		switch(b)
		{
			case 1:head=sort(head);list(head);break;
			case 2:break;
			case 3:menu_t();break;
			case 4:exit(0);printf("\n");
		}
		printf("������Ҫɾ����ѧ��ѧ�ţ�");
		scanf("%lf",&num);
		getchar();
		p1=head;
		while((num!=p1->num)&&(p1->next!=NULL))
		{
			p2=p1;
            p1=p1->next;
		}
		if( num==p1->num )
		{
			system("cls");
			printf("��ѧ������ϢΪ��\n\n");
			list_one(p1);
			printf("\n�Ƿ�Ҫɾ����ѧ����Ϣ��y/n����");
			c=judge_ch();
			printf("%c\n",c);
			if(c=='y'||c=='Y')
			{
				if(p1==head)
					head=p1->next;
				else
					p2->next=p1->next;
				free(p1);
				system("cls");
				printf("\n********************************************************************************************************\n");
				printf("*****************************************ѧ����Ϣ�Ѿ��ɹ�ɾ��!******************************************\n");
				printf("\nϵͳ��������֮���Զ���ת.......\n");
				Sleep(2000);
				system("cls");
				savefile_wb(head);
				head=read();
				judge_del_continue(head);
			}
			else
			{
				system("cls");
				printf("��ȡ����ɾ����ѧ����Ϣ��");
				judge_del_choose();
			}
		}
		else
		{
			system("cls");
			printf("\n*****************************��Ϣ���в����ڸ�ѧ������Ϣ���޷�ִ��ɾ��������*****************************\n");
			judge_del_choose();
		}
	}
}
void judge_del_continue(StuManage *head)
{
	char c;
	printf("�Ƿ����ɾ��ѧ����Ϣ(y/n)��");
	c=judge_ch();
	printf("%c\n",c);
	if(c=='y'||c=='Y')
	{
		system("cls");
		del();
	}
	else
	{
		system("cls");
		judge_del_choose();
	}
}
void judge_del_choose()
{
	int a;
	printf("********************************************************************************************************\n");
	printf("****************************************��ѡ�����������Ĳ�����******************************************\n");
	printf("--------------------||       1.����ɾ���˵�����       2.�������˵�          ||--------------------------\n");
	printf("----------------------------------------||  3.�˳�ϵͳ   ||---------------------------------------------\n");
	printf("--------------------------------------------------------------------------------------------------------\n");
	printf("\n����ѡ��Ϊ:");
	a=judge_num(3);
	printf("%d\n",a);
	switch(a)
	{
		case 1:system("cls");del();break;
		case 2:system("cls");menu_t();break;
		case 3:exit(0);printf("\n");
	}
}
void search()
{
	StuManage *head=NULL;
	int a=judge_null();
	char c;
	if(!a)
	{
		system("cls");
		printf("--------------------------------------------------------------------------------------------------------\n");
		printf("********************************************************************************************************\n");
		printf("                       �洢ѧ����Ϣ�ļ�test.txt��ѧ����ϢΪ�գ��޷�ִ�в��Ҳ�����\n");
		printf("                                1.����ѧ����Ϣ        2.�������˵�\n");
		printf("********************************************************************************************************\n");
		a=judge_num(2);
		switch(a)
		{
			case 1:system("cls");creat();break;
			case 2:system("cls");menu_t();break;
		}
	}
	else
	{
		head=read();
		char name[]="����",idcard[]="���֤��",college[]="ѧԺ",cla[]="�༶";
		system("cls");
		printf("********************************************************************************************************\n");
		printf("************************************�����ڽ����˲�ѯѧ����Ϣ�Ľ��棡************************************\n");
		printf("*****************************************��ѡ�����������Ĳ�����*****************************************\n");
		printf("-------------------                1.��ѧ�Ų�ѯ        2.��������ѯ                 --------------------\n");
		printf("-------------------                3.�����֤�Ų�ѯ    4.��ѧԺ��ѯ                 --------------------\n");
		printf("-------------------                5.���༶��ѯ        6.�������˵�                 --------------------\n");
		printf("------------------------------------------||   7.�˳�ϵͳ    ||-----------------------------------------\n");
		printf("********************************************************************************************************\n");
		printf("\n���ѡ��Ϊ��");
		a=judge_num(7);
		printf("%d\n",a);
		system("cls");
		switch(a)
		{
			case 1:search_num();break;
			case 2:search_merge(name,2);break;
			case 3:search_merge(idcard,3);break;
			case 4:search_merge(college,4);break;
			case 5:search_merge(cla,5);break;
			case 6:menu_t();break;
			case 7:exit(0);break;
		}

	}
}
void search_num()
{
	printf("\n********************************************************************************************************\n");
	printf("*****************************��ӭ���밴��ѧ�Ų�ѯѧ����Ϣ�Ľ��棡***************************************\n\n");
	StuManage *head=NULL;
	head=read();
	int n=countnode(head),i,a,b=1,c=1,d=0;
	double num;
	StuManage *p=head;
	printf("\n��������Ҫ���ҵ�ѧ��:");
	scanf("%lf",&num);
	getchar();
	for(i=1;i<=n;i++)
	{
		if(p->num==num)
		{
			if(b==1)
			{
				system("cls");
				printf("\n�������ҵ�ѧ�Ŷ�Ӧ��ѧ����ϢΪ��\n\n");
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
		judge_search(1);
	else
	{
		system("cls");
		printf("\n********************************************************************************************************\n");
		printf("********************************ѧ����Ϣ��û����Ҫ���ҵ�ѧ�ŵ�ѧ����************************************\n\n");
		printf("\nϵͳ��������֮�������ת.......\n");
		Sleep(2000);
		system("cls");
		printf("**********************************��ѡ�����������Ĳ�����************************************************\n");
		printf("********************************************************************************************************\n");
		printf("--------------           1.��������ѧ�Ž��в�ѯ         2.���ز�ѯ��Ϣ�Ľ���                 -----------\n");
		printf("--------------           3.�������˵�                  4.�˳�ϵͳ                            -----------\n");
		printf("********************************************************************************************************\n");
		printf("\n����ѡ��Ϊ��");
		a=judge_num(4);
		system("cls");
		switch(a)
		{
			case 1:search_num();break;
			case 2:search();break;
			case 3:menu_t();break;
			case 4:exit(0);break;
		}
	}
}
void search_merge(char ch[],int c)
{
	StuManage *head;
	head=read();
	int n=countnode(head),i,a,b=1;
	char merge[20];
	StuManage *p=head;
	printf("\n********************************************************************************************************\n");
	printf("*******************************��ӭ���밴��%s��ѯѧ����Ϣ�Ľ��棡***************************************\n\n",ch);
	printf("\n��������Ҫ���ҵ�%s:",ch);
	scanf("%s",merge);
	getchar();
	for(i=1;i<=n;i++)
	{
		switch(c)
		{
			case 2:
			if(!strcmp(p->name,merge))
			{
				if(b==1)
					printf("�������ҵ�%s��Ӧ��ѧ����ϢΪ��\n\n",ch);
				list_one(p);
				b=2;
			}
			case 3:
			if(!strcmp(p->idcard,merge))
			{
				if(b==1)
					printf("�������ҵ�%s��Ӧ��ѧ����ϢΪ��\n\n",ch);
				list_one(p);
				b=2;
			}
			break;
			case 4:
			if(!strcmp(p->college,merge))
			{
				if(b==1)
					printf("�������ҵ�%s��Ӧ��ѧ����ϢΪ��\n\n",ch);
				list_one(p);
				b=2;
			}
			break;
			case 5:
			if(!strcmp(p->cla,merge))
			{
				if(b==1)
					printf("�������ҵ�%s��Ӧ��ѧ����ϢΪ��\n\n",ch);
				list_one(p);
				b=2;
			}
			break;
		}
		p=p->next;
	}
	if(i<=n)
	{
		system("cls");
		judge_search(c);
	}
	if(i>n)
	{
		printf("****************************ѧ����Ϣ��û����Ҫ���ҵ�%s��Ӧ�ĵ�ѧ����************************************\n\n",ch);
		printf("\nϵͳ��������֮�������ת.......\n");
		Sleep(2000);
		system("cls");
		printf("\n**************************************��ѡ�����������Ĳ�����********************************************\n");
		printf("********************************************************************************************************\n");
		printf("----------------         1.��������%s���в�ѯ        2.���ز�ѯ��Ϣ��������      -----------------------\n",ch);
		printf("----------------         3.�������˵�                4.�˳�ϵͳ                  -----------------------\n");
		printf("********************************************************************************************************\n");
		printf("\n����ѡ��Ϊ��");
		a=judge_num(4);
		printf("%d\n",a);
		system("cls");
		switch(a)
		{
			case 1:search_merge(ch,c);break;
			case 2:search();break;
			case 3:menu_t();break;
			case 4:exit(0);break;
		}
	}
}
void judge_search(int a)
{
	char n,ch2[]="����",ch3[]="���֤��",ch4[]="ѧԺ",ch5[]="�༶";
	int c;
	printf("\n\n�Ƿ����ִ�в��Ҳ�����y/n����");
	n=judge_ch();
	printf("%c\n",n);
	if(n=='y'||n=='Y')
	{
		system("cls");
		switch(a)
		{
			case 1:search_num();break;
			case 2:search_merge(ch2,2);break;
			case 3:search_merge(ch3,3);break;
			case 4:search_merge(ch4,4);break;
			case 5:search_merge(ch5,5);break;
		}
	}
	else
	{
		system("cls");
		printf("********************************************************************************************************\n");
		printf("******************************************��ѡ�����������Ĳ�����****************************************\n");
		printf("----------------             1.���ز�ѯϵͳ����     2.����ϵͳ������               ---------------------\n");
		printf("-------------------------------------------||  3.�˳�ϵͳ   ||------------------------------------------\n");
		printf("********************************************************************************************************\n");
		printf("\n����ѡ��");
		c=judge_num(3);
		printf("%d\n",c);
		system("cls");
		switch(c)
		{
			case 1:search();break;
			case 2:menu_t();break;
			case 3:exit(0);break;
		}
	}
}
void insert()
{
	printf("********************************************************************************************************\n");
	printf("***********************************�����ڽ����˲���ѧ����Ϣ�Ľ��棡*************************************\n");
	printf("********************************************************************************************************\n");
	StuManage *head=NULL;
	int a=judge_null();
	char c;
	if(!a)
	{
		printf("**************** �洢ѧ����Ϣ�ļ�test.txt��ѧ����ϢΪ�գ��������ȴ���ѧ����Ϣ��*************************\n\n");
		printf("\nϵͳ��������֮�������ת.......");
		Sleep(2000);
		system("cls");
		menu_t();
	}
	else
	{
		head=read();
		StuManage  *p0 , *p1 , *p2 ;
		p0=( StuManage *) malloc (LEN);
		p0->next = NULL;
		printf("������ѧ����ѧ�ţ�");
		scanf("%lf",&p0->num);
		p0=input_stu(p0,1);
		system("cls");
		printf("���������ѧ����Ϣ������ʾ��\n\n");
		list_one(p0);
		printf("\n");
		head=judge_insert_validity(head,p0,p1,p2);
	}
}
StuManage *judge_insert_continue(StuManage *head)
{
	char c;
	int a;
	printf("�Ƿ��������ѧ����Ϣ(y/n)��");
	c=judge_ch();
	printf("%c\n",c);
	if(c=='y'||c=='Y')
	{
		system("cls");
		head=insert_cooperate(head);
	}
	else
	{
		system("cls");
		printf("\n************************************��ѡ����ֹͣ����ѧ����Ϣ��******************************************\n");
		printf("\nϵͳ��������֮�������ת.....\n");
		Sleep(2000);
		system("cls");
		printf("\n********************************************************************************************************\n");
		printf("****************************************��ѡ�����������Ĳ�����******************************************\n");
		printf("------------------||             1.�鿴����ѧ����Ϣ���ѧ����Ϣ��             ||------------------------\n");
		printf("------------------||             2.�������˵�          3.�˳�ϵͳ             ||------------------------\n");
		printf("--------------------------------------------------------------------------------------------------------\n");
		printf("\n����ѡ��Ϊ��");
		a=judge_num(3);
		system("cls");
		switch(a)
		{
			case 1:head=sort(head);list(head);judge_insert_continue_2();break;
			case 2:menu_t();break;
			case 3:printf("\n");exit(0);
		}
	}
	return head;
}
StuManage *judge_insert_validity(StuManage *head,StuManage *p0,StuManage *p1,StuManage *p2)
{
	char c='c';
	int a;
	while(c!='y'&&c!='Y'&&c!='n'&&c!='N')
	{
		printf("\n���������ѧ����Ϣ�Ƿ���ȷ��y/n����");
		c=judge_ch();
		printf("%c\n",c);
		if(c=='y'||c=='Y')
		{
			p0->next = NULL;
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
			head=read();
			head=judge_insert_continue(head);
		}
		else
		{

			savefile_wb(head);
			printf("\n***********************************����Ϊ���ղ��������Ϣ����*****************************************\n");
			printf("***************************************��ѡ��������һ��������*******************************************\n");
			printf("----------------         1.ִ�������޸Ĺ���       2.�������ݲ����ز��빦�ܽ���      --------------------\n");
			printf("----------------         3.����ϵͳ������         4.�˳�ϵͳ                        --------------------\n");
			printf("--------------------------------------------------------------------------------------------------------\n");
			printf("����ѡ��");
			a=judge_num(4);
			printf("%d\n",a);
			system("cls");
			switch(a)
			{
				case 1:modify();break;
				case 2:insert();break;
				case 3:menu_t();break;
				case 4:exit(0);break;
			}
		}
	}
	return head;
}
StuManage *insert_cooperate(StuManage *head)
{
		StuManage  *p0 , *p1 , *p2 ;
		p0=( StuManage *) malloc (LEN);
		p0->next = NULL;
		printf("�������1��ѧ����ѧ�ţ�");
		scanf("%lf",&p0->num);
		p0=input_stu(p0,1);
		printf("���������ѧ����Ϣ������ʾ��");
		list_one(p0);
		head=judge_insert_validity(head,p0,p1,p2);
	return head;
}
void judge_insert_continue_2()
{
	int a;
	printf("\n***************************************��ѡ�����������Ĳ�����*******************************************\n");
	printf("------------------        1.��������ѧ����Ϣ        2.����ϵͳ���˵�             -----------------------\n");
	printf("-------------------------------------||    3.�˳�ϵͳ   ||----------------------------------------------\n");
	printf("--------------------------------------------------------------------------------------------------------\n");
	printf("\n����ѡ��Ϊ:");
	a=judge_num(3);
	printf("%d\n",a);
	system("cls");
	switch(a)
	{
		case 1:insert();break;
		case 2:menu_t();break;
		case 3:exit(0);printf("\n");
	}
}
void modify()
{
	StuManage *head=NULL,*p1,*p2;
	int a=judge_null(),c,b;
	double num;
	char ch2[]="����",ch5[]="����",ch6[]="���֤��",ch7[]="ѧԺ",ch8[]="�༶";
	if(!a)
	{
		system("cls");
		printf("\n********************************************************************************************************\n");
		printf("                    �洢ѧ����Ϣ�ļ�test.txt��ѧ����ϢΪ�գ��޷�ִ���޸Ĳ�����\n");
		printf("----------------                1.����ѧ����Ϣ           2.�������˵�             ----------------------\n");
		printf("--------------------------------------------------------------------------------------------------------\n");
		printf("\n����ѡ��Ϊ��");
		a=judge_num(2);
		switch(a)
		{
			case 1:system("cls");creat();break;
			case 2:system("cls");menu_t();break;
		}
	}
	else
	{
		head=read();
		system("cls");
		printf("********************************************************************************************************\n");
		printf("***************************************�����ڽ������޸�ѧ����Ϣ�Ľ��棡*********************************\n");
		printf("********************************************��ѡ�����������Ĳ�����**************************************\n");
		printf("-------------------               1.���ѧ����Ϣ       2.ֱ�ӽ����޸Ĳ���           --------------------\n");
		printf("-------------------               3.����ϵͳ���˵�     4.�˳�ϵͳ                   --------------------\n");
		printf("********************************************************************************************************\n");
		printf("\n����ѡ��Ϊ:");
		b=judge_num(4);
		printf("%d\n",b);
		system("cls");
		switch(b)
		{
			case 1:system("cls");head=sort(head);list(head);;break;
			case 2:break;
			case 3:system("cls");menu_t();break;
			case 4:printf("\n");exit(0);break;
		}
		printf("\n��������Ҫ�޸���Ϣ��ѧ����ѧ�ţ�");
		scanf("%lf",&num);
		getchar();
		p1=head;                      //p1ָ���ͷ���
		while((num!=p1->num)&&(p1->next!=NULL))
		{
			p2=p1;                 //p2ָ��p1��ָ��Ľ��
            p1=p1->next ;          //p1ָ����һ�����
		}
		if( num==p1->num )    //�ж�p1�Ƿ�ָ��Ҫɾ���Ľ��
		{
			system("cls");
			printf("\n�������ѧ�Ŷ�Ӧ��ѧ������ϢΪ��\n\n");
			list_one(p1);
			printf("\n********************************************************************************************************\n");
			printf("***************************************��ѡ������Ҫ�޸ĵ�ѡ��*******************************************\n");
			printf("********************************************************************************************************\n");
			printf("------------------           1.ѧ��     2.����        3.����      4.�Ա�           ---------------------\n");
			printf("------------------           5.����     6.���֤��    7.ѧԺ      8.�༶           ---------------------\n");
		 	printf("------------------------||     9.�����޸���Ϣ����       0.����ϵͳ������     ||-------------------------\n");
		 	printf("********************************************************************************************************\n");
		 	printf("����ѡ��Ϊ��");
			c=judge_num(10);
			printf("%d\n",c);
			system("cls");
			switch(c)
			{
				case 1:head=modify_num(head,p1);break;
				case 2:head=modify_merge(head,p1,2,ch2);break;
				case 3:head=modify_age(head,p1);break;
				case 4:head=modify_sex(head,p1);break;
				case 5:head=modify_merge(head,p1,5,ch5);break;
				case 6:head=modify_merge(head,p1,6,ch6);break;
				case 7:head=modify_merge(head,p1,7,ch7);break;
				case 8:head=modify_merge(head,p1,8,ch8);break;
				case 9:system("cls");modify();break;
				case 0:system("cls");menu_t();break;
			}
			head=read();
			head=sort(head);
			list(head);
		}
		else
		{
			system("cls");
			printf("\n**************************������ѧ��Ϊ��%.0lf����Ϣ���޷�ִ��ɾ��������*********************************\n",num);
			printf("\n\nϵͳ��������֮����ת......");
			Sleep(2000);
			system("cls");
			modify();
		}
	}
}
StuManage *modify_num(StuManage *head,StuManage *p1)
{
	double a;
	char c;
	printf("\n*********************************����Ҫ�޸�ѧ��Ϊ%.0lf��ѧ����ѧ�ţ�************************************\n\n",p1->num);
	printf("\n�������ѧ�����µ�ѧ�ţ�");
	scanf("%lf",&a);
	getchar();
	printf("\n�Ƿ�Ҫ����ѧ����ԭѧ��  %.0lf  ��Ϊ��ѧ��  %.0lf ��y/n����",p1->num,a);
	c=judge_ch();
	printf("%c\n",c);
	if(c=='y'||c=='Y')
	{
		system("cls");
		p1->num=a;
		savefile_wb(head);
		head=read();
		printf("\n********************************************************************************************************\n");
		printf("******************************************��Ϣ�޸ĳɹ�!*************************************************\n\n\n");
		printf("\nϵͳ��������֮�������ת.......");
		Sleep(2000);
		system("cls");
		judge_modify();
	}
	else
	{
		system("cls");
		printf("\n********************************************************************************************************\n");
		printf("**************************************��ȡ���������Ϣ�޸ģ�********************************************\n\n\n");
		printf("\nϵͳ��������֮�������ת.......");
		Sleep(2000);
		system("cls");
		judge_modify();
	}
	return head;
}
StuManage *modify_age(StuManage *head,StuManage *p1)
{
	int age;
	char c;
	printf("\n*****************************����Ҫ�޸�ѧ��Ϊ%.0lf��ѧ�������䣡****************************************\n\n",p1->num);
	printf("�������ѧ�����µ����䣺");
	scanf("%d",&age);
	getchar();
	printf("\n�Ƿ�Ҫ����ѧ����ԭ����  %d  ��Ϊ������  %d ��y/n����",p1->age,age);
	c=judge_ch();
	printf("%c\n",c);
	if(c=='y'||c=='Y')
	{
		p1->age=age;
		savefile_wb(head);
		head=read();
		printf("\n***********************************************��Ϣ�޸ĳɹ�!********************************************\n\n\n");
		printf("\nϵͳ��������֮�������ת.......");
		Sleep(2000);
		system("cls");
		judge_modify();
	}
	else
	{
		system("cls");
		printf("\n**************************************��ȡ���������Ϣ�޸ģ�********************************************\n\n\n");
		printf("\nϵͳ��������֮�������ת.......");
		Sleep(2000);
		system("cls");
		judge_modify();
	}
	return head;
}
StuManage *modify_sex(StuManage *head,StuManage *p1)
{
	char c,sex[8];
	printf("\n*******************************����Ҫ�޸�ѧ��Ϊ%.0lf��ѧ�����Ա�**************************************\n\n",p1->num);
	printf("�������ѧ�����޸ĺ���Ա�");
	scanf("%s",sex);
	getchar();
	printf("\n�Ƿ�Ҫ����ѧ����ԭ�Ա�  %s  ��Ϊ������  %s ��y/n����",p1->sex,sex);
	c=judge_ch();
	printf("%c\n",c);
	if(c=='y'||c=='Y')
	{
		strcpy(p1->sex,sex);
		savefile_wb(head);
		head=read();
		printf("\n**************************************��Ϣ�޸ĳɹ�!*****************************************************\n\n\n");
		printf("\nϵͳ��������֮�������ת.......");
		Sleep(2000);
		system("cls");
		judge_modify();
	}
	else
	{
		system("cls");
		printf("\n**********************************��ȡ���������Ϣ�޸ģ�***********************************************\n\n\n");
		printf("\nϵͳ��������֮�������ת.......");
		Sleep(2000);
		system("cls");
		judge_modify();
	}
	return head;
}
StuManage *modify_merge(StuManage *head,StuManage *p1,int n,char ch[])
{
	char ch2[]="����",ch5[]="����",ch6[]="���֤��",ch7[]="ѧԺ",ch8[]="�༶",merge[20],c;
	int a;
	printf("�������ѧ�����޸ĺ��%s��",ch);
	scanf("%s",merge);
	getchar();
	switch(n)
	{
		case 2:printf("�Ƿ�Ҫ����ѧ����ԭ%s : %s  ��Ϊ��%s : %s ��y/n����",ch,p1->name,ch,merge);break;
		case 5:printf("�Ƿ�Ҫ����ѧ����ԭ%s : %s  ��Ϊ��%s : %s ��y/n����",ch,p1->nation,ch,merge);break;
		case 6:printf("�Ƿ�Ҫ����ѧ����ԭ%s : %s  ��Ϊ��%s : %s ��y/n����",ch,p1->idcard,ch,merge);break;
		case 7:printf("�Ƿ�Ҫ����ѧ����ԭ%s : %s  ��Ϊ��%s : %s ��y/n����",ch,p1->college,ch,merge);break;
		case 8:printf("�Ƿ�Ҫ����ѧ����ԭ%s : %s  ��Ϊ��%s : %s ��y/n����",ch,p1->cla,ch,merge);break;
	}
	c=judge_ch();
	printf("%c\n",c);
	if(c=='y'||c=='Y')
	{
		switch(n)
		{
			case 2:strcpy(p1->name,merge);break;
			case 5:strcpy(p1->nation,merge);break;
			case 6:strcpy(p1->idcard,merge);break;
			case 7:strcpy(p1->college,merge);break;
			case 8:strcpy(p1->cla,merge);break;
		}
		system("cls");
		printf("\n****************************************�޸ĺ�ĸ�ѧ������Ϣ����****************************************\n\n");
		list_one(p1);
		savefile_wb(head);
		head=read();
		printf("\n*******************************************��ѡ�����������Ĳ�����***************************************\n");
		printf("-----------------               1.�����޸�ѧ����Ϣ        2.����ϵͳ���˵�            --------------------\n");
		printf("------------------------------------------||    3.�˳�ϵͳ    ||------------------------------------------\n");
		printf("**********************************************************************************************************\n");
		printf("����ѡ��");
		a=judge_num(3);
		printf("%d\n",a);
		switch(a)
		{
			case 1:system("cls");modify();break;
			case 2:system("cls");menu_t();break;
			case 3:printf("\n");exit(0);
		}

	}
	else
	{
		printf("��ȡ���������Ϣ�޸ģ�\n");
		judge_modify();
	}
	return head;
}
void judge_modify()
{
	int a;
	printf("\n*****************************************��ѡ�����������Ĳ�����*****************************************\n");
	printf("********************************************************************************************************\n");
	printf("--------------------      1.������Ϣ�޸ĵĹ��ܽ���       2.����ϵͳ������            -------------------\n");
	printf("-----------------------------------------||   3.�˳�ϵͳ   ||-------------------------------------------\n");
	printf("********************************************************************************************************\n");
	printf("\n����ѡ��Ϊ��");
	a=judge_num(3);
	printf("%d\n",a);
	system("cls");
	switch(a)
	{
		case 1:modify();break;
		case 2:menu_t();break;
		case 3:exit(0);break;
	}
}
void list(StuManage *head)		//����ı�����ָ��head�������������Ϊ���߳��򣬱����ĳ�ʼλ��
{
	int i=1;
	StuManage *p;				//ʹ��ָ��p��������������
	if(head==NULL)
		printf("����Ϊ�գ�����\n");
	else
	{
		p=head;
		printf("********************************************************************************************************\n");
		printf("���|    ѧ��     |  ����  | ���� | �Ա� |   ����   |     ���֤����     |     ѧԺ    |     �༶    |\n");
		while(p!=NULL)
		{
			printf(" %-3d|%12.0lf | %+6s |  %2d  |  %2s  | %+6s   | %18s | %+10s  | %+11s |\n",i,p->num,p->name,p->age,p->sex,p->nation,p->idcard,p->college,p->cla);
			p=p->next;			//ָ��p���ƶ�
			i++;
		}
	}
}
void list_one(StuManage *p)
{
	int i=1;
    printf("���|    ѧ��     |  ����  | ���� | �Ա� |   ����   |     ���֤����     |     ѧԺ    |     �༶    |\n");
    printf(" %-3d|%12.0lf | %+6s |  %2d  |  %2s  | %+6s   | %18s | %+10s  | %+11s |\n",i,p->num,p->name,p->age,p->sex,p->nation,p->idcard,p->college,p->cla);
}
StuManage *sort(StuManage *head)
{
    StuManage *pfirst;      /* ���к��������ı�ͷָ�� */
    StuManage *ptail;       /* ���к��������ı�βָ�� */
    StuManage *pminBefore;  /* ������ֵ��С�Ľڵ��ǰ���ڵ��ָ�� */
    StuManage *pmin;        /* �洢��С�ڵ�   */
    StuManage *p;           /* ��ǰ�ȽϵĽڵ� */
    pfirst = NULL;
    while (head != NULL)         /*���������Ҽ�ֵ��С�Ľڵ㡣*/
    {
    /* ע�⣺����for����������ѡ������˼��ĵط� */
        for (p = head, pmin = head; p->next != NULL; p = p->next) /*ѭ�����������еĽڵ㣬�ҳ���ʱ��С�Ľڵ㡣*/
        {
           if (p->next->num < pmin->num) /*�ҵ�һ���ȵ�ǰminС�Ľڵ㡣*/
            {
                pminBefore = p;           /*�����ҵ��ڵ��ǰ���ڵ㣺��Ȼp->next��ǰ���ڵ���p��*/
                pmin       = p->next;     /*�����ֵ��С�Ľڵ㡣*/
            }
        }
   /*����for�������󣬾�Ҫ�������£�һ�ǰ����������������У����Ǹ�����Ӧ�������жϣ��������뿪ԭ��������*/

       /*��һ����*/
       if (pfirst == NULL)     /* �����������Ŀǰ����һ��������                      */
       {
           pfirst = pmin;      /* ��һ���ҵ���ֵ��С�Ľڵ㡣                          */
          ptail  = pmin;      /* ע�⣺βָ������ָ������һ���ڵ㡣                */
      }
       else                    /* �����������Ѿ��нڵ�                                */
       {
            ptail->next = pmin; /* �Ѹ��ҵ�����С�ڵ�ŵ���󣬼���βָ���nextָ������*/
            ptail = pmin;       /* βָ��ҲҪָ������                                  */
        }

        /*�ڶ�����*/
        if (pmin == head)        /* ����ҵ�����С�ڵ���ǵ�һ���ڵ�                    */
        {
            head = head->next;   /* ��Ȼ��headָ��ԭhead->next,���ڶ����ڵ㣬��OK       */
       }
       else /*������ǵ�һ���ڵ�*/
        {
            pminBefore->next = pmin->next; /*ǰ����С�ڵ��nextָ��ǰpmin��next,��������pmin�뿪��ԭ����*/
        }
    }
    if (pfirst != NULL)     /*ѭ�������õ���������first                */
        ptail->next = NULL; /*������������һ���ڵ��nextӦ��ָ��NULL */
    head = pfirst;
    return head;
}
StuManage *input_stu(StuManage *p,int i)
{
	printf("�������%d��ѧ����������",i);
	scanf("%s",p->name);
	printf("�������%d��ѧ�������䣺",i);
	scanf("%d",&p->age);
	printf("�������%d��ѧ�����Ա�",i);
	scanf("%s",p->sex);
	printf("�������%d��ѧ�������壺",i);
	scanf("%s",p->nation);
	printf("�������%d��ѧ�������֤���룺",i);
	scanf("%s",p->idcard);
	printf("�������%d��ѧ����ѧԺ��",i);
	scanf("%s",p->college);
	printf("�������%d��ѧ���İ༶��",i);
	scanf("%s",p->cla);
	getchar();
	return p;
}
