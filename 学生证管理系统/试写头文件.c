#include "stdio.h"
#include"linkchange.h"//链表操作
#include"filerw.h"//文档读写
#include"count.h"
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
