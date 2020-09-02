/*#include<stdio.h>
main()
{
    int a[100],n,i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",&a[i]);
    for(i=2;i<=n;i++)
    {
        if(a[i-1]>a[i]){
            a[0]=a[i];
            a[i]=a[i-1];
            for(j=i-2;a[0]<a[j];j--) a[j+1]=a[j];
            a[j+1]=a[0];
        }
        for(k=1;k<=n;k++) printf("%d ",a[k]);
        printf("\n");
    }
}*/
/*输入样例
10
5 4 8 0 9 3 2 6 7 1


输出样例
4 5 8 0 9 3 2 6 7 1
4 5 8 0 9 3 2 6 7 1
0 4 5 8 9 3 2 6 7 1
0 4 5 8 9 3 2 6 7 1
0 3 4 5 8 9 2 6 7 1
0 2 3 4 5 8 9 6 7 1
0 2 3 4 5 6 8 9 7 1
0 2 3 4 5 6 7 8 9 1
0 1 2 3 4 5 6 7 8 9*/
#include<stdio.h>
main()
{
    int a[100],i,j,n,key;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",&a[i]);
    for(i=2;i<=n;i++){//i表示一个范围  i=2表示前 2位数
        key=0;
        a[0]=a[i];
        for(j=i-1;j>=1;j--)
        {
            if(a[j]>a[0]){a[j+1]=a[j];key=j;}//key是a[0]要放的位置
        }
        a[key]=a[0];
        for(j=1;j<=n;j++) printf("%d ",a[j]);
        printf("\n");
    }
}
