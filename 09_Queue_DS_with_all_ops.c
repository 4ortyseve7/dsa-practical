// Queue Data Structure with all operations.

#include<stdio.h>
#include<stdlib.h>

int IsFull(int*, int*, int*, int);
int IsEmpty(int*, int*, int*, int);
void Peek(int*, int*, int*, int);
void Enqueue(int*, int*, int*, int);
void Dequeue(int*, int*, int*, int);

int main(){
    int length,elements,operation;

    printf("Enter the size of the Queue you want to create : ");
    scanf(" %d",&length);

    int queue[length];

    printf("Enter the number of values you want to input in queue : ");
    scanf(" %d",&elements);

    if(elements >= 0 && elements <= length){
        printf("Input the Values\n");
        for(int i=0;i<elements;i++){
            printf("Input at index ( %d ) : ",i);
            scanf(" %d",&queue[i]);
        }
    }
    else{
        printf("Cannot Insert ...");
        return(0);
    }

    int front, rear;
    if(elements == 0){
        front = rear = -1;
    }
    else{
        front = 0;
        rear = elements-1;
    }

    while(1){
        printf("\n---------------");
        printf("\nChoose the operations to perform on Queue Data Structure.\n1. IsFull\n2. IsEmpty\n3. Peek\n4. Enqueue\n5. Dequeue\n\n0. To Exit the Program.\nEnter Here : ");
        scanf(" %d",&operation);

        int boolVal;
        switch (operation)  
        {
        case 1:
            boolVal = IsFull(queue,&front,&rear,length);
            if(boolVal == 1){
                printf("\nQueue is Full.");
            }
            else{
                printf("\nQueue is NOT Full.");
            }
            break;
        case 2:
            boolVal = IsEmpty(queue,&front,&rear,length);
            if(boolVal == 1){
                printf("\nQueue is Empty.");
            }
            else{
                printf("\nQueue is NOT Empty.");
            }
            break;
        case 3:
            if(IsEmpty(queue,&front,&rear,length)){
                printf("\nPeek cannot performed on Empty Queue.");
            }
            else{
                Peek(queue,&front,&rear,length);
            }
            break;
        case 4:
            if(IsFull(queue,&front,&rear,length)){
                printf("Enqueue cannot be performed. The Queue is already Full.");
            }
            else{
                Enqueue(queue,&front,&rear,length);
            }
            break;
        case 5:
            if(IsEmpty(queue,&front,&rear,length)){
                printf("Dequeue cannot be performed. The Queue is Empty.");
            }
            else{
                Dequeue(queue,&front,&rear,length);
            }
            break;
        case 0:
            printf("\nExiting Program . . .\n");
            return(0);
            break;
        
        default:
            printf("Uh Oh! Invalid Input.\nExiting Program . . .");
            return(0);
        }
    }

    return(0);
}

int IsFull(int Q[], int *front, int *rear, int size){
    if(*rear == size-1){
        return(1);
    }
    return(0);
}
int IsEmpty(int Q[], int *front, int *rear, int size){
    if(*rear==-1 || *rear < *front){
        return(1);
    }
    return(0);
}
void Peek(int Q[], int *front, int *rear, int size){
    printf("\nThe Current Front Element is %d.",Q[*front]);
}
void Enqueue(int Q[], int *front, int *rear, int size){
    *rear += 1;
    int value;
    printf("\nInput at index ( %d ) : ",*rear);
    scanf(" %d",&Q[*rear]);
}
void Dequeue(int Q[], int *front, int *rear, int size){
    printf("\nThe Deleted Element is %d.",Q[*front]);
    *front += 1;
}
