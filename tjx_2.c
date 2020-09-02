#include <time.h>
#include <stdio.h>
#include <stdlib.h>


int main() {
    int numOfPeople = 6;
    int timesOfTest = 1000000;
    int times = 0;      //成功数
    int result[numOfPeople];
    srand( ( unsigned ) time ( NULL ) );
    for(int i = 0; i < timesOfTest; i++)   //测试次数循环
    {
        if( isFindout( result, numOfPeople ) ) times++;
    }
    printf("结果：%lf",(double)timesOfTest / (double)times);

}

int isFindout(int result[], int numOfPeople)
{

    int count = 0;
    for(int i = 0; i < numOfPeople; i++)
    {
        result[i] = (int)rand() % 2;
        count += result[i];
    }
    if(count == 1 || count == ( numOfPeople - 1 ))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
