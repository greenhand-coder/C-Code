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
// �㷨2.3������һ���յ����Ա�L�������Ա�Ԥ�����СΪLIST_INIT_SIZE
// �벹ȫ����
    L.elem=new ElemType[LIST_INIT_SIZE];
    L.length=0;
    return 1;

}

int Load_Sq(SqList &L)
{
// ���˳����е�����Ԫ��
	int i;
	if(L.length==0) printf("The List is empty!");  // �����
	else
	{
		printf("The List is: ");
		for(i=0;i<=L.length-1;i++) printf("%d ",L.elem[i]);  // �����
	}

	printf("\n");
	return OK;
}

int ListInsert_Sq(SqList &L,int i,int e)
{
// �㷨2.4����˳�����Ա�L�е�i��λ�� ֮ǰ �����µ�Ԫ��e  �±�i-1  i-1->L.length-1ȫ������
// i�ĺϷ�ֵΪ1��i��L.length +1
// �벹ȫ����
    if(i<1||i>L.length+1) return 0;
    for(int j=L.length-1;j>=i-1;j--) L.elem[j+1]=L.elem[j];
    L.elem[i-1]=e;
    L.length++;

    return 1;
}

int ListDelete_Sq(SqList &L,int i, int &e)
{
// �㷨2.5,��˳�����Ա�L��ɾ����i��λ�õ�Ԫ�أ�����e������ֵ
// i�ĺϷ�ֵΪ1��i��L.length
// �벹ȫ����

    if(L.length==0||i<1||i>L.length) return 0;

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
	if(InitList_Sq(T))    // �ж�˳����Ƿ񴴽��ɹ�
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
					if(!(ListInsert_Sq(T,i,x))) printf("Insert Error!\n"); // �ж�iֵ�Ƿ�Ϸ��������
					else printf("The Element %d is Successfully Inserted!\n", x);
					break;
			case 2: scanf("%d",&i);
					if(!(ListDelete_Sq(T,i,e))) printf("Delete Error!\n"); // �ж�iֵ�Ƿ�Ϸ��������
					else printf("The Element %d is Successfully Deleted!\n", e);
					break;
			case 3: Load_Sq(T);
					break;
			case 0: return 1;
		}
	}
}
