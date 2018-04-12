#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef char DataType;
#define MaxSize 100
typedef struct Node
{
	DataType data;
	struct Node *lchild;
	struct Node *rchild;
}
*BiTree,BitNode;

void InitBitTree(BiTree *T);        /*���ĳ�ʼ��*/
void CreateBitTree(BiTree *T);      /*�������������ַ����еݹ鴴��������*/
void PreOrderTraverse(BiTree T);	/*����������������ĵݹ麯������*/
void InOrderTraverse(BiTree T);		/*����������������ĵݹ麯������*/
void PostOrderTraverse(BiTree T);	/*�������ĺ�������ĵݹ麯������*/
void PreOrderTraverse2(BiTree T);	/*����������������ķǵݹ麯������*/
void InOrderTraverse2(BiTree T);	/*����������������ķǵݹ麯������*/
void PostOrderTraverse2(BiTree T);	/*�������ĺ�������ķǵݹ麯������*/

void main()
{
	BiTree T,root;
	InitBitTree(&T);
	printf("����������������������д���������('#'��ʾ����)��\n");
	CreateBitTree(&T);
	printf("���������������У�\n");
	printf("�ݹ飺\t");
	PreOrderTraverse(T);
	printf("\n");
	printf("�ǵݹ飺");
	PreOrderTraverse2(T);
	printf("\n");
	printf("���������������У�\n");
	printf("�ݹ飺\t");
	InOrderTraverse(T);
	printf("\n");
	printf("�ǵݹ飺");
	InOrderTraverse2(T);
	printf("\n");
	printf("�������ĺ������У�\n");
	printf("�ݹ飺\t");
	PostOrderTraverse(T);
	printf("\n");
	printf("�ǵݹ飺");
	PostOrderTraverse2(T);
	printf("\n");
}

void InitBitTree(BiTree *T)
{
	*T=NULL;
}

void CreateBitTree(BiTree *T)
/*�ݹ鴴��������*/
{ 
    DataType ch;
    scanf("%c",&ch);
    if(ch=='#') 
        *T=NULL;
    else
    {
        *T=(BiTree)malloc(sizeof(BitNode)); 		/*���ɸ����*/
        if(!(*T))
            exit(-1);
        (*T)->data=ch;
        CreateBitTree(&((*T)->lchild)); 			/*����������*/
        CreateBitTree(&((*T)->rchild)); 			/*����������*/
    }
}

void PreOrderTraverse(BiTree T)
/*��������������ĵݹ�ʵ��*/
{
    if(T)								/*�����������Ϊ��*/
    {
        printf("%2c",T->data); 				/*���ʸ����*/
        PreOrderTraverse(T->lchild);		/*�������������*/
        PreOrderTraverse(T->rchild); 		/*�������������*/
    }
}
void InOrderTraverse(BiTree T)
/*��������������ĵݹ�ʵ��*/
{
    if(T)								/*�����������Ϊ��*/
	{
		InOrderTraverse(T->lchild);			/*�������������*/
        printf("%2c",T->data); 				/*���ʸ����*/
        InOrderTraverse(T->rchild); 		/*�������������*/
    }
}
void PostOrderTraverse(BiTree T)
/*��������������ĵݹ�ʵ��*/
{
    if(T)								/*�����������Ϊ��*/
	{
		PostOrderTraverse(T->lchild);		/*�������������*/
        PostOrderTraverse(T->rchild); 		/*�������������*/
		printf("%2c",T->data); 				/*���ʸ����*/
    }
}

void PreOrderTraverse2(BiTree T)
/*��������������ķǵݹ�ʵ��*/
{
	BiTree stack[MaxSize]; 				/*����һ��ջ�����ڴ�Ž���ָ��*/
	int top; 							/*����ջ��ָ��*/
	BitNode *p; 						/*����һ������ָ��*/
	top=0;							/*��ʼ��ջ*/
	p=T;
	while(p!=NULL||top>0)
	{
		while(p!=NULL) 					/*���p���գ����ʸ���㣬����������*/
		{
			printf("%2c",p->data); 			/*���ʸ����*/
			stack[top++]=p; 				/*��p��ջ*/
			p=p->lchild; 				/*����������*/
		}
		if(top>0) 						/*���ջ����*/
		{
			p=stack[--top]; 				/*ջ��Ԫ�س�ջ*/
			p=p->rchild;					/*����������*/
		}
	}
}
void InOrderTraverse2(BiTree T)
/*��������������ķǵݹ�ʵ��*/
{
	BiTree stack[MaxSize]; 				/*����һ��ջ�����ڴ�Ž���ָ��*/
	int top; 							/*����ջ��ָ��*/
	BitNode *p; 						/*����һ������ָ��*/
	top=0;							/*��ʼ��ջ*/
	p=T;
	while(p!=NULL||top>0)
	{
		while(p!=NULL) 					/*���p���գ����ʸ���㣬����������*/
		{
			stack[top++]=p; 				/*��p��ջ*/
			p=p->lchild; 				/*����������*/
		}
		if(top>0) 						/*���ջ����*/
		{
			p=stack[--top]; 				/*ջ��Ԫ�س�ջ*/
			printf("%2c",p->data); 			/*���ʸ����*/
			p=p->rchild;					/*����������*/
		}
	}
}

void PostOrderTraverse2(BiTree T)
/*��������������ķǵݹ�ʵ��*/
{
	BiTree stack[MaxSize]; 				/*����һ��ջ�����ڴ�Ž���ָ��*/
	int top; 							/*����ջ��ָ��*/
	BitNode *p,*q; 						/*�������ָ��*/
	top=0;								/*��ʼ��ջ*/
	p=T,q=NULL; 						/*��ʼ������ָ��*/
	while(p!=NULL||top>0)
	{
		while(p!=NULL) 						/*���p���գ����ʸ���㣬����������*/
		{
			stack[top++]=p; 				/*��p��ջ*/
			p=p->lchild; 					/*����������*/
		}
		if(top>0) 							/*���ջ����*/
		{
			p=stack[top-1]; 					/*ȡջ��Ԫ��*/
			if(p->rchild==NULL||p->rchild==q) 	/*���pû���Һ��ӽ�㣬���Һ��ӽ���Ѿ����ʹ�*/
			{
				printf("%2c",p->data); 			/*���ʸ����*/
				q=p; 
				p=NULL;	
				top--;		
			}
			else
				p=p->rchild;
		}
	}
}
