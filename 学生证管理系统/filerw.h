#ifndef FILERW_H_INCLUDED
#define FILERW_H_INCLUDED
#include "stdio.h"
#include "math.h"
#include "string.h"
#include "stdlib.h"
#include "linkchange.h"

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

void write_file(struct student*head){
struct student *p=head;
FILE *fp;
if((fp=fopen("student.txt","w"))==NULL) return 0;
while(p!=NULL){
fprintf(fp,"%d\n%d\n%d\n%s\n%s\n%s\n%s\n%s\n",p->idnum,p->cardnum,p->date,p->school,p->sex,p->major,p->iden,p->name);
p=p->next;}
fclose(fp);
}
#endif // 文档的读写与写入_H_INCLUDED
