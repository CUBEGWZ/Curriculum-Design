#include"lib.h"
void print(struct st *head){//�����������
	struct st *p;
	if (head == NULL){
		printf("������\n");
	}
	else{
		p = head;
		printf("ISBN      |����          |����               |������    |���      |���  |�ɽ�\n");
		while (p != NULL){
			printf("%-10s|%-14s|%-19s|%-10s|%-10s|%-6d|%c\n", p->num, p->name, p->author, p->from, p->type, p->n, p->status);
			p = p->next;
		}
	}
}