#include<malloc.h>
#include<stdio.h>
#define OK 1
#define ERROR 0
typedef int Status; // Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK��
typedef int QElemType;
#define MAXQSIZE 100 // �����г���(����ѭ�����У������г���Ҫ��1)

typedef struct
{
   QElemType *base; // ��ʼ���Ķ�̬����洢�ռ�
   int front; // ͷָ��,�����в���,ָ�����ͷԪ��
   int rear; // βָ��,�����в���,ָ�����βԪ�ص���һ��λ��
 }SqQueue;

Status InitQueue(SqQueue &Q)
{
// ����һ���ն���Q���ö���Ԥ�����СΪMAXQSIZE
// �벹ȫ����
    Q.base=new QElemType[MAXQSIZE];
    Q.front=0;Q.rear=0;
    return 1;

}

Status EnQueue(SqQueue &Q,QElemType e)
{
// ����Ԫ��eΪQ���µĶ�βԪ��
// �벹ȫ����
    Q.base[Q.rear]=e;
    Q.rear++;
    return 1;

}

Status DeQueue(SqQueue &Q, QElemType &e)
{
// �����в���, ��ɾ��Q�Ķ�ͷԪ��, ��e������ֵ, ������OK; ���򷵻�ERROR
// �벹ȫ����
	if(Q.front==Q.rear) return 0;
	e=Q.base[Q.front];
	Q.front++;
	return 1;
}

Status GetHead(SqQueue Q, QElemType &e)
{
// �����в��գ�����e���ض�ͷԪ�أ�������OK�����򷵻�ERROR
// �벹ȫ����
	if(Q.front==Q.rear) return 0;
	e=Q.base[Q.front];
	return 1;
}

int QueueLength(SqQueue Q)
{
// ����Q��Ԫ�ظ���
// �벹ȫ����
	return (Q.rear-Q.front);
}

Status QueueTraverse(SqQueue Q)
{
// �����в��գ���Ӷ�ͷ����β���������������Ԫ�أ�������OK�����򷵻�ERROR.
	int i;
	i=Q.front;
	if(Q.front==Q.rear)printf("The Queue is Empty!");  //�����
	else{
		printf("The Queue is: ");
		while(Q.front!=Q.rear)     //�����
		{
			printf("%d ",Q.base[Q.front] );   //�����
			i = Q.front++;   //�����
		}
	}
	printf("\n");
	return OK;
}

int main()
{
	int a;
  SqQueue S;
	QElemType x, e;
  if(InitQueue(S))    // �ж�˳����Ƿ񴴽��ɹ��������
	{
		printf("A Queue Has Created.\n");
	}
	while(1)
	{
	printf("1:Enter \n2:Delete \n3:Get the Front \n4:Return the Length of the Queue\n5:Load the Queue\n0:Exit\nPlease choose:\n");
		scanf("%d",&a);
		switch(a)
		{
			case 1: scanf("%d", &x);
				  if(!(EnQueue(S,x))) printf("Enter Error!\n"); // �ж�����Ƿ�Ϸ��������
				  else printf("The Element %d is Successfully Entered!\n", x);
				  break;
			case 2: if(!(DeQueue(S,e) )) printf("Delete Error!\n"); // �жϳ����Ƿ�Ϸ��������
				  else printf("The Element %d is Successfully Deleted!\n", e);
				  break;
			case 3: if(!(GetHead(S,e)))printf("Get Head Error!\n"); // �ж�Get Head�Ƿ�Ϸ��������
				  else printf("The Head of the Queue is %d!\n", e);
				  break;
			case 4: printf("The Length of the Queue is %d!\n",QueueLength(S)  );  //�����
				  break;
			case 5:QueueTraverse(S);   //�����
				  break;
			case 0: return 1;
		}
	}
}
