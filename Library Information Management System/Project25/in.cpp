#include"lib.h"
struct st *in(struct st *head){//ok
	struct st *p, *q, *x;
	char a;
	p = q = (struct st*)malloc(N);
	if (head != NULL){
		printf("存在数据，是否清空(Y/N)：");
		getchar();
		scanf_s("%c", &a);
		if (a == 'y' || a == 'Y'){
			while (head != NULL){
				x = head;
				head = head->next;
				free(x);
			}
			printf("清空完成\n");
		}
		else{
			q = head;
			while (q->next != NULL){
				q = q->next;
			}
		}
	}
	printf("开始录入\n请输入ISBN（结束请输入#）\n");
	scanf_s("%s", p->num, 40);
	while (p->num[0] != '#'){
		p->s = 0;
		printf("请输入书名、作者、出版社、类别、库存量\n");
		scanf_s("%s %s %s %s %d", p->name, 100, p->from, 100, p->author, 100, p->type, 40, &p->n);
		printf("是否可借（Y/N）\n");
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
				printf("格式错误，重新输入\n");
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
		printf("请输入ISBN（结束请输入#）\n");
		scanf_s("%s", p->num, 40);
	}
	q->next = NULL;
	free(p);
	return(head);
}