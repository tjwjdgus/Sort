#include<stdio.h>
#include<stdlib.h>

void print(int *a, int size) {
	for (int i = 0; i < size; i++)
		printf("%d\n", a[i]);
}

void selection_sort(int a[],int size) {
	int minindex;

	for (int i = 0; i < size-1; i++) {
		minindex = i;
		for (int j = i + 1; j < size; j++) {
			if (a[minindex] > a[j])
				minindex = j;
		}

		int temp = a[i];
		a[i] = a[minindex];
		a[minindex] = temp;
	}
	print(a, size);
}

int main(void) {
	int num;
	scanf("%d", &num);
	int *arr = malloc(sizeof(int)*num);

	for (int i = 0; i < num; i++)
		scanf("%d", &arr[i]);

	selection_sort(arr, num);

	free(arr);
	return 0;
}