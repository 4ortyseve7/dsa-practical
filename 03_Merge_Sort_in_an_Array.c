// Merge Sort in an Array.

#include<stdio.h>
#include<stdlib.h>

int Merging(int*, int, int, int, int);
int MergeSort(int*, int, int);
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

    printf("\nApplying The Merge Sort Algorithm ...\n");
    MergeSort(arr,0,length);
    
    printf("\nThe Sorted Array is :\n");
    PrintArray(arr,length);
    return(0);
}

int Merging(int A[], int low1, int up1, int low2, int up2){
    int art1[up1-low1+1],art2[up2-low2+1],length=up2-low1+1;
    for(int i=0; i<up1-low1+1; i++){
        art1[i] = A[low1+i];
        art2[i] = A[low2+i];
    }
    int i=0,j=0,k=0;
    while(i<up1-low1+1 && j<up2-low2+1){
        if(art1[i] < art2[j]){
            A[k+low1] = art1[i++];
        }
        else{
            A[k+low1] = art2[j++];
        }
        k++;
    }
    while(i<up1-low1+1){
        A[k+low1] = art1[i++];
        k++;
    }
    while(j<up2-low2+1){
        A[k+low1] = art2[j++];
        k++;
    }
}

int MergeSort(int A[], int low, int up){
    int mid = ( low + up ) / 2 ;
    if ( low == up ){
        return(A[low]);
    }
    else{
        MergeSort(A,low,mid);
        MergeSort(A,mid+1,up);

        Merging(A,low,mid,mid+1,up);
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