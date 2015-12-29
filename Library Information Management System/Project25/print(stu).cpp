#include"lib.h"
void printstu(struct stu *head){//定义学生端输出函数
	struct stu *p;
	if (head == NULL){
		printf("无数据\n");
	}
	else{
		p = head;
		printf("学号      |书名\n");
		while (p != NULL){
			printf("%-10s|%-10s\n", p->student, p->name1);
			p = p->next;
		}
	}
}