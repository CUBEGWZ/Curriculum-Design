struct goods                    //记录系统包含哪些商品信息的结构体
{
	int id;
	char name[20];
	double price;
	int num;
	char type[20];
	struct goods *next;
};
void menu();                               
