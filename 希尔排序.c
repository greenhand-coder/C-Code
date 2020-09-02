/*#include<stdio.h>
main()
{
    int a[110],j,i,k,l,d,n;
    scanf("%d",&n);d=n/2;
    for(i=1;i<=n;i++) scanf("%d",&a[i]);
    while(d){

    for(i=1+d;i<=n;i++)
    {
        if(a[i]<a[i-d]){
            a[0]=a[i];
            a[i]=a[i-d];
            for(j=i-2*d;j>0&&a[j]>a[0];j-=d) a[j+d]=a[j];
            a[j+d]=a[0];
        }

    }
    d/=2;
    for(l=1;l<=n;l++) printf("%d ",a[l]);
    printf("\n");
    }
}*/
/*输入样例
10
5 4 8 0 9 3 2 6 7 1


输出样例
3 2 6 0 1 5 4 8 7 9
1 0 3 2 4 5 6 8 7 9
0 1 2 3 4 5 6 7 8 9*/
#include<stdio.h>
main()
{
    int a[100],i,j,n,key,d=5;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",&a[i]);
    while(d){
    for(i=1+d;i<=n;i++)
    {
        key=0;
        a[0]=a[i];
        for(j=i-d;j>=1;j-=d)
        {
            if(a[j]>a[0]) { a[j+d]=a[j];key=j; }
        }
        a[key]=a[0];

    }
    for(j=1;j<=n;j++) printf("%d ",a[j]);
    printf("\n");
    d/=2;
    }
}

