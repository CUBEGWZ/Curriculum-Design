#include"lib.h"
struct st *manage(struct st *head,struct stu *headb){//定义管理函数
	int i, a;
	system("CLS"); //清屏
	while (1){
		printf("****************************************************************************\n");
		printf("*                   欢迎使用图书信息管理系统（管理员）                     *\n");
		printf("* 功能选择（输入数字并回车）                                               *\n");
		printf("*     1.数  据  录  入                        2.更  新  数  据             *\n");
		printf("*     3.添  加  数  据                        4.删  除  数  据             *\n");
		printf("*     5.数  据  查  询                        6.修  改  数  据             *\n");
		printf("*     7.显  示  数  据                        8.读  取  数  据             *\n");
		printf("*     9.借  阅  信  息                        10.退  出  系  统            *\n");
		printf("****************************************************************************\n");
		printf("请输入：");
		scanf_s("%d", &i);
		if (i == 10){
			printf("系统已退出\n");
			break;
		}
		system("CLS"); //清屏
		switch (i){
		case 1:{
			head = in(head);
			fresh(head);
		} break;
		case 2:{
			fresh(head);
		} break;
		case 3:{
			//head=add(head);
			fresh(head);
		} break;
		case 4:{
			head=del(head);
			fresh(head);
		} break;
		case 5:{
			printf("请选择查询方式1.关键字查询/2.精确查询：");
			scanf_s("%d", &a);
			if (a == 1){
				findb(head, 0);
			}
			if (a == 2){
				find(head,0);
			}
		} break;
		case 6:{
			//head=change(head);
			fresh(head);
		} break;
		case 7:{
			print(head);
		}break;
		case 8:{
			printf("开始读取data.txt\n");
			head = read(head);
			printf("开始读取borrow.txt\n");
			headb = readstu(headb);
		}break;
		case 9:{
			printstu(headb);
		}break;
		}
		system("PAUSE");//停顿
		system("CLS"); //清屏
	}
	return(head);
	
}