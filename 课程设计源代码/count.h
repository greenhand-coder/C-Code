#ifndef COUNT_H_INCLUDED
#define COUNT_H_INCLUDED
#include "linkchange.h"
#include"filerw.h"

void count(int classnum,struct student *head){
int man=0,woman=0;
struct student *p1=head;
for(;p1!=NULL;p1=p1->next){
if((p1->idnum-1825010000-classnum*100)<40&&(p1->idnum-1825010000-classnum*100)>0){
    if(strcmp(p1->sex,"��")==0) man++;
    else woman++;}}
printf("���ǰ��Ů����Ϊ%d\n",woman);
printf("���ǰ��������Ϊ%d\n",man);
printf("���ǰ������Ϊ%d\n",man+woman);}
//����֤
#endif // COUNT_H_INCLUDED
