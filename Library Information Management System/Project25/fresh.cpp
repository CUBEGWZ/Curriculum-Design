#include"lib.h"
void fresh(struct st *head){//�������data.txt����
	struct st *p;
	FILE *f;
	fopen_s(&f, "data.txt", "w");
	if (head == NULL){
		printf("������\n");
	}
	else{
		p = head;
		printf("��ʼ��������\n");
		while (p != NULL){
			fprintf_s(f, "%s ", p->num);
			fprintf_s(f, "%s ",p->name);
			fprintf_s(f, "%s ", p->author);
			fprintf_s(f, "%s ", p->from);
			fprintf_s(f, "%s ",p->type);
			fprintf_s(f, "%d ", p->n);
			if (p->n == 0){
				p->status = 'N';
			}
			fprintf_s(f, "%c", p->status);
			if (p->next != NULL){
				fputc('\n', f);
			}
			p = p->next;
		}
		printf("���ݸ������\n");	
	}
	fclose(f);
}