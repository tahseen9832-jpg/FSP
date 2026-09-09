#include <stdio.h>
int maxconsecutiveOnes(int arr[], int n) {
    int count = 0, maxCount = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            count++;
            if (count > maxCount) {
                maxCount = count;
            }
        } else {
        count = 0;
        }
    }
    return maxCount;
}
int main(){
    int arr[10], n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements (0s and 1s): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int result = maxconsecutiveOnes(arr, n);
    printf("The Maximum consecutive 1s: %d\n", result);
    return 0;
}