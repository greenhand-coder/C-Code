/*#include<stdio.h>
main()
{
    int a[100],j,i,n,k,t,l;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",&a[i]);
    for(i=1;i<n;i++)
    {
        k=i;
        for(j=i+1;j<=n;j++){  if (a[j]<a[k]) k=j;  }
        if(k!=i) {t=a[i];a[i]=a[k];a[k]=t; }
        for(l=1;l<=n;l++) printf("%d ",a[l]);
        printf("\n");
    }
}*/

/*输入样例
10
5 4 8 0 9 3 2 6 7 1


输出样例
0 4 8 5 9 3 2 6 7 1
0 1 8 5 9 3 2 6 7 4
0 1 2 5 9 3 8 6 7 4
0 1 2 3 9 5 8 6 7 4
0 1 2 3 4 5 8 6 7 9
0 1 2 3 4 5 8 6 7 9
0 1 2 3 4 5 6 8 7 9
0 1 2 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9*/
#include<stdio.h>
#include<iostream>
main()
{
    int a[100],n,j,i,key,t,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",&a[i]);
    for(i=1;i<=n-1;i++)
    {
        k=i; //a[k]用来放最小的数字
        for(j=i+1;j<=n;j++)//第一趟把最小一个放前面  第二趟放两个
        {
            k=a[k]<a[j]?k:j;
        }
        std::swap(a[i],a[k]);
        for(j=1;j<=n;j++) printf("%d ",a[j]);
        printf("\n");
    }
}
