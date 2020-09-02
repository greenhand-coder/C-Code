/*#include<stdio.h>
int T[100];
int len;
void Merge (int a[],int low,int mid,int high)
{
    int i=low,j=mid+1,k=1;
    while(i<=mid&&j<=high)
    {
        if(a[i]<a[j]) T[k++]=a[i++];
        else T[k++]=a[j++];
    }
    while(i<=mid) T[k++]=a[i++];
    while(j<=high) T[k++]=a[j++];
    for(i=low,j=1;i<=high;i++,j++) a[i]=T[j];
}
void Mergesort(int a[],int n)
{
    int step=1;
    int i,j;
    while(step<n)
    {
        for(i=1;i<=n&&(i+step*2-1<=n);i+=step*2)
        {
            int low=i,high=low+step*2-1,mid=(low+high)/2;
            Merge(a,i,mid,high);
        }
        if(2*step>n) Merge(a,1,step,n);
        step*=2;
        for(j=1;j<=n;j++) printf("%d ",a[j]);
        printf("\n");

    }
}
main()
{
    int n,a[100],i;
    scanf("%d",&n);len=n;
    for(i=1;i<=n;i++) scanf("%d",&a[i]);
    Mergesort(a,n);
}*/
 /*输入样例
10
5 4 8 0 9 3 2 6 7 1


输出样例
4 5 0 8 3 9 2 6 1 7
0 4 5 8 2 3 6 9 1 7
0 2 3 4 5 6 8 9 1 7
0 1 2 3 4 5 6 7 8 9*/
#include<stdio.h>
void Merge(int a[],int low,int mid,int high)
{
    int i=low,j=mid+1,k=1,T[100],l;
    while(i<=mid&&j<=high)
    {
        if(a[i]<a[j]) T[k++]=a[i++];
        else T[k++]=a[j++];
    }
    while(i<=mid) T[k++]=a[i++];
    while(j<=high) T[k++]=a[j++];
    for(l=1,i=low;i<=high;i++,l++) a[i]=T[l];
}


main()
{
    int a[100],n,i,k,j,step=2;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",&a[i]);
    while(step<=n)
    {
        for(i=1;i<=n&&(i+step-1<=n);i+=step)  //主体部分
        {
            Merge(a,i,(i+i+step-1)/2,i+step-1);
        }
        for(i=1;i<=n;i++) printf("%d ",a[i]);
        printf("\n");
        step*=2;
    }
    if((step/2)!=n){   //额外部分
        Merge(a,1,step/2,n);
        for(i=1;i<=n;i++) printf("%d ",a[i]);
        printf("\n");
    }
}


/*8
5 4 8 0 9 3 2 6*/





