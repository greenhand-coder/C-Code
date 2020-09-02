#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int judge(int result[],int n){
    int total=0;
    for(int i=0;i<n;i++){
        total+=result[i];
    }
    if(total==1||total==n-1){
        return 1;
    }
    return 0;

}

int main() {
    int numOfPeople = 10;
    int timesOfTest = 1000000;
    int totalTimes = 0;
    int times = 0;
    int result[numOfPeople];
    srand((unsigned)time( NULL ) );
    for(int i=0;i<timesOfTest;i++){
        times = 0;
        do{
            for(int j=0;j<numOfPeople;j++){
                result[j]=(int)rand()%2;
            }
            ++times;
        }while (!judge(result,numOfPeople));
        totalTimes+=times;
    }
    printf("总人数:%d\n",numOfPeople);
    printf("总查找数:%d\n",totalTimes);
    printf("总测试数:%d\n",timesOfTest);
    printf("总查找数/总测试数:%lf",(double)totalTimes/timesOfTest);

}
