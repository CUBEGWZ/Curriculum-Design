struct goods                    //��¼ϵͳ������Щ��Ʒ��Ϣ�Ľṹ��
{
	int id;
	char name[20];
	double price;
	int num;
	char type[20];
	struct goods *next;
};
void menu();                               
