#include <stdio.h>
int main(){	
	float n,sum;
	struct Student{
		char name[20];
		int num;
		char root[20];
		float score;
	}student1,student2,student3,student4,student5;
	printf("������5��ѧ������Ϣ����ʽ�밴��������ѧ�š����ᡢC���Կ��Գɼ���˳�����룬�м��Կո����ӡ�\n");
	scanf("%s %d %s %f",&student1.name,&student1.num,&student1.root,&student1.score);
	scanf("%s %d %s %f",&student2.name,&student2.num,&student2.root,&student2.score);
	scanf("%s %d %s %f",&student3.name,&student3.num,&student3.root,&student3.score);
	scanf("%s %d %s %f",&student4.name,&student4.num,&student4.root,&student4.score);
	scanf("%s %d %s %f",&student5.name,&student5.num,&student5.root,&student5.score);
	printf("%s\t%d\t%s\t%f\n",student1.name,student1.num,student1.root,student1.score);
	printf("%s\t%d\t%s\t%f\n",student2.name,student2.num,student2.root,student2.score);
	printf("%s\t%d\t%s\t%f\n",student3.name,student3.num,student3.root,student3.score);
	printf("%s\t%d\t%s\t%f\n",student4.name,student4.num,student4.root,student4.score);
	printf("%s\t%d\t%s\t%f\n",student5.name,student5.num,student5.root,student5.score);	
	sum=student1.score+student2.score+student3.score+student4.score+student5.score;
	n=sum/5.00;
	printf("C���Կ��Գɼ�ƽ����:%f\n",n);
	return 0;
}
