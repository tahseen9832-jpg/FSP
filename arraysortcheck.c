#include <stdio.h>
int main(){
    int n ,i,sorted=1;
    printf("Enter the size of array:");
    scanf("%d",&n);

    int array[n];
    printf("Enter the elements of array:");
    for(i=0;i<n;i++){
        scanf("%d",&array[i]);
    
    }

    for(i=0;i<n-1;i++){
        if(array[i]>array[i+1]){
            sorted=0;
            break;
        }
    }
    if(sorted==1){
        printf("The array is sorted");
    }
    else{
        printf("The array is not sorted");
    }
}