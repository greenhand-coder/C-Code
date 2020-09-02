#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define STACK_INIT_SIZE 100 // �洢�ռ��ʼ������
#define STACKINCREMENT 10 // �洢�ռ��������

typedef char SElemType; // ����ջԪ������
typedef int Status; // Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK��

struct SqStack
{
     SElemType *base; // ��ջ����֮ǰ������֮��base��ֵΪNULL
     SElemType *top; // ջ��ָ��
     int stacksize; // ��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ
}; // ˳��ջ

Status InitStack(SqStack &S)
{
// ����һ����ջS����ջԤ�����СΪSTACK_INIT_SIZE
	 S.base=(SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
     if(!S.base) return ERROR;
	 S.top=S.base;
	 S.stacksize=STACK_INIT_SIZE;
	 return OK;
}

Status Push(SqStack &S,SElemType e)
{
// ��ջS�в���Ԫ��eΪ�µ�ջ��Ԫ��
	if(S.top-S.base>=S.stacksize)
	{
		S.base=(SElemType*)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(SElemType));
		if(!S.base) return ERROR;
		S.top=S.base+S.stacksize;
		S.stacksize+=STACKINCREMENT;
	}
	*S.top++=e;
	return OK;
}

Status Pop(SqStack &S,SElemType &e)
{
// ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
	if(S.top==S.base) return ERROR;
     e=*--S.top;
	 return OK;
}

Status GetTop(SqStack S,SElemType &e)
{
// ��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR
	if(S.top==S.base) return ERROR;
    e=*(S.top-1);
	return OK;
}

SElemType precede(SElemType t1,SElemType t2)
{//�Ƚ�����������ȹ�ϵ
    SElemType f;
    switch(t2)
    {
        case'+':
        case'-':if(t1=='('||t1=='=')
                   f='<';
                else
                    f='>';
                break;
        case'*':
        case'/':if(t1=='*'||t1=='/'||t1==')')
                    f='>';
                else
                    f='<';
                break;
        case'(':if(t1==')'){printf("ERROR1");  exit(ERROR);}
                else f='<';
                break;
        case')':switch(t1)
                {
                    case'(':f='=';break;
                    case'=':printf("ERROR2"); exit(ERROR);break;
                    default:f='>';
                }
                break;
        case'=':switch(t1)
                {
                    case'(':printf("ERROR3"); exit(ERROR);break;
                    case'=':f='=';break;
                    default:f='>';
                }
                break;
    }
    return f;
}

Status In(SElemType c)
{
    switch(c)
    {
        case'+':
        case'-':
        case'*':
        case'/':
        case'(':
        case')':
        case'=':return TRUE;
        default:return FALSE;
    }
}

SElemType Operate(SElemType a,SElemType theta,SElemType b)
{
    SElemType c;
    switch(theta)
    {
        case'+':c=a+b; break;
        case'-':c=a-b; break;
        case'*':c=a*b; break;
        case'/':c=a/b; break;
    }
    return c;
}

void EvaluateExpression()
{
    int i,d;
    char z[6];
    SElemType a,b,c,x,theta;
    SqStack OPTR,OPND;
    InitStack(OPTR);
    Push(OPTR,'=');  //==cStack
    InitStack(OPND);
    c=getchar();
    GetTop(OPTR,x);
    while(c!='='||x!='=')
    {
        if(In(c))
        {
            switch(precede(x,c))
            {
                case'<':Push(OPTR,c);
                        c=getchar();
                        break;
                case'=':Pop(OPTR,x);
                        c=getchar();
                        break;
                case'>':Pop(OPTR,theta);
                        Pop(OPND,b);
                        Pop(OPND,a);
                        Push(OPND,Operate(a,theta,b));
                        break;
            }
        }
        else
        {
            if(c>='0'&&c<='9')
            {
                i=0;
                do
                {
                    z[i]=c;
                    i++;
                    c=getchar();
                }while(c>='0'&&c<='9');
                z[i]=0;
                d=atoi(z);
                Push(OPND,d);
            }
            else
            {
                printf("ERROR4");
                exit(ERROR);
            }
        }
        GetTop(OPTR,x);
    }
    GetTop(OPND,x);
    printf("%d",x);
}

int main()
{
    EvaluateExpression();
    return 0;
}
