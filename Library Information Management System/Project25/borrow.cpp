#include"lib.h"
struct stu *borrow(struct st *head, struct stu *headb){//ok
	int a;
	struct st *p = NULL;
	printf("��ѡ���ѯ��ʽ1.�ؼ��ֲ�ѯ/2.��ȷ��ѯ��");
	scanf_s("%d", &a);
	if (a == 1){
		p = findb(head, 1);
	}
	if (a == 2){
		p = find(head, 1);
	}
	if (p != NULL){
		printf("�Ƿ���ģ���Y/N����");
		getchar();
		scanf_s("%c", &a);
		if (a == 'y' || a == 'Y'){
			if (p->status == 'N'){
				printf("�޷�����\n");
			}
			else{
				headb = instu(p, headb);
				if (p->n != 0){
					p->status = 'y';
					printf("���ĳɹ�\n");
					p->n--;
				}
				else{
					printf("�޷�����\n");
				}
			}
		}
	}
	return (headb);
}