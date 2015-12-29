#include"lib.h"
int main(){
	int i, x;
	struct st  *head = NULL;
	struct stu *headb = NULL;
	while (1){
		headb = readstu(headb);
		head = read(head);
		printf("****************************************************************************\n");
		printf("*                       欢迎使用图书信息管理系统                           *\n");
		printf("*  选择身份：                                                              *\n");
		printf("*          1.学生               2.管理员                3.退出             *\n");
		printf("****************************************************************************\n");
		printf("请输入：");
		scanf_s("%d", &i);
		if (i == 1){
			printf("以学生身份登陆\n");
			student(head,headb);
		}
		if (i == 2){
			printf("以管理员身份登陆\n");
			x = login();
			if (x == 1){
				printf("登陆成功\n");
				system("PAUSE");
				head=manage(head,headb);
			}
			else{
				printf("登陆失败请重新选择\n");
			}
		}
		if(i==3){
			printf("系统已退出\n");
			break;
		}
		if (i == 4){
			head=manage(head,headb);
		}
		system("PAUSE");
		system("CLS");
	}
	return 0;
}