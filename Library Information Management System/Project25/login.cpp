#include"lib.h"
int login(){
	char user[40] = { "admin" }, password0[40] = { "admin" };//������������飬����������
	char password[40], name[40];
	printf("�������û���\n");
	scanf_s("%s", name, 40);
	if (strcmp(name, user) == 0){
		printf("����������\n");
		scanf_s("%s", password, 40);
		if (strcmp(password0, password) == 0){
			return 1;
		}
		else{
			return 0;
		}
	}
	else{
		printf("����\n");
		return 0;
	}
}