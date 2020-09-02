#include <stdio.h>

int b[100]; //中间过程数组

void merge(int a[], int low, int mid, int high){
	// 此时a[] 的a[low,mid] 和a[mid+1,high]各自都是有序的,属于成对的两个子问题
	//需要合并成一个有序表
	int i, j, k;
	i = low;
	j = mid + 1;
	k = 0;
	for (k=0; i <= mid&&j <= high; k++){
		//将较小的先放入b[]
		if (a[i] < a[j])
			b[k] = a[i++];
		else
			b[k] = a[j++];
	}

	while (i <= mid)  b[k++] = a[i++];
	while (j <= high) b[k++] = a[j++];

	// 将已有序的数据b[0,k-1]拷贝到a[low,high]中
	for (i = low,j=0; i <= high; i++,j++){
		a[i] = b[j];
	}
}

void mergeSort(int a[], int low, int high){
	if (low < high){//划分
		int mid = (low + high) / 2;
		mergeSort(a, low, mid); //左子问题
		mergeSort(a, mid + 1, high);//右子问题
		merge(a, low, mid, high);//归并两个子问题

	}
	for(int i=0;i<high;i++) printf("%d ",a[i]);
    printf("\n");
}

int main(){

	int a[8] = {1, 6, 3, 2, 9, 8, 7, 5};

	//8个元素
	int n = 8;

	mergeSort(a, 0, n - 1);

	for (int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}

	printf("\n");

	return 0;
}

