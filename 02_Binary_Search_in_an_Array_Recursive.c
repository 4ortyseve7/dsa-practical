// Binary Search in an Array Recursive.

#include <stdio.h>
#include <stdlib.h>

int RecBinarySearch(int*, int, int, int);
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
    PrintArray(arr,length);

    for (int i=0 ; i<length-1;i++){
        if(arr[i]>arr[i+1]){
            printf("The Input Array is not sorted in ascending order.\nCannot perform Binary Search.");
            return(0);
        }
    }
    int key,key_pos;
    printf("Enter the Element you want to Rec. Binary Search in the Array : ");
    scanf(" %d",&key);

    key_pos = RecBinarySearch(arr, 0, length-1, key);

    if( key_pos == -1){
        printf("The Key Value ( %d ) is NOT Present in the Array. \n",key);
    }
    else{
        printf("The Key Value ( %d ) is Present at the index ( %d ) of the Array. \n",key,key_pos);
    }


    return(0);
}
int RecBinarySearch(int A[], int lower, int upper, int K){
    int middle = (lower+upper)/2;
    if(lower==upper){
        if(A[middle] == K){
            return(middle);
        }
        else{
            return(-1);
        }
    }
    else{
        if(A[middle]==K){
            return(middle);
        }
        else{
            if(A[middle]>K){
                return(RecBinarySearch(A,lower,middle-1,K));
            }
            else{
                return(RecBinarySearch(A,middle+1,upper,K));
            }
        }
    }

}

void PrintArray(int arr[],int length){
    printf("\nThe Array you created is :\n");
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