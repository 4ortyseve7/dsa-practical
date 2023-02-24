// Bubble Sort in an Array without FLAG.

#include <stdio.h>
#include <stdlib.h>

int swap(int*,int*);
void nonFlagBubbleSort(int*, int);
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

    printf("\nApplying The Non Flag Bubble Sort Algorithm ...\n");
    printf("The Sorted Array is : \n");
    nonFlagBubbleSort(arr,length);
    PrintArray(arr,length);

    return(0);
}

int swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void nonFlagBubbleSort(int A[],int len){
    for(int i=0;i<len;i++){
        for(int j=0;j<len-i-1;j++){
            if(A[j]>=A[j+1]){
                swap(&A[j],&A[j+1]);
            }
        }
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