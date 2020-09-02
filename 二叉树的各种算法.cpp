#include "cstdio"
#include "malloc.h"
#define TRUE 1
#include "iostream"
#define FALSE 0
#define OK  1
#define ERROR  0
#define INFEASIBLE -1
#define OVERFLOW -2
#define STACK_INIT_SIZE 100 // 存储空间初始分配量
#define STACKINCREMENT 10 // 存储空间分配增量
#define MAXQSIZE 100 // 最大队列长度(对于循环队列，最大队列长度要减1)

typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等
typedef int QElemType;
typedef int SElemType; // 定义栈元素类型
typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等
typedef int  Status;

using namespace std;

typedef int  ElemType;

typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild,*rchild;//左右孩子指针
} BiTNode,*BiTree;

struct SqStack
{
    BiTree *base; // 在栈构造之前和销毁之后，base的值为NULL
    BiTree *top; // 栈顶指针
    int stacksize; // 当前已分配的存储空间，以元素为单位
}; // 顺序栈

typedef struct queuenode
{
    BiTree ch;
    struct queuenode *next;
}queuenode,*queueptr;


typedef struct
{
    queueptr front;
    queueptr rear;
}linkqueue;

void initqueue(linkqueue &q)
{
    q.front = q.rear=(queuenode *)malloc(sizeof(queuenode));
    q.front->next = NULL;
}

void enqueue(linkqueue &q,BiTree p)
{
    queueptr s;
    s = (queueptr)malloc(sizeof(queuenode));
    s->ch = p;
    s->next = NULL;
    q.rear->next = s;
    q.rear = s;
}

void dequeue(linkqueue &q,BiTree &p)
{
    int data;
    queueptr s;
    s = q.front->next;
    p=s->ch;
    data = p->data;
    q.front->next = s->next;
    if(q.rear == s)
    q.rear = q.front;
    free(s);
    cout<<data<<" ";
}

int queueempty(linkqueue q)
{
    if(q.front->next == NULL)
        return 1;
    return 0;
}

void traverse(BiTree bt)
{
    linkqueue q;
    BiTree p;
    initqueue(q);
    p = bt;
    enqueue(q,p);
    while (queueempty(q)!= 1)
    {
        dequeue(q,p);
        if(p->lchild!=NULL)
            enqueue(q,p->lchild);
        if(p->rchild!= NULL)
            enqueue(q,p->rchild);
    }
    cout<<endl;
}

Status InitStack(SqStack &S)
{
// 构造一个空栈S，该栈预定义大小为STACK_INIT_SIZE
    S.base = (BiTree *)malloc(STACK_INIT_SIZE*sizeof(BiTree));
    if(!S.base)return(ERROR);
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}

Status Push(SqStack &S,BiTree T)
{
// 在栈S中插入元素e为新的栈顶元素
    if(S.top - S.base>=S.stacksize)
    {
        S.base = (BiTree *)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(BiTree));
        if(S.base) return 0;

        S.stacksize += STACKINCREMENT;
    }
    *S.top++=T;
    return OK;
}

Status Pop(SqStack &S,BiTree &e)
{
// 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
    if(S.top == S.base)return ERROR;
    e = *--S.top;
    return OK;
}

Status GetTop(SqStack S,BiTree &e)
{
// 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
    if(S.top == S.base)return ERROR;
    e = *(S.top-1);
    return OK;
}

int StackEmpty(SqStack S)
{
    if(S.top == S.base) return OK;
    else return ERROR;
}

int StackLength(SqStack S)
{
// 返回栈S的元素个数
    BiTree *p = (BiTree *)malloc(sizeof(BiTree));
    p = S.top;
    int n = 0;
    p--;
    while (p!= S.base-1)
    {
        p--;
        n++;
    }
    return n;
}

int Insert_Tree(BiTree *T,int e)
{
    BiTNode *q, *p = *T;
    while (p)
    {
        if(p->data == e)
        {
            return ERROR;
        }
        q = p;
        p = (e<p->data)?p->lchild:p->rchild;
    }
    p = (BiTNode *)malloc(sizeof(BiTNode));
    p->data = e;
    p->lchild = p->rchild = NULL;
    if(*T == NULL) *T = p;
    else
    {
        if(e < q->data) q->lchild = p;
        else q->rchild = p;
    }
    return OK;

}

BiTree CreateBiTree(int n)    // 算法6.4
{
    int k;
    BiTree T = NULL;
    while (n--)
    {
        cin>>k;
        Insert_Tree(&T,k);
    }
    return T;
} // CreateBiTree

int Search (BiTree *T,int V)
{
    BiTNode *q, *p = *T;
    while (p)
    {
        if(p->data == V)
        {
            cout<<1<<endl;
            return 0;
        }
        q = p;
        p = (V<p->data)?p->lchild:p->rchild;
    }
    cout<<0<<endl;
    return 0;
}

Status Visit(ElemType e)
{
    cout<<e<<" ";
    return OK;
}

Status PreOrderTraverse( BiTree T, Status(*Visit)(ElemType) )
{
   if(T){
      printf("%d ",T->data);
      PreOrderTraverse(T->lchild,Visit);
      PreOrderTraverse(T->rchild,Visit);
   }
    // 前序遍历二叉树T的递归算法，对每个数据元素调用函数Visit。
 }


Status InOrderTraverse( BiTree T, Status(*Visit)(ElemType) )
{
      if(T){
      InOrderTraverse(T->lchild,Visit);
      printf("%d ",T->data);
      InOrderTraverse(T->rchild,Visit);
   }// 中序遍历二叉树T的递归算法，对每个数据元素调用函数Visit。
 }
Status PostOrderTraverse( BiTree T, Status(*Visit)(ElemType) )
{
      if(T){
      PostOrderTraverse(T->lchild,Visit);
      PostOrderTraverse(T->rchild,Visit);
      printf("%d ",T->data);
   }// 后序遍历二叉树T的递归算法，对每个数据元素调用函数Visit。
}

int InOrderTraverse_NoRecursion(BiTree *T,Status(*Visit)(ElemType))
{
    SqStack S;
    BiTNode  *p = *T;
    InitStack(S);
    Push(S,*T);
    while(!StackEmpty(S))
    {
        while(GetTop(S,p)&&p) Push(S,p->lchild);
        Pop(S,p);
        if(!StackEmpty(S))
        {
            Pop(S,p);
            if(!Visit(p->data)) return ERROR;
            Push(S,p->rchild);
        }
    }
    return OK;
}

int main()

{
    BiTree T;
    int n,e,V,k;
    scanf("%d",&n);
    T = CreateBiTree(n);
    PreOrderTraverse(T,Visit);
    printf("\n");
    InOrderTraverse(T,Visit);
    printf("\n");
    PostOrderTraverse(T,Visit);
    printf("\n");
    scanf("%d",&e);
    Search(&T,e);
    scanf("%d",&V);
    Search(&T,V);
    scanf("%d",&k);
    Insert_Tree(&T,k);
    PreOrderTraverse(T,Visit);
    printf("\n");
    InOrderTraverse(T,Visit);
    printf("\n");
    PostOrderTraverse(T,Visit);
    printf("\n");
    InOrderTraverse_NoRecursion(&T,Visit);
    printf("\n");
    traverse(T);
    return 0;
}
