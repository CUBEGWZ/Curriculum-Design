void menu_t();	//��ʦ�˹������
void creat();	//����
void del();	//ɾ��
void judge_del_continue(StuManage *head);	//�Ƿ����ɾ��ѧ����Ϣ���ж�
void judge_del_choose();     //ɾ��ѧ����Ϣ���ѡ�����
void search();  //��ѯ
void search_num();  //��ѯѧ��
void search_merge(char ch[],int c);     //��ѯ����
void judge_search(int a);   //�Ƿ������ѯ����
void insert();	//����
StuManage *judge_insert_continue(StuManage *head);	//�Ƿ��������ѧ����Ϣ
StuManage *judge_insert_validity(StuManage *head,StuManage *p0,StuManage *p1,StuManage *p2);    //������Ϣ��ȷ�Ե��ж�
StuManage *insert_cooperate(StuManage *head);      //�����Э�����������÷���ֵ
void judge_insert_continue_2();     //������Ϣ�󣬱�����Ϣ��ʾ���ѡ���������
void modify();  //�޸�
StuManage *modify_num(StuManage *head,StuManage *p1);   //�޸�ѧ��
StuManage *modify_age(StuManage *head,StuManage *p1);   //�޸�����
StuManage *modify_sex(StuManage *head,StuManage *p1);   //�޸��Ա�
StuManage *modify_merge(StuManage *head,StuManage *p1,int n,char ch[]);     //�޸�����
void judge_modify();  //�޸ĺ��ѡ��
void list(StuManage *head);	    //����
void list_one(StuManage *p);    //����һ��
StuManage *sort(StuManage *head);		//��������
StuManage *input_stu(StuManage *p,int i);   //����ѧ��������Ϣ�Զ��庯��
