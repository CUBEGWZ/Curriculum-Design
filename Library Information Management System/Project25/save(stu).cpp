#include"lib.h"
void save(struct stu *headb){//����ѧ��������Ϣ���溯�� 
	struct stu *p;
	FILE *f;
	fopen_s(&f, "borrow.txt", "w");
	if (headb == NULL){
		printf("������\n");
	}
	else{
		p = headb;
		while (p != NULL){
			fprintf_s(f, "%s ", p->student);
			fprintf_s(f, "%s", p->name1);
			if (p->next != NULL){
				fputc('\n', f);
			}
			p = p->next;
		}	
	}
	fclose(f);
}