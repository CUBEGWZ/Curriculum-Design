#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"
void main()
{   system("cls");
	printf("                      *************欢迎进入题库系统************\n");
	printf("                        管理员身份运行输入1，学生身份运行输入2\n");
	int a;
	scanf("%d",&a);
	if(a==1)
	{menu1();}
	else if(a==2)
	{menu2();}
	else
	{
		printf("请输入正确的数字!\n");
		getchar();
		getchar();
		main();
	}
}