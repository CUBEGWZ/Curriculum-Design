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
	printf("*********【教师端】*************************************************************************************\n");
	printf("*********************************   学  生  信  息  管  理  系  统   *************   欢迎您：%8s\n",teacher.login_name);
	printf("**********************************************************************************   登录次数:第%3d次\n",teacher.login_time);
	printf("********************************************************************************************************\n");
	printf("||----------               1.创 建 学 生 信 息    ||    2.插 入 学 生 信 息                 -----------||\n");
	printf("||----------               3.删 除 学 生 信 息    ||    4.修 改 学 生 信 息                 -----------||\n");
	printf("||----------               5.查 询 学 生 信 息    ||    6.返 回 登 陆 界 面                 -----------||\n");
	printf("||----------               7.登 录 信 息 修 改    ||    8.退 出 管 理 系 统                 -----------||\n");
	printf("||-----------------------------------------------------------------------------------------------------||\n");
	printf("您的选择为:");
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
	printf("\n*******************************您现在进入了创建学生信息的界面！*****************************************\n");
	printf("                   （如果您要结束输入,请在系统提示您输入学号处输入0并回车！）\n");
	printf("********************************************************************************************************\n");
	StuManage *head=NULL,*p1,*p2;
	int i=1,n;
	char a,c='c';
	p1=p2=(StuManage *)malloc(LEN);
	printf("\n请输入第%d个学生的学号：",i);
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
		printf("请输入第%d个学生的学号：",i);
		scanf("%lf",&p1->num);
		getchar();
	}
	p2->next=NULL;
	system("cls");
	printf("\n您所建立的学生信息如下所示：\n");
	head=sort(head);
	list(head);
	printf("\n您输入的信息是否正确（y/n）？");
	a=judge_ch();
	if(a=='y'||a=='Y')
	{
		savefile_ab(head);
		system("cls");
		printf("\n********************************************************************************************************\n");
		printf("***********************************请选择您接下来的操作！***********************************************\n");
		printf("------------        1.继续建立的学生信息         2.查看建立的学生信息                      -------------\n");
		printf("------------        3.修改建立的学生信息         4.返回系统主菜单                          -------------\n");
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
			printf("************************************请选择您接下来的操作！**********************************************\n");
			printf("---------------         1.修改建立的学生信息         2.返回系统主菜单                  -----------------\n");
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
		printf("**************************由于您认为您刚才输入信息有误！现在进行信息修改！******************************\n");
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
		printf("**********************存储学生信息文件test.txt中学生信息为空！无法执行删除操作！************************\n");
		printf("----------------             1.创建学生信息              2.返回主菜单               --------------------\n");
		printf("--------------------------------------------------------------------------------------------------------\n");
		printf("\n你的选择为：");
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
		printf("**********************************您现在进入了删除学生信息的界面！**************************************\n");
		printf("***************************************请选择您接下来的操作！*******************************************\n");
		printf("------------------              1.浏览学生信息          2.直接进行删除操作            ------------------\n");
		printf("------------------              3.返回系统主菜单        4.退出系统                    ------------------\n");
		printf("********************************************************************************************************\n");
		printf("您的选择为:");
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
		printf("请输入要删除的学生学号：");
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
			printf("该学生的信息为：\n\n");
			list_one(p1);
			printf("\n是否要删除该学生信息（y/n）？");
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
				printf("*****************************************学生信息已经成功删除!******************************************\n");
				printf("\n系统将在两秒之后自动跳转.......\n");
				Sleep(2000);
				system("cls");
				savefile_wb(head);
				head=read();
				judge_del_continue(head);
			}
			else
			{
				system("cls");
				printf("您取消了删除该学生信息！");
				judge_del_choose();
			}
		}
		else
		{
			system("cls");
			printf("\n*****************************信息表中不存在该学生的信息，无法执行删除操作！*****************************\n");
			judge_del_choose();
		}
	}
}
void judge_del_continue(StuManage *head)
{
	char c;
	printf("是否继续删除学生信息(y/n)？");
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
	printf("****************************************请选择您接下来的操作！******************************************\n");
	printf("--------------------||       1.返回删除菜单界面       2.返回主菜单          ||--------------------------\n");
	printf("----------------------------------------||  3.退出系统   ||---------------------------------------------\n");
	printf("--------------------------------------------------------------------------------------------------------\n");
	printf("\n您的选择为:");
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
		printf("                       存储学生信息文件test.txt中学生信息为空！无法执行查找操作！\n");
		printf("                                1.创建学生信息        2.返回主菜单\n");
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
		char name[]="姓名",idcard[]="身份证号",college[]="学院",cla[]="班级";
		system("cls");
		printf("********************************************************************************************************\n");
		printf("************************************您现在进入了查询学生信息的界面！************************************\n");
		printf("*****************************************请选择您接下来的操作！*****************************************\n");
		printf("-------------------                1.按学号查询        2.按姓名查询                 --------------------\n");
		printf("-------------------                3.按身份证号查询    4.按学院查询                 --------------------\n");
		printf("-------------------                5.按班级查询        6.返回主菜单                 --------------------\n");
		printf("------------------------------------------||   7.退出系统    ||-----------------------------------------\n");
		printf("********************************************************************************************************\n");
		printf("\n你的选择为：");
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
	printf("*****************************欢迎进入按照学号查询学生信息的界面！***************************************\n\n");
	StuManage *head=NULL;
	head=read();
	int n=countnode(head),i,a,b=1,c=1,d=0;
	double num;
	StuManage *p=head;
	printf("\n请输入您要查找的学号:");
	scanf("%lf",&num);
	getchar();
	for(i=1;i<=n;i++)
	{
		if(p->num==num)
		{
			if(b==1)
			{
				system("cls");
				printf("\n您所查找的学号对应的学生信息为：\n\n");
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
		printf("********************************学生信息中没有您要查找的学号的学生！************************************\n\n");
		printf("\n系统将在两秒之后进行跳转.......\n");
		Sleep(2000);
		system("cls");
		printf("**********************************请选择您接下来的操作！************************************************\n");
		printf("********************************************************************************************************\n");
		printf("--------------           1.重新输入学号进行查询         2.返回查询信息的界面                 -----------\n");
		printf("--------------           3.返回主菜单                  4.退出系统                            -----------\n");
		printf("********************************************************************************************************\n");
		printf("\n您的选择为：");
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
	printf("*******************************欢迎进入按照%s查询学生信息的界面！***************************************\n\n",ch);
	printf("\n请输入您要查找的%s:",ch);
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
					printf("您所查找的%s对应的学生信息为：\n\n",ch);
				list_one(p);
				b=2;
			}
			case 3:
			if(!strcmp(p->idcard,merge))
			{
				if(b==1)
					printf("您所查找的%s对应的学生信息为：\n\n",ch);
				list_one(p);
				b=2;
			}
			break;
			case 4:
			if(!strcmp(p->college,merge))
			{
				if(b==1)
					printf("您所查找的%s对应的学生信息为：\n\n",ch);
				list_one(p);
				b=2;
			}
			break;
			case 5:
			if(!strcmp(p->cla,merge))
			{
				if(b==1)
					printf("您所查找的%s对应的学生信息为：\n\n",ch);
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
		printf("****************************学生信息中没有您要查找的%s对应的的学生！************************************\n\n",ch);
		printf("\n系统将在两秒之后进行跳转.......\n");
		Sleep(2000);
		system("cls");
		printf("\n**************************************请选择您接下来的操作！********************************************\n");
		printf("********************************************************************************************************\n");
		printf("----------------         1.重新输入%s进行查询        2.返回查询信息的主界面      -----------------------\n",ch);
		printf("----------------         3.返回主菜单                4.退出系统                  -----------------------\n");
		printf("********************************************************************************************************\n");
		printf("\n您的选择为：");
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
	char n,ch2[]="姓名",ch3[]="身份证号",ch4[]="学院",ch5[]="班级";
	int c;
	printf("\n\n是否继续执行查找操作（y/n）？");
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
		printf("******************************************请选择您接下来的操作！****************************************\n");
		printf("----------------             1.返回查询系统界面     2.返回系统主界面               ---------------------\n");
		printf("-------------------------------------------||  3.退出系统   ||------------------------------------------\n");
		printf("********************************************************************************************************\n");
		printf("\n您的选择：");
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
	printf("***********************************您现在进入了插入学生信息的界面！*************************************\n");
	printf("********************************************************************************************************\n");
	StuManage *head=NULL;
	int a=judge_null();
	char c;
	if(!a)
	{
		printf("**************** 存储学生信息文件test.txt中学生信息为空！建议您先创建学生信息！*************************\n\n");
		printf("\n系统将在两秒之后进行跳转.......");
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
		printf("请输入学生的学号：");
		scanf("%lf",&p0->num);
		p0=input_stu(p0,1);
		system("cls");
		printf("您所输入的学生信息如下所示：\n\n");
		list_one(p0);
		printf("\n");
		head=judge_insert_validity(head,p0,p1,p2);
	}
}
StuManage *judge_insert_continue(StuManage *head)
{
	char c;
	int a;
	printf("是否继续插入学生信息(y/n)？");
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
		printf("\n************************************您选择了停止插入学生信息！******************************************\n");
		printf("\n系统将在两秒之后进行跳转.....\n");
		Sleep(2000);
		system("cls");
		printf("\n********************************************************************************************************\n");
		printf("****************************************请选择您接下来的操作！******************************************\n");
		printf("------------------||             1.查看插入学生信息后的学生信息表             ||------------------------\n");
		printf("------------------||             2.返回主菜单          3.退出系统             ||------------------------\n");
		printf("--------------------------------------------------------------------------------------------------------\n");
		printf("\n您的选择为：");
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
		printf("\n您刚输入的学生信息是否正确（y/n）？");
		c=judge_ch();
		printf("%c\n",c);
		if(c=='y'||c=='Y')
		{
			p0->next = NULL;
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
			head=read();
			head=judge_insert_continue(head);
		}
		else
		{

			savefile_wb(head);
			printf("\n***********************************您认为您刚才输入的信息有误！*****************************************\n");
			printf("***************************************请选择您的下一步操作！*******************************************\n");
			printf("----------------         1.执行数据修改功能       2.保存数据并返回插入功能界面      --------------------\n");
			printf("----------------         3.返回系统主界面         4.退出系统                        --------------------\n");
			printf("--------------------------------------------------------------------------------------------------------\n");
			printf("您的选择：");
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
		printf("请输入第1个学生的学号：");
		scanf("%lf",&p0->num);
		p0=input_stu(p0,1);
		printf("您所输入的学生信息如下所示：");
		list_one(p0);
		head=judge_insert_validity(head,p0,p1,p2);
	return head;
}
void judge_insert_continue_2()
{
	int a;
	printf("\n***************************************请选择您接下来的操作！*******************************************\n");
	printf("------------------        1.继续插入学生信息        2.返回系统主菜单             -----------------------\n");
	printf("-------------------------------------||    3.退出系统   ||----------------------------------------------\n");
	printf("--------------------------------------------------------------------------------------------------------\n");
	printf("\n您的选择为:");
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
	char ch2[]="姓名",ch5[]="民族",ch6[]="身份证号",ch7[]="学院",ch8[]="班级";
	if(!a)
	{
		system("cls");
		printf("\n********************************************************************************************************\n");
		printf("                    存储学生信息文件test.txt中学生信息为空！无法执行修改操作！\n");
		printf("----------------                1.创建学生信息           2.返回主菜单             ----------------------\n");
		printf("--------------------------------------------------------------------------------------------------------\n");
		printf("\n您的选择为：");
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
		printf("***************************************您现在进入了修改学生信息的界面！*********************************\n");
		printf("********************************************请选择您接下来的操作！**************************************\n");
		printf("-------------------               1.浏览学生信息       2.直接进行修改操作           --------------------\n");
		printf("-------------------               3.返回系统主菜单     4.退出系统                   --------------------\n");
		printf("********************************************************************************************************\n");
		printf("\n您的选择为:");
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
		printf("\n请输入您要修改信息的学生的学号：");
		scanf("%lf",&num);
		getchar();
		p1=head;                      //p1指向表头结点
		while((num!=p1->num)&&(p1->next!=NULL))
		{
			p2=p1;                 //p2指向p1所指向的结点
            p1=p1->next ;          //p1指向下一个结点
		}
		if( num==p1->num )    //判断p1是否指向要删除的结点
		{
			system("cls");
			printf("\n您输入的学号对应的学生的信息为：\n\n");
			list_one(p1);
			printf("\n********************************************************************************************************\n");
			printf("***************************************请选择您将要修改的选项*******************************************\n");
			printf("********************************************************************************************************\n");
			printf("------------------           1.学号     2.姓名        3.年龄      4.性别           ---------------------\n");
			printf("------------------           5.民族     6.身份证号    7.学院      8.班级           ---------------------\n");
		 	printf("------------------------||     9.返回修改信息界面       0.返回系统主界面     ||-------------------------\n");
		 	printf("********************************************************************************************************\n");
		 	printf("您的选择为：");
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
			printf("\n**************************不存在学号为：%.0lf的信息，无法执行删除操作！*********************************\n",num);
			printf("\n\n系统将在两秒之后跳转......");
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
	printf("\n*********************************您将要修改学号为%.0lf的学生的学号！************************************\n\n",p1->num);
	printf("\n请输入该学生的新的学号：");
	scanf("%lf",&a);
	getchar();
	printf("\n是否要将该学生的原学号  %.0lf  改为新学号  %.0lf （y/n）？",p1->num,a);
	c=judge_ch();
	printf("%c\n",c);
	if(c=='y'||c=='Y')
	{
		system("cls");
		p1->num=a;
		savefile_wb(head);
		head=read();
		printf("\n********************************************************************************************************\n");
		printf("******************************************信息修改成功!*************************************************\n\n\n");
		printf("\n系统将在两秒之后进行跳转.......");
		Sleep(2000);
		system("cls");
		judge_modify();
	}
	else
	{
		system("cls");
		printf("\n********************************************************************************************************\n");
		printf("**************************************您取消了这次信息修改！********************************************\n\n\n");
		printf("\n系统将在两秒之后进行跳转.......");
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
	printf("\n*****************************您将要修改学号为%.0lf的学生的年龄！****************************************\n\n",p1->num);
	printf("请输入该学生的新的年龄：");
	scanf("%d",&age);
	getchar();
	printf("\n是否要将该学生的原年龄  %d  改为新年龄  %d （y/n）？",p1->age,age);
	c=judge_ch();
	printf("%c\n",c);
	if(c=='y'||c=='Y')
	{
		p1->age=age;
		savefile_wb(head);
		head=read();
		printf("\n***********************************************信息修改成功!********************************************\n\n\n");
		printf("\n系统将在两秒之后进行跳转.......");
		Sleep(2000);
		system("cls");
		judge_modify();
	}
	else
	{
		system("cls");
		printf("\n**************************************您取消了这次信息修改！********************************************\n\n\n");
		printf("\n系统将在两秒之后进行跳转.......");
		Sleep(2000);
		system("cls");
		judge_modify();
	}
	return head;
}
StuManage *modify_sex(StuManage *head,StuManage *p1)
{
	char c,sex[8];
	printf("\n*******************************您将要修改学号为%.0lf的学生的性别！**************************************\n\n",p1->num);
	printf("请输入该学生的修改后的性别：");
	scanf("%s",sex);
	getchar();
	printf("\n是否要将该学生的原性别  %s  改为新年龄  %s （y/n）？",p1->sex,sex);
	c=judge_ch();
	printf("%c\n",c);
	if(c=='y'||c=='Y')
	{
		strcpy(p1->sex,sex);
		savefile_wb(head);
		head=read();
		printf("\n**************************************信息修改成功!*****************************************************\n\n\n");
		printf("\n系统将在两秒之后进行跳转.......");
		Sleep(2000);
		system("cls");
		judge_modify();
	}
	else
	{
		system("cls");
		printf("\n**********************************您取消了这次信息修改！***********************************************\n\n\n");
		printf("\n系统将在两秒之后进行跳转.......");
		Sleep(2000);
		system("cls");
		judge_modify();
	}
	return head;
}
StuManage *modify_merge(StuManage *head,StuManage *p1,int n,char ch[])
{
	char ch2[]="姓名",ch5[]="民族",ch6[]="身份证号",ch7[]="学院",ch8[]="班级",merge[20],c;
	int a;
	printf("请输入该学生的修改后的%s：",ch);
	scanf("%s",merge);
	getchar();
	switch(n)
	{
		case 2:printf("是否要将该学生的原%s : %s  改为新%s : %s （y/n）？",ch,p1->name,ch,merge);break;
		case 5:printf("是否要将该学生的原%s : %s  改为新%s : %s （y/n）？",ch,p1->nation,ch,merge);break;
		case 6:printf("是否要将该学生的原%s : %s  改为新%s : %s （y/n）？",ch,p1->idcard,ch,merge);break;
		case 7:printf("是否要将该学生的原%s : %s  改为新%s : %s （y/n）？",ch,p1->college,ch,merge);break;
		case 8:printf("是否要将该学生的原%s : %s  改为新%s : %s （y/n）？",ch,p1->cla,ch,merge);break;
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
		printf("\n****************************************修改后的该学生的信息如下****************************************\n\n");
		list_one(p1);
		savefile_wb(head);
		head=read();
		printf("\n*******************************************请选择您接下来的操作！***************************************\n");
		printf("-----------------               1.继续修改学生信息        2.返回系统主菜单            --------------------\n");
		printf("------------------------------------------||    3.退出系统    ||------------------------------------------\n");
		printf("**********************************************************************************************************\n");
		printf("您的选择：");
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
		printf("您取消了这次信息修改！\n");
		judge_modify();
	}
	return head;
}
void judge_modify()
{
	int a;
	printf("\n*****************************************请选择您接下来的操作！*****************************************\n");
	printf("********************************************************************************************************\n");
	printf("--------------------      1.返回信息修改的功能界面       2.返回系统主界面            -------------------\n");
	printf("-----------------------------------------||   3.退出系统   ||-------------------------------------------\n");
	printf("********************************************************************************************************\n");
	printf("\n您的选择为：");
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
void list(StuManage *head)		//链表的遍历，指针head这个参数的作用为告诉程序，遍历的初始位置
{
	int i=1;
	StuManage *p;				//使用指针p来遍历整个链表
	if(head==NULL)
		printf("链表为空！！！\n");
	else
	{
		p=head;
		printf("********************************************************************************************************\n");
		printf("序号|    学号     |  姓名  | 年龄 | 性别 |   民族   |     身份证号码     |     学院    |     班级    |\n");
		while(p!=NULL)
		{
			printf(" %-3d|%12.0lf | %+6s |  %2d  |  %2s  | %+6s   | %18s | %+10s  | %+11s |\n",i,p->num,p->name,p->age,p->sex,p->nation,p->idcard,p->college,p->cla);
			p=p->next;			//指针p的移动
			i++;
		}
	}
}
void list_one(StuManage *p)
{
	int i=1;
    printf("序号|    学号     |  姓名  | 年龄 | 性别 |   民族   |     身份证号码     |     学院    |     班级    |\n");
    printf(" %-3d|%12.0lf | %+6s |  %2d  |  %2s  | %+6s   | %18s | %+10s  | %+11s |\n",i,p->num,p->name,p->age,p->sex,p->nation,p->idcard,p->college,p->cla);
}
StuManage *sort(StuManage *head)
{
    StuManage *pfirst;      /* 排列后有序链的表头指针 */
    StuManage *ptail;       /* 排列后有序链的表尾指针 */
    StuManage *pminBefore;  /* 保留键值更小的节点的前驱节点的指针 */
    StuManage *pmin;        /* 存储最小节点   */
    StuManage *p;           /* 当前比较的节点 */
    pfirst = NULL;
    while (head != NULL)         /*在链表中找键值最小的节点。*/
    {
    /* 注意：这里for语句就是体现选择排序思想的地方 */
        for (p = head, pmin = head; p->next != NULL; p = p->next) /*循环遍历链表中的节点，找出此时最小的节点。*/
        {
           if (p->next->num < pmin->num) /*找到一个比当前min小的节点。*/
            {
                pminBefore = p;           /*保存找到节点的前驱节点：显然p->next的前驱节点是p。*/
                pmin       = p->next;     /*保存键值更小的节点。*/
            }
        }
   /*上面for语句结束后，就要做两件事；一是把它放入有序链表中；二是根据相应的条件判断，安排它离开原来的链表。*/

       /*第一件事*/
       if (pfirst == NULL)     /* 如果有序链表目前还是一个空链表                      */
       {
           pfirst = pmin;      /* 第一次找到键值最小的节点。                          */
          ptail  = pmin;      /* 注意：尾指针让它指向最后的一个节点。                */
      }
       else                    /* 有序链表中已经有节点                                */
       {
            ptail->next = pmin; /* 把刚找到的最小节点放到最后，即让尾指针的next指向它。*/
            ptail = pmin;       /* 尾指针也要指向它。                                  */
        }

        /*第二件事*/
        if (pmin == head)        /* 如果找到的最小节点就是第一个节点                    */
        {
            head = head->next;   /* 显然让head指向原head->next,即第二个节点，就OK       */
       }
       else /*如果不是第一个节点*/
        {
            pminBefore->next = pmin->next; /*前次最小节点的next指向当前pmin的next,这样就让pmin离开了原链表。*/
        }
    }
    if (pfirst != NULL)     /*循环结束得到有序链表first                */
        ptail->next = NULL; /*单向链表的最后一个节点的next应该指向NULL */
    head = pfirst;
    return head;
}
StuManage *input_stu(StuManage *p,int i)
{
	printf("请输入第%d个学生的姓名：",i);
	scanf("%s",p->name);
	printf("请输入第%d个学生的年龄：",i);
	scanf("%d",&p->age);
	printf("请输入第%d个学生的性别：",i);
	scanf("%s",p->sex);
	printf("请输入第%d个学生的民族：",i);
	scanf("%s",p->nation);
	printf("请输入第%d个学生的身份证号码：",i);
	scanf("%s",p->idcard);
	printf("请输入第%d个学生的学院：",i);
	scanf("%s",p->college);
	printf("请输入第%d个学生的班级：",i);
	scanf("%s",p->cla);
	getchar();
	return p;
}
