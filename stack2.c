#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int value)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = top;
    top = newNode;

    printf("%d pushed into stack.\n", value);
}
void pop()
{
    struct Node *temp;

    if (top == NULL)
    {
        printf("Stack Underflow!\n");
    }
    else
    {
        temp = top;
        printf("%d popped from stack.\n", top->data);
        top = top->next;
        free(temp);
    }
}


void peek()
{
    if (top == NULL)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Top element is: %d\n", top->data);
    }
}
void display()
{
    struct Node *temp;

    if (top == NULL)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        temp = top;

        printf("Stack elements are:\n");

        while (temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}
int main()
{
    int choice, value;

    while (1)
    {
        printf("\n--- STACK USING LINKED LIST ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}