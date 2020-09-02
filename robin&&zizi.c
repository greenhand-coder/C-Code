#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
int comp(const void*a,const void*b){
return *(int*)a-*(int*)b;
}
main(){
int T,A,B,S,x=1;//切记整体不要出现小S
int i,j,a,b,t;
scanf("%d",&T);
while(T--){
int numA[1005]={0},numB[1005]={0},sum[1005]={0};
scanf("%d %d",&A,&B);
scanf("%d",&S);
for(i=0;S-i>=0;i++){
    for(j=1,t=A;j<=i;j++){
    t++;
    if((t%10==0)&&(t%100!=0)) numA[i]+=10;
    else if(t%100==0) numA[i]+=19;
    else numA[i]++;}}
for(i=0;S-i>=0;i++){
    for(j=1,t=B;j<=S-i;j++){
    t++;
    if((t%10==0)&&(t%100!=0)) {numB[i]+=10;}
    else if(t%100==0) numB[i]+=19;
    else numB[i]++;}}
for(i=0;i<=S;i++) {sum[i]=numA[i]+numB[i]; }
qsort(sum,S+1,sizeof(int),comp);
printf("Case %d: %d %d\n",x,sum[S],sum[0]);
x++;
}
}
