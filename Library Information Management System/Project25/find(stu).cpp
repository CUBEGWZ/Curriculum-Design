#include"lib.h"
struct stu *finds(struct stu *head,int x){
	struct stu *p;
	int i, b = 0, a, sum;
	char searcher[100];//�����������ַ���
	printf("������ѧ�ţ�");
	scanf_s("%s", searcher, 100);
	if (head == NULL){
		printf("������\n");
	}
	else{
		p = head;
		i = 0;
		printf("��ѯ�����\n");
		printf("  ����\n");
		while (p != NULL){
			if (strcmp(p->student, searcher) == 0){
				i++;
				p->i = i;
				printf("%d. %10s\n", p->i, p->name1);
				b = 1;
			}
			p = p->next;
			sum = i;
		}
		if (b == 1){
			if (x != 0){
				printf("��ѡ��");
				scanf_s("%d", &a);
				p = head;
				while ((a == -858993460) || a<1 || a>sum){
					printf("������ѡ��");
					getchar();
					scanf_s("%d", &a);
				}
				while (a != p->i){
					p = p->next;
				}
				return(p);
			}
		}
		if (b != 1){
			printf("�޽��\n");
			return NULL;
		}
	}
	return NULL;
}