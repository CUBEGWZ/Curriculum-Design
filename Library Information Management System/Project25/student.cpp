#include"lib.h"
void student(struct st *head,struct stu *headb){
	int i;
	system("CLS");//清屏
	while (1){
		printf("****************************************************************************\n");
		printf("*                   欢迎使用图书信息管理系统（学生）                       *\n");
		printf("*                                                                          *\n");
		printf("*     1.借书          2.还书           3.借阅查询             4.退出       *\n");
		printf("****************************************************************************\n");
		printf("请输入：");
		scanf_s("%d", &i);
		if (i == 4){
			printf("系统已退出\n");
			break;
		}
		system("CLS");//清屏
		switch (i){
		case 1:{
			headb=borrow(head,headb);
			save(headb);
			back0(head);
			fresh(head);
		}break;
		case 2:{
			headb=back(head,headb);
			save(headb);
			back0(head);
			fresh(head);
		}break;
		case 3:{
			finds(headb,0);
		}break;
		}
		system("PAUSE");//停顿
		system("CLS");//清屏
	}
}