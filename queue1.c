#include <stdio.h>
#define MAX 5
int queue[MAX];
int front = -1;
int rear = -1;
void enqueue()
{
    int value;
    printf("Enter value to insert: ");
    scanf("%d", &value);
     if ((rear + 1) % MAX == front)
    {
        printf("Circular Queue Overflow!\n");
        return;
    }
    if (front == -1)
    {  front = 0;  rear = 0;    }
    else
    {     rear = (rear + 1) % MAX;    }

    queue[rear] = value;

    printf("%d inserted successfully.\n", value);
}
void dequeue()
{
    int value;
  if (front == -1)
    {   printf("Circular Queue Underflow!\n");   return;    }
    value = queue[front];
    printf("%d deleted successfully.\n", value);
   if (front == rear)
    {  front = -1;        rear = -1;    }
    else
    {        
        front = (front + 1) % MAX;
    }
}
void peek()
{
    if (front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Front element = %d\n", queue[front]);
}
void display()
{
    int i;
    if (front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Circular Queue: ");
    i = front;
    while (1)
    {
        printf("%d ", queue[i]);
       if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}
void count()
{
    int i;
    int count = 0;

    if (front == -1)
    {
        printf("Number of elements = 0\n");
        return;
    }
    i = front;
    while (1)
    {
        count++;

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }
    printf("Number of elements = %d\n", count);
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n");
        printf("=================================\n");
        printf("       CIRCULAR QUEUE MENU\n");
        printf("=================================\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Count\n");
        printf("6. Exit\n");
        printf("=================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                count();
                break;
            case 6:
                printf("Program terminated.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
