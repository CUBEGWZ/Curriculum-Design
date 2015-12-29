#include"lib.h"
struct st *add(struct st *head){//ok
	struct st *p, *q, *x;
	char a = 'y', b;
	int i;
	x = p = q = head;
	while (a == 'y' || a == 'Y'){
		x = head;
		p = findb(head, 1);
		if (p != NULL){
			while (x->next != p&&p != head){
				x = x->next;
			}
			q = p;
			printf("是否插入？（Y/N）：");
			getchar();
			scanf_s("%c", &b);
			if (b == 'y' || b == 'Y'){
				p = (struct st*)malloc(N);
				printf("已找到插入点\n请选择插入方式（1.向前插入/2.向后插入）：");
				scanf_s("%d", &i);
				if (i == 2){
					printf("向后插入模式\n");
					printf("请输入ISBN（结束请输入#）\n");//输入序号
					scanf_s("%s", p->num, 40);
					printf("请输入书名、作者、出版社、类别、库存量\n");
					scanf_s("%s %s %s %s %d", p->name, 100, p->type, 40, p->author, 100, p->from, 100, &p->n);//读取文件里的信息并生成链表
					printf("是否可借（Y/N）\n");
					getchar();
					scanf_s("%c", &p->status);
					while (p->status != 'Y' || p->status != 'N'){
						printf("格式错误，重新输入\n");
						getchar();
						scanf_s("%c", &p->status);
						if (p->status == 'Y' || p->status == 'N'){
							break;
						}
					}
					p->next = q->next;
					q->next = p;
				}
				if (i == 1){
					printf("向前插入模式\n");
					printf("请输入ISBN（结束请输入#）\n");//输入序号
					scanf_s("%s", p->num, 40);
					printf("请输入书名、作者、出版社、类别、库存量\n");
					scanf_s("%s %s %s %s %d", p->name, 100, p->type, 40, p->author, 100, p->from, 100, &p->n);
					printf("是否可借（Y/N）\n");
					getchar();
					scanf_s("%c", &p->status);
					while (p->status != 'Y' || p->status != 'N'){
						printf("格式错误，重新输入\n");
						getchar();
						scanf_s("%c", &p->status);
						if (p->status == 'Y' || p->status == 'N'){
							break;
						}
					}
					if (q == head){
						head = p;
						p->next = q;
					}
					else{
						x->next = p;
						p->next = q;
					}
				}
			}
			else{
				printf("插入已取消\n");
			}
		}
		if (p == NULL){
			printf("未找到插入点\n");
		}
		printf("是否继续插入？（Y/N）：");
		getchar();
		scanf_s("%c", &a);
		back0(head);//序号归零
	}
	return (head);
}