#ifndef _HEADER_H
#define _HEADER_H
//ѧ����Ϣ�Ľṹ��
struct sts
{   //�����������͵ĳ������򣬳�����ǰ���Ż�����
	char name[20];
	char nation[20];
	char idcard[20];
	char college[20];
	char cla[20];
	double num;
	int age;
	char sex[8];    //���ṹ��ĳ������Ϊ����ͳ��ȵ����������Ż�����
	struct sts *next;
};
typedef struct sts StuManage;
#define LEN sizeof(StuManage)
#endif
