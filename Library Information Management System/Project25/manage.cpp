#include"lib.h"
struct st *manage(struct st *head,struct stu *headb){//���������
	int i, a;
	system("CLS"); //����
	while (1){
		printf("****************************************************************************\n");
		printf("*                   ��ӭʹ��ͼ����Ϣ����ϵͳ������Ա��                     *\n");
		printf("* ����ѡ���������ֲ��س���                                               *\n");
		printf("*     1.��  ��  ¼  ��                        2.��  ��  ��  ��             *\n");
		printf("*     3.��  ��  ��  ��                        4.ɾ  ��  ��  ��             *\n");
		printf("*     5.��  ��  ��  ѯ                        6.��  ��  ��  ��             *\n");
		printf("*     7.��  ʾ  ��  ��                        8.��  ȡ  ��  ��             *\n");
		printf("*     9.��  ��  ��  Ϣ                        10.��  ��  ϵ  ͳ            *\n");
		printf("****************************************************************************\n");
		printf("�����룺");
		scanf_s("%d", &i);
		if (i == 10){
			printf("ϵͳ���˳�\n");
			break;
		}
		system("CLS"); //����
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
			printf("��ѡ���ѯ��ʽ1.�ؼ��ֲ�ѯ/2.��ȷ��ѯ��");
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
			printf("��ʼ��ȡdata.txt\n");
			head = read(head);
			printf("��ʼ��ȡborrow.txt\n");
			headb = readstu(headb);
		}break;
		case 9:{
			printstu(headb);
		}break;
		}
		system("PAUSE");//ͣ��
		system("CLS"); //����
	}
	return(head);
	
}