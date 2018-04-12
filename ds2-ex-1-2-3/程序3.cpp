#include<iostream> 
#include<iomanip> 
#include<fstream> 
#include<string> 
#define max 100;
using namespace std; 
class student {
	public: 
		student *next; 
	public: 
		string name;//姓名 
		long num;//学号 
		int x,y,z;//数学，语文，英语 
		int AA;//总分 
	void play(){
		cout<<name<<"学生的学号是"<<num<<",数学:"<<x<<",语文:"<<y<<",英语:"<<z<<",总分:"<<AA<<endl;
	}; 
	student(string sname,long snum,int sx,int sy,int sz){
		name=sname; 
		num=snum; 
		x=sx; 
		y=sy; 
		z=sz; 
	} 
}; 

class cla{
	public: 
		cla(){ //构造函数 
			stu=0; 
			sload(); 
		} 
	~cla(){//析构函数 
 		student *p; 
		p=stu; 
		while(p){ 
			p=p->next; 
			delete stu; 
			stu=p; 
		} 
	stu=0; 
	} 
	void sadd(); //添加 
	void sremove(); //删除 
	void samend(); //修改 
	void ssearch(); //查询 
	void staxis(); //排序 
	void ssave(); //保存 
	void sload(); //读取 
	//排序函数 
	void pxh(); 
	void psx(); 
	void pyw(); 
	void pyy(); 
	void pAA(); 
	private: 
		student *stu; //头接点 
}; 

void cla::sadd(){//添加 
	student *q; 
	string name1; 
	long num1; 
	int x1,y1,z1; 

	system("cls"); 
	cout<<"\n **增加的学生** \n"<<endl; 
	cout<<"请输入学生的(中间用空格间隔) "<<endl; 
	cout<<"姓名 学号 数学成绩 语文成绩 英语成绩:"<<endl; 
	cin>>name1>>num1>>x1>>y1>>z1; 

	q=new student(name1,num1,x1,y1,z1); 
	q->next=0; 
	q->AA=x1+y1+z1; 

	if(stu) { 
		student *t; 
		t=stu; 
		if(t->num==num1) { 
			cout<<"学号已存在，请重新输入"<<endl; 
			return; 
		} 
		while(t->next) { 
			if(t->num==num1) { 
				cout<<"学号已存在，请重新输入"<<endl; 
				return; 
			} 
			t=t->next; 
		} 
		t->next=q; 
	} else { 
		stu=q; 
	} 
	cout<<"输入完毕"<<endl; 
} 

void cla::sremove(){//删除 
	system("cls"); 
	int num1; 
	cout<<"\n** 删除学生信息 **\n"; 
	cout<<"请输入想要删除学生的学号:"; 
	cin>>num1; 

	//查找要删除的结点 
	student *p1,*p2; 
	p1=stu; 
	while(p1) { 
		if(p1->num==num1) 
			break; 
		else { 
			p2=p1; 
			p1=p1->next; 
		} 
	} 

	//删除结点 
	if(p1!=NULL){ //若找到结点，则删除 
		p1->play(); 
		cout<<"确定删除吗?[Y/N]"<<endl; 
		char c;cin>>c; 
		if(toupper(c)!='Y') 
			return; 
		if(p1==stu){  //若要删除的结点是第一个结点 
			stu=p1->next; 
			delete p1; 
		} else {//若要删除的结点是后续结点 
			p2->next=p1->next; 
			delete p1; 
		} 
		cout<<"找到学号为"<<num1<<"的学生，并删除\n"; 
	} else //未找到结点 
		cout<<"未找到想要删除的学生!\n"; 
} 

void cla::samend(){ //修改 
	system("cls"); 
	long num1; 
	cout<<"\n** 修改学生信息 **\n"; 
	cout<<"输入要修改学生的学号"; 
	cin>>num1; 
	//查找要修改的结点 
	student *p1,*p2; 
	p1=stu; 
	while(p1) { 
		if(p1->num==num1) 
			break; 
		else { 
			p2=p1; 
			p1=p1->next; 
		} 
	} 
	if(p1!=NULL) { 
		cout<<"学号是"<<num1<<"的学生的信息"<<endl; 
		cout<<"姓名 "<<p1->name<<"数学"<<p1->x<<"语文"<<p1->y<<"英语"<<p1->z<<endl; 
		cout<<"请输入修改后的信息：姓名 数学成绩 语文成绩 英语成绩"<<endl; 
		cin>>p1->name>>p1->x>>p1->y>>p1->z; 
		p1->AA=p1->x+p1->y+p1->z; 
		cout<<"修改成功"<<endl; 
	} else //未找到接点 
		cout<<"未找到!\n"; 
} 

void cla::ssearch(){ //查询 
	system("cls"); 
	cout<<"\n** 查询学生信息 **\n"<<endl; 
	cout<<"请输入查询方式："<<endl; 
	cout<<"1.按学号查询"<<endl; 
	cout<<"2.按姓名查询"<<endl; 
	cout<<"3.返回"<<endl; 
	char c; cin>>c; 
	switch (c) { 
		case '1': { 
			long num1; 
			cout<<"要查询的学号"<<endl; 
			cin>>num1; 
			//查找要查询的结点 
			student *p1,*p2; 
			p1=stu; 
			while(p1) { 
				if(p1->num==num1) 
					break; 
				else {
					p2=p1; 
					p1=p1->next; 
				} 
			} 
			if(p1!=NULL) { 
				cout<<"学号是"<<num1<<"的学生的信息"<<endl; 
				cout<<"姓名:"<<p1->name<<" 数学:"<<p1->x<<" 语文:"<<p1->y<<" 英语:"<<p1->z<<endl; 
				cout<<"查询完毕..."; 
			}else //未找到接点 
				cout<<"未找到!\n"; 
				break; 
		} 
		case '2': {
			string name1; 
			cout<<"要查询的学生姓名"<<endl; 
			cin>>name1; 
			//查找要查询的结点 
			student *p1,*p2; 
			p1=stu; 
			while(p1) { 
				if(p1->name==name1) 
					break; 
				else { 
					p2=p1; 
					p1=p1->next; 
				} 
			} 
			if(p1!=NULL) { 
				cout<<name1<<"的学生的信息"<<endl; 
				cout<<"学号:"<<p1->num<<" 数学:"<<p1->x<<" 语文:"<<p1->y<<" 英语:"<<p1->z<<endl; 
				cout<<"查询完毕..."; 
			} else //未找到接点 
				cout<<"未找到!\n"; 
				break; 
		} 
		case '3': 
			return; 
	} 
} 

void cla::pxh() {//按学号排序 
	student *p1,*p2; 
	int n; 
	p1=stu; 
	n=1; 
	while(p1->next) { 
		n++; 
		p1=p1->next; 
	} 
	cout<<"共有"<<n<<"条信息..."<<endl; 
	int i; 
	p1=stu; 
	for(i=1;i<n;i++) { 
		p1=stu; 
		if (p1->num>p1->next->num) {// 如果头结点大于第二个的 
			p2=p1->next; 
			p1->next=p1->next->next; 
			p2->next=p1; //头结点交换 
			stu=p2; 
		} 
		p1=stu; 
		while(p1->next->next) {//中间的交换  
			p2=p1; 
			p1=p1->next; 
			if(p1->num>p1->next->num) {
				p2->next=p1->next; 
				p1->next=p1->next->next; 
				p2->next->next=p1; 
				p1=p2->next; //交换 
			} 
		} 
	} 
	p1=stu; 
	do {
		p1->play(); 
		p1=p1->next; 
	}
	while(p1); 
} 

void cla::psx(){//按数学成绩排序 
 	student *p1,*p2; 
	int n; 
	p1=stu; 
	n=1; 
	while(p1->next) {
 		n++; 
		p1=p1->next; 
	} 
	cout<<"共有"<<n<<"条信息..."<<endl; 
	int i; 
	p1=stu; 
	for(i=1;i<n;i++) {
 		p1=stu; 
		if (p1->x>p1->next->x) {// 如果头结点大于第二个的 
 			p2=p1->next; 
			p1->next=p1->next->next; 
			p2->next=p1; //头结点交换 
			stu=p2; 
		} 
		p1=stu; 
		while(p1->next->next) {//中间的交换 
 			p2=p1; 
			p1=p1->next; 
			if(p1->x>p1->next->x) {
 				p2->next=p1->next; 
				p1->next=p1->next->next; 
				p2->next->next=p1; 
				p1=p2->next; //交换 
			} 
		} 
	} 
	p1=stu; 
	do { 
		p1->play(); 
		p1=p1->next; 
	}
	while(p1); 
} 

void cla::pyw(){//按语文成绩排序 
 	student *p1,*p2; 
	int n; 
	p1=stu; 
	n=1; 
	while(p1->next) {
 		n++; 
		p1=p1->next; 
	} 
	cout<<"共有"<<n<<"条信息..."<<endl; 
	int i; 
	p1=stu; 
	for(i=1;i<n;i++) {
 		p1=stu; 
		if (p1->y>p1->next->y) {// 如果头结点大于第二个的 
 			p2=p1->next; 
			p1->next=p1->next->next; 
			p2->next=p1; //头结点交换 
			stu=p2; 
		} 
		p1=stu; 
		while(p1->next->next) {//中间的交换 
 			p2=p1; 
			p1=p1->next; 
			if(p1->y>p1->next->y) {
				p2->next=p1->next; 
				p1->next=p1->next->next; 
				p2->next->next=p1; 
				p1=p2->next; //交换 
			} 
		} 
	} 
	p1=stu; 
	do { 
		p1->play(); 
		p1=p1->next; 
	}
	while(p1); 
} 

void cla::pyy(){ //按英语成绩排序 
	student *p1,*p2; 
	int n; 
	p1=stu; 
	n=1; 
	while(p1->next) { 
		n++; 
		p1=p1->next; 
	} 
	cout<<"共有"<<n<<"条信息..."<<endl; 
	int i; 
	p1=stu; 
	for(i=1;i<n;i++) { 
		p1=stu; 
		if (p1->z>p1->next->z) {// 如果头结点大于第二个的 
 			p2=p1->next; 
			p1->next=p1->next->next; 
			p2->next=p1; //头结点交换 
			stu=p2; 
		} 
		p1=stu; 
		while(p1->next->next) {//中间的交换 
 			p2=p1; 
			p1=p1->next; 
			if(p1->z>p1->next->z) {
 				p2->next=p1->next; 
				p1->next=p1->next->next; 
				p2->next->next=p1; 
				p1=p2->next; //交换 
			} 
		} 
	} 
	p1=stu; 
	do {
		p1->play(); 
		p1=p1->next; 
	}
	while(p1); 
} 

void cla::pAA() {//按总分排序 
	student *p1,*p2; 
	int n; 
	p1=stu; 
	n=1; 
	while(p1->next) {
 		n++; 
		p1=p1->next; 
	} 
	cout<<"共有"<<n<<"条信息..."<<endl; 
	int i; 
	p1=stu; 
	for(i=1;i<n;i++) { 
		p1=stu; 
		if (p1->AA>p1->next->AA) {// 如果头结点大于第二个的 
 			p2=p1->next; 
			p1->next=p1->next->next; 
			p2->next=p1; //头结点交换 
			stu=p2; 
		} 
		p1=stu; 
		while(p1->next->next) {//中间的交换 
 			p2=p1; 
			p1=p1->next; 
			if(p1->AA>p1->next->AA) {
				p2->next=p1->next; 
				p1->next=p1->next->next; 
				p2->next->next=p1; 
				p1=p2->next; //交换 
			} 
		} 
	} 
	p1=stu; 
	do {
 		p1->play(); 
		p1=p1->next; 
	}
	while(p1); 
} 

void cla::staxis(){//排序 
	system("cls"); 
	char c; 
	cout<<"请选择以何种方式排序："<<endl; 
	cout<<"1……以学号排序"<<endl; 
	cout<<"2……以数学成绩排序"<<endl; 
	cout<<"3……以语文成绩排序"<<endl; 
	cout<<"4……以英语成绩排序"<<endl; 
	cout<<"5……以总分排序"<<endl; 
	cout<<"6……返回"<<endl; 
	cout<<"请选择(1-6)"<<endl; 
	cin>>c; 
	switch (c) { 
		case '1':
			pxh(); 
			break; 
		case '2':
			psx(); 
			break; 
		case '3':
			pyw(); 
			break; 
		case '4':
			pyy(); 
			break; 
		case '5':
			pAA();
			 break; 
		case '6':
			return; 
	} 
} 

void cla::ssave() {//保存到文件 
	system("cls"); 
	char c; 
	cout<<"\n保存学生信息（将覆盖原文件）,是否继续?[Y/N]:"; cin>>c; 
	if(toupper(c)!='Y') 
		return; 
	ofstream tfile("date.txt",ios_base::binary); 
	student *p=stu; 
	while(p) {// 写入文件 
		tfile<<p->name<<"\t"<<p->num<<"\t"<<p->x<<"\t"<<p->y<<"\t"<<p->z; 
		tfile<<endl; 
		p=p->next; 
	} 
	tfile.close(); 
	cout<<"保存完毕..."<<endl; 
} 

void cla::sload() {//读取 
	student *p; 
	p=stu; 
	while(p) {
		stu=p->next; 
		delete p; 
		p=stu; 
	} 
	ifstream tfile("date.txt",ios_base::binary); 
	string name1; 
	long num1; 
	int x1,y1,z1; 
	tfile>>name1>>num1>>x1>>y1>>z1; 
	while(tfile.good()) {//创建学生接点 
		student *s; 
		s=stu; 
		s=new student(name1,num1,x1,y1,z1); 
		s->next=0; 
		s->AA=x1+y1+z1; 
		if(stu) { //若已经存在结点  
			student *p2; 
			p2=stu; 
			while(p2->next) {//查找尾结点 
				p2=p2->next; 
			} 
			p2->next=s; //连接 
		} else {//若不存在结点(表空) 
			stu=s; //连接 
		} 
		tfile>>name1>>num1>>x1>>y1>>z1; 
	} 
	tfile.close(); 
	cout<<"\n学生信息已经装入...\n"; 
} 

int main(){
	char c; 
	cla a; 
	do{ 
		cout<<"\n 学 生 成 绩 管 理 系 统 \n"; 
		cout<<"**************************************\n"; 
		cout<<" 1……增加学生 \n"; 
		cout<<" 2……删除学生 \n"; 
		cout<<" 3……修改学生 \n"; 
		cout<<" 4……查询学生信息 \n"; 
		cout<<" 5……排序 \n"; 
		cout<<" 6……保存 \n"; 
		cout<<" 7……读取信息 \n"; 
		cout<<" 8……退出 \n"; 
		cout<<"**************************************\n"; 
		cout<<"请选择(1-8):"; 
		cin>>c; 
		switch(c){ 
			case '1': a.sadd();break; 
			case '2': a.sremove();break; 
			case '3': a.samend();break; 
			case '4': a.ssearch();break; 
			case '5': a.staxis();break; 
			case '6': a.ssave();break; 
			case '7': a.sload();break;
		}
	}while(c!='8');
}
