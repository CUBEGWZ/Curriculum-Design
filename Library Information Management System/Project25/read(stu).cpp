#include"lib.h"
struct stu *readstu(struct stu  *head){//ok
	struct stu  *p, *q;
	p = q = (struct stu*)malloc(N1);
	int a;
	FILE *f;
	fopen_s(&f, "borrow.txt", "a+");
	a = (int)fgetc(f);
	if (feof(f)){
		printf("borrow.txt������\n");
		head = NULL;
	}
	else{
		rewind(f);
		while (!feof(f)){
			fscanf_s(f, "%s %s\n", p->student, 100, p->name1, 100);//��ȡ�ļ������Ϣ����������
			p->i = 0;
			if (head == NULL){
				head = p;
			}
			else{
				q->next = p;
			}
			q = p;
			
			p = (struct stu*)malloc(N1);
		}
		q->next = NULL;
		free(p);
	}
	fclose(f);
	return(head);
}