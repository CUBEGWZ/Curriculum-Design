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
			printf("�Ƿ���룿��Y/N����");
			getchar();
			scanf_s("%c", &b);
			if (b == 'y' || b == 'Y'){
				p = (struct st*)malloc(N);
				printf("���ҵ������\n��ѡ����뷽ʽ��1.��ǰ����/2.�����룩��");
				scanf_s("%d", &i);
				if (i == 2){
					printf("������ģʽ\n");
					printf("������ISBN������������#��\n");//�������
					scanf_s("%s", p->num, 40);
					printf("���������������ߡ������硢��𡢿����\n");
					scanf_s("%s %s %s %s %d", p->name, 100, p->type, 40, p->author, 100, p->from, 100, &p->n);//��ȡ�ļ������Ϣ����������
					printf("�Ƿ�ɽ裨Y/N��\n");
					getchar();
					scanf_s("%c", &p->status);
					while (p->status != 'Y' || p->status != 'N'){
						printf("��ʽ������������\n");
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
					printf("��ǰ����ģʽ\n");
					printf("������ISBN������������#��\n");//�������
					scanf_s("%s", p->num, 40);
					printf("���������������ߡ������硢��𡢿����\n");
					scanf_s("%s %s %s %s %d", p->name, 100, p->type, 40, p->author, 100, p->from, 100, &p->n);
					printf("�Ƿ�ɽ裨Y/N��\n");
					getchar();
					scanf_s("%c", &p->status);
					while (p->status != 'Y' || p->status != 'N'){
						printf("��ʽ������������\n");
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
				printf("������ȡ��\n");
			}
		}
		if (p == NULL){
			printf("δ�ҵ������\n");
		}
		printf("�Ƿ�������룿��Y/N����");
		getchar();
		scanf_s("%c", &a);
		back0(head);//��Ź���
	}
	return (head);
}