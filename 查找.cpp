#include<stdio.h>
main()
{
    int n,i,*a,key;
    scanf("%d",&n);
    a=new int[n+1];
    for(i=1;i<=n;i++) scanf("%d",&a[i]);
    scanf("%d",&key);
    for(i=1;i<=n;i++){ if(a[i]==key) {printf("The element position is %d.",i-1);break; }}
    if(i==n+1) printf("The element is not exist.");
}
