#include"lib.h"
struct stu *back(struct st *head, struct stu *headb){
	char a;
	struct st *q;
	q = head;
	struct stu *p, *x;
	x = headb;
	p=finds(headb,1);
	if (p == NULL){
		return headb;
	}
	printf("是否归还？（Y/N）：");
	getchar();
	scanf_s("%c", &a);
	if (a == 'y' || a == 'Y'){
		printf("归还成功\n");
		while (x->next != p&&p != headb){
			x = x->next;
		}
		while (strcmp(p->name1, q->name) != 0){
			q = q->next;
		}
		if (headb == p){
			headb = p->next;
			free(p);
		}
		else{
			x->next = p->next;
			free(p);
		}
		q->n++;
		if (q->n > 0){
			q->status = 'Y';
		}
	}
	return headb;
}