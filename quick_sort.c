#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int count = 0;
void print(int *a, int num) {
	for (int i = 0; i < num; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int partition(int *a, int start, int end,int num) {
	int j = start, i;
	int pivot = a[end];
	printf("%d�ܰ� pivot: %d\n", ++count,pivot);
	for (i = start; i < end; i++) {
		if (a[i] < pivot) {
			int tmp = a[j];
			a[j] = a[i];
			a[i] = tmp;
			j++;
		}
	}

	int tmp = a[j];
	a[j] = a[end];
	a[end] = tmp;
	print(a, num);
	printf("=================================\n");
	return j;
}

void quick_sort(int *a, int start,int end, int num) {
	if (start < end) {
		int mid = partition(a, start, end, num);
		quick_sort(a, start, mid - 1, num);
		quick_sort(a, mid + 1, end, num);
	}
}

int main(void) {
	int num;
	printf("���Ŀ� ����� ������ ���� : ");
	scanf("%d", &num);

	int *arr = malloc(sizeof(int)*num);
	for (int i = 0; i < num; i++)
		arr[i] = rand() % 100 + 1;

	printf("<<�� ���� ��>>\n");
	print(arr, num);
	printf("\n");
	quick_sort(arr, 0, num-1, num);

	printf("\n<<�� ���� ��>>\n");
	print(arr, num);
	free(arr);
	return 0;
}