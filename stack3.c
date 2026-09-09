#include <stdio.h>
#include <string.h>

#define MAX 100
char stack[MAX];
int top = -1;
void push(char ch){
    stack[++top] = ch;
}
char pop(){
    return stack[top--];
}
int main(){
    char str[MAX];
    printf("Enter a string: ");
    scanf("%s", str);
    int len = strlen(str);
    for(int i=0; i<len; i++){
        push(str[i]);
    }
    printf("Reversed string: ");
    for(int i=0; i<len; i++){
        printf("%c", pop());
    }
    printf("\n");
    return 0;
}
