#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;


void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    printf("Deleted node with value %d from beginning.\n", temp->data);
    free(temp);
}


void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    struct Node* temp = head;
    struct Node* prev = NULL;
     if (temp->next == NULL) {
        printf("Deleted node with value %d from end.\n", temp->data);
        free(temp);
        head = NULL;
        return;
    }
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    printf("Deleted node with value %d from end.\n", temp->data);
    prev->next = NULL;
    free(temp);
}


void deleteAtPosition() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    int pos, i;
    printf("Enter the position to delete: ");
    scanf("%d", &pos);
   if (pos <= 0) {
        printf("Invalid position.\n");
        return;
    }
    struct Node* temp = head;
    struct Node* prev = NULL;
    if (pos == 1) {
        head = head->next;
        printf("Deleted node with value %d from position 1.\n", temp->data);
        free(temp);
        return;
    }
    for (i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }
    prev->next = temp->next;
    printf("Deleted node with value %d from position %d.\n", temp->data, pos);
    free(temp);
}


void displayList() {
    struct Node* temp = head;

    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main() {
    int choice, value, pos;

    while (1) {
        printf("\n----- MENU -----\n");
        printf("1. Insert at End\n");
        printf("2. Delete at Beginning\n");
        printf("3. Delete at End\n");
        printf("4. Delete at Position\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
                if (newNode == NULL) {
                    printf("Memory allocation failed.\n");
                    break;
                }
                printf("Enter value to insert: ");
                scanf("%d", &value);
                newNode->data = value;
                newNode->next = NULL;

                if (head == NULL) {
                    head = newNode;
                } else {
                    struct Node* temp = head;
                    while (temp->next != NULL)
                        temp = temp->next;
                    temp->next = newNode;
                }
                printf("Node inserted at end.\n");
                break;
            }

            case 2:
                deleteAtBeginning();
                break;

            case 3:
                deleteAtEnd();
                break;

            case 4:
                deleteAtPosition();
                break;

            case 5:
                displayList();
                break;

            case 6:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}