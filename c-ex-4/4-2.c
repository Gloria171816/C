#include<stdio.h>
#include<math.h>
int main(){
	void intoa(int value, char string[]);
	int atoint(char string[]);
	char figure[1000];
	int n,choose,design=0;
	printf("将整数转化为字符串请输入1，将字符串转化为整数请输入2.\n");
	scanf("%d",&choose);
	printf("请输入：\n");
	switch(choose){
	case 1:
		scanf("%d",&n);
		if(n<0){
			design=1;
		}
		intoa(n,figure);
		if(design==1){
		putchar('-');
		}
		puts(figure);break;
	case 2:
	fflush(stdin);
	gets(figure);
	n=atoint(figure);
	default:
		printf("输入不合法!(请输入1或2)\n");
	}
	return 0;
}

void intoa(int value, char string[]){
	int a,b,c,design=0;
	if(value<=0){
		value=-value;
	}
	for(a=1;value/(int)pow(10,a-1)!=0;a++){
	}
	a=a-1;
	for(b=1;b<=a;b++){
		c=value%10;
		string[a-b]=c+48;
		value=value/10;
	}
	string[a]='\0';
}

int atoint(char string[]){
	int d,e,f=0;
	if(string[0]!='-'){
		for(d=0;string[d]!='\0';d++){
		}
		d=d-1;
		for(e=0;e<=d;e++){
			f=(string[e]-48)*(int)pow(10,d-e)+f;
		}
	}else{
		for(d=1;string[d]!='\0';d++){
		}
		d=d-1;
		for(e=1;e<=d;e++){
			f=(string[e]-48)*(int)pow(10,d-e)+f;
		}
		f=-f;
	}
	return f;
}

