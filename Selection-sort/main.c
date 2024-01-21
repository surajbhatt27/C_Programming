//program of selection sort.

#include<stdio.h>

//function for selection sort.
void sorting(int arr[], int n)
{
   for (int i = 0; i < n-1; i++)
   {
    int min = i;
    for (int j = i+1; j < n; j++)
    {
        if (arr[j] < arr[min])
        {
            min = j;
        }
    }
    if (min != i)
    {
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
   } 
}

int main()
{
    int arr[] = {9, 3, 5, 1, 8, 4, 2, 7, 6};
    int size = sizeof(arr)/sizeof(arr[0]);
    sorting(arr, size);
    
    printf("Sorted array\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d  ",arr[i]);
    }

    return 0;
}