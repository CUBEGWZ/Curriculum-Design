void menu_t();	//老师端管理界面
void creat();	//创建
void del();	//删除
void judge_del_continue(StuManage *head);	//是否继续删除学生信息的判断
void judge_del_choose();     //删除学生信息后的选择界面
void search();  //查询
void search_num();  //查询学号
void search_merge(char ch[],int c);     //查询其他
void judge_search(int a);   //是否继续查询操作
void insert();	//插入
StuManage *judge_insert_continue(StuManage *head);	//是否继续插入学生信息
StuManage *judge_insert_validity(StuManage *head,StuManage *p0,StuManage *p1,StuManage *p2);    //插入信息正确性的判断
StuManage *insert_cooperate(StuManage *head);      //插入的协助函数，利用返回值
void judge_insert_continue_2();     //插入信息后，遍历信息显示后的选择操作界面
void modify();  //修改
StuManage *modify_num(StuManage *head,StuManage *p1);   //修改学号
StuManage *modify_age(StuManage *head,StuManage *p1);   //修改年龄
StuManage *modify_sex(StuManage *head,StuManage *p1);   //修改性别
StuManage *modify_merge(StuManage *head,StuManage *p1,int n,char ch[]);     //修改其他
void judge_modify();  //修改后的选择
void list(StuManage *head);	    //遍历
void list_one(StuManage *p);    //遍历一个
StuManage *sort(StuManage *head);		//链表排序
StuManage *input_stu(StuManage *p,int i);   //输入学生部分信息自定义函数
