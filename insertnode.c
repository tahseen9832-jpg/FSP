#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;


void insertAtBeginning() {
    int value;
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter the data: ");
    scanf("%d", &value);
    newnode->data = value;
    newnode->next = head;
    head = newnode;
    printf("Node with data %d inserted at beginning.\n", value);
}


void insertAtEnd() {
    int value;
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter data: ");
    scanf("%d", &value);
    newnode->data = value;
    newnode->next = NULL;
    
    if (head == NULL) {
        head = newnode;
    } else {
        struct node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
    printf("Node with data %d inserted at end.\n", value);
}


void insertAtPosition() {
    int value, position, count = 1;
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    printf("Enter data: ");
    scanf("%d", &value);
    printf("Enter position (1-based): ");
    scanf("%d", &position);
    
    newnode->data = value;
    
    
    if (position == 1) {
        newnode->next = head;
        head = newnode;
        printf("Node with data %d inserted at position %d.\n", value, position);
        return;
    }
    

    struct node* temp = head;
    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }
    
    
    if (temp == NULL) {
        printf("Invalid position! List has only %d nodes.\n", count);
        free(newnode);
        return;
    }
    
    newnode->next = temp->next;
    temp->next = newnode;
    printf("Node with data %d inserted at position %d.\n", value, position);
}


void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int ch;
    while (1) {
        printf("\n----MENU----\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        
        switch (ch) {
            case 1:
                insertAtBeginning();
                break;
            case 2:
                insertAtEnd();
                break;
            case 3:
                insertAtPosition();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}