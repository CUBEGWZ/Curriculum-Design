#include"lib.h"
struct st *find(struct st *head, int x){
	struct st *p,*q;
	int i = 0, b = 0, c;
	char searcher[100];//定义搜索用字符串
	if (x == 4){
		printf("请输入学号\n");
		scanf_s("%s", searcher, 100);
	}
	else{
		printf("请输入关键词\n");
		scanf_s("%s", searcher, 100);
		printf("请选择检索方式：1.ISBN 2.书名 3.作者 4.出版社 5.类别：");
		scanf_s("%d", &c);
	}
	if (head == NULL){
		printf("无数据\n");
	}
	else{
		p = head;
		printf("查询结果：\n");
		printf("ISBN      |书名          |作者               |出版社    |类别      |库存  |可借\n");
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
			printf("无结果\n");
			return NULL;
		}
	}
	return NULL;
}