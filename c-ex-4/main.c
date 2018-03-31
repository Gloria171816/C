#include <stdio.h>
#include <string.h>

struct chengji {        //����һ���ṹ�����������ѧ��������5����Ŀ�ĳɼ�
    char xingming[20];
    float yuwen;
    float shuxue;
    float wuli;
    float huaxue;
    float shengwu;
};

int main(int argc, const char * argv[])
{
    float xspj(struct chengji cj);  //����ÿѧ����ȫ��ƽ���ɼ���������ʽ��ѧ������
    float kmpj(float a[], int n);   //����ÿ��Ŀƽ���ɼ���������ʽ����Ŀ����ѧ���ɼ�����,ѧ����
    void xzd(struct chengji xuesheng[],int n,int *p,char *ke,float *max);    //ѡ����߷ֺ�������ʽΪ��ѧ����������,ѧ������,ѧ�����ָ��,ke��ͷָ��,��߷�ָ��
    struct chengji xuesheng[10];    //����ѧ��������
    int i,x;                        //i����ѭ����x���ڴ���ѧ�����
    float f,km[10];                 //f���ڴ�����߷֣�km���ڴ���ÿ����Ŀ������ѧ���ĳɼ�
    char ke[10];                    //���Ҫ����γ̵�����
    int *p = &x;                    //ָ��ѧ�����
    float *max = &f;                //ָ����߷�
    
    //����
    printf("������ѧ�����������Ƴɼ�����ʽΪ������ ���� ��ѧ ���� ��ѧ �����\n");
    for (i=0; i<10; i++) {
        scanf("%s %f %f %f %f %f",xuesheng[i].xingming,&xuesheng[i].yuwen,&xuesheng[i].shuxue,&xuesheng[i].wuli,&xuesheng[i].huaxue,&xuesheng[i].shengwu);
    }
    
    //����ÿ��ѧ����ƽ����
    for (i=0; i<10; i++) {
        printf("%s��5��ƽ����Ϊ%.1f\n",xuesheng[i].xingming,xspj(xuesheng[i]));
    }
    
    //����ÿ�ſγ̵�ƽ����
    for (i=0; i<10; i++) {          //�Ƚ�����ѧ����ͬһ��Ŀ�ɼ��ӽṹ���������ɼ����飬�ٽ��������뺯��
        km[i]=xuesheng[i].yuwen;
    }
    printf("���ĵ�ƽ����Ϊ%.1f\n",kmpj(km,10));
    for (i=0; i<10; i++) {
        km[i]=xuesheng[i].shuxue;
    }
    printf("��ѧ��ƽ����Ϊ%.1f\n",kmpj(km,10));
    for (i=0; i<10; i++) {
        km[i]=xuesheng[i].wuli;
    }
    printf("�����ƽ����Ϊ%.1f\n",kmpj(km,10));
    for (i=0; i<10; i++) {
        km[i]=xuesheng[i].huaxue;
    }
    printf("��ѧ��ƽ����Ϊ%.1f\n",kmpj(km,10));
    for (i=0; i<10; i++) {
        km[i]=xuesheng[i].shengwu;
    }
    printf("�����ƽ����Ϊ%.1f\n",kmpj(km,10));
    
    //ͳ�ƻ����߷ֵ�ѧ�����������Կ�Ŀ
    xzd(xuesheng,10,p,ke,max);
    printf("��߷�Ϊ%sͬѧ��%s��Ŀ�п�ȡ��%.1f�֡�\n",xuesheng[*p].xingming,ke,*max);
    return 0;
}

float xspj(struct chengji cj) {
    return (cj.yuwen+cj.shuxue+cj.wuli+cj.huaxue+cj.shengwu)/5;
}

float kmpj(float a[],int n) {
    int i;
    float sum=0;
    for (i=0; i<n; i++) {
        sum=sum+a[i];
    }
    return sum/n;
}

void xzd(struct chengji xuesheng[],int n,int *p,char *ke,float *max) {
    int i;
    *max=0;
    for (i=0; i<10; i++) {
        if (*max<=xuesheng[i].yuwen) {
            *max=xuesheng[i].yuwen;
            *p=i;
            strcpy(ke,"����");
        }
        if (*max<=xuesheng[i].shuxue) {
            *max=xuesheng[i].shuxue;
            *p=i;
            strcpy(ke,"��ѧ");
        }
        if (*max<=xuesheng[i].wuli) {
            *max=xuesheng[i].wuli;
            *p=i;
            strcpy(ke,"����");
        }
        if (*max<=xuesheng[i].huaxue) {
            *max=xuesheng[i].huaxue;
            *p=i;
            strcpy(ke,"��ѧ");
        }
        if (*max<=xuesheng[i].shengwu) {
            *max=xuesheng[i].shengwu;
            *p=i;
            strcpy(ke,"����");
        }
    }
}



