#include"lib.h"
void back0(struct st *head){//��Ź���
	struct st *p;
	p = head;
	while (p != NULL){
		p->s = 0;
		p = p->next;
	}
}