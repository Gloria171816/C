#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define MAX 20   //ͼ���Դ洢�����ڵ���Ϊ20��

struct tnode
{
    struct tnode * next;//ָ����һ���ٽڵ�
    int data;//����ڽڵ��������е�λ��
};

struct node
{
    int valu;//��Žڵ��ֵ
    struct tnode * link;//ָ���ڽڵ�
};

struct picture
{
    struct node nd[MAX];    //����һ���ڵ�����
    int count;  //ͼ�еĽڵ���
    char a; //������ͼ������
};

struct picture * createpicture();
int search(struct picture *p,int value);//����value��nd�����е�λ��
void bfs(struct picture * q,int i,int visit[]); //������ȱ���
void dfs(struct picture * q,int i,int visit[]);//������ȱ���
void traversedfs(struct picture *p);
void traversebfs(struct picture *p);

int main()
{
    char a;
    struct picture *p;
    p=createpicture();
    while(1)
    {
        getchar();
        printf("���ڽ���ͼ���б�������ʹ�ù�����ȱ���������a,��ʹ��������ȱ���������b������������c,�˳�������d:\n");
        scanf("%c",&a);
        if(a=='a')
        {
        printf("������ȱ������£�\n");
        traversebfs(p);
        }
        if(a=='b')
        {
        printf("������ȱ������£�\n");
        traversedfs(p);
        }
        if(a=='c')
        system("cls");
        if(a=='d')
        exit(0);
    }
    return 0;
}

struct picture * createpicture()
{
    int i,j,k,l;//l�д�ŷ��صĽڵ��������е�λ��
    char a;
    struct picture *p;
    p=(struct picture *)malloc(sizeof(struct picture));
    struct tnode * t;
    printf("��������Ҫ������ͼ�еĽڵ����Լ�ͼ������(a��ʾ����ͼb��ʾ����ͼ):\n");
    scanf("%d %c",&i,&a);
    p->count=i;
    p->a=a;
    printf("������������ڵ��ֵ(ÿ����һ���ڵ��ֵ���س�����)��\n");
    for(i=0;i<p->count;i++)
    {
        scanf("%d",&j);
        p->nd[i].valu=j;
        p->nd[i].link=NULL;
    }
    for(i=0;i<p->count;i++)
    {
        printf("����������ֵΪ%d�Ľڵ����ڵĽڵ������ֵ(ÿ����һ���ڵ��ֵ���س�����),�����ٺ������ڵ�ֵ������-1\n",p->nd[i].valu);
        while(1)
        {
            scanf("%d",&k);
            if(k==-1)
                break;
            l=search(p,k);
            if(l!=-1)
            {
                t=(struct tnode *)malloc(sizeof(struct tnode));
                t->data=l;
                t->next=p->nd[i].link;
                p->nd[i].link=t;
            }
            else
                printf("�޴�����ֵ!\n");
            //getchar();
        }
    }
    return p;
}

int search(struct picture *p,int value)
{
    int i;
    for(i=0;i<p->count;i++)
    {
        if(value==p->nd[i].valu)
        {
            return i;
        }
    }
    return -1;
}

void traversedfs(struct picture *p)
{
    int i;
    int visit[MAX];//����һ����־����,�����ʼֵ��Ϊ0,0��ʾ�ýڵ�δ�����ʹ���1��ʾ�ýڵ㱻���ʹ�
    for(i=0;i<p->count;i++)
    {
        visit[i]=0;
    }
    for(i=0;i<p->count;i++)
    {
        if(visit[i]==0)
        {
            dfs(p,i,visit);
        }
    }
    //getchar();
}
void dfs(struct picture * q,int i,int visit[])//i��ʾ������±�ֵvisit���±���p�е��±���һһ��Ӧ�Ĺ�ϵ
{
    struct tnode * w;
    printf("%d\n",q->nd[i].valu);
    visit[i]=1;
    w=q->nd[i].link;
    while(w!=NULL)
    {
        if(visit[w->data]==0)
        {
            dfs(q,w->data,visit);
        }
        else
        {
            w=w->next;
        }
    }   
}

void traversebfs(struct picture *p)
{
    int i;
    int visit[MAX];//����һ����־����,�����ʼֵ��Ϊ0,0��ʾ�ýڵ�δ�����ʹ���1��ʾ�ýڵ㱻���ʹ�
    for(i=0;i<p->count;i++)
    {
        visit[i]=0;
    }
    for(i=0;i<p->count;i++)
    {
        if(visit[i]==0)
        {
            bfs(p,i,visit);
        }
    }
    //getchar();
}

void bfs(struct picture * q,int i,int visit[])
{
    struct tnode *w;
    int a[MAX];//����һ������
    int f,r;
    int v;
    f=r=0;
    visit[i]=1;
    printf("%d\n",q->nd[i].valu);
    a[r]=i;
    r++;//������Ӳ���
    while(f!=r)
    {
        v=a[f];
        f++;//��Ӳ���
        w=q->nd[v].link;
        while(w!=NULL)
        {
            if(visit[w->data]==0)
            {
            visit[w->data]=1;
            printf("%d\n",q->nd[w->data].valu);
            a[r]=w->data;
            r++;
            }
            w=w->next;
        }
    }
}
