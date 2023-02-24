// Queue Data Structure with all operations.

#include<stdio.h>
#include<stdlib.h>

int IsFull(int*, int*, int);
int IsEmpty(int*, int*, int);
int Peek(int*, int*, int);
void Push(int*, int*, int);
int Pop(int*, int*, int);
int StackDisplay(int*, int*, int);

int main(){
    int length,operation;

    printf("Enter the size of the Stack you want to create : ");
    scanf(" %d",&length);

    int stack[length];

    int top=-1;
    
    while(1){
        printf("\n---------------");
        printf("\nChoose the operations to perform on Stack Data Structure.\n1. IsFull\n2. IsEmpty\n3. Peek\n4. Push\n5. Pop\n6. Display\n\n0. To Exit the Program.\nEnter Here : ");
        scanf(" %d",&operation);

        int boolVal,value,pop_value;
        switch (operation)  
        {
        case 1:
            boolVal = IsFull(stack,&top,length);
            if(boolVal){
                printf("\nStack is Full.");
            }
            else{
                printf("\nStack is NOT Full.");
            }
            break;
        case 2:
            boolVal = IsEmpty(stack,&top, length);
            if(boolVal){
                printf("Stack is Empty.");
            }
            else{
                printf("Stack is NOT Empty.");
            }
            break;
        case 3: 
            Peek(stack,&top,length);
            break;
        case 4: 
            Push(stack,&top,length);
            break;
        case 5: 
            if(!IsEmpty(stack,&top,length)){
                pop_value = Pop(stack,&top,length);
                printf("\nThe Popped element is %d",pop_value);
            }
            else{
                Pop(stack,&top,length);
            }
            break;
        case 6: 
            StackDisplay(stack,&top,length);
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

int IsFull(int S[], int *top, int size){
    if(*top == size - 1){
        return(1);
    }
    return(0);
}

int IsEmpty(int S[], int *top, int size){
    if(*top == -1){
        return(1);
    }
    return(0);
}

int Peek(int S[], int *top, int size){
    if(IsEmpty(S,&*top,size)){
        printf("\nThe Stack is Empty. There is no element.");
        return(0);
    }
    printf("\nThe top element is %d",S[*top]);
}

void Push(int S[], int *top, int size){
    int value;
    if(IsFull(S, &*top, size)){
        printf("\nStack Overflow.");
    }
    else{
        printf("\nEnter the value to Push : ");
        scanf(" %d",&value);
        *top+=1;
        S[*top]=value;
    }
}

int Pop(int S[], int *top, int size){
    if(IsEmpty(S, &*top, size)){
        printf("\nStack Underflow.");
    }
    else{
        int pop_value;
        pop_value=S[*top];
        *top-=1;
        return(pop_value);
    }
}

int StackDisplay(int S[], int *top, int size){
    if(IsEmpty(S,&*top,size)){
        printf("\nStack is Empty.");
        return(0);
    }
    else{
        for(int i=size-1;i>=0;i--){
            if(i<=*top){
                printf("\n----\n%d",S[i]);
            }
            else{
                printf("\n----\n");
            }
        }
        printf("\n----\n");
    }
}
