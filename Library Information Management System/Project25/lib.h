#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct st{
	int s,n;
	char name[100], num[40], type[40], author[100], from[100];//ISDN 书名 类型 作者 出版社
	char status;//借阅状态
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
struct st *in(struct st *head);//链表的输入
struct st *del(struct st *head);//链表的删除
struct st *add(struct st *head);//链表的添加
struct st *change(struct st *head);//借书
void fresh(struct st *head);//数据的更新
struct st *findb(struct st *head, int x);//模糊查询
struct st *find(struct st *head, int x);//精确查找
void print(struct st *head);//信息的输出
void student(struct st *head,struct stu *headb);//学生借阅
struct st *manage(struct st *head, struct stu *headb);//管理员管理
int login();//输入密码
struct stu *borrow(struct st *head, struct stu *headb);//借阅
struct stu *back(struct st *head, struct stu *headb);//归还
struct st *read(struct st  *head);//读取数据，生成链表
void back0(struct st *head);//序号归零
struct stu *instu(struct st *x, struct stu *head);//学生端链表的输入
struct stu *finds(struct stu *head,int x);//学生借阅信息查寻
void save(struct stu *headb);//学生借阅信息的保存
struct stu *readstu(struct stu  *head); //学生端链表的读取与生成
void printstu(struct stu *head);//输出学生的借阅信息