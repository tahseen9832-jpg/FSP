#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
}; struct Node* head=NULL;
void createNode(){
    int value;
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
      if(newNode==NULL){
        printf("Memory allocation failed\n");
        return;
      }
    printf("Enter data:");
    scanf("%d",&value);
    newNode->data=value;
    newNode->next=NULL;
    if(head==NULL){
        head=newNode;
    }else{
        
        struct Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
    printf("Node with data %d created successfully\n",value);
}
void displayList(){
    if(head==NULL){
        printf("The List is empty\n");
        return;
    }
    struct Node* temp=head;
    printf("Linked List: ");
    while(temp!=NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
int main(){
    int choice;
    while(1){
        printf("\n------ Menu ---\n");
        printf("1. Create Node\n");
        printf("2. Display List\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                createNode();
                break;
            case 2:
                displayList();
                break;
            case 3:
                printf("Exiting program\n");
                exit(0);
            default:
                printf("Invalid choice.Try again\n");
        }
    }
    return 0;
}
    