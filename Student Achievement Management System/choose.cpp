#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<io.h>
#include<conio.h>
#include<windows.h>
#include "header.h"
#include "login.h"
#include "about_stu.h"
#include "about_tea.h"
#include "choose.h"
#include "about_file.h"
char judge_ch()
{
	char b;
	b=getch();
	while(b!='y'&&b!='Y'&&b!='n'&&b!='N')
		b=getch();
	return b;
}
int judge_num(int n)
{
	char b;
	b=getch();
	switch(n)
	{
		case 10:
		while(b<'0'||b>'9')
            b=getch();
        break;
		case 8:
		while(b<'1'||b>'8')
			b=getch();
		break;
		case 7:
		while(b<'1'||b>'7')
			b=getch();
		break;
		case 6:
		while(b<'1'||b>'6')
			b=getch();
		break;
		case 5:
		while(b<'1'||b>'5')
			b=getch();
		break;
		case 4:
		while(b<'1'||b>'4')
			b=getch();
		break;
		case 3:
		while(b<'1'||b>'3')
			b=getch();
		break;
		case 2:
		while(b<'1'||b>'2')
			b=getch();
		break;
	}
	return ((int)b-48);
}
