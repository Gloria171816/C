#include <stdio.h>
#include <string.h>

struct chengji {        //定义一个结构体变量，包含学生姓名，5个科目的成绩
    char xingming[20];
    float yuwen;
    float shuxue;
    float wuli;
    float huaxue;
    float shengwu;
};

int main(int argc, const char * argv[])
{
    float xspj(struct chengji cj);  //计算每学生的全科平均成绩函数，格式：学生数据
    float kmpj(float a[], int n);   //计算每科目平均成绩函数，格式：科目所有学生成绩数组,学生数
    void xzd(struct chengji xuesheng[],int n,int *p,char *ke,float *max);    //选择最高分函数，格式为：学生数据数组,学生个数,学生编号指针,ke的头指针,最高分指针
    struct chengji xuesheng[10];    //储存学生的数据
    int i,x;                        //i用于循环，x用于储存学生编号
    float f,km[10];                 //f用于储存最高分，km用于储存每个科目中所有学生的成绩
    char ke[10];                    //存放要输出课程的名字
    int *p = &x;                    //指向学生编号
    float *max = &f;                //指向最高分
    
    //输入
    printf("请输入学生姓名及各科成绩，格式为“姓名 语文 数学 物理 化学 生物”。\n");
    for (i=0; i<10; i++) {
        scanf("%s %f %f %f %f %f",xuesheng[i].xingming,&xuesheng[i].yuwen,&xuesheng[i].shuxue,&xuesheng[i].wuli,&xuesheng[i].huaxue,&xuesheng[i].shengwu);
    }
    
    //计算每个学生的平均分
    for (i=0; i<10; i++) {
        printf("%s的5科平均分为%.1f\n",xuesheng[i].xingming,xspj(xuesheng[i]));
    }
    
    //计算每门课程的平均分
    for (i=0; i<10; i++) {          //先将所有学生的同一科目成绩从结构体变量导入成绩数组，再将数组输入函数
        km[i]=xuesheng[i].yuwen;
    }
    printf("语文的平均分为%.1f\n",kmpj(km,10));
    for (i=0; i<10; i++) {
        km[i]=xuesheng[i].shuxue;
    }
    printf("数学的平均分为%.1f\n",kmpj(km,10));
    for (i=0; i<10; i++) {
        km[i]=xuesheng[i].wuli;
    }
    printf("物理的平均分为%.1f\n",kmpj(km,10));
    for (i=0; i<10; i++) {
        km[i]=xuesheng[i].huaxue;
    }
    printf("化学的平均分为%.1f\n",kmpj(km,10));
    for (i=0; i<10; i++) {
        km[i]=xuesheng[i].shengwu;
    }
    printf("生物的平均分为%.1f\n",kmpj(km,10));
    
    //统计获得最高分的学生姓名及考试科目
    xzd(xuesheng,10,p,ke,max);
    printf("最高分为%s同学在%s科目中考取了%.1f分。\n",xuesheng[*p].xingming,ke,*max);
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
            strcpy(ke,"语文");
        }
        if (*max<=xuesheng[i].shuxue) {
            *max=xuesheng[i].shuxue;
            *p=i;
            strcpy(ke,"数学");
        }
        if (*max<=xuesheng[i].wuli) {
            *max=xuesheng[i].wuli;
            *p=i;
            strcpy(ke,"物理");
        }
        if (*max<=xuesheng[i].huaxue) {
            *max=xuesheng[i].huaxue;
            *p=i;
            strcpy(ke,"化学");
        }
        if (*max<=xuesheng[i].shengwu) {
            *max=xuesheng[i].shengwu;
            *p=i;
            strcpy(ke,"生物");
        }
    }
}



