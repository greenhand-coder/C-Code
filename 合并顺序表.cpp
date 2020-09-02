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

Status InitList_Sq(SqList &L)
{  // �㷨2.3
  // ����һ���յ����Ա�L��
  L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
  if (!L.elem) return 0;        // �洢����ʧ��
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
} // ListInsert_Sq

int MergeList_Sq(SqList La,SqList Lb,SqList&Lc)
{
   ElemType *pa,*pb,*pc,*pa_last,*pb_last;
   pa=La.elem;pb=Lb.elem;
   Lc.listsize=Lc.length=La.length+Lb.length;
   pc=Lc.elem= (ElemType *)malloc(Lc.listsize*sizeof(ElemType));
   if(!Lc.elem)return 0;
   pa_last=La.elem+La.length-1;
   pb_last=Lb.elem+Lb.length-1;
   while(pa<=pa_last&&pb<=pb_last)
   {
       if(*pa<=*pb)*pc++=*pa++;
       else *pc++=*pb++;
   }
   while(pa<=pa_last)*pc++=*pa++;
   while(pb<=pb_last)*pc++=*pb++;
}

main(){
SqList L1,L2,L3;
int a,b,e,x;
InitList_Sq(L1);InitList_Sq(L2);InitList_Sq(L3);
scanf("%d",&a);
for(int i=1;i<=a;i++){
scanf("%d",&x);
ListInsert_Sq(L1,i,x);
}//����L1
scanf("%d",&b);
for(int j=1;j<=b;j++){
scanf("%d",&e);
ListInsert_Sq(L2,j,e);
}//����L2����֤
MergeList_Sq(L1,L2,L3);
printf("List A:"); Load_Sq(L1);
printf("List B:");Load_Sq(L2);
printf("List C:");Load_Sq(L3);
}
