#include<stdio.h>
#include<stdlib.h>

void print(int *a, int size) {
	for (int i = 0; i < size; i++)
		printf("%d\n", a[i]);
}

void insertion_sort(int a[],int size) {
	for (int i = 1; i < size; i++) {
            int key = a[i];
            int j = i - 1;
            while (j >= 0 && a[j] > key) {
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = key;
        }
        print(a, size);
}

int main(void) {
	int num;
        scanf("%d",&num);
        int *arr=malloc(sizeof(int)*num);
        for (int i = 0; i < num; i++)
            scanf("%d", &arr[i]);

        insertion_sort(arr,num);
        
        free(arr);
        return 0;
}
