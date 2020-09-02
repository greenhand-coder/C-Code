#include<iostream>
using namespace std;
void combine(int *nums,int l,int m,int r){
   // cout<<"combine"<<l<<" "<<m<<" "<<r<<endl;
   int len = r-l+1;
    int *temp = new int[len+1];
    int i = l;
    int j = m+1;
    int k =0;
    while(i<=m && j <=r){
        if(nums[i] >nums[j]){
                temp[k++] = nums[j];
                j++;
        }else{
            temp[k++] = nums[i];
            i++;
        }
    }
    while(i <=m) {temp[k++] = nums[i]; i++;}
    while(j<=r) {temp[k++] = nums[j]; j++;}
    k =0;
    for(i =l;i<=r;i++) nums[i] = temp[k++];
    delete []temp;
}
void merge_sort(int * nums,int length){
    for(int i = 1;i<length;i*=2){//ö�ٲ���
        int l = 0;
        while(l<length-1){
            int mid = l+i-1;
            int r = mid +i;
            if(mid>= length-1) break;//mid�Ѿ��������鳤���ˣ�֤���Ѿ�����
            if(r>=length){  r = length -1;}//�ұ߲����������鳤��Ҫ�˻ص����鳤
            if(r ==mid) break;//ֻ����ߣ���������
            combine(nums,l,mid,r);
            l = r+1;
        }
    	for(int j=1;j<=length;j++) printf("%d ",nums[j]);
        printf("\n");
    }
}

int main(){
int nums[] = {5,4,2,1,6,8,9,3};
int len = sizeof(nums)/sizeof(int);



merge_sort(nums,len);


return 0;
}

