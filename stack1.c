#include <stdio.h>
#include <stdlib.h>

#define MAX 100  

struct Stack {
    int items[MAX];
    int top;
};

void initStack(struct Stack *s) {
    s->top = -1;
}

int isFull(struct Stack *s) {
    return s->top == MAX - 1;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

void push(struct Stack *s, int value) {
    if (isFull(s)) {
        printf("Error: Stack Overflow! Reached maximum limit of %d items.\n", MAX);
    } else {
        s->top++;
        s->items[s->top] = value;
        printf("%d pushed onto stack.\n", value);
    }
}

int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Error: Stack Underflow! Stack is empty.\n");
        return -1;
    } else {
        int poppedValue = s->items[s->top];
        s->top--;
        printf("%d popped from stack.\n", poppedValue);
        return poppedValue;
    }
}


int peek(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is currently empty.\n");
        return -1;
    } else {
        printf("Top element: %d\n", s->items[s->top]);
        return s->items[s->top];
    }
}

void display(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("\n--- Stack Contents (Top to Bottom) ---\n");
    for (int i = s->top; i >= 0; i--) {
        printf("[%d] -> %d\n", i, s->items[i]);
    }
    printf("-------------------------------------\n");
}

int main() {
    struct Stack s;
    initStack(&s);
    int choice, val;

    while (1) {
        printf("\n--- Stack Menu (Max: %d) ---\n", MAX);
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);
                push(&s, val);
                break;
            case 2:
                pop(&s);
                break;
            case 3:
                peek(&s);
                break;
            case 4:
                display(&s);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}