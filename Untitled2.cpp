#include <stdio.h>

int b[100]; //�м��������

void merge(int a[], int low, int mid, int high){
	// ��ʱa[] ��a[low,mid] ��a[mid+1,high]���Զ��������,���ڳɶԵ�����������
	//��Ҫ�ϲ���һ�������
	int i, j, k;
	i = low;
	j = mid + 1;
	k = 0;
	for (k=0; i <= mid&&j <= high; k++){
		//����С���ȷ���b[]
		if (a[i] < a[j])
			b[k] = a[i++];
		else
			b[k] = a[j++];
	}

	while (i <= mid)  b[k++] = a[i++];
	while (j <= high) b[k++] = a[j++];

	// �������������b[0,k-1]������a[low,high]��
	for (i = low,j=0; i <= high; i++,j++){
		a[i] = b[j];
	}
}

void mergeSort(int a[], int low, int high){
	if (low < high){//����
		int mid = (low + high) / 2;
		mergeSort(a, low, mid); //��������
		mergeSort(a, mid + 1, high);//��������
		merge(a, low, mid, high);//�鲢����������

	}
	for(int i=0;i<high;i++) printf("%d ",a[i]);
    printf("\n");
}

int main(){

	int a[8] = {1, 6, 3, 2, 9, 8, 7, 5};

	//8��Ԫ��
	int n = 8;

	mergeSort(a, 0, n - 1);

	for (int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}

	printf("\n");

	return 0;
}

