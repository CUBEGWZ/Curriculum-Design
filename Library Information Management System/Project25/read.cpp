#include"lib.h"
struct st *read(struct st  *head){//ok
	struct st  *p, *q;
	p = q = (struct st*)malloc(N);
	FILE *f;
	int a;
	fopen_s(&f, "data.txt", "r+");
	a = (int)fgetc(f);
	if (feof(f)){
		printf("data.txt无数据\n");
		head = NULL;
	}
	else{
		rewind(f);
		while (!feof(f)){
			fscanf_s(f, "%s %s %s %s %s %d %c\n", p->num, 40, p->name, 100, p->author, 100, p->from, 100, p->type, 40, &p->n, &p->status);//读取文件里的信息并生成链表
			p->s = 0;
			if (head == NULL){
				head = p;
			}
			else{
				q->next = p;
			}
			q = p;
			p = (struct st*)malloc(N);
		}
		q->next = NULL;
		free(p);
	}
	fclose(f);
	return(head);
}