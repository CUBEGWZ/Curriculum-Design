#include"lib.h"
struct st *in(struct st *head){//ok
	struct st *p, *q, *x;
	char a;
	p = q = (struct st*)malloc(N);
	if (head != NULL){
		printf("�������ݣ��Ƿ����(Y/N)��");
		getchar();
		scanf_s("%c", &a);
		if (a == 'y' || a == 'Y'){
			while (head != NULL){
				x = head;
				head = head->next;
				free(x);
			}
			printf("������\n");
		}
		else{
			q = head;
			while (q->next != NULL){
				q = q->next;
			}
		}
	}
	printf("��ʼ¼��\n������ISBN������������#��\n");
	scanf_s("%s", p->num, 40);
	while (p->num[0] != '#'){
		p->s = 0;
		printf("���������������ߡ������硢��𡢿����\n");
		scanf_s("%s %s %s %s %d", p->name, 100, p->from, 100, p->author, 100, p->type, 40, &p->n);
		printf("�Ƿ�ɽ裨Y/N��\n");
		getchar();
		scanf_s("%c", &p->status);
		while (1){
			if (p->status != 'Y'){
				break;
			}
			else if (p->status != 'N'){
				break;
			}
			else{
				printf("��ʽ������������\n");
				getchar();
				scanf_s("%c", &p->status);
				if (p->status == 'Y' || p->status == 'N'){
					break;
				}
			}
		}
		if (head == NULL){
			head = p;
		}
		else{
			q->next = p;
		}
		q = p;
		p = (struct st*)malloc(N);
		printf("������ISBN������������#��\n");
		scanf_s("%s", p->num, 40);
	}
	q->next = NULL;
	free(p);
	return(head);
}