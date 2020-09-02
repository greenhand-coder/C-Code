#include "stdio.h"
#include "malloc.h"

typedef int *List;
List T;
void Merge(List R,List T,int low, int mid,int high);
void Msort(List R,List T,int step,int N);
void MergeSort(List R,int N)
{
    T=(List)malloc((N+1)*sizeof(List));
    int step=1;
    while(step<N)
    {
        Msort(R,T,step,N);
        step*=2;
        for(int j=1;j<=N;j++)
        printf("%d ",*(T+j));
        printf("\n");
        if(step<N) {Msort(T,R,step,N); step*=2;
        for(int j=1;j<=N;j++)
        printf("%d ",*(R+j));
        printf("\n");
        }
        else { for(int j=1;j<=N;j++) R[j]=T[j]; }
    }
}
void Msort(List R,List T,int s,int N)
{
    int i=1;
    while(i<N+1-2*s)
    {
        Merge(R,T,i,i+s-1,i+2*s-1);
        i+=2*s;
    }
    if(i+s<=N) Merge(R,T,i,i+s-1,N);
    else { for(int j=i;j<=N;j++) T[j]=R[j]; }
}
void Merge(List R,List T,int low, int mid,int high)
{
    int i,j,k;
    i=low; j=mid+1; k=low;
    while(i<=mid&&j<=high)
    {
        if(R[i]<=R[j]) T[k++]=R[i++];
        else T[k++]=R[j++];
    }
    while(i<=mid) T[k++]=R[i++];
    while(j<=high) T[k++]=R[j++];
}
main()
{
    List R;
    int n,i;
    scanf("%d",&n);R=(List)malloc((n+1)*sizeof(List));
    for(i=1;i<=n;i++) scanf("%d",R+i);
    MergeSort(R,n);
}
