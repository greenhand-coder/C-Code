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


Status ListInsert_L(LinkList &L, int i, ElemType e) {  // 算法2.9
  // 在带头结点的单链线性表L的第i个元素之前插入元素e
  LinkList p,s;
  p = L;
  int j = 0;
  while (p && j < i-1) {  // 寻找第i-1个结点
    p = p->next;
    ++j;
  }
  if (!p || j > i-1) return ERROR;      // i小于1或者大于表长
  s = (LinkList)malloc(sizeof(LNode));  // 生成新结点
  s->data = e;  s->next = p->next;      // 插入L中
  p->next = s;
  return OK;
} // LinstInsert_L

Status ListDelete_L(LinkList &L, int i, ElemType &e) {  // 算法2.10
  // 在带头结点的单链线性表L中，删除第i个元素，并由e返回其值
  LinkList p,q;
  p = L;
  int j = 0;
  while (p->next && j < i-1) {  // 寻找第i个结点，并令p指向其前趋
    p = p->next;
    ++j;
  }
  if (!(p->next) || j > i-1) return ERROR;  // 删除位置不合理
  q = p->next;
  p->next = q->next;           // 删除并释放结点
  e = q->data;
  free(q);
  return OK;
} // ListDelete_L

int CreateLink_L(LinkList &L,int n){
// 创建含有n个元素的单链表
  LinkList p,q;
  int i;
  ElemType e;
  L = (LinkList)malloc(sizeof(LNode));
  L->next = NULL;              // 先建立一个带头结点的单链表
  q = (LinkList)malloc(sizeof(LNode));
  q = L;
  for (i=0; i<n; i++) {
	 scanf("%d", &e);
    p = (LinkList)malloc(sizeof(LNode));  // 生成新结点
    p->next=NULL;
    p->data=e;
    q->next=p;
    q=p;

  }
  return OK;
}

int LoadLink_L(LinkList &L){//此函数已验证无误
// 单链表遍历
 LinkList p = L->next;//p从L.next 开始
 if(L->next==NULL)printf("The List is empty!"); // 请填空
 else
 {
	 while(p!=NULL)    // 请填空
	 {
		printf("%d ",p->data);
		p=p->next;    // 请填空
	 }
 }
 printf("\n");
 return OK;
}

int sortL(LinkList &LA,LinkList &LB,LinkList &LC){
LinkList p1=LA->next,p2=LB->next,q,p;//从第一个有数据的链表开始
LC=(LinkList)malloc(sizeof(LNode));
LC->next=NULL;
q=(LinkList)malloc(sizeof(LNode));
q=LC;
while(p1!=NULL&&p2!=NULL){
p = (LinkList)malloc(sizeof(LNode));  // 生成新结点
p->next=NULL;   q->next=p;      q=p;
    if(p1->data<=p2->data){
    p->data=p1->data;
    p1=p1->next;    }
    else{
    p->data=p2->data;
    p2=p2->next;}//取两个中小的放进新的p的data;
}
if(p2==NULL){//此时p1是还未放好的数据  p已经放好数据
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
printf("List B:");LoadLink_L(LB);//到此无误
sortL(LA,LB,LC);
printf("List C:");LoadLink_L(LC);

}
