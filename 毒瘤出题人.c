#include<stdio.h>
#include<stdlib.h>
main(){
int T,n,r,m;
scanf("%d",&T);
while(T--){
scanf("%d %d %d",&n,&r,&m);
if(m==0) printf("-1\n");
else{
    if((r*10/6)>n) printf("-1\n");
    else{
        if(r<=6) printf("10\n");
        else{
            if(r%6==0) printf("%d\n",r*10/6);
            else printf("%d\n",((r*10/6)/10+1)*10);}
        }
    }
}
}

