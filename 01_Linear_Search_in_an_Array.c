// Linear Search in an Array.

#include <stdio.h>
#include <stdlib.h>
int LinearSearch(int*, int, int);
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

    int key,key_pos;
    printf("Enter the Element you want to Linear Search in the Array : ");
    scanf(" %d",&key);

    key_pos = LinearSearch(arr , length , key);

    if( key_pos == -1){
        printf("The Key Value ( %d ) is NOT Present in the Array. \n",key);
    }
    else{
        printf("The Key Value ( %d ) is Present at the index ( %d ) of the Array. \n",key,key_pos);
    }

    return(0);
}
int LinearSearch(int A[], int Len, int K){
    for(int i=0; i<Len; i++){
        if(A[i]==K){
            return(i);
        }
    }
    return(-1);
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
