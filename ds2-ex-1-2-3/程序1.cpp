#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Node   //  ˫������Ľṹ�嶨��
{
	int data;
	struct Node *prior;
	struct Node *next;
}DLNode;

void ListInitiate(DLNode **head)      //˫������ĳ�ʼ��
{
	if((*head=(DLNode *)malloc(sizeof(DLNode)))==NULL) exit(0);
	(*head)->prior=*head;
	(*head)->next=*head;
}

int ListLength(DLNode *head)    //˫������ı�
{
	DLNode *p=head;
	int size=0;
	while(p->next!=head)
	{
		 p=p->next;
		 size++;
	}
	return size;
}

int ListInsert(DLNode *head,int i,int x)    //˫����������ݲ���,i��ʾ�ǲ���ĵڼ���Ԫ��
{
	DLNode *p,*s;
	int j;
	p=head->next;
	j=0;
	while(p!=head&&j<i)
	{
		p=p->next;
		j++;
	}
	if(j!=i)
	{
		 printf("\n����λ�ò��Ϸ���");
		return 0;
	}
	if((s=(DLNode *)malloc(sizeof(DLNode)))==NULL) exit(0);
	s->data=x;
	s->prior=p->prior;//����
	p->prior->next=s;
	s->next=p;
	p->prior=s;
	return 1;
}

int abs(int x)   
{     
	if(x<0)   
		return -x;
	else return x;
}

int InputNumber(DLNode *head)    //�������������
{
	int input,i=0;//��i���ڵ�
	char c;
	scanf("%d%c",&input,&c);
	while(1)
	{
		if(input<0&&i==0)//������Ϊ�����ǵ�һ���ڵ�
		{
			head->data=0;//���������ķ��ű�����ͷ�����
			//input=abs(input);//ȡ�������ֵľ���ֵ
			ListInsert(head,i,input);//��������
		}
		else if(input>=0&&i==0)//������Ϊ�����ǵ�һ���ڵ�
		{
			head->data=1;//���������ķ��ű�����ͷ�����
			ListInsert(head,i,input);//��������
		}
		else
		{ 
			if(head->next->data>=0)
				ListInsert(head,i,input);//�ǵ�һ���ڵ�
			else
			{
				//input=-1*input;
				ListInsert(head,i,input);
			}
		}
		i++;
		if(c==';') break;//��������������ɱ�־������ѭ��
		scanf("%d%c",&input,&c);
	}
	return 1;
}

void OutputNumber(DLNode *head,int sign)    //�ӱ�β�������Ԫ��
{
	DLNode *r=head->next;
	while(r->data==0&&r!=head->prior)
	{
		r=r->next;
	}
	if(sign==1)
	{
		 printf("�����:");
	}
	else
	{
		printf("�����: -");
	}
		printf("%d",r->data);
		r=r->next;
		while(r!=head)
		{	
			if(r->data<10)
			{
				printf(",000");
				printf("%d",r->data);
			}
			else if(r->data<100)
			{			
				printf(",00");
				printf("%d",r->data);
			}
			else if(r->data<1000)
			{
				printf(",0");
				printf("%d",r->data);
			}
			else
			{	
				printf(",%d",r->data);
			}
			r=r->next;
		}
		printf("\n");
} 

void add(DLNode *head1,DLNode *head2,DLNode *head3){
    int z=0;
	int e;
	DLNode *p1,*p2;
    
    p1=head1->prior;
	 p2=head2->prior;
	 while(p1!=head1&&p2!=head2) 
	 {
	     e=p1->data+p2->data+z;
			if(e>=10000)
			{
				z=1;
				e=e%10000;
			}
			else z=0;
			ListInsert(head3,0,e);
			p1=p1->prior;p2=p2->prior;
	 }

   if(p1==head1&&p2!=head2)
   {
	   while(p2!=head2)
	   {
			e=p2->data+z;
			if(e>=10000)
			{
				z=1;
				e=e%10000;
			}
			else z=0;
			ListInsert(head3,0,e);
			p2=p2->prior;
	   }
	   if(z==1) ListInsert(head3,0,z);
   }
   else if(p1!=head1&&p2==head2){
	   while(p1!=head1)
	   {
	    e=p1->data+z;
		if(e>=10000)
		{
			z=1;
			e=e%10000;
		}
	    else z=0;
         ListInsert(head3,0,e);
		 p1=p1->prior;
	   }
	   if(z==1)  ListInsert(head3,0,z);
   }
   else{
	   if(z==1)  ListInsert(head3,0,z);
   }
	

}

int change(DLNode *head1,DLNode *head2)
{
	int length1,length2,r=2;
	length1=ListLength(head1);
    length2=ListLength(head2);
	DLNode *p1,*p2;
	p1=head1->next;
	p2=head2->next;
	if(length1>length2)
	{
		r=0;
		return r;
	}
	else if(length1<length2)
	{
		r=1;
		return r;
	}
	else
	{
		int i=0;
		for(i=0;i<length1;i++)
		{
			if(p1->data>p2->data)
			{
				r=0;
				return r;
				break;
			}
			else if(p2->data>p1->data)
			{
				r=1;
				return r;
				break;
			}
			else
			{
				p1=p1->next;
				p2=p2->next;
				r=2;
			}
		}
	}
	return r;
}

void minus(DLNode *head1,DLNode *head2,DLNode *head3)
{
	int z=0,x=-1;
	int e;
	DLNode *p1,*p2;
	p1=head1->prior;
	p2=head2->prior;
	x=change(head1,head2);
	if(x==0)
	{
		while(p1!=head1&&p2!=head2) 
		{
			 p1->data=p1->data+z;
			 if(p1->data>=p2->data)
			 {
				 e=p1->data-p2->data;
				ListInsert(head3,0,e);
				p1=p1->prior;p2=p2->prior;
				z=0;
			 }
			 else
			 {
				 e=10000+p1->data-p2->data;
				 ListInsert(head3,0,e);
			     p1=p1->prior;p2=p2->prior;
				 z=-1;
			}
		}
		p1->data=p1->data+z;
	   while(p1!=head1)
	   {
	    e=p1->data;
         ListInsert(head3,0,e);
		 p1=p1->prior;
	   }
   }
	else if(x==1)
	{
		p2=head1->prior;
	    p1=head2->prior;
		while(p1!=head2&&p2!=head1) 
		{
			 p1->data=p1->data+z;
			 if(p1->data>=p2->data)
			 {
				 e=p1->data-p2->data;
				ListInsert(head3,0,e);
				p1=p1->prior;p2=p2->prior;
				z=0;
			 }
			 else
			 {
				 e=10000+p1->data-p2->data;
				 ListInsert(head3,0,e);
			     p1=p1->prior;p2=p2->prior;
				 z=-1;
			}
		}
		p1->data=p1->data+z;
	   while(p1!=head2)
	   {
	    e=p1->data;
         ListInsert(head3,0,e);
		 p1=p1->prior;
	   }
	   head3->next->data=-1*head3->next->data;
	}
	else
	{
		head3->next->data=0;
	}

}

void yunsuan(DLNode *head1,DLNode *head2,DLNode *head3,char ch)
{   
	DLNode *p1,*p2;
	p1=head1->next;
	p2=head2->next;
	if(head1->data==1&&head2->data==1)  
	{   
		if(ch=='+')  add(head1,head2,head3);
		else   minus(head1,head2,head3);
	}
	else if(head1->data==1&&head2->data==0)
	{
		if(ch=='+')  
		{
			head2->next->data*=-1;
		    minus(head1,head2,head3);
		}
		else 
		{
			head2->next->data*=-1;
			add(head1,head2,head3);
		}
	}
	else if(head1->data==0&&head2->data==1)
	{
		if(ch=='+')
		{
			head1->next->data*=-1;
			minus(head2,head1,head3);
		}
		else 
		{
			head1->next->data*=-1;
			head2->next->data*=-1;
			add(head1,head2,head3);
			head3->next->data*=-1;
		}
	}
	else
	{
		if(ch=='+') 
		{
			head1->next->data*=-1;
			head2->next->data*=-1;
			add(head1,head2,head3);
			head3->next->data*=-1;
		}
	     else
		 {
			 head1->next->data*=-1;
			 head2->next->data*=-1;
			 minus(head2,head1,head3);
		}
	}
}

int main()
{
	char ch,ch1;
	while(1)
	{
		//int w=-1;
		DLNode *a,*b,*c;
		ListInitiate(&a);
		ListInitiate(&b);
		ListInitiate(&c);
		printf("��������A(�ԷֺŽ���):");
		InputNumber(a);
		//printf("\n");
		printf("��������B(�ԷֺŽ���):");
		InputNumber(b);
		//w=change(a,b);
		printf("��ѡ���������<+,->:\n");
		scanf("%s",&ch1);
		if(ch1=='+'||ch1=='-')
		{
			yunsuan(a,b,c,ch1);
			OutputNumber(c,1);
		}
		else printf("�˰汾��֧��%c����",ch1);
		printf("Ҫ������(y/n) :");
		scanf("%s",&ch);
		if(ch=='Y'||ch=='y') 
		{
			printf("\n");
			continue;	
		}
		else exit(0); 
	}
}
