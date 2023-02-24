// Bubble Sort in an Array with FLAG.

#include <stdio.h>
#include <stdlib.h>

int swap(int*,int*);
void FlagBubbleSort(int*, int);
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

    printf("\nApplying The Flag Bubble Sort Algorithm ...\n");
    printf("The Sorted Array is : \n");
    FlagBubbleSort(arr,length);
    PrintArray(arr,length);

    return(0);
}

int swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void FlagBubbleSort(int A[],int len){
    int flag=1;
    for(int i=0;i<len;i++){
        flag=1;
        for(int j=0;j<len-i-1;j++){
            if(A[j]>=A[j+1]){
                swap(&A[j],&A[j+1]);
                flag=0;
            }

        }
        if(flag){
            break;  
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