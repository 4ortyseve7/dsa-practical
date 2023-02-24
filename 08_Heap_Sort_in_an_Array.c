#include <stdio.h>
#include <stdlib.h>

void swap(int*, int*);
void max_heapify(int*, int, int);
void build_heap(int*, int);
void heap_sort(int*, int);
void PrintArray(int*, int);

int main(){
    int n;
    printf("Enter length of the Array : ");
    scanf(" %d", &n);

    int arr[n];
    printf("\nEnter elements in the Array\n");
    for (int i = 0; i < n; i++){
            printf("Input Value at index [%d] : ",i);
            scanf(" %d",&arr[i]);
    }

    printf("\nThe Input Array is\n");
    PrintArray(arr,n);

    heap_sort(arr, n);

    printf("\nThe Array after Heap sorting\n");
    PrintArray(arr,n);
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void max_heapify(int arr[], int n, int i){
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;
    int largest = i;
    if(left < n && arr[left] > arr[i]){
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]){
        largest = right;
    }
    if (largest != i){
        swap(&arr[i], &arr[largest]);
        max_heapify(arr, n, largest);
    }
}

void build_heap(int arr[], int n){
    for(int i = (n / 2) ; i >= 0; i--){
        max_heapify(arr, n, i);
    }
}

void heap_sort(int arr[], int n){
    build_heap(arr, n);
    for(int i = n-1 ; i >= 0; i--){
        swap(&arr[0], &arr[i]);
        max_heapify(arr, i, 0);
    }
}

void PrintArray(int arr[],int length){
    if(length<=0){
        printf("NULL");
        exit(0);
    }
    else{
        printf("[");
    }
    for(int i=0;i<length;i++){
        printf(" %d",arr[i]);
        if(i!=length-1){
            printf(",");
        }
        else if(i==length-1){
            printf(" ]\n");
        }
    }
}