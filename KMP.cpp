#include "stdio.h"
#include "stdlib.h"

#define TRUE  1
#define FALSE  0
#define OK  1
#define ERROR  0
#define INFEASLBLE  -1
#define OVERFLOW  -2
#define MAXSTRLEN  255  //�û�����255���ڶ�����󴮳�
typedef unsigned char SString[MAXSTRLEN+1]; //0�ŵ�Ԫ��Ŵ��ĳ���

void get_next(SString T,int next[]){
// �㷨4.7
// ��ģʽ��T��next����ֵ����������next
// �벹ȫ����
int i=1,j=0;next[1]=0;
while(i<MAXSTRLEN)
{
    if(j==0||T[i]==T[j]){i++;j++;next[i]=j; }
    else j=next[j];
}
}

int Index_KMP(SString S,SString T,int Slen,int Tlen){
// �㷨4.6
// ����ģʽ��T��next������T������S�е�pos���ַ�֮���λ��
// KMP�㷨���벹ȫ����
int i=1,j=1;
int next[256];
get_next(T,next);
while(i<=Slen&&j<=Tlen)
{
    if(j==0||S[i]==T[j]) {i++;j++;}
    else j=next[j];
}
if(j>=Tlen) return i-Tlen;
else return 0;
}
int main()
{
SString T,S;
 int i,j,n;
 char ch;
 int pos,Slen,Tlen;
scanf("%d",&n);    // ָ��n�������ģʽƥ����ַ���
ch=getchar();
for(j=1;j<=n;j++)
{
ch=getchar();
  for( i=1;i<=MAXSTRLEN&&(ch!='\n');i++)    // ¼������
  {
S[i]=ch;
  ch=getchar();
}
Slen=i-1;    // S[0]���ڴ洢�������ַ�����
ch=getchar();
for( i=1;i<=MAXSTRLEN&&(ch!='\n');i++)    // ¼��ģʽ��
{
  T[i]=ch;
  ch=getchar();
}
Tlen=i-1;    // T[0]���ڴ洢ģʽ�����ַ�����
pos=Index_KMP(S,T,Slen,Tlen)                ;    // �����
printf("%d\n",pos);
}
}
