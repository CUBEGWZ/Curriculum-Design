#include"lib.h"
struct stu *borrow(struct st *head, struct stu *headb){//ok
	int a;
	struct st *p = NULL;
	printf("请选择查询方式1.关键字查询/2.精确查询：");
	scanf_s("%d", &a);
	if (a == 1){
		p = findb(head, 1);
	}
	if (a == 2){
		p = find(head, 1);
	}
	if (p != NULL){
		printf("是否借阅？（Y/N）：");
		getchar();
		scanf_s("%c", &a);
		if (a == 'y' || a == 'Y'){
			if (p->status == 'N'){
				printf("无法借阅\n");
			}
			else{
				headb = instu(p, headb);
				if (p->n != 0){
					p->status = 'y';
					printf("借阅成功\n");
					p->n--;
				}
				else{
					printf("无法借阅\n");
				}
			}
		}
	}
	return (headb);
}