#include"lib.h"
void student(struct st *head,struct stu *headb){
	int i;
	system("CLS");//����
	while (1){
		printf("****************************************************************************\n");
		printf("*                   ��ӭʹ��ͼ����Ϣ����ϵͳ��ѧ����                       *\n");
		printf("*                                                                          *\n");
		printf("*     1.����          2.����           3.���Ĳ�ѯ             4.�˳�       *\n");
		printf("****************************************************************************\n");
		printf("�����룺");
		scanf_s("%d", &i);
		if (i == 4){
			printf("ϵͳ���˳�\n");
			break;
		}
		system("CLS");//����
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
		system("PAUSE");//ͣ��
		system("CLS");//����
	}
}