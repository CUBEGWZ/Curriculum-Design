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
int judge_null()
{
	FILE *fp = fopen("test.txt","rb+");
	char ch;
	int size;
	if(access("test.txt",0) == -1)
	{
		fclose(fp);
		printf("\n*********************************存储学生信息的文件不存在！请先创建学生信息！***************************\n\n\n");
		printf("\n系统将在两秒之后进行跳转.......");
		Sleep(2000);
		system("cls");
	}
	else
	{
		fseek(fp,0,SEEK_END);
		size=ftell(fp);
		fclose(fp);
		return size;
	}
}
StuManage *read()
{
    FILE *fp = fopen("test.txt","rb+");//以"r"（读）的形式读取文件，!*文件必须存在
    StuManage *head = (StuManage *)malloc(LEN);//链表头节点
    StuManage *p = head;//工作指针，建立链表
    while(!feof(fp))
    {
        StuManage *newNode = (StuManage *)malloc(LEN);//临时节点,从文件中读取节点
        fread(newNode,LEN,1,fp);
        if(feof(fp))//读取结束跳出循环
        {
            p->next = NULL;
            break;
        }
        p->next = newNode;
        p=newNode;
        p->next = NULL;
    }
	head=head->next;
    return head;
}
void savefile_ab(StuManage *head)
{
	FILE *fp;
	StuManage *p=head;
	int count,i=0;
	if((fp=fopen("test.txt","ab+"))==NULL)
	{
		printf("Can not open file!\n");
		exit(0);
	}
	if(head==NULL)
		printf("学生信息为空！无法写入文件！");
	else
	{
		count=countnode(head);
		for(i=0;i<count;i++)
		{
			fwrite(p,LEN,1,fp);
			p=p->next;
		}
	}
	fclose(fp);
}
void savefile_wb(StuManage *head)
{
	FILE *fp;
	StuManage *p=head;
	int count,i=0;
	if((fp=fopen("test.txt","wb"))==NULL)
	{
		printf("Can not open file!\n");
		exit(0);
	}
	if(head==NULL)
		printf("学生信息为空！无法写入文件！");
	else
	{
		count=countnode(head);
		for(i=0;i<count;i++)
		{
			fwrite(p,LEN,1,fp);
			p=p->next;
		}
		fclose(fp);
	}
}
int countnode(StuManage *head)
{
	StuManage *p=head;
	int count=0;
	while(p != NULL)
	{
		p=p->next;
		count++;
	}
	return count;
}
