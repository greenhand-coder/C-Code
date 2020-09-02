#include<stdio.h>
void HeapAdjust(int a[],int s,int m)
{
    int j;
    int key=a[s];
    for(j=2*s;j<=m;j*=2)
    {
        if(j<m&&a[j]<a[j+1]) j++;
        if(key>=a[j]) break;
        a[s]=a[j];s=j;
    }
    a[s]=key;
}
void CreatHeap(int a[],int n)
{
    int i;
    for(i=n/2;i>0;i--) HeapAdjust(a,i,n);

}
main()
{
    int i,j,k,l,n,a[100],x;//左子节点2i  右2i+1
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",&a[i]);
    CreatHeap(a,n);
    for(k=1;k<=n;k++) printf("%d ",a[k]);
    printf("\n");
    for(i=n;i>1;i--)
    {
        x=a[1];a[1]=a[i];a[i]=x;
        HeapAdjust(a,1,i-1);
        for(k=1;k<=n;k++) printf("%d ",a[k]);
        printf("\n");
    }
}
/*输入样例
10
5 4 8 0 9 3 2 6 7 1


输出样例
9 7 8 6 4 3 2 5 0 1
8 7 3 6 4 1 2 5 0 9
7 6 3 5 4 1 2 0 8 9
6 5 3 0 4 1 2 7 8 9
5 4 3 0 2 1 6 7 8 9
4 2 3 0 1 5 6 7 8 9
3 2 1 0 4 5 6 7 8 9
2 0 1 3 4 5 6 7 8 9
1 0 2 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9*/
