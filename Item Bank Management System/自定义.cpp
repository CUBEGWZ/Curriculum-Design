#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"
void menu1()
{   printf("                \t**********以管理员身份运行***********\n");
	int x;
	char n;
	struct M *head;
	printf("                \t*************************************\n");
	printf("                \t***    欢 迎 进 入 题 库 系 统    ***\n\n");
	printf("                \t***     1.题 目 的 输 入          ***\n\n");
	printf("                \t***     2.题 目 的 浏 览          ***\n\n");
	printf("                \t***     3.题 目 的 删 除          ***\n\n");
	printf("                \t***     4.题 目 的 添 加          ***\n\n");
	printf("                \t***     5.题 目 的 查 找          ***\n\n");
	printf("                \t***     6.退 出 系 统             ***\n\n");
	printf("                \t***    输入1--6(第一次打开输入1)  ***\n");
	printf("                \t*************************************\n");
	printf("请输入功能选项：");
	while(scanf("%d",&x)!=EOF)
	{
		switch (x)
		{
			case 1:input();break;
			case 2:list();printf("题目已输出!请输入回车返回主菜单!");getchar();getchar();system("cls");menu1();break;
			case 3:head=creat();del(head);break;
			case 4:head=creat();add(head);break;
			case 5:head=creat();find(head);menu1();break;
			case 6:printf("您真的忍心要离开我吗QWQ！若执意离开请输入回车否则按任意键返回主菜单！");getchar();scanf("%c",&n);if(n=='\n'){exit(0);}else{system("cls");menu1();}
			default:printf("请输入正确的数!\n");
		}
	}
}
void menu2()
{   printf("                \t***************学生界面**************\n");
	int x;
	char n;
	struct M *head;
	printf("                \t*************************************\n");
	printf("                \t***    欢 迎 进 入 题 库 系 统    ***\n\n");
	printf("                \t***     1.题 目 的 作 答          ***\n\n");
	printf("                \t***     2.题 目 的 浏 览          ***\n\n");
	printf("                \t***     3.题 目 的 查 找          ***\n\n");
	printf("                \t***     4.错 题 的 浏 览          ***\n\n");
	printf("                \t***     5.退 出 系 统             ***\n\n");
	printf("                \t***    输入1--5                   ***\n");
	printf("                \t*************************************\n");
	printf("请输入功能选项：");
	while(scanf("%d",&x)!=EOF)
	{
		switch (x)
		{
			case 1:DO();break;
			case 2:list();printf("题目已输出!请输入回车返回主菜单!");getchar();getchar();system("cls");menu2();break;
			case 3:head=creat();find(head);menu2();break;
			case 4:list2();printf("错题已输出!请输入回车返回主菜单!");getchar();getchar();system("cls");menu2();break;
			case 5:printf("您真的忍心要离开我吗QWQ！若执意离开请输入回车否则按任意键返回主菜单！");getchar();scanf("%c",&n);if(n=='\n'){exit(0);}else{system("cls");menu2();}
			default:printf("请输入正确的数!\n");
		}
	}
}
void input()
{  
	system("cls");
	FILE *f1;
	char a[10],b[100],c[100],d[100],e[10];
    f1=fopen("GD.txt","w");
	if(f1==NULL)
	{exit(0);}
	printf("请输入题号(01、02...)、题目、题型、答案与分值(以0结束)：\n");
	scanf("%s",&a);
	while(strcmp(a,"0")!=0)
	{
		scanf("%s %s %s %s",&b,&c,&d,&e);
		fprintf(f1,"%s %s %s %s %s",a,b,c,d,e);
		scanf("%s",&a);
		if(strcmp(a,"0")!=0)
		{fprintf(f1,"\n");}	
	}
	fclose(f1);
	printf("题库已建好！请输入回车返回主菜单!");
	getchar();
	getchar();
	system("cls");
	menu1();
}
struct M *creat()
{
	FILE *f1;
	struct M *p,*q,*head=NULL;
    f1=fopen("GD.txt","r");
	if(f1==NULL)
	{exit(0);}
	p=q=(struct M *)malloc(N);
	while(!feof(f1))
	{
		fscanf(f1,"%s %s %s %s %s",p->a,p->b,p->c,p->d,p->e);
		if(head==NULL)
		{head=p;}
		else
		{q->next=p;}
		q=p;
		p=(struct M *)malloc(N);
	}
	q->next=NULL;
	free(p);
	fclose(f1);
	return head;
}
void del(struct M *head)
{
	system("cls");
	struct M *p=head,*q;
	char n[10],x;
	printf("请输入要删除的题号:");
	scanf("%s",&n);
	while(strcmp(p->a,n)!=0&&p->next!=NULL)
	{
		q=p;
		p=p->next;
	}
	if(strcmp(p->a,n)==0)
	{
		if(p==head)
		{head=p->next;}
		else
		{q->next=p->next;}
		free(p);
		save(head);
		list();
		printf("题目已删除！\n");
	}
	else
	{printf("不存在要删除的题号!\n");}
	getchar();
	printf("如果想继续删除请输入'y',如果操作完毕请输入回车返回主菜单:");
	scanf("%c",&x);
	if(x=='y')
	{del(head);}
	system("cls");
	menu1();
}
void add(struct M *head)
{
	system("cls");
	struct M *p1=head,*p2,*p0;
	char n[10],x;	
	printf("请输入插入位置的题号(待插入的内容在此号之前):");
	scanf("%s",&n);
	p0=(struct M *)malloc(N);
	while(strcmp(p1->a,n)!=0&&p1->next!=NULL)
	{
		p2=p1;
		p1=p1->next;
	}
	if(strcmp(p1->a,n)==0)
	{
		printf("请输入待插入的题号、题目、题型、答案与分值：\n");
		scanf("%s %s %s %s %s",p0->a,p0->b,p0->c,p0->d,p0->e);
		if(p1==head)
		{
			head=p0;
			p0->next=p1;
		}
		else
		{
			p2->next=p0;
			p0->next=p1;
		}
		save(head);
		list();
		printf("题目已添加！\n");
	}
	else
	{printf("插入位置不存在!\n");}
	getchar();
	printf("如果想继续添加请输入'y',如果操作完毕请输入回车返回主菜单:");
	scanf("%c",&x);
	if(x=='y')
	{add(head);}
	system("cls");
	menu1();
}
void save(struct M *head)
{
	FILE *f1;
	struct M *p=head;
	f1=fopen("GD.txt","w");
	while(p!=NULL)
	{
		fprintf(f1,"%s %s %s %s %s",p->a,p->b,p->c,p->d,p->e);
		p=p->next;
		if(p!=NULL)
		{fprintf(f1,"\n");}
	}
	fclose(f1);
}
void find(struct M *head)
{
	system("cls");
	struct M *p=head;
	char n[100],m;
	int x,k=0;
	printf("请选择查找方式(输入1为按题号查找、2按题目查找、3按题型查找、4按分数查找)：");
	scanf("%d",&x);
	if(x==1)
	{
		printf("请输入查找的题号:");
		scanf("%s",&n);
		while(strcmp(p->a,n)!=0&&p->next!=NULL)
		{p=p->next;}
		if(strcmp(p->a,n)==0)
		{
			printf("题号：%s 题目：%s 题型：%s 答案：%s 分值：%s\n",p->a,p->b,p->c,p->d,p->e);
			printf("题目已找到！\n");
		}
		else
		{printf("不存在该题号！\n");}
	}
	else if(x==2)
	{
		printf("请输入查找的题目:");
		scanf("%s",&n);
		while(strcmp(p->b,n)!=0&&p->next!=NULL)
		{p=p->next;}
		if(strcmp(p->b,n)==0)
		{
			printf("题号：%s 题目：%s 题型：%s 答案：%s 分值：%s\n",p->a,p->b,p->c,p->d,p->e);
			printf("题目已找到！\n");
		}
		else
		{printf("不存在该题目！\n");}
	}
	else if(x==3)
	{
		printf("请输入查找的题型:");
		scanf("%s",&n);
		while(p!=NULL)
		{
			if(strcmp(p->c,n)==0)
			{
				printf("题号：%s 题目：%s 题型：%s 答案：%s 分值：%s\n",p->a,p->b,p->c,p->d,p->e);
				k++;
			}
			p=p->next;
		}
		if(k==0)
		{printf("不存在该题型的题目！\n");}
		else
		{printf("题目已找到！\n");}
	}
	else if(x==4)
	{
		printf("请输入查找的分值:");
		scanf("%s",&n);
		while(p!=NULL)
		{
			if(strcmp(p->e,n)==0)
			{
				printf("题号：%s 题目：%s 题型：%s 答案：%s 分值：%s\n",p->a,p->b,p->c,p->d,p->e);
				k++;
			}
			p=p->next;
		}
		if(k==0)
		{printf("不存在该分值的题目！\n");}
		else
		{printf("题目已找到！\n");}
	}
	else
	{
		printf("请输入正确的数!\n");
		getchar();
		getchar();
		find(head);
	}
	getchar();
	printf("如果想继续查找请输入'y',如果操作完毕请回车返回主菜单:");
	scanf("%c",&m);
	if(m=='y')
	{find(head);}
	system("cls");
}
void list()
{
	system("cls");
	FILE *f1;
	char a[10],b[100],c[100],d[100],e[10];
    f1=fopen("GD.txt","r");
	if(f1==NULL)
	{exit(0);}
	while(!feof(f1))
	{
		fscanf(f1,"%s %s %s %s %s",a,b,c,d,e);
		printf("题号：%s 题目：%s 题型：%s 答案：%s 分值：%s\n",a,b,c,d,e);
	}
	fclose(f1);
}
void list2()
{  
	system("cls");
	printf("以下为错题集\n");
	FILE *f2;
	char a[10],b[100],c[100],d[100],e[10];
    f2=fopen("错题集.txt","r");
	if(f2==NULL)
	{exit(0);}
	while(!feof(f2))
	{
		fscanf(f2,"%s %s %s %s %s",a,b,c,d,e);
		printf("题号：%s 题目：%s 题型：%s 答案：%s 分值：%s\n",a,b,c,d,e);
	}
	fclose(f2);
}
void DO()
{
	system("cls");
	FILE *f1,*f2;
	char a[10],b[100],c[100],d[100],e[10],f[100];
	printf("请开始答题:\n");
	f1=fopen("GD.txt","r");
	f2=fopen("错题集.txt","w");
	while(!feof(f1))
	{
		fscanf(f1,"%s %s %s %s %s",a,b,c,d,e);
		printf("题号：%s 题目：%s 题型：%s 分值：%s\n",a,b,c,e);
		printf("答案:");
		scanf("%s",f);
		if(strcmp(d,f)==0)
		{printf("答题正确!\n");}
		else
		{  	
			printf("答案错误，正确答案为:%s  本题将存入错题集!\n",d);
			fprintf(f2,"%s %s %s %s %s",a,b,c,d,e);
			if(!feof(f1))
			{fprintf(f2,"\n");}
		}

	}
	fclose(f2);
	fclose(f1);	
	printf("题目已完成请输入回车返回主菜单:");
	getchar();
	getchar();
	system("cls");
	menu2();
}