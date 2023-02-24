// Quick Sort in an Array.

#include <stdio.h>
#include <stdlib.h>

void swap(int*, int*);
int Partition(int*, int, int);
int QuickSort(int*, int, int);
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

    printf("\nApplying The Quick Sort Algorithm ...\n");
    printf("The Sorted Array is : \n");
    QuickSort(arr,0,length-1);

    PrintArray(arr,length);

    return(0);
}

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int A[], int lo, int hi){
    int pivot,i,j;
    pivot = A[lo];
    i = lo;
    for ( j = i+1 ; j <= hi ; j++ ){
        if( pivot >= A[j] ){
            i++;
            swap(&A[i],&A[j]);
        }
    }
    swap(&A[lo],&A[i]);
    return(i);
}

int QuickSort(int A[], int low, int up){
    if(low<up){
        int p = Partition(A, low, up);
        QuickSort(A,low,p-1);
        QuickSort(A,p+1,up);
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