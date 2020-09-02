#include "stdio.h"
#include "malloc.h"
#define TRUE 1
#define FALSE 0
#define OK  1
#define ERROR  0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int  Status;

typedef char  ElemType;
typedef struct BiTNode{
  ElemType data;
  struct BiTNode *lchild,*rchild;//���Һ���ָ��
} BiTNode,*BiTree;

Status CreateBiTree(BiTree &T) {  // �㷨6.4
  // �������������������н���ֵ��һ���ַ�������#���ַ���ʾ������
  // ������������ʾ�Ķ�����T��
  char ch;
  scanf("%c",&ch);
  if (ch=='#') T = NULL;
  else {
    if (!(T = (BiTNode *)malloc(sizeof(BiTNode)))) return ERROR;
    T->data=ch;   // ���ɸ����
    CreateBiTree(T->lchild);// ����������
    CreateBiTree(T->rchild);// ����������
  }
  return OK;
} // CreateBiTree


Status PrintElement( ElemType e ) {  // ���Ԫ��e��ֵ
printf("%c", e );
return OK;
}// PrintElement


Status PreOrderTraverse( BiTree T ) {
   // ǰ�����������T�ĵݹ��㷨����ÿ������Ԫ�ص��ú���Visit��
   //��ȫ����,���ö�����
if(T){
printf("%c",T->data);
PreOrderTraverse(T->lchild);
PreOrderTraverse(T->rchild);
}} // PreOrderTraverse

Status InOrderTraverse( BiTree T ) {
     // �������������T�ĵݹ��㷨����ÿ������Ԫ�ص��ú���Visit��
    //��ȫ����,���ö�����
if(T){
InOrderTraverse(T->lchild);
printf("%c",T->data);
InOrderTraverse(T->rchild);
}} // InOrderTraverse

Status PostOrderTraverse( BiTree T)  {
     // �������������T�ĵݹ��㷨����ÿ������Ԫ�ص��ú���Visit��
     //��ȫ����,���ö�����
if(T){
PostOrderTraverse(T->lchild);
PostOrderTraverse(T->rchild);
printf("%c",T->data);
}} // PostOrderTraverse



int main()   //������
{
BiTree T;
CreateBiTree(T);
PreOrderTraverse(T);printf("\n");
InOrderTraverse(T);printf("\n");
PostOrderTraverse(T);printf("\n");
                      //�������
 }//main

