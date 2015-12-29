#include"lib.h"
struct st *findb(struct st *head,int x){//定义模糊查询函数
	struct st *p;
	int i, a, b = 0, c, sum;
	char searcher[100];
	printf("请输入关键词\n");
	scanf_s("%s", searcher, 100);
	printf("请选择检索方式：1.ISBN 2.书名 3.作者 4.出版社 5.类别：");
	scanf_s("%d", &c);//输入序号
	if (head == NULL){
		printf("无数据\n");
	}
	else{
		p = head;
		i = 0;
		printf("查询结果：\n");
		printf(" ISBN      |书名           |作者              |出版社    |类别      |库存  |可借\n");
		while (p != NULL){
			if (x == 0){
				if (c == 1){
					if (strstr(p->num, searcher)){
						printf(" %-10s|%-14s|%-19s|%-10s|%-10s|%-6d|%c\n", p->num, p->name, p->author, p->from, p->type, p->n, p->status);
						b = 1;
					}
				}
				if (c == 2){
					if (strstr(p->name, searcher)){
						printf(" %-10s|%-14s|%-19s|%-10s|%-10s|%-6d|%c\n", p->num, p->name, p->author, p->from, p->type, p->n, p->status);
						b = 1;
					}
				}
				if (c == 3){
					if (strstr(p->author, searcher)){
						printf(" %-10s|%-14s|%-19s|%-10s|%-10s|%-6d|%c\n", p->num, p->name, p->author, p->from, p->type, p->n, p->status);
						b = 1;
					}
				}
				if (c == 4){
					if (strstr(p->from, searcher)){
						printf(" %-10s|%-14s|%-19s|%-10s|%-10s|%-6d|%c\n", p->num, p->name, p->author, p->from, p->type, p->n, p->status);
						b = 1;
					}
				}
				if (c == 5){
					if (strstr(p->type, searcher)){
						printf(" %-10s|%-14s|%-19s|%-10s|%-10s|%-6d|%c\n", p->num, p->name, p->author, p->from, p->type, p->n, p->status);
						b = 1;
					}
				}
			}
			if (x == 1){
				if (c == 1){
					if (strstr(p->num, searcher)){
						i++;
						p->s = i;
						printf("%2d.%-10s|%-14s|%-19s|%-10s|%-10s|%-6d|%c\n", p->s, p->num, p->name, p->author, p->from, p->type, p->n, p->status);
						b = 1;
					}
				}
				if (c == 2){
					if (strstr(p->name, searcher)){
						i++;
						p->s = i;
						printf("%2d.%-10s|%-14s|%-19s|%-10s|%-10s|%-6d|%c\n", p->s, p->num, p->name, p->author, p->from, p->type, p->n, p->status);
						b = 1;
					}
				}
				if (c == 3){
					if (strstr(p->author, searcher)){
						i++;
						p->s = i;
						printf("%2d.%-10s|%-14s|%-19s|%-10s|%-10s|%-6d|%c\n", p->s, p->num, p->name, p->author, p->from, p->type, p->n, p->status);
						b = 1;
					}
				}
				if (c == 4){
					if (strstr(p->from, searcher)){
						i++;
						p->s = i;
						printf("%2d.%-10s|%-14s|%-19s|%-10s|%-10s|%-6d|%c\n", p->s, p->num, p->name, p->author, p->from, p->type, p->n, p->status);
						b = 1;
					}
				}
				if (c == 5){
					if (strstr(p->type, searcher)){
						i++;
						p->s = i;
						printf("%2d.%-10s|%-14s|%-19s|%-10s|%-10s|%-6d|%c\n", p->s, p->num, p->name, p->author, p->from, p->type, p->n, p->status);
						b = 1;
					}
				}
			}
			p = p->next;
			sum = i;
		}
		if (b == 1){
			if (x != 0){
				printf("请选择：");
				scanf_s("%d", &a);
				p = head;
				while ((a == -858993460)||a<1||a>sum){
					printf("请重新选择：");
					getchar();
					scanf_s("%d", &a);
				}
				while (a != p->s){
					p = p->next;
				}
				return(p);
			}
		}
		else{
			printf("无结果\n");
			return NULL;
		}
	}
	return NULL;
}