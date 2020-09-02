typedef char SElemType;
#include"malloc.h"
#include"stdio.h"
#include"math.h"
#include"stdlib.h" // exit()
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status; // Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK��
#define STACK_INIT_SIZE 100 // �洢�ռ��ʼ������
 #define STACKINCREMENT 2 // �洢�ռ��������
struct SqStack
{
 SElemType *base; // ��ջ����֮ǰ������֮��base��ֵΪNULL
 SElemType *top; // ջ��ָ��
 int stacksize; // ��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ
}; // ˳��ջ

Status InitStack(SqStack &S)
{ // ����һ����ջS
    S.base=new SElemType[STACK_INIT_SIZE];
    S.top=S.base;
    S.stacksize=STACK_INIT_SIZE;
    return 1;
 }
Status StackEmpty(SqStack S)
 { // ��ջSΪ��ջ���򷵻�TRUE�����򷵻�FALSE
     if(S.top==S.base) return 1;
     else return 0;

 }
Status ClearStack(SqStack &S)
 { // ��S��Ϊ��ջ
   S.top=S.base;
   return OK;
 }
Status DestroyStack(SqStack &S)
 { // ����ջS��S���ٴ���
   free(S.base);
   S.base=NULL;
   S.top=NULL;
   S.stacksize=0;
   return OK;
 }
Status Push(SqStack &S,SElemType e)
 { // ����Ԫ��eΪ�µ�ջ��Ԫ��
    if(S.top-S.base==STACK_INIT_SIZE) return 0;
    *S.top++=e;
    return 1;
 }
 Status Pop(SqStack &S,SElemType &e)
 { // ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
    if(S.top==S.base) return 0;
    e=*--S.top;
    return 1;
 }
Status StackTraverse(SqStack S,Status(*visit)(SElemType))
 { // ��ջ�׵�ջ�����ζ�ջ��ÿ��Ԫ�ص��ú���visit()��
   // һ��visit()ʧ�ܣ������ʧ��
   while(S.top>S.base)
   visit(*S.base++);
   printf("\n");
   return OK;
 }
Status visit(SElemType c)
 {
   printf("%c",c);
   return OK;
 }
 void LineEdit()
 { // �����ַ�ջs�����ն˽���һ�в��������ù��̵����������㷨3.2
   SqStack s;
   char ch,c;
   int n,i;
   InitStack(s);
   scanf("%d",&n);
   ch=getchar();
   for(i=1;i<=n;i++)
   { ch=getchar();
     while(ch!='\n')
    {
       switch(ch)
       {
         case '#':Pop(s,c);
                  break; // ����ջ�ǿ�ʱ��ջ
         case '@':ClearStack(s);
                  break; // ����sΪ��ջ
         default :Push(s,ch); // ��Ч�ַ���ջ
       }
       ch=getchar(); // ���ն˽�����һ���ַ�
     }
     StackTraverse(s,visit); // ����ջ�׵�ջ����ջ���ַ����
    ClearStack(s); // ����sΪ��ջ
    }
   DestroyStack(s);
 }
int  main()
 {
     LineEdit();
 }
