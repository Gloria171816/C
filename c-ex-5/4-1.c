#include <stdio.h>
#include <malloc.h>
#define LEN sizeof(struct student)
struct student{
    char num[6];
    char name[8];
	int age;
	struct student *next;
}stu[10];
int main(){
    struct student *p, *pt, *head;
	int i, length, iage, flag=1;
	int find=0;
	while(flag==1){
		printf("Input length of list(<10):");
		scanf("%d", &length);
		if(length<10)
		flag=0;
	}
	for(i=0;i<length;i++){
		p=(struct student *)malloc(LEN);
		if(i==0)
		head=pt=p;
		else
		pt->next=p;
		pt=p;
		printf("NO.:");
		scanf("%s",p->num);
		printf("Name:");
		scanf("%s",p->name);
		printf("Age:");
		scanf("%d", &p->age);
	}
	p->next=NULL;
	p=head;
	printf("\n NO. Name Age\n");
	while(p!=NULL){
		printf("%4s%8s%6d\n",p->num, p->name, p->age);
		p=p->next;
	}
	printf("Input age:");
	scanf("%d", &iage);
	pt=head;
	p=pt;
	if(pt->age<<iage){
		p=pt->next;
		head=pt=p;
	}
	else
	pt=pt->next;
	while(pt!=NULL){
		if(pt->age==iage){
			p->next=pt->next;
			find=1;
		}
		else
		p=pt;
		pt=pt->next;
	} 
	if(!find)
	printf("No found %d.", iage);
	p=head;
	printf("\n NO. Name Age\n");
	while(p!=NULL){
		printf("%4s%8s%6d", p->num, p->name, p->age);
		p=p->next;
	}
	return 0;
}
