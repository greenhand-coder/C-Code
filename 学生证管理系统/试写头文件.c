#include "stdio.h"
#include"linkchange.h"//�������
#include"filerw.h"//�ĵ���д
#include"count.h"
main(){
int choice=0,n,idnum,classnum;
struct student *head;
printf("+                     ������.........             +\n");
head=read_file();
if(head==NULL)
printf("                �ĵ���û��ѧ����Ϣ����             \n");
while(1){
printf("+=================================================+\n");
printf("+                  ѧ��֤����ϵͳ                 +\n");
printf("+=================================================+\n");
printf("+1.¼��ѧ����Ϣ            + 2.�޸�ѧ����Ϣ       +\n");
printf ("+------------------------------------------------+\n");
printf("+3.ɾ��ѧ����Ϣ            + 4.�鿴����ѧ����Ϣ   +\n");
printf ("+------------------------------------------------+\n");
printf("+5.�鿴ȫ��ѧ����Ϣ        + 6.ͳ�Ƹ�����Ů����   +\n");
printf("+=================================================+\n");
printf("+                +0.����������˳�                +\n");
printf("+=================================================+\n");
printf("�������Ĺ���ѡ����ţ�\n");
scanf("%d",&choice);
if(choice==1){
printf("��ѡ��Ҫ¼����Ϣ��ѧ������:\n");
scanf("%d",&n);
head=create(n,head);}
if(choice==2){
printf("������Ҫ�޸ĵ�ѧ����ѧ��:");
scanf("%d",&idnum);
head=update(head,idnum);}
if(choice==3){
printf("������Ҫɾ����ѧ����ѧ��:");
scanf("%d",&idnum);
head=delet(head,idnum);}
if(choice==4){
printf("������Ҫ�鿴��Ϣ��ѧ����ѧ��:");
scanf("%d",&idnum);
check(idnum,head);    }
if(choice==5){
printf("������Ҫ�鿴��Ϣ�İ��1���ʾΪ 1��:");
scanf("%d",&classnum);
classroom(classnum,head);}
if(choice==6){
printf("������Ҫ�鿴��Ϣ�İ��1���ʾΪ 1��:");
scanf("%d",&classnum);
count(classnum,head);}
if(choice==0){
write_file(head);
break;}
}
}
