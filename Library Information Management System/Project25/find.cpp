#include"lib.h"
struct st *find(struct st *head, int x){
	struct st *p,*q;
	int i = 0, b = 0, c;
	char searcher[100];//�����������ַ���
	if (x == 4){
		printf("������ѧ��\n");
		scanf_s("%s", searcher, 100);
	}
	else{
		printf("������ؼ���\n");
		scanf_s("%s", searcher, 100);
		printf("��ѡ�������ʽ��1.ISBN 2.���� 3.���� 4.������ 5.���");
		scanf_s("%d", &c);
	}
	if (head == NULL){
		printf("������\n");
	}
	else{
		p = head;
		printf("��ѯ�����\n");
		printf("ISBN      |����          |����               |������    |���      |���  |�ɽ�\n");
		while (p != NULL){
			if (x == 0){
				if (c == 1){
					if (strcmp(searcher, p->num) == 0){
						printf("%-10s|%-14s|%-19s|%-10s|%-10s|%-6d|%c\n", p->num, p->name, p->author, p->from, p->type, p->n, p->status);
						b = 1;
					}
				}
				if (c == 2){
					if (strcmp(searcher, p->name) == 0){
						printf("%-10s|%-14s|%-19s|%-10s|%-10s|%-6d|%c\n", p->num, p->name, p->author, p->from, p->type, p->n, p->status);
						b = 1;
					}
				}
				if (c == 3){
					if (strcmp(searcher, p->author) == 0){
						printf("%-10s|%-14s|%-19s|%-10s|%-10s|%-6d|%c\n", p->num, p->name, p->author, p->from, p->type, p->n, p->status);
						b = 1;
					}
				}
				if (c == 4){
					if (strcmp(searcher, p->from) == 0){
						printf("%-10s|%-14s|%-19s|%-10s|%-10s|%-6d|%c\n", p->num, p->name, p->author, p->from, p->type, p->n, p->status);
						b = 1;
					}
				}
				if (c == 5){
					if (strcmp(searcher, p->type) == 0){
						printf("%-10s|%-14s|%-19s|%-10s|%-10s|%-6d|%c\n", p->num, p->name, p->author, p->from, p->type, p->n, p->status);
						b = 1;
					}
				}
			}
			if (x == 1){
				if (c == 1){
					if (strcmp(searcher, p->num) == 0){
						printf("%-10s|%-14s|%-19s|%-10s|%-10s|%-6d|%c\n", p->num, p->name, p->author, p->from, p->type, p->n, p->status);
						b = 1;
						q = p;
					}
				}
				if (c == 2){
					if (strcmp(searcher, p->name) == 0){
						printf("%-10s|%-14s|%-19s|%-10s|%-10s|%-6d|%c\n", p->num, p->name, p->author, p->from, p->type, p->n, p->status);
						b = 1;
						q = p;
					}
				}
				if (c == 3){
					if (strcmp(searcher, p->author) == 0){
						printf("%-10s|%-14s|%-19s|%-10s|%-10s|%-6d|%c\n", p->num, p->name, p->author, p->from, p->type, p->n, p->status);
						b = 1;
						q = p;
					}
				}
				if (c == 4){
					if (strcmp(searcher, p->from) == 0){
						printf("%-10s|%-14s|%-19s|%-10s|%-10s|%-6d|%c\n", p->num, p->name, p->author, p->from, p->type, p->n, p->status);
						b = 1;
						q = p;
					}
				}
				if (c == 5){
					if (strcmp(searcher, p->type) == 0){
						printf("%-10s|%-14s|%-19s|%-10s|%-10s|%-6d|%c\n", p->num, p->name, p->author, p->from, p->type, p->n, p->status);
						b = 1;
						q = p;
					}
				}
			}
			p = p->next;
		}
		if (b == 1){
			return q;
		}
		if (b != 1){
			printf("�޽��\n");
			return NULL;
		}
	}
	return NULL;
}