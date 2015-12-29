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
		printf("\n*********************************�洢ѧ����Ϣ���ļ������ڣ����ȴ���ѧ����Ϣ��***************************\n\n\n");
		printf("\nϵͳ��������֮�������ת.......");
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
    FILE *fp = fopen("test.txt","rb+");//��"r"����������ʽ��ȡ�ļ���!*�ļ��������
    StuManage *head = (StuManage *)malloc(LEN);//����ͷ�ڵ�
    StuManage *p = head;//����ָ�룬��������
    while(!feof(fp))
    {
        StuManage *newNode = (StuManage *)malloc(LEN);//��ʱ�ڵ�,���ļ��ж�ȡ�ڵ�
        fread(newNode,LEN,1,fp);
        if(feof(fp))//��ȡ��������ѭ��
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
		printf("ѧ����ϢΪ�գ��޷�д���ļ���");
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
		printf("ѧ����ϢΪ�գ��޷�д���ļ���");
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
