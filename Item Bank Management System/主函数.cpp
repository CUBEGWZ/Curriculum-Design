#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"
void main()
{   system("cls");
	printf("                      *************��ӭ�������ϵͳ************\n");
	printf("                        ����Ա�����������1��ѧ�������������2\n");
	int a;
	scanf("%d",&a);
	if(a==1)
	{menu1();}
	else if(a==2)
	{menu2();}
	else
	{
		printf("��������ȷ������!\n");
		getchar();
		getchar();
		main();
	}
}