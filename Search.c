#include<stdio.h>
int main()
{
    int num,i;  //记录查找的次数
    int a[10]={1,5,63,87,21,1,74,52,2,10};
    for(i=0;i<=9;i++)
    {
        if(a[i]==5) {num=i+1;break;}
    }
    printf("%d",num);
}
