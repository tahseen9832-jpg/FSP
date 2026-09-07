#include <stdio.h>
int main(){
    char s[20],result[20];
    int depth=0,j=0,i;
    printf("Enter any string:");
    gets(s);
    int n=strlen(s);
    for(i=0;i<n;i++){
        if(s[i]=='('){
            if(depth>0){
                result[j++]=s[i];
                depth++;
            }
            else{
                depth--;
                if(depth>0){
                    result[j++]=s[i];
                }
            }
        }
}
result[j]='\0';
puts(result);