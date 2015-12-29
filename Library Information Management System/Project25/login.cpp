#include"lib.h"
int login(){
	char user[40] = { "admin" }, password0[40] = { "admin" };//定义密码的数组，姓名的数组
	char password[40], name[40];
	printf("请输入用户名\n");
	scanf_s("%s", name, 40);
	if (strcmp(name, user) == 0){
		printf("请输入密码\n");
		scanf_s("%s", password, 40);
		if (strcmp(password0, password) == 0){
			return 1;
		}
		else{
			return 0;
		}
	}
	else{
		printf("错误\n");
		return 0;
	}
}