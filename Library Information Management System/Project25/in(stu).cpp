#include"lib.h"
struct stu *instu(struct st *x,struct stu *head){
	struct stu *p, *q;
	p = q = (struct stu*)malloc(N1);
	printf("������ѧ�ţ�");
	scanf_s("%s", p->student, 100);
	strcpy_s(p->name1, x->name);//�ַ�����������
	q = head;
	if (head != NULL){
		while (q->next != NULL){
			q = q->next;
		}
	}
	if (head == NULL){
		head = p;
	}
	else{
		q->next = p;
	}
	q = p;
	p = (struct stu*)malloc(N1);
	q->next = NULL;
	free(p);
	return(head);
}