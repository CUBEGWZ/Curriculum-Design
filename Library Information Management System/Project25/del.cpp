#include"lib.h"
struct st *del(struct st *head){//ok
	struct st *p, *q;
	char a = 'y',b;
	if (head == NULL){
		printf("无数据\n");
	}
	else{
		while (a == 'y' || a == 'Y'){
			q = head;
			p = findb(head, 1);
			if (p != NULL){
				while (q->next != p&&p != head){
					q = q->next;
				}
				printf("是否删除？（Y/N）：");
				getchar();
				scanf_s("%c", &b);
				if (b == 'y' || b == 'Y'){
					if (head == p){
						head = p->next;
						free(p);
						printf("删除完成\n");
					}
					else{
						q->next = p->next;
						free(p);
						printf("删除完成\n");
					}
				}
				else{
					printf("删除已取消\n");
				}
			}
			else{
				printf("无数据\n");
			}
			printf("是否继续删除？（Y/N）：");
			getchar();
			scanf_s("%c", &a);
			back0(head);//序号归零
		}
	}
	return(head);
}