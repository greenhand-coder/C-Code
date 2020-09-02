#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define OK 1
#define ElemType int

typedef int Status;
typedef struct LNode
{
 int data;
 struct LNode *next;
}LNode,*LinkList;


Status ListInsert_L(LinkList &L, int i, ElemType e) {  // �㷨2.9
  // �ڴ�ͷ���ĵ������Ա�L�ĵ�i��Ԫ��֮ǰ����Ԫ��e
  LinkList p,s;
  p = L;
  int j = 0;
  while (p && j < i-1) {  // Ѱ�ҵ�i-1�����
    p = p->next;
    ++j;
  }
  if (!p || j > i-1) return ERROR;      // iС��1���ߴ��ڱ�
  s = (LinkList)malloc(sizeof(LNode));  // �����½��
  s->data = e;  s->next = p->next;      // ����L��
  p->next = s;
  return OK;
} // LinstInsert_L

Status ListDelete_L(LinkList &L, int i, ElemType &e) {  // �㷨2.10
  // �ڴ�ͷ���ĵ������Ա�L�У�ɾ����i��Ԫ�أ�����e������ֵ
  LinkList p,q;
  p = L;
  int j = 0;
  while (p->next && j < i-1) {  // Ѱ�ҵ�i����㣬����pָ����ǰ��
    p = p->next;
    ++j;
  }
  if (!(p->next) || j > i-1) return ERROR;  // ɾ��λ�ò�����
  q = p->next;
  p->next = q->next;           // ɾ�����ͷŽ��
  e = q->data;
  free(q);
  return OK;
} // ListDelete_L

int CreateLink_L(LinkList &L,int n){
// ��������n��Ԫ�صĵ�����
  LinkList p,q;
  int i;
  ElemType e;
  L = (LinkList)malloc(sizeof(LNode));
  L->next = NULL;              // �Ƚ���һ����ͷ���ĵ�����
  q = (LinkList)malloc(sizeof(LNode));
  q = L;
  for (i=0; i<n; i++) {
	 scanf("%d", &e);
    p = (LinkList)malloc(sizeof(LNode));  // �����½��
    p->next=NULL;
    p->data=e;
    q->next=p;
    q=p;

  }
  return OK;
}

int LoadLink_L(LinkList &L){//�˺�������֤����
// ���������
 LinkList p = L->next;//p��L.next ��ʼ
 if(L->next==NULL)printf("The List is empty!"); // �����
 else
 {
	 while(p!=NULL)    // �����
	 {
		printf("%d ",p->data);
		p=p->next;    // �����
	 }
 }
 printf("\n");
 return OK;
}

int sortL(LinkList &LA,LinkList &LB,LinkList &LC){
LinkList p1=LA->next,p2=LB->next,q,p;//�ӵ�һ�������ݵ�����ʼ
LC=(LinkList)malloc(sizeof(LNode));
LC->next=NULL;
q=(LinkList)malloc(sizeof(LNode));
q=LC;
while(p1!=NULL&&p2!=NULL){
p = (LinkList)malloc(sizeof(LNode));  // �����½��
p->next=NULL;   q->next=p;      q=p;
    if(p1->data<=p2->data){
    p->data=p1->data;
    p1=p1->next;    }
    else{
    p->data=p2->data;
    p2=p2->next;}//ȡ������С�ķŽ��µ�p��data;
}
if(p2==NULL){//��ʱp1�ǻ�δ�źõ�����  p�Ѿ��ź�����
while(p1!=NULL){
p = (LinkList)malloc(sizeof(LNode));
p->next=NULL;   q->next=p;      q=p;
p->data=p1->data;
p1=p1->next;    }}

if(p2!=NULL){
while(p2!=NULL){
p = (LinkList)malloc(sizeof(LNode));
p->next=NULL;   q->next=p;      q=p;
p->data=p2->data;
p2=p2->next;    }}
}


main(){
LinkList LA,LB,LC;
int a,b;
scanf("%d",&a);
CreateLink_L(LA,a);
printf("List A:");LoadLink_L(LA);
scanf("%d",&b);
CreateLink_L(LB,b);
printf("List B:");LoadLink_L(LB);//��������
sortL(LA,LB,LC);
printf("List C:");LoadLink_L(LC);

}
