#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void merge(int *arr, int start, int mid, int end) {
	int s = start;
	int m = mid + 1;
	int idx = 0;
	int *a=malloc(sizeof(int)*(end-start+1));

	while (s <= mid && m <= end) {
		if (arr[s] < arr[m])
			a[idx] = arr[s++];
		else
			a[idx] = arr[m++];
		idx++;
	}

	while (s <= mid)
		a[idx++] = arr[s++];
	while (m <= end)
		a[idx++] = arr[m++];
	
	int i = start;
	int idx2 = 0;
	while(i<=end)
		arr[i++] = a[idx2++];

	free(a);
}

void merge_sort(int *arr, int start, int end) {
	int mid;
	if (start < end) {
		mid = (start + end) / 2;
		merge_sort(arr, start, mid);
		merge_sort(arr, mid + 1, end);
		merge(arr, start, mid, end);
	}
}

int main(void) {
	int num;
	scanf("%d", &num);
	int *arr = malloc(sizeof(int)*1000000);

	for (int i = 0; i < num; i++) {
		scanf("%d", &arr[i]);
	}

	merge_sort(arr, 0, num-1);

	for (int i = 0; i < num; i++)
		printf("%d\n", arr[i]);
	
	free(arr);
	return 0;
}