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
// 输出顺序表中的所有元素
	int i;
	if(L.length==0) printf("The List is empty!");  // 请填空

	else
	{

		for(i=1;i<=L.length;i++) printf("%d ",L.elem[i-1]);  // 请填空
	}
	printf("\n");
	return OK;
}

Status InitList_Sq(SqList &L)
{  // 算法2.3
  // 构造一个空的线性表L。
  L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
  if (!L.elem) return 0;        // 存储分配失败
  L.length = 0;                  // 空表长度为0
  L.listsize = LIST_INIT_SIZE;   // 初始存储容量
  return OK;
} // InitList_Sq

Status ListInsert_Sq(SqList &L, int i, ElemType e)
{  // 算法2.4
  // 在顺序线性表L的第i个元素之前插入新的元素e，
  // i的合法值为1≤i≤ListLength_Sq(L)+1
  ElemType *p;
  if (i < 1 || i > L.length+1) return ERROR;  // i值不合法
  if (L.length >= L.listsize) {   // 当前存储空间已满，增加容量
    ElemType *newbase = (ElemType *)realloc(L.elem,
                  (L.listsize+LISTINCREMENT)*sizeof (ElemType));
    if (!newbase) return ERROR;   // 存储分配失败
    L.elem = newbase;             // 新基址
    L.listsize += LISTINCREMENT;  // 增加存储容量
  }
  ElemType *q = &(L.elem[i-1]);   // q为插入位置
  for (p = &(L.elem[L.length-1]); p>=q; --p) *(p+1) = *p;
                                  // 插入位置及之后的元素右移
  *q = e;       // 插入e
  ++L.length;   // 表长增1
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
}//输入L1
scanf("%d",&b);
for(int j=1;j<=b;j++){
scanf("%d",&e);
ListInsert_Sq(L2,j,e);
}//输入L2已验证
MergeList_Sq(L1,L2,L3);
printf("List A:"); Load_Sq(L1);
printf("List B:");Load_Sq(L2);
printf("List C:");Load_Sq(L3);
}
