#include"lib.h"
int main(){
	int i, x;
	struct st  *head = NULL;
	struct stu *headb = NULL;
	while (1){
		headb = readstu(headb);
		head = read(head);
		printf("****************************************************************************\n");
		printf("*                       ��ӭʹ��ͼ����Ϣ����ϵͳ                           *\n");
		printf("*  ѡ����ݣ�                                                              *\n");
		printf("*          1.ѧ��               2.����Ա                3.�˳�             *\n");
		printf("****************************************************************************\n");
		printf("�����룺");
		scanf_s("%d", &i);
		if (i == 1){
			printf("��ѧ����ݵ�½\n");
			student(head,headb);
		}
		if (i == 2){
			printf("�Թ���Ա��ݵ�½\n");
			x = login();
			if (x == 1){
				printf("��½�ɹ�\n");
				system("PAUSE");
				head=manage(head,headb);
			}
			else{
				printf("��½ʧ��������ѡ��\n");
			}
		}
		if(i==3){
			printf("ϵͳ���˳�\n");
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