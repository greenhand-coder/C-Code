#include<stdio.h>
#include<malloc.h>
#define OK 1
#define ERROR 0
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define ElemType int

typedef struct
{
	int *elem;
	int length;
	int listsize;
}SqList;

int InitList_Sq(SqList &L)
{
// 算法2.3，构造一个空的线性表L，该线性表预定义大小为LIST_INIT_SIZE
// 请补全代码
    L.elem=new ElemType[LIST_INIT_SIZE];
    L.length=0;
    return 1;

}

int Load_Sq(SqList &L)
{
// 输出顺序表中的所有元素
	int i;
	if(L.length==0) printf("The List is empty!");  // 请填空
	else
	{
		printf("The List is: ");
		for(i=0;i<=L.length-1;i++) printf("%d ",L.elem[i]);  // 请填空
	}

	printf("\n");
	return OK;
}

int ListInsert_Sq(SqList &L,int i,int e)
{
// 算法2.4，在顺序线性表L中第i个位置 之前 插入新的元素e  下标i-1  i-1->L.length-1全部后拉
// i的合法值为1≤i≤L.length +1
// 请补全代码
    if(i<1||i>L.length+1) return 0;
    for(int j=L.length-1;j>=i-1;j--) L.elem[j+1]=L.elem[j];
    L.elem[i-1]=e;
    L.length++;

    return 1;
}

int ListDelete_Sq(SqList &L,int i, int &e)
{
// 算法2.5,在顺序线性表L中删除第i个位置的元素，并用e返回其值
// i的合法值为1≤i≤L.length
// 请补全代码
    if(L.length==0||i<0||i>L.length) return 0;
    e=L.elem[i-1];
    for(int j=i-1;j<=L.length-2;j++) L.elem[j]=L.elem[j+1];
    L.length--;
    return 1;
}

int main()
{
	SqList T;
	int a, i;
	ElemType e, x;
	if(InitList_Sq(T))    // 判断顺序表是否创建成功
	{
		printf("A Sequence List Has Created.\n");
	}
	while(1)
	{
		printf("1:Insert element\n2:Delete element\n3:Load all elements\n0:Exit\nPlease choose:\n");
		scanf("%d",&a);
		switch(a)
		{
			case 1: scanf("%d%d",&i,&x);
					if(!(ListInsert_Sq(T,i,x))) printf("Insert Error!\n"); // 判断i值是否合法，请填空
					else printf("The Element %d is Successfully Inserted!\n", x);
					break;
			case 2: scanf("%d",&i);
					if(!(ListDelete_Sq(T,i,e))) printf("Delete Error!\n"); // 判断i值是否合法，请填空
					else printf("The Element %d is Successfully Deleted!\n", e);
					break;
			case 3: Load_Sq(T);
					break;
			case 0: return 1;
		}
	}
}

