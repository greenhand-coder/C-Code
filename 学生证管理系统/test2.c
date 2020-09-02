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
        printf("���������ѧ�ţ�(ȥ��ǰ���20)"); scanf("%d",&p1->idnum);
        printf("��������Ŀ��ţ�"); scanf("%d",&p1->cardnum);
        printf("���������ѧ��֤��Ч�ڣ�(����20220620)"); scanf("%d",&p1->date);
        printf("���������ѧԺ��(������ȫ�ƣ��磺��ѧ����ϢѧԺ)"); scanf("%s",&p1->school);
        printf("����������Ա�(�л�Ů)"); scanf("%s",&p1->sex);
        printf("���������רҵ��(������ȫ��,�磺�������ѧ�뼼��)"); scanf("%s",&p1->major);
        printf("�����������ݣ�(���������о���)"); scanf("%s",&p1->iden);
        printf("������������֣�"); scanf("%s",&p1->name);
        printf("\n");
        p1->next=NULL;
        if(i==1) head=p1;
        else p2->next=p1;
        p2=p1;
      }
        return(head);}//file==null ����
      else{
      for(i=1;i<=n;i++){
      p1=(struct student *)malloc(LEN);
      printf("���������ѧ�ţ�(ȥ��ǰ���20)"); scanf("%d",&p1->idnum);
      printf("��������Ŀ��ţ�"); scanf("%d",&p1->cardnum);
      printf("���������ѧ��֤��Ч�ڣ�(����20220620)"); scanf("%d",&p1->date);
      printf("���������ѧԺ��(������ȫ�ƣ��磺��ѧ����ϢѧԺ)"); scanf("%s",&p1->school);
      printf("����������Ա�(�л�Ů)"); scanf("%s",&p1->sex);
      printf("���������רҵ��(������ȫ��,�磺�������ѧ�뼼��)"); scanf("%s",&p1->major);
      printf("�����������ݣ�(���������о���)"); scanf("%s",&p1->iden);
      printf("������������֣�"); scanf("%s",&p1->name);
      printf("\n");
      p1->next==NULL;

      if(i==1){
      p3=file;
      while(p3->next!=NULL) p3=p3->next;//p3�����һ�������ݽڵ�
      p3->next=p1;}
      else p2->next=p1;
      p2=p1;

      }
       return (file);
      }


}//�Ѳ���

struct student *read_file(){
int i=0;
struct student *p1=NULL,*head=NULL,*p2=NULL;
FILE *pfile;
pfile = fopen("student.txt","r");

if(pfile == NULL){
printf("+                     δ���ִ浵                    +\n");
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
printf("+                     �����ɹ�                     +\n");

return head;
}

struct student *delet(struct student *head,int idnum){
struct student *p1=head;
for(;p1!=NULL;p1=p1->next){
if(p1->next->idnum==idnum) p1->next=p1->next->next;}
return head;}
//�Ѳ���
struct student *update(struct student *head,int idnum){
struct student *p1=head;
for(;p1!=NULL;p1=p1->next){
if(p1->idnum==idnum){
printf("���������������Ϣ\n");
printf("������������Ŀ��ţ�"); scanf("%d",&p1->cardnum);
printf("�������������ѧ��֤��Ч�ڣ�(����20220620)"); scanf("%d",&p1->date);
printf("�������������ѧԺ��(������ȫ�ƣ��磺��ѧ����ϢѧԺ)"); scanf("%s",&p1->school);
printf("��������������Ա�(�л�Ů)"); scanf("%s",&p1->sex);
printf("�������������רҵ��(������ȫ��,�磺�������ѧ�뼼��)"); scanf("%s",&p1->major);
printf("���������������ݣ�(���������о���)"); scanf("%s",&p1->iden);
printf("����������������֣�"); scanf("%s",&p1->name);
printf("\n");}}
return head;}
//�Ѳ���
void check(int idnum,struct student *head){
struct student *p1=head;
for(;p1!=NULL;p1=p1->next){
if(p1->idnum==idnum){
printf("�����Ϣ:");
printf("���ţ�%d\n",p1->cardnum);
printf("ѧ��֤��Ч�ڣ�%d\n",p1->date);
printf("ѧԺ��%s\n",p1->school);
printf("�Ա�%s\n",p1->sex);
printf("רҵ��%s\n",p1->major);
printf("��ݣ�%s\n",p1->iden);
printf("���֣�%s\n",p1->name);
printf("\n");
break;}
if(p1->next==NULL) printf("�����ѧ��ѧ�Ų�����\n");
printf("\n");}}
//����֤
void classroom(int classnum,struct student *head){
struct student *p1=head;
for(;p1!=NULL;p1=p1->next){
if(p1->idnum-1825010000-classnum*100<40){
printf("ѧ�ţ�%d\n",p1->idnum);
printf("���ţ�%d\n",p1->cardnum);
printf("ѧ��֤��Ч�ڣ�%d\n",p1->date);
printf("ѧԺ��%s\n",p1->school);
printf("�Ա�%s\n",p1->sex);
printf("רҵ��%s\n",p1->major);
printf("��ݣ�%s\n",p1->iden);
printf("���֣�%s\n",p1->name);
printf("\n"); }}}
//����֤
void count(int classnum,struct student *head){
int man=0,woman=0;
struct student *p1=head;
for(;p1!=NULL;p1=p1->next){
if(p1->idnum-1825010000-classnum*100<40){
    if(strcmp(p1->sex,"��")==0) man++;
    else woman++;}}
printf("���ǰ��Ů����Ϊ%d\n",woman);
printf("���ǰ��������Ϊ%d\n",man);
printf("���ǰ������Ϊ%d\n",man+woman);}
//����֤
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
