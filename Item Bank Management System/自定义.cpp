#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"
void menu1()
{   printf("                \t**********�Թ���Ա�������***********\n");
	int x;
	char n;
	struct M *head;
	printf("                \t*************************************\n");
	printf("                \t***    �� ӭ �� �� �� �� ϵ ͳ    ***\n\n");
	printf("                \t***     1.�� Ŀ �� �� ��          ***\n\n");
	printf("                \t***     2.�� Ŀ �� � ��          ***\n\n");
	printf("                \t***     3.�� Ŀ �� ɾ ��          ***\n\n");
	printf("                \t***     4.�� Ŀ �� �� ��          ***\n\n");
	printf("                \t***     5.�� Ŀ �� �� ��          ***\n\n");
	printf("                \t***     6.�� �� ϵ ͳ             ***\n\n");
	printf("                \t***    ����1--6(��һ�δ�����1)  ***\n");
	printf("                \t*************************************\n");
	printf("�����빦��ѡ�");
	while(scanf("%d",&x)!=EOF)
	{
		switch (x)
		{
			case 1:input();break;
			case 2:list();printf("��Ŀ�����!������س��������˵�!");getchar();getchar();system("cls");menu1();break;
			case 3:head=creat();del(head);break;
			case 4:head=creat();add(head);break;
			case 5:head=creat();find(head);menu1();break;
			case 6:printf("���������Ҫ�뿪����QWQ����ִ���뿪������س�����������������˵���");getchar();scanf("%c",&n);if(n=='\n'){exit(0);}else{system("cls");menu1();}
			default:printf("��������ȷ����!\n");
		}
	}
}
void menu2()
{   printf("                \t***************ѧ������**************\n");
	int x;
	char n;
	struct M *head;
	printf("                \t*************************************\n");
	printf("                \t***    �� ӭ �� �� �� �� ϵ ͳ    ***\n\n");
	printf("                \t***     1.�� Ŀ �� �� ��          ***\n\n");
	printf("                \t***     2.�� Ŀ �� � ��          ***\n\n");
	printf("                \t***     3.�� Ŀ �� �� ��          ***\n\n");
	printf("                \t***     4.�� �� �� � ��          ***\n\n");
	printf("                \t***     5.�� �� ϵ ͳ             ***\n\n");
	printf("                \t***    ����1--5                   ***\n");
	printf("                \t*************************************\n");
	printf("�����빦��ѡ�");
	while(scanf("%d",&x)!=EOF)
	{
		switch (x)
		{
			case 1:DO();break;
			case 2:list();printf("��Ŀ�����!������س��������˵�!");getchar();getchar();system("cls");menu2();break;
			case 3:head=creat();find(head);menu2();break;
			case 4:list2();printf("���������!������س��������˵�!");getchar();getchar();system("cls");menu2();break;
			case 5:printf("���������Ҫ�뿪����QWQ����ִ���뿪������س�����������������˵���");getchar();scanf("%c",&n);if(n=='\n'){exit(0);}else{system("cls");menu2();}
			default:printf("��������ȷ����!\n");
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
	printf("���������(01��02...)����Ŀ�����͡������ֵ(��0����)��\n");
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
	printf("����ѽ��ã�������س��������˵�!");
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
	printf("������Ҫɾ�������:");
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
		printf("��Ŀ��ɾ����\n");
	}
	else
	{printf("������Ҫɾ�������!\n");}
	getchar();
	printf("��������ɾ��������'y',����������������س��������˵�:");
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
	printf("���������λ�õ����(������������ڴ˺�֮ǰ):");
	scanf("%s",&n);
	p0=(struct M *)malloc(N);
	while(strcmp(p1->a,n)!=0&&p1->next!=NULL)
	{
		p2=p1;
		p1=p1->next;
	}
	if(strcmp(p1->a,n)==0)
	{
		printf("��������������š���Ŀ�����͡������ֵ��\n");
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
		printf("��Ŀ����ӣ�\n");
	}
	else
	{printf("����λ�ò�����!\n");}
	getchar();
	printf("�����������������'y',����������������س��������˵�:");
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
	printf("��ѡ����ҷ�ʽ(����1Ϊ����Ų��ҡ�2����Ŀ���ҡ�3�����Ͳ��ҡ�4����������)��");
	scanf("%d",&x);
	if(x==1)
	{
		printf("��������ҵ����:");
		scanf("%s",&n);
		while(strcmp(p->a,n)!=0&&p->next!=NULL)
		{p=p->next;}
		if(strcmp(p->a,n)==0)
		{
			printf("��ţ�%s ��Ŀ��%s ���ͣ�%s �𰸣�%s ��ֵ��%s\n",p->a,p->b,p->c,p->d,p->e);
			printf("��Ŀ���ҵ���\n");
		}
		else
		{printf("�����ڸ���ţ�\n");}
	}
	else if(x==2)
	{
		printf("��������ҵ���Ŀ:");
		scanf("%s",&n);
		while(strcmp(p->b,n)!=0&&p->next!=NULL)
		{p=p->next;}
		if(strcmp(p->b,n)==0)
		{
			printf("��ţ�%s ��Ŀ��%s ���ͣ�%s �𰸣�%s ��ֵ��%s\n",p->a,p->b,p->c,p->d,p->e);
			printf("��Ŀ���ҵ���\n");
		}
		else
		{printf("�����ڸ���Ŀ��\n");}
	}
	else if(x==3)
	{
		printf("��������ҵ�����:");
		scanf("%s",&n);
		while(p!=NULL)
		{
			if(strcmp(p->c,n)==0)
			{
				printf("��ţ�%s ��Ŀ��%s ���ͣ�%s �𰸣�%s ��ֵ��%s\n",p->a,p->b,p->c,p->d,p->e);
				k++;
			}
			p=p->next;
		}
		if(k==0)
		{printf("�����ڸ����͵���Ŀ��\n");}
		else
		{printf("��Ŀ���ҵ���\n");}
	}
	else if(x==4)
	{
		printf("��������ҵķ�ֵ:");
		scanf("%s",&n);
		while(p!=NULL)
		{
			if(strcmp(p->e,n)==0)
			{
				printf("��ţ�%s ��Ŀ��%s ���ͣ�%s �𰸣�%s ��ֵ��%s\n",p->a,p->b,p->c,p->d,p->e);
				k++;
			}
			p=p->next;
		}
		if(k==0)
		{printf("�����ڸ÷�ֵ����Ŀ��\n");}
		else
		{printf("��Ŀ���ҵ���\n");}
	}
	else
	{
		printf("��������ȷ����!\n");
		getchar();
		getchar();
		find(head);
	}
	getchar();
	printf("������������������'y',������������س��������˵�:");
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
		printf("��ţ�%s ��Ŀ��%s ���ͣ�%s �𰸣�%s ��ֵ��%s\n",a,b,c,d,e);
	}
	fclose(f1);
}
void list2()
{  
	system("cls");
	printf("����Ϊ���⼯\n");
	FILE *f2;
	char a[10],b[100],c[100],d[100],e[10];
    f2=fopen("���⼯.txt","r");
	if(f2==NULL)
	{exit(0);}
	while(!feof(f2))
	{
		fscanf(f2,"%s %s %s %s %s",a,b,c,d,e);
		printf("��ţ�%s ��Ŀ��%s ���ͣ�%s �𰸣�%s ��ֵ��%s\n",a,b,c,d,e);
	}
	fclose(f2);
}
void DO()
{
	system("cls");
	FILE *f1,*f2;
	char a[10],b[100],c[100],d[100],e[10],f[100];
	printf("�뿪ʼ����:\n");
	f1=fopen("GD.txt","r");
	f2=fopen("���⼯.txt","w");
	while(!feof(f1))
	{
		fscanf(f1,"%s %s %s %s %s",a,b,c,d,e);
		printf("��ţ�%s ��Ŀ��%s ���ͣ�%s ��ֵ��%s\n",a,b,c,e);
		printf("��:");
		scanf("%s",f);
		if(strcmp(d,f)==0)
		{printf("������ȷ!\n");}
		else
		{  	
			printf("�𰸴�����ȷ��Ϊ:%s  ���⽫������⼯!\n",d);
			fprintf(f2,"%s %s %s %s %s",a,b,c,d,e);
			if(!feof(f1))
			{fprintf(f2,"\n");}
		}

	}
	fclose(f2);
	fclose(f1);	
	printf("��Ŀ�����������س��������˵�:");
	getchar();
	getchar();
	system("cls");
	menu2();
}