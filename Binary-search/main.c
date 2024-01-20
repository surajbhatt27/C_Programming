//program for binary search.

#include<stdio.h>

void binarySearch(int arr[], int key, int size)
{
   int start = 0, end = size - 1, mid;
   while (start <= end)
   {
    mid = (start + end)/2;
    if (key == arr[mid])
    {
        printf("%d is found at index %d",key,mid);
        return;
    }
    else if (key < arr[mid])
    {
        end = mid - 1;
    }
    else
    {
        start = mid + 1;
    }
   }
   printf("Not found\n");
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int key, size;
    size = sizeof(arr)/sizeof(arr[0]);
    printf("Enter the element you want to search: ");
    scanf("%d", &key);
    binarySearch(arr, key, size);
    return 0;
}