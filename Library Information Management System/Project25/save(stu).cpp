#include"lib.h"
void save(struct stu *headb){//定义学生借阅信息保存函数 
	struct stu *p;
	FILE *f;
	fopen_s(&f, "borrow.txt", "w");
	if (headb == NULL){
		printf("无数据\n");
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