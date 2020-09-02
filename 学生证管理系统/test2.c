#include "stdio.h"
#include "math.h"
#include "string.h"
#include "stdlib.h"
#define LEN sizeof(struct student)
struct student{
    int idnum;
    char school[50];
    char sex[50];
    char major[50];
    char iden[50];
    int cardnum;
    int date;
    char name[50];
    struct student *next;
    };
struct student *create(int n,struct student *file)
{
     struct student *head=NULL,*p1=NULL,*p2=NULL,*p3=NULL;
     int i;
     if(file==NULL){
     for(i=1;i<=n;i++)
     {  p1=(struct student *)malloc(LEN);
        printf("请输入你的学号：(去掉前面的20)"); scanf("%d",&p1->idnum);
        printf("请输入你的卡号："); scanf("%d",&p1->cardnum);
        printf("请输入你的学生证有效期：(形如20220620)"); scanf("%d",&p1->date);
        printf("请输入你的学院：(请输入全称，如：数学与信息学院)"); scanf("%s",&p1->school);
        printf("请输入你的性别：(男或女)"); scanf("%s",&p1->sex);
        printf("请输入你的专业：(请输入全称,如：计算机科学与技术)"); scanf("%s",&p1->major);
        printf("请输入你的身份：(本科生或研究生)"); scanf("%s",&p1->iden);
        printf("请输入你的名字："); scanf("%s",&p1->name);
        printf("\n");
        p1->next=NULL;
        if(i==1) head=p1;
        else p2->next=p1;
        p2=p1;
      }
        return(head);}//file==null 无误
      else{
      for(i=1;i<=n;i++){
      p1=(struct student *)malloc(LEN);
      printf("请输入你的学号：(去掉前面的20)"); scanf("%d",&p1->idnum);
      printf("请输入你的卡号："); scanf("%d",&p1->cardnum);
      printf("请输入你的学生证有效期：(形如20220620)"); scanf("%d",&p1->date);
      printf("请输入你的学院：(请输入全称，如：数学与信息学院)"); scanf("%s",&p1->school);
      printf("请输入你的性别：(男或女)"); scanf("%s",&p1->sex);
      printf("请输入你的专业：(请输入全称,如：计算机科学与技术)"); scanf("%s",&p1->major);
      printf("请输入你的身份：(本科生或研究生)"); scanf("%s",&p1->iden);
      printf("请输入你的名字："); scanf("%s",&p1->name);
      printf("\n");
      p1->next==NULL;

      if(i==1){
      p3=file;
      while(p3->next!=NULL) p3=p3->next;//p3是最后一个有数据节点
      p3->next=p1;}
      else p2->next=p1;
      p2=p1;

      }
       return (file);
      }


}//已测试

struct student *read_file(){
int i=0;
struct student *p1=NULL,*head=NULL,*p2=NULL;
FILE *pfile;
pfile = fopen("student.txt","r");

if(pfile == NULL){
printf("+                     未发现存档                    +\n");
return 0;}

while(!feof(pfile)){
p1 = (struct student*)malloc(LEN);
if(fscanf(pfile,"%d%d%d%s%s%s%s%s",&p1->idnum,&p1->cardnum,&p1->date,p1->school,p1->sex,&p1->major,&p1->iden,p1->name)>0)
{

p1->next=NULL;
if(i==0) head=p1;
else p2->next=p1;
p2=p1;
i++;

}
}
fclose(pfile);
printf("+                     读档成功                     +\n");

return head;
}

struct student *delet(struct student *head,int idnum){
struct student *p1=head;
for(;p1!=NULL;p1=p1->next){
if(p1->next->idnum==idnum) p1->next=p1->next->next;}
return head;}
//已测试
struct student *update(struct student *head,int idnum){
struct student *p1=head;
for(;p1!=NULL;p1=p1->next){
if(p1->idnum==idnum){
printf("请重新输入你的信息\n");
printf("请重新输入你的卡号："); scanf("%d",&p1->cardnum);
printf("请重新输入你的学生证有效期：(形如20220620)"); scanf("%d",&p1->date);
printf("请重新输入你的学院：(请输入全称，如：数学与信息学院)"); scanf("%s",&p1->school);
printf("请重新输入你的性别：(男或女)"); scanf("%s",&p1->sex);
printf("请重新输入你的专业：(请输入全称,如：计算机科学与技术)"); scanf("%s",&p1->major);
printf("请重新输入你的身份：(本科生或研究生)"); scanf("%s",&p1->iden);
printf("请重新输入你的名字："); scanf("%s",&p1->name);
printf("\n");}}
return head;}
//已测试
void check(int idnum,struct student *head){
struct student *p1=head;
for(;p1!=NULL;p1=p1->next){
if(p1->idnum==idnum){
printf("你的信息:");
printf("卡号：%d\n",p1->cardnum);
printf("学生证有效期：%d\n",p1->date);
printf("学院：%s\n",p1->school);
printf("性别：%s\n",p1->sex);
printf("专业：%s\n",p1->major);
printf("身份：%s\n",p1->iden);
printf("名字：%s\n",p1->name);
printf("\n");
break;}
if(p1->next==NULL) printf("输入的学生学号不存在\n");
printf("\n");}}
//已验证
void classroom(int classnum,struct student *head){
struct student *p1=head;
for(;p1!=NULL;p1=p1->next){
if(p1->idnum-1825010000-classnum*100<40){
printf("学号：%d\n",p1->idnum);
printf("卡号：%d\n",p1->cardnum);
printf("学生证有效期：%d\n",p1->date);
printf("学院：%s\n",p1->school);
printf("性别：%s\n",p1->sex);
printf("专业：%s\n",p1->major);
printf("身份：%s\n",p1->iden);
printf("名字：%s\n",p1->name);
printf("\n"); }}}
//已验证
void count(int classnum,struct student *head){
int man=0,woman=0;
struct student *p1=head;
for(;p1!=NULL;p1=p1->next){
if(p1->idnum-1825010000-classnum*100<40){
    if(strcmp(p1->sex,"男")==0) man++;
    else woman++;}}
printf("你们班的女生数为%d\n",woman);
printf("你们班的男生数为%d\n",man);
printf("你们班的人数为%d\n",man+woman);}
//已验证
void write_file(struct student*head){
struct student *p=head;
FILE *fp;
if((fp=fopen("student.txt","w"))==NULL) return 0;
while(p!=NULL){
fprintf(fp,"%d\n%d\n%d\n%s\n%s\n%s\n%s\n%s\n",p->idnum,p->cardnum,p->date,p->school,p->sex,&p->major,&p->iden,p->name);
p=p->next;}
fclose(fp);
}

main(){
int choice=0,n,idnum,classnum;
struct student *head;
printf("+                     读档中.........             +\n");
head=read_file();
if(head==NULL)
printf("                文档中没有学生信息！！             \n");
while(1){
printf("+=================================================+\n");
printf("+                  学生证管理系统                 +\n");
printf("+=================================================+\n");
printf("+1.录入学生信息            + 2.修改学生信息       +\n");
printf ("+------------------------------------------------+\n");
printf("+3.删除学生信息            + 4.查看个人学生信息   +\n");
printf ("+------------------------------------------------+\n");
printf("+5.查看全班学生信息        + 6.统计各班男女数量   +\n");
printf("+=================================================+\n");
printf("+                +0.保存操作并退出                +\n");
printf("+=================================================+\n");
printf("输入您的功能选项序号：\n");
scanf("%d",&choice);
if(choice==1){
printf("请选择要录入信息的学生人数:\n");
scanf("%d",&n);
head=create(n,head);}
if(choice==2){
printf("请输入要修改的学生的学号:");
scanf("%d",&idnum);
head=update(head,idnum);}
if(choice==3){
printf("请输入要删除的学生的学号:");
scanf("%d",&idnum);
head=delet(head,idnum);}
if(choice==4){
printf("请输入要查看信息的学生的学号:");
scanf("%d",&idnum);
check(idnum,head);    }
if(choice==5){
printf("请输入要查看信息的班别（1班表示为 1）:");
scanf("%d",&classnum);
classroom(classnum,head);}
if(choice==6){
printf("请输入要查看信息的班别（1班表示为 1）:");
scanf("%d",&classnum);
count(classnum,head);}
if(choice==0){
write_file(head);
break;}
}
}
