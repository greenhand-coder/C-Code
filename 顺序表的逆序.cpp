#include<stdio.h>
#include<malloc.h>
#define OK 1
#define ERROR 0
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define ElemType int

typedef int Status;
typedef struct
{
    int *elem;
    int length;
    int listsize;
}SqList;

Status InitList_Sq(SqList &L)
{  // �㷨2.3
  // ����һ���յ����Ա�L��
  L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
  if (!L.elem) return OK;        // �洢����ʧ��
  L.length = 0;                  // �ձ���Ϊ0
  L.listsize = LIST_INIT_SIZE;   // ��ʼ�洢����
  return OK;
} // InitList_Sq
Status ListInsert_Sq(SqList &L, int i, ElemType e)
{  // �㷨2.4
  // ��˳�����Ա�L�ĵ�i��Ԫ��֮ǰ�����µ�Ԫ��e��
  // i�ĺϷ�ֵΪ1��i��ListLength_Sq(L)+1
  ElemType *p;
  if (i < 1 || i > L.length+1) return ERROR;  // iֵ���Ϸ�
  if (L.length >= L.listsize) {   // ��ǰ�洢�ռ���������������
    ElemType *newbase = (ElemType *)realloc(L.elem,
                  (L.listsize+LISTINCREMENT)*sizeof (ElemType));
    if (!newbase) return ERROR;   // �洢����ʧ��
    L.elem = newbase;             // �»�ַ
    L.listsize += LISTINCREMENT;  // ���Ӵ洢����
  }
  ElemType *q = &(L.elem[i-1]);   // qΪ����λ��
  for (p = &(L.elem[L.length-1]); p>=q; --p) *(p+1) = *p;
                                  // ����λ�ü�֮���Ԫ������
  *q = e;       // ����e
  ++L.length;   // ����1
  return OK;
}
int Load_Sq(SqList &L)
{
// ���˳����е�����Ԫ��
	int i;
	if(L.length==0) printf("The List is empty!");  // �����

	else
	{

		for(i=1;i<=L.length;i++) printf("%d ",L.elem[i-1]);  // �����
	}
	printf("\n");
	return OK;
}

main(){
int n,x,t;
SqList L;
InitList_Sq(L);
scanf("%d",&n);
for(int i=1;i<=n;i++){
scanf("%d",&x);
ListInsert_Sq(L,i,x);}
printf("The List is:"); Load_Sq(L);
for(int i=1;i<L.length/2+1;i++){
t=L.elem[i-1];
L.elem[i-1]=L.elem[L.length-i];
L.elem[L.length-i]=t;}
printf("The turned List is:"); Load_Sq(L);
}
