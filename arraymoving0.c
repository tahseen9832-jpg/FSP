#include <stdio.h>
int main(){
    int a[10],n,i;
    printf("Enter the number of elements in array:");
    scanf("%d",&n);
    printf("Enter the %d elements of array:",n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int j=0;
    for(i=0;i<n;i++){
        if(a[i]!=0){
            a[j]=a[i];
            
        }
    int temp=a[i];a[i]=a[j];a[j]=temp;j++;
    }
    printf("Array after moving all the zeros to the end:");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}