#include<string.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
main(){
int T,n,m,k,x;
int i,j,eachnum[35][25]={0},LorS[105]={0},smaterial[35]={0},l,L,result[25];
char material[25][35],drink[35][35],eachmaterial[35][25][35],customer[105][35];
scanf("%d",&T);
while(T--){
for(i=0;i<25;i++) result[i]=0;
scanf("%d %d %d",&n,&m,&k);//�ͻ�����  ԭ����������  ������������ n<=100,m<=20,k<=30 ��x<=20  �����ַ����ĳ���<=30�������ո�  ��һ��Ӧ0
for(i=0;i<m;i++) scanf("%s",material[i]);
for(i=0;i<k;i++){
scanf("%s",drink[i]);
scanf("%d",&x);
smaterial[i]=0;
    for(j=0;j<x;j++){
    scanf("%s",eachmaterial[i][j]);
    scanf("%d",&eachnum[i][j]);
    smaterial[i]+=eachnum[i][j]; }}
for(i=0;i<n;i++){
scanf("%s",customer[i]);
scanf("%d",&LorS[i]);}//����������ȷ,smaterial�������쳣
//---------------------------cut-----------------------------------------
for(i=0;i<n;i++){//һ���ͻ�һ���ͻ��жϣ�Ҳ����һ��һ���������ж�
    for(j=0;j<k;j++){
    if((strcmp(customer[i],drink[j]))==0){//�ж����������� drink[j]�ǵ�ǰ����
    if(LorS[i]==0){  //�жϴ󱭻���С��
        for(l=0;l<x;l++){
            for(L=0;L<m;L++){
            if((strcmp(eachmaterial[j][l],material[L])==0)) result[L]+=eachnum[j][l];}}}
    else{
        if(smaterial[j]>10){
        for(l=0;l<x;l++){
            for(L=0;L<m;L++){
            if((strcmp(eachmaterial[j][l],material[L])==0)) result[L]+=eachnum[j][l];}}}
        else{
        for(l=0;l<x;l++){
            for(L=0;L<m;L++){
            if((strcmp(eachmaterial[j][l],material[L])==0)) result[L]=(eachnum[j][l])*2+result[L];}}}
    }}}}
for(i=0;i<m-1;i++) {printf("%d ",result[i]);}
printf("%d\n",result[i]);
}
return 0;
}

