#include"lib.h"
void printstu(struct stu *head){//����ѧ�����������
	struct stu *p;
	if (head == NULL){
		printf("������\n");
	}
	else{
		p = head;
		printf("ѧ��      |����\n");
		while (p != NULL){
			printf("%-10s|%-10s\n", p->student, p->name1);
			p = p->next;
		}
	}
}