#include <stdio.h>
#define MAX=100
int stack[MAX];
int top=-1;
void push(int value){
    stack[++top]=value;
}
int pop(){
    return stack[top--];
}
int main(){
    char postfix[MAX];
    int i,a,b,result;
    printf("Enter the postfix expression:");
    scanf("%s",postfix);
    for(i=0;postfix[i]!='\0'; i++){
        if(isdigit(postfix[i])){
            push(postfix[i]-'0');
        }
        else{
            b=pop();
            a=pop();
            switch(postfix[i]){
                case '+':
                    result=a+b;
                    break;
                case '-':
                    result=a-b;
                    break;
                case '*':
                    result=a*b;
                    break;
                case '/':
                    result=a/b;
                    break;
            }
            push(result);
        }
}