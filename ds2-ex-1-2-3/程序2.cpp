#include <iostream>
using namespace std;
#include <stdio.h>
#include <malloc.h>
#define MAX 25
typedef struct
{
	char data;
	int weight;
	int parent;
	int lchild;
	int rchild;
} HTNode;
typedef struct
{   
	char cd[MAX];
	int start;
} HuffmanCode;
int main()
{
	HTNode ht[2*MAX];
	HuffmanCode hcd[MAX], d;
	int i, k, f, l, r, n, c, s1, s2;
    cout<<"* * * * * * * * * * * * * * * * * * * * * \n"
	    <<"\t����������������ϵͳ\n"
		<<"* * * * * * * * * * * * * * * * * * * * * \n";
	cout<<"\n�������������Ԫ�ظ�����";
	cin>>n;
	cout<<"���������Ԫ�صĽ��ֵ��Ȩֵ:\n";
	for(i=1;i<=n;i++)
	{
		cout<<"  ��"<<i<<"��Ԫ��-->\n\t���ֵ��";
		cin>>&ht[i].data;
		cout<<"\tȨ  ֵ��";
		cin>>ht[i].weight;
	}
	for(i=1;i<=2*n-1;i++)
		ht[i].parent=ht[i].lchild=ht[i].rchild=0;

	for(i=n+1;i<=2*n-1;i++)
	{
		s1=s2=32767;
		l=r=0;
		for(k=1;k<=i-1;k++)
			if(ht[k].parent==0)
			{
				if(ht[k].weight<s1)
				{
					s2=s1;
					r=l;
					s1=ht[k].weight;
					l=k;
				}
				else if(ht[k].weight<s2)
				{
					s2=ht[k].weight;
					r=k;
				}
			}
			ht[l].parent=i;
			ht[r].parent=i;
			ht[i].weight=ht[l].weight+ht[r].weight;
			ht[i].lchild=l;
			ht[i].rchild=r;
	}
	for(i=1;i<=n;i++)
	{
		d.start=n+1;
		c=i;
		f=ht[i].parent;
		while(f!=0)
		{
			if(ht[f].lchild==c)
				d.cd[--d.start]='0';
			else 
				d.cd[--d.start]='1';
			c=f;
			f=ht[f].parent;
		}
		hcd[i]=d;
	}
	cout<<"������������룺\n";
	for(i=1;i<=n;i++)
	{
		cout<<ht[i].data<<": ";
		for(k=hcd[i].start;k<=n;k++)
			cout<<hcd[i].cd[k];
		cout<<"\n";
	}
	return 0;
}  //Huffman
