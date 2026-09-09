#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push function
void push(char ch)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        stack[top] = ch;
    }
}

// Pop function
char pop()
{
    if (top == -1)
    {
        return '\0';
    }
    else
    {
        return stack[top--];
    }
}

int main()
{
    char str[MAX];
    int i;

    printf("Enter any string: ");
    fgets(str, MAX, stdin);

    // Push each character into stack
    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] != '\n')
            push(str[i]);
    }

    // Pop characters to reverse
    printf("Reversed string: ");

    while (top != -1)
    {
        printf("%c", pop());
    }

    return 0;
}