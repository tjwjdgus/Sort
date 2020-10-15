#include <stdio.h>
#include <stdlib.h>

void printArray(int *arr, int len) {
	for (int i = 1; i <= len; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(int *arr, int k, int n) {
	int left = 2 * k, right = 2 * k + 1;
	int larger;

	if (right <= n)
		larger = arr[left] < arr[right] ? right : left;
	else if (left <= n) larger = left;
	else return;

	if (arr[larger] >= arr[k]) { 
		swap(&arr[k], &arr[larger]);
		heapify(arr, larger, n);
	}
}

void buildHeap(int *arr, int n){
	for (int i = n / 2; i > 0; i--)
		heapify(arr, i, n);
}

void heapSort(int *arr, int n) {

	buildHeap(arr, n);
	printf("�ʱ���: ");
	printArray(arr, n);
	for (int i = n; i > 0; i--) {
		swap(&arr[1], &arr[i]);
		printArray(arr, n);

		heapify(arr, 1, i - 1);
	}
	printf("�� ���� ");
	printArray(arr, n);
}

int main(void){
	int n;
	printf("�迭�� ũ�⸦ �Է��ϼ���: ");
	scanf("%d", &n);
	int* arr = (int *)malloc(sizeof(int)*n);
	
	printf("�迭�� �� ������ �Է��ϼ���: ");
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);

	printf("������ �迭: ");
	printArray(arr, n);

	heapSort(arr, n);

	return 0;
}