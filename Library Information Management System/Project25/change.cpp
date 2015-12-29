#include"lib.h"
struct st *change(struct st *head){//ok
	int i;
	struct st *p=NULL;
	char a = 'y', b;
	if (head == NULL){
		printf("无数据\n");
	}
	else{
		while (a == 'y' || a == 'Y'){
			p = findb(head, 1);
			printf("是否修改？（Y/N）：");
			getchar();
			scanf_s("%c", &b);
			while (b == 'y' || b == 'Y'){
				printf("选择修改项1.ISBN 2.书名 3.作者 4.出版社 5.类别 6.库存量 7.是否可借：");
				scanf_s("%d", &i);
				if (i == 1){
					printf("请输入ISBN（结束请输入#）\n");
					scanf_s("%s", p->num, 40);
				}
				if (i == 2){
					printf("请输入书名\n");
					scanf_s("%s", p->name, 100);
				}
				if (i == 3){
					printf("请输入作者\n");
					scanf_s("%s", p->author, 100);
				}
				if (i == 4){
					printf("请输入出版社\n");
					scanf_s("%s", p->from, 100);
				}
				if (i == 5){
					printf("请输入类别\n");
					scanf_s("%s", p->type, 40);
				}
				if (i == 6){
					printf("请输入库存量\n");
					scanf_s("%d", &p->n);
				}
				if (i == 7){
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
				}
				printf("修改完成\n");
				printf("是否继续修改该项？（Y/N）：");
				getchar();
				scanf_s("%c", &b);
			}
			if (p == NULL){
				printf("没有找到数据\n");
			}
			printf("是否继续修改？（Y/N）：");
			getchar();
			scanf_s("%c", &a);
			back0(head);
		}
	}
	return(head);
}