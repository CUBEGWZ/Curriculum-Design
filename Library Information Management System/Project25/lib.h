#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct st{
	int s,n;
	char name[100], num[40], type[40], author[100], from[100];//ISDN ���� ���� ���� ������
	char status;//����״̬
	struct st *next;
};
struct stu{
	int i;
	char name1[100];
	char student[100];
	struct stu *next;
};
#define N sizeof(struct st)
#define N1 sizeof(struct stu)
struct st *in(struct st *head);//���������
struct st *del(struct st *head);//�����ɾ��
struct st *add(struct st *head);//��������
struct st *change(struct st *head);//����
void fresh(struct st *head);//���ݵĸ���
struct st *findb(struct st *head, int x);//ģ����ѯ
struct st *find(struct st *head, int x);//��ȷ����
void print(struct st *head);//��Ϣ�����
void student(struct st *head,struct stu *headb);//ѧ������
struct st *manage(struct st *head, struct stu *headb);//����Ա����
int login();//��������
struct stu *borrow(struct st *head, struct stu *headb);//����
struct stu *back(struct st *head, struct stu *headb);//�黹
struct st *read(struct st  *head);//��ȡ���ݣ���������
void back0(struct st *head);//��Ź���
struct stu *instu(struct st *x, struct stu *head);//ѧ�������������
struct stu *finds(struct stu *head,int x);//ѧ��������Ϣ��Ѱ
void save(struct stu *headb);//ѧ��������Ϣ�ı���
struct stu *readstu(struct stu  *head); //ѧ��������Ķ�ȡ������
void printstu(struct stu *head);//���ѧ���Ľ�����Ϣ