//Implementation of Linked List and all its operations.

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
typedef struct node node;
node *start = NULL;

node *getnode(int);
void createLL(int);
int countnode();
void insertionLL();
void deletionLL();
void displayLL();
void searchingLL();

int main(){
    int length,operation,value;

    printf("Enter the length of Linked List you want to create : ");
    scanf(" %d",&length);

    createLL(length);

    while(1){
        printf("\n---------------");
        printf("\nChoose the operations to perform on Linked List Data Structure.\n1. Count Node\n2. Insertion\n3. Deletion\n4. Searching\n5. Display\n\n0. To Exit the Program.\nEnter Here : ");
        scanf(" %d",&operation);

        int returnval;
        switch(operation){
        case 1:
            returnval = countnode();
            printf("\nTotal number of nodes in Linked List is %d",returnval);
            break;
        case 2:
            insertionLL();
            break;
        case 3:
            if(countnode() == 0){
                printf("\nLinked List Underflow.");
            }
            else{
                deletionLL();
            }
            
            break;
        case 4:
            if(countnode() == 0){
                printf("The Linked List is Empty, Cannot Search!");
            }
            else{
                printf("\nEnter the data to search in the Linked List : ");
                scanf(" %d",&value);
                searchingLL(value);
            }
            break;
        case 5:
            displayLL();
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

node *getnode(int ctr){
    node *newnode;
    newnode = (node*)malloc(sizeof(node));
    printf("Enter the data in node %d : ",ctr);
    scanf(" %d",&newnode->data);

    newnode->next = NULL;
    return(newnode);
}

void createLL(int n){
    node *temp,*last;
    int ctr=0;
    while(ctr<n){
        temp = getnode(++ctr);
        if(start == NULL){
            start = temp;
        }
        else{
            last->next=temp;
        }
        last=temp;
    }
    
}

int countnode(){
    node *temp;
    temp=start;

    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return(count);  
}

void insertionLL(){
    int pos,value,nodectr,i=1;
    node *prev,*temp;
    prev = temp = start;
    nodectr = countnode();
    printf("\nEnter position of Insertion.\n1 is beginning and %d is last position.\nEnter here : ",nodectr+1);
    scanf(" %d",&pos);
    if(pos > 0 && pos <= nodectr+1){
        node *insertnode = getnode(pos);
        while(i < pos){
            prev = temp;
            temp = temp->next;            
            ++i;
        }
        if(pos == 1){
            insertnode->next = start;
            start = insertnode;
        }
        else{
            insertnode->next = prev->next;
            prev->next = insertnode;
        }
    }
    else{
        printf("\nInvalid Position of Insertion.");
    }

}

void deletionLL(){
    int delpos,nodectr,i=1;
    node *prev,*temp;
    prev = temp = start;
    nodectr = countnode();
    printf("\nEnter the position of Deletion.\n1 is beginning and %d is last position.\nEnter here : ",nodectr);
    scanf(" %d",&delpos);
    if(delpos > 0 && delpos <= nodectr){
        while(i<delpos){
            prev = temp;
            temp = temp->next;
            ++i;
        }
        if(delpos==1){
            start = temp->next;
        }
        else{
            prev->next = temp->next;
        }
        free(temp);

    }
    else{
        printf("\nInvalid Position of Deletion.");
    }


}

void displayLL(){
    node *temp;
    temp = start;
    if(start == NULL){
        printf("\n( START = %x ) -> NULL",start);
    }
    else{
        printf("\n( START = %x )",start);
        while(temp != NULL){
            printf(" -> [ %d | %x ]",temp->data,temp->next);
            temp = temp->next;
        }
    } 
}

void searchingLL(int value){
    node *temp;
    int ctr=0,flag=1;
    temp = start;
    
    while(temp != NULL){
        ++ctr;
        if( temp->data == value){
            printf("\n%d is present at node %d",value,ctr);
            flag=0;
        }
        temp = temp->next;
    }
    if(flag){
        printf("\n%d is not present in the Linked List.",value);
    }
}
