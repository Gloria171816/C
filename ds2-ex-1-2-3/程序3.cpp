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
		string name;//���� 
		long num;//ѧ�� 
		int x,y,z;//��ѧ�����ģ�Ӣ�� 
		int AA;//�ܷ� 
	void play(){
		cout<<name<<"ѧ����ѧ����"<<num<<",��ѧ:"<<x<<",����:"<<y<<",Ӣ��:"<<z<<",�ܷ�:"<<AA<<endl;
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
		cla(){ //���캯�� 
			stu=0; 
			sload(); 
		} 
	~cla(){//�������� 
 		student *p; 
		p=stu; 
		while(p){ 
			p=p->next; 
			delete stu; 
			stu=p; 
		} 
	stu=0; 
	} 
	void sadd(); //��� 
	void sremove(); //ɾ�� 
	void samend(); //�޸� 
	void ssearch(); //��ѯ 
	void staxis(); //���� 
	void ssave(); //���� 
	void sload(); //��ȡ 
	//������ 
	void pxh(); 
	void psx(); 
	void pyw(); 
	void pyy(); 
	void pAA(); 
	private: 
		student *stu; //ͷ�ӵ� 
}; 

void cla::sadd(){//��� 
	student *q; 
	string name1; 
	long num1; 
	int x1,y1,z1; 

	system("cls"); 
	cout<<"\n **���ӵ�ѧ��** \n"<<endl; 
	cout<<"������ѧ����(�м��ÿո���) "<<endl; 
	cout<<"���� ѧ�� ��ѧ�ɼ� ���ĳɼ� Ӣ��ɼ�:"<<endl; 
	cin>>name1>>num1>>x1>>y1>>z1; 

	q=new student(name1,num1,x1,y1,z1); 
	q->next=0; 
	q->AA=x1+y1+z1; 

	if(stu) { 
		student *t; 
		t=stu; 
		if(t->num==num1) { 
			cout<<"ѧ���Ѵ��ڣ�����������"<<endl; 
			return; 
		} 
		while(t->next) { 
			if(t->num==num1) { 
				cout<<"ѧ���Ѵ��ڣ�����������"<<endl; 
				return; 
			} 
			t=t->next; 
		} 
		t->next=q; 
	} else { 
		stu=q; 
	} 
	cout<<"�������"<<endl; 
} 

void cla::sremove(){//ɾ�� 
	system("cls"); 
	int num1; 
	cout<<"\n** ɾ��ѧ����Ϣ **\n"; 
	cout<<"��������Ҫɾ��ѧ����ѧ��:"; 
	cin>>num1; 

	//����Ҫɾ���Ľ�� 
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

	//ɾ����� 
	if(p1!=NULL){ //���ҵ���㣬��ɾ�� 
		p1->play(); 
		cout<<"ȷ��ɾ����?[Y/N]"<<endl; 
		char c;cin>>c; 
		if(toupper(c)!='Y') 
			return; 
		if(p1==stu){  //��Ҫɾ���Ľ���ǵ�һ����� 
			stu=p1->next; 
			delete p1; 
		} else {//��Ҫɾ���Ľ���Ǻ������ 
			p2->next=p1->next; 
			delete p1; 
		} 
		cout<<"�ҵ�ѧ��Ϊ"<<num1<<"��ѧ������ɾ��\n"; 
	} else //δ�ҵ���� 
		cout<<"δ�ҵ���Ҫɾ����ѧ��!\n"; 
} 

void cla::samend(){ //�޸� 
	system("cls"); 
	long num1; 
	cout<<"\n** �޸�ѧ����Ϣ **\n"; 
	cout<<"����Ҫ�޸�ѧ����ѧ��"; 
	cin>>num1; 
	//����Ҫ�޸ĵĽ�� 
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
		cout<<"ѧ����"<<num1<<"��ѧ������Ϣ"<<endl; 
		cout<<"���� "<<p1->name<<"��ѧ"<<p1->x<<"����"<<p1->y<<"Ӣ��"<<p1->z<<endl; 
		cout<<"�������޸ĺ����Ϣ������ ��ѧ�ɼ� ���ĳɼ� Ӣ��ɼ�"<<endl; 
		cin>>p1->name>>p1->x>>p1->y>>p1->z; 
		p1->AA=p1->x+p1->y+p1->z; 
		cout<<"�޸ĳɹ�"<<endl; 
	} else //δ�ҵ��ӵ� 
		cout<<"δ�ҵ�!\n"; 
} 

void cla::ssearch(){ //��ѯ 
	system("cls"); 
	cout<<"\n** ��ѯѧ����Ϣ **\n"<<endl; 
	cout<<"�������ѯ��ʽ��"<<endl; 
	cout<<"1.��ѧ�Ų�ѯ"<<endl; 
	cout<<"2.��������ѯ"<<endl; 
	cout<<"3.����"<<endl; 
	char c; cin>>c; 
	switch (c) { 
		case '1': { 
			long num1; 
			cout<<"Ҫ��ѯ��ѧ��"<<endl; 
			cin>>num1; 
			//����Ҫ��ѯ�Ľ�� 
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
				cout<<"ѧ����"<<num1<<"��ѧ������Ϣ"<<endl; 
				cout<<"����:"<<p1->name<<" ��ѧ:"<<p1->x<<" ����:"<<p1->y<<" Ӣ��:"<<p1->z<<endl; 
				cout<<"��ѯ���..."; 
			}else //δ�ҵ��ӵ� 
				cout<<"δ�ҵ�!\n"; 
				break; 
		} 
		case '2': {
			string name1; 
			cout<<"Ҫ��ѯ��ѧ������"<<endl; 
			cin>>name1; 
			//����Ҫ��ѯ�Ľ�� 
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
				cout<<name1<<"��ѧ������Ϣ"<<endl; 
				cout<<"ѧ��:"<<p1->num<<" ��ѧ:"<<p1->x<<" ����:"<<p1->y<<" Ӣ��:"<<p1->z<<endl; 
				cout<<"��ѯ���..."; 
			} else //δ�ҵ��ӵ� 
				cout<<"δ�ҵ�!\n"; 
				break; 
		} 
		case '3': 
			return; 
	} 
} 

void cla::pxh() {//��ѧ������ 
	student *p1,*p2; 
	int n; 
	p1=stu; 
	n=1; 
	while(p1->next) { 
		n++; 
		p1=p1->next; 
	} 
	cout<<"����"<<n<<"����Ϣ..."<<endl; 
	int i; 
	p1=stu; 
	for(i=1;i<n;i++) { 
		p1=stu; 
		if (p1->num>p1->next->num) {// ���ͷ�����ڵڶ����� 
			p2=p1->next; 
			p1->next=p1->next->next; 
			p2->next=p1; //ͷ��㽻�� 
			stu=p2; 
		} 
		p1=stu; 
		while(p1->next->next) {//�м�Ľ���  
			p2=p1; 
			p1=p1->next; 
			if(p1->num>p1->next->num) {
				p2->next=p1->next; 
				p1->next=p1->next->next; 
				p2->next->next=p1; 
				p1=p2->next; //���� 
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

void cla::psx(){//����ѧ�ɼ����� 
 	student *p1,*p2; 
	int n; 
	p1=stu; 
	n=1; 
	while(p1->next) {
 		n++; 
		p1=p1->next; 
	} 
	cout<<"����"<<n<<"����Ϣ..."<<endl; 
	int i; 
	p1=stu; 
	for(i=1;i<n;i++) {
 		p1=stu; 
		if (p1->x>p1->next->x) {// ���ͷ�����ڵڶ����� 
 			p2=p1->next; 
			p1->next=p1->next->next; 
			p2->next=p1; //ͷ��㽻�� 
			stu=p2; 
		} 
		p1=stu; 
		while(p1->next->next) {//�м�Ľ��� 
 			p2=p1; 
			p1=p1->next; 
			if(p1->x>p1->next->x) {
 				p2->next=p1->next; 
				p1->next=p1->next->next; 
				p2->next->next=p1; 
				p1=p2->next; //���� 
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

void cla::pyw(){//�����ĳɼ����� 
 	student *p1,*p2; 
	int n; 
	p1=stu; 
	n=1; 
	while(p1->next) {
 		n++; 
		p1=p1->next; 
	} 
	cout<<"����"<<n<<"����Ϣ..."<<endl; 
	int i; 
	p1=stu; 
	for(i=1;i<n;i++) {
 		p1=stu; 
		if (p1->y>p1->next->y) {// ���ͷ�����ڵڶ����� 
 			p2=p1->next; 
			p1->next=p1->next->next; 
			p2->next=p1; //ͷ��㽻�� 
			stu=p2; 
		} 
		p1=stu; 
		while(p1->next->next) {//�м�Ľ��� 
 			p2=p1; 
			p1=p1->next; 
			if(p1->y>p1->next->y) {
				p2->next=p1->next; 
				p1->next=p1->next->next; 
				p2->next->next=p1; 
				p1=p2->next; //���� 
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

void cla::pyy(){ //��Ӣ��ɼ����� 
	student *p1,*p2; 
	int n; 
	p1=stu; 
	n=1; 
	while(p1->next) { 
		n++; 
		p1=p1->next; 
	} 
	cout<<"����"<<n<<"����Ϣ..."<<endl; 
	int i; 
	p1=stu; 
	for(i=1;i<n;i++) { 
		p1=stu; 
		if (p1->z>p1->next->z) {// ���ͷ�����ڵڶ����� 
 			p2=p1->next; 
			p1->next=p1->next->next; 
			p2->next=p1; //ͷ��㽻�� 
			stu=p2; 
		} 
		p1=stu; 
		while(p1->next->next) {//�м�Ľ��� 
 			p2=p1; 
			p1=p1->next; 
			if(p1->z>p1->next->z) {
 				p2->next=p1->next; 
				p1->next=p1->next->next; 
				p2->next->next=p1; 
				p1=p2->next; //���� 
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

void cla::pAA() {//���ܷ����� 
	student *p1,*p2; 
	int n; 
	p1=stu; 
	n=1; 
	while(p1->next) {
 		n++; 
		p1=p1->next; 
	} 
	cout<<"����"<<n<<"����Ϣ..."<<endl; 
	int i; 
	p1=stu; 
	for(i=1;i<n;i++) { 
		p1=stu; 
		if (p1->AA>p1->next->AA) {// ���ͷ�����ڵڶ����� 
 			p2=p1->next; 
			p1->next=p1->next->next; 
			p2->next=p1; //ͷ��㽻�� 
			stu=p2; 
		} 
		p1=stu; 
		while(p1->next->next) {//�м�Ľ��� 
 			p2=p1; 
			p1=p1->next; 
			if(p1->AA>p1->next->AA) {
				p2->next=p1->next; 
				p1->next=p1->next->next; 
				p2->next->next=p1; 
				p1=p2->next; //���� 
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

void cla::staxis(){//���� 
	system("cls"); 
	char c; 
	cout<<"��ѡ���Ժ��ַ�ʽ����"<<endl; 
	cout<<"1������ѧ������"<<endl; 
	cout<<"2��������ѧ�ɼ�����"<<endl; 
	cout<<"3���������ĳɼ�����"<<endl; 
	cout<<"4������Ӣ��ɼ�����"<<endl; 
	cout<<"5�������ܷ�����"<<endl; 
	cout<<"6��������"<<endl; 
	cout<<"��ѡ��(1-6)"<<endl; 
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

void cla::ssave() {//���浽�ļ� 
	system("cls"); 
	char c; 
	cout<<"\n����ѧ����Ϣ��������ԭ�ļ���,�Ƿ����?[Y/N]:"; cin>>c; 
	if(toupper(c)!='Y') 
		return; 
	ofstream tfile("date.txt",ios_base::binary); 
	student *p=stu; 
	while(p) {// д���ļ� 
		tfile<<p->name<<"\t"<<p->num<<"\t"<<p->x<<"\t"<<p->y<<"\t"<<p->z; 
		tfile<<endl; 
		p=p->next; 
	} 
	tfile.close(); 
	cout<<"�������..."<<endl; 
} 

void cla::sload() {//��ȡ 
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
	while(tfile.good()) {//����ѧ���ӵ� 
		student *s; 
		s=stu; 
		s=new student(name1,num1,x1,y1,z1); 
		s->next=0; 
		s->AA=x1+y1+z1; 
		if(stu) { //���Ѿ����ڽ��  
			student *p2; 
			p2=stu; 
			while(p2->next) {//����β��� 
				p2=p2->next; 
			} 
			p2->next=s; //���� 
		} else {//�������ڽ��(���) 
			stu=s; //���� 
		} 
		tfile>>name1>>num1>>x1>>y1>>z1; 
	} 
	tfile.close(); 
	cout<<"\nѧ����Ϣ�Ѿ�װ��...\n"; 
} 

int main(){
	char c; 
	cla a; 
	do{ 
		cout<<"\n ѧ �� �� �� �� �� ϵ ͳ \n"; 
		cout<<"**************************************\n"; 
		cout<<" 1��������ѧ�� \n"; 
		cout<<" 2����ɾ��ѧ�� \n"; 
		cout<<" 3�����޸�ѧ�� \n"; 
		cout<<" 4������ѯѧ����Ϣ \n"; 
		cout<<" 5�������� \n"; 
		cout<<" 6�������� \n"; 
		cout<<" 7������ȡ��Ϣ \n"; 
		cout<<" 8�����˳� \n"; 
		cout<<"**************************************\n"; 
		cout<<"��ѡ��(1-8):"; 
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
