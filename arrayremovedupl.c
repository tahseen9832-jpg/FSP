#include <stdio.h>
int main(){
    int a[10],n,i;
    int freq[10]={0};
    printf("Enter the number of elements in array:");
    scanf("%d",&n);
    printf("Enter the %d elements of array:",n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Array after removing the duplicates:");
    for(i=0;i<n;i++){
        if(freq[a[i]]==0){
            printf("%d ",a[i]);
            freq[a[i]]=1;
        }
    }
    return 0;
}