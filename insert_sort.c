#include<stdio.h>

void print(int *a) {
	for (int i = 0; i < 10; i++)
		printf("%d ", a[i]);
		printf("\n");
}

void insertion_sort(int a[]) {
	for (int i = 1; i < 10; i++) {
            int key = a[i];
            int j = i - 1;
            while (j >= 0 && a[j] > key) {
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = key;
        }
        print(a);
}

int main(void) {
	int arr[10];
	printf("10개의 정수 입력 : ");
        for (int i = 0; i < 10; i++)
            scanf("%d", &arr[i]);

        insertion_sort(arr);

        return 0;
}
