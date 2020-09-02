/*#include<stdio.h>
main()
{
    int a[11],i,j,n,t,k,num;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    for(i=0;i<n-1;i++)
    {
        for(j=0,num=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1]) { t=a[j];a[j]=a[j+1];a[j+1]=t;num++; }
        }
        for(k=0;k<n;k++) printf("%d ",a[k]);
        printf("\n");
        if(num==0) break;
    }

}*/
#include<stdio.h>
main()
{
    int a[100],i,j,n,t;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++){ if(a[j]>a[j+1]) {t=a[j];a[j]=a[j+1];a[j+1]=t; }   }
        for(j=0;j<n;j++) printf("%d ",a[j]);
        printf("\n");
    }

}
