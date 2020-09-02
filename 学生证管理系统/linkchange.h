#ifndef LINKCHANGE_H_INCLUDED
#define LINKCHANGE_H_INCLUDED
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
if((p1->idnum-1825010000-classnum*100)<40&&(p1->idnum-1825010000-classnum*100)>0){
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













#endif // FOUNCTION_H_INCLUDED
