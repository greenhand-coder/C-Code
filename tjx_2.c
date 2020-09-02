#include <time.h>
#include <stdio.h>
#include <stdlib.h>


int main() {
    int numOfPeople = 6;
    int timesOfTest = 1000000;
    int times = 0;      //�ɹ���
    int result[numOfPeople];
    srand( ( unsigned ) time ( NULL ) );
    for(int i = 0; i < timesOfTest; i++)   //���Դ���ѭ��
    {
        if( isFindout( result, numOfPeople ) ) times++;
    }
    printf("�����%lf",(double)timesOfTest / (double)times);

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
