#include"lib.h"
void print(struct st *head){//定义输出函数
	struct st *p;
	if (head == NULL){
		printf("无数据\n");
	}
	else{
		p = head;
		printf("ISBN      |书名          |作者               |出版社    |类别      |库存  |可借\n");
		while (p != NULL){
			printf("%-10s|%-14s|%-19s|%-10s|%-10s|%-6d|%c\n", p->num, p->name, p->author, p->from, p->type, p->n, p->status);
			p = p->next;
		}
	}
}