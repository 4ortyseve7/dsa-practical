// Insertion Sort in an Array.

#include <stdio.h>
#include <stdlib.h>

int swap(int*, int*);
int InsertionSort(int*, int);
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

    printf("\nApplying The Insertion Sort Algorithm ...\n");
    printf("The Sorted Array is : \n");
    InsertionSort(arr,length);
    PrintArray(arr,length);

    return(0);
}

int swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int InsertionSort(int A[],int len){ 
    if(len>1){
        InsertionSort(A,len-1);
        int p,q,temp;
        q=len-1;
        p=q-1;
        while(p!=-1){
            if(A[p]>A[q]){
                // temp=A[p];
                // A[p]=A[q];
                // A[q]=temp;
                swap(&A[p],&A[q]);
                p--;
                q--;
            }
            else{
                return(0);
            }
        }
    }
    return(0);    
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