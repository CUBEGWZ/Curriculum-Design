#include"lib.h"
struct st *del(struct st *head){//ok
	struct st *p, *q;
	char a = 'y',b;
	if (head == NULL){
		printf("������\n");
	}
	else{
		while (a == 'y' || a == 'Y'){
			q = head;
			p = findb(head, 1);
			if (p != NULL){
				while (q->next != p&&p != head){
					q = q->next;
				}
				printf("�Ƿ�ɾ������Y/N����");
				getchar();
				scanf_s("%c", &b);
				if (b == 'y' || b == 'Y'){
					if (head == p){
						head = p->next;
						free(p);
						printf("ɾ�����\n");
					}
					else{
						q->next = p->next;
						free(p);
						printf("ɾ�����\n");
					}
				}
				else{
					printf("ɾ����ȡ��\n");
				}
			}
			else{
				printf("������\n");
			}
			printf("�Ƿ����ɾ������Y/N����");
			getchar();
			scanf_s("%c", &a);
			back0(head);//��Ź���
		}
	}
	return(head);
}