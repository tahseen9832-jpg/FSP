#include <stdio.h>

int main()
{
    int n, i, secondmax, max;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    max = arr[0];
    secondmax = arr[0];
    for(i = 1; i < n; i++)
    {
        if(arr[i] > max)
        {
            secondmax = max;
            max = arr[i];
        }else if(arr[i] > secondmax && arr[i] != max)
        {
            secondmax = arr[i];
        }
    }
    printf("Second maximum element = %d", secondmax);

    return 0;
}