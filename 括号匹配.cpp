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
#define STACK_INIT_SIZE 10 // �洢�ռ��ʼ������
#define STACKINCREMENT 2 // �洢�ռ��������
struct SqStack
{
 SElemType *base; // ��ջ����֮ǰ������֮��base��ֵΪNULL
 SElemType *top; // ջ��ָ��
 int stacksize; // ��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ
 }; // ˳��ջ
Status InitStack(SqStack &S)
{
    S.base=new SElemType[100];
    S.top=S.base;
    S.stacksize=STACK_INIT_SIZE;
    return 1;
}

Status StackEmpty(SqStack S)
{
    if(S.base==S.top) return 1;
    else return 0;
}
Status Push(SqStack &S,SElemType e)
{
    if(S.top-S.base==STACK_INIT_SIZE) return 0;
    *S.top++=e;
    return 1;
}
 Status Pop(SqStack &S,SElemType &e)
{
    if(S.top==S.base) return 0;
    e=*--S.top;
    return 1;
}
void check()
 { // �������������һ���ַ��������������Ƿ����
   SqStack s;
   SElemType ch[80],*p,e;
   if(InitStack(s)) // ��ʼ��ջ�ɹ�
   {
    //printf("��������ʽ\n");
     gets(ch);
     p=ch;
     while(*p) // û����β
       switch(*p)
       {
         case '(':
         case '[':Push(s,*p);p++;
                  break; // ��������ջ����p++
         case ')':
         case ']':if(!StackEmpty(s)) // ջ����
                  {
                   Pop(s,e);//p++; // ����ջ��Ԫ��???????
                    if(*p==')'&&e!='('||*p==']'&&e!='[')
                                                // ������ջ��Ԫ����*p�����
{
                      printf("isn't matched pairs\n");
                      exit(ERROR);
                    }
                    else
                    {
                     p++;
                      break; // ����switch���
                    }
                  }
                  else // ջ��
                  {
                    printf("lack of left parenthesis\n");
                    exit(ERROR);
                  }
         default: p++; // �����ַ�������ָ�������
       }
     if(StackEmpty(s)) // �ַ�������ʱջ��
       printf("matching\n");
     else
       printf("lack of right parenthesis\n");
   }
 }
int main()
{
    check();
}
