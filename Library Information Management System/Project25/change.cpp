#include"lib.h"
struct st *change(struct st *head){//ok
	int i;
	struct st *p=NULL;
	char a = 'y', b;
	if (head == NULL){
		printf("������\n");
	}
	else{
		while (a == 'y' || a == 'Y'){
			p = findb(head, 1);
			printf("�Ƿ��޸ģ���Y/N����");
			getchar();
			scanf_s("%c", &b);
			while (b == 'y' || b == 'Y'){
				printf("ѡ���޸���1.ISBN 2.���� 3.���� 4.������ 5.��� 6.����� 7.�Ƿ�ɽ裺");
				scanf_s("%d", &i);
				if (i == 1){
					printf("������ISBN������������#��\n");
					scanf_s("%s", p->num, 40);
				}
				if (i == 2){
					printf("����������\n");
					scanf_s("%s", p->name, 100);
				}
				if (i == 3){
					printf("����������\n");
					scanf_s("%s", p->author, 100);
				}
				if (i == 4){
					printf("�����������\n");
					scanf_s("%s", p->from, 100);
				}
				if (i == 5){
					printf("���������\n");
					scanf_s("%s", p->type, 40);
				}
				if (i == 6){
					printf("����������\n");
					scanf_s("%d", &p->n);
				}
				if (i == 7){
					printf("�Ƿ�ɽ裨Y/N��\n");
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
							printf("��ʽ������������\n");
							getchar();
							scanf_s("%c", &p->status);
							if (p->status == 'Y' || p->status == 'N'){
								break;
							}
						}
					}
				}
				printf("�޸����\n");
				printf("�Ƿ�����޸ĸ����Y/N����");
				getchar();
				scanf_s("%c", &b);
			}
			if (p == NULL){
				printf("û���ҵ�����\n");
			}
			printf("�Ƿ�����޸ģ���Y/N����");
			getchar();
			scanf_s("%c", &a);
			back0(head);
		}
	}
	return(head);
}