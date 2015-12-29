struct M 
{
	char a[10],b[100],c[100],d[100],e[10];
	struct M *next;
};
#define N sizeof(struct M)
void menu1();
void menu2();
void input();
struct M *creat();
void del(struct M *head);
void add(struct M *head);
void save(struct M *head);
void find(struct M *head);
void list();
void list2();
void DO();
