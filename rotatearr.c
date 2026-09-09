#include <stdio.h>
void rev(int a[],int start,int end){
    int temp;
    while(start<end){
        temp=a[start];
        a[start]=a[end];
        a[end]=temp;
        start++;
        end--;
    }
}
int main(){
    int a[100],n,k,i;
    printf("Enter the number of elements in array:");
    scanf("%d",&n);
    printf("Enter the %d elements of array:",n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter the value of k:");
    scanf("%d",&k);
    k=k%n;
    rev(a,0,k-1);
    rev(a,k,n-1);
    rev(a,0,n-1);
    printf("Array after left roatation by %d positions:",k);
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}
