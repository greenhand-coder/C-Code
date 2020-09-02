/*#include<stdio.h>
int length;
int Partition(int a[],int low,int high)
{
    a[0]=a[low];
    int povotkey=a[low];
    while(low<high)
    {
        while(low<high&&a[high]>=povotkey) high--;
        a[low]=a[high];
        while(low<high&&a[low]<=povotkey) low++;
        a[high]=a[low];
    }
    a[low]=a[0];
    for(int i=1;i<=length;i++) printf("%d ",a[i]);
    printf("\n");
    return low;

}
void Qsort(int a[],int low ,int high)
{
    if(low<high){
        int pivotloc=Partition(a,low,high);
        Qsort(a,low,pivotloc-1);
        Qsort(a,pivotloc+1,high);
    }

}
main()
{
    int a[100];
    int low=1,n,i;
    scanf("%d",&n);  length=n;
    for(i=1;i<=n;i++) scanf("%d",&a[i]);
    Qsort(a,1,n);
}*/
/*输入样例
10
5 4 8 0 9 3 2 6 7 1


输出样例
1 4 2 0 3 5 9 6 7 8
0 1 2 4 3 5 9 6 7 8
0 1 2 4 3 5 9 6 7 8
0 1 2 3 4 5 9 6 7 8
0 1 2 3 4 5 8 6 7 9
0 1 2 3 4 5 7 6 8 9
0 1 2 3 4 5 6 7 8 9*/
#include<stdio.h>
#include<iostream>
int len;
int Partition(int a[],int low,int high)
{
    int i=low,j=high,x,k;
    x=a[i];
    while(i<j)
    {
        while(x<a[j]&&i<j) j--;
        std::swap(a[i],a[j]);
        while(x>a[i]&&i<j) i++;
        std::swap(a[i],a[j]);
    }
    for(k=1;k<=len;k++) printf("%d ",a[k]);
    printf("\n");
    return i;
}
void Qsort(int a[],int low,int high)
{
    if(low<high)
    {
        int poc=Partition(a,low,high);
        Qsort(a,low,poc-1);
        Qsort(a,poc+1,high);
    }
}
main()
{
    int n,a[100],i,j;
    scanf("%d",&n);len=n;
    for(i=1;i<=n;i++) scanf("%d",&a[i]);
    Qsort(a,1,n);
}
#
