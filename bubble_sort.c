#include<stdio.h>
#include<stdlib.h>
void print(int *a, int size) {
    for (int i = 0; i < size; i++)
        printf("%d\n", a[i]);
}

void bubble_sort(int a[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++){
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    print(a, size);
}

int main(void){
    int num;
    scanf("%d",&num);
    int *arr=malloc(sizeof(int)*num);
    for(int i=0;i<num;i++)
        scanf("%d",&arr[i]);

    bubble_sort(arr,num);

    free(arr);
    return 0;
}
