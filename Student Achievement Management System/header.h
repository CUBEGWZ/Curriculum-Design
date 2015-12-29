#ifndef _HEADER_H
#define _HEADER_H
//学生信息的结构体
struct sts
{   //按照数据类型的长度排序，长的在前，优化代码
	char name[20];
	char nation[20];
	char idcard[20];
	char college[20];
	char cla[20];
	double num;
	int age;
	char sex[8];    //将结构体的长度填充为最长类型长度的整倍数，优化代码
	struct sts *next;
};
typedef struct sts StuManage;
#define LEN sizeof(StuManage)
#endif
