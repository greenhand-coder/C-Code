#include<string.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int comp(const void*a,const void*b){
return *(int*)a-*(int*)b;
}
main(){
int i,num,n,m,j,len,k,sum=0,min,slen=0;
char s[100][10000];
scanf("%d",&n);
for(i=0;i<n;i++){
    sum=0;
    int a[10]={0};
    scanf("%d",&m);
    char temp =getchar();
    for(j=0;j<m;j++){
    gets(s[j]);
    strlwr(s[j]);
    len=strlen(s[j]);
    slen+=len;
        for(k=0;k<len;k++){
        if(s[j][k]=='h') a[0]++;
        else if(s[j][k]=='l') a[1]++;
        else if(s[j][k]=='o') a[2]++;
        else if(s[j][k]=='w') a[3]++;
        else if(s[j][k]=='k') a[4]++;
        else if(s[j][k]=='n') a[5]++;
        else if(s[j][k]=='i') a[6]++;
        else if(s[j][k]=='g') a[7]++;
        else if(s[j][k]=='t') a[8]++;
        else a[9]++;
        }//此步已验证
        }
    if(a[0]<2||a[1]<2||a[2]<2||a[4]<1||a[5]<1||a[6]<1||a[7]<1||a[8]<1||a[3]<1||a[9]<1) min=0;
    else{
    a[0]/=2;a[1]/=2;a[2]/=2;
    qsort(a,10,sizeof(int),comp);//ok
    min=a[0];}
    sum+=min;
    printf("%d\n",sum);
}
}
