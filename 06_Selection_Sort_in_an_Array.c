// Selection Sort in an Array.

#include <stdio.h>
#include <stdlib.h>

int swap(int*, int*);
int SelectionSort(int*, int, int);
void PrintArray(int*, int);

int main(){
    int length;
    printf("Enter the Size of the Array you want to create : ");
    scanf(" %d",&length);
    int arr[length];

    printf("Enter the numerical values into the Array\n");
    for(int i=0;i<length;i++){
        printf("Input Value at index [%d] : ",i);
        scanf(" %d",&arr[i]);
    }

    printf("\nThe Array you created is :\n");
    PrintArray(arr,length);

    printf("\nApplying The Selection Sort Algorithm ...\n");
    printf("The Sorted Array is : \n");
    SelectionSort(arr,0,length);
    PrintArray(arr,length);

    return(0);
}

int swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int SelectionSort(int A[],int low, int hi){
    int minimum = A[low],index = low;
    if(low == hi){
        return(0);
    }
    for(int i=low+1;i<hi;i++){
        if(A[i] < minimum){
            minimum = A[i];
            index = i;
        }
    }
    swap(&A[low],&A[index]);
    SelectionSort(A,low+1,hi);
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