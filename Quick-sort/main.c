//program of Quick sort.

#include<stdio.h>

int partition(int arr[], int lb, int ub)
{
    int pivot = arr[lb];
    int start = lb;
    int end = ub;
    while (start < end)
    {
        while (arr[start] <= pivot)
        {
            start++;
        }
        while (arr[end] > pivot)
        {
            end--;
        }
        if (start < end)
        {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }
    int temp = arr[lb];
    arr[lb] = arr[end];
    arr[end] = temp;

    return end;
}

//function for Quick sort.
void sorting(int arr[], int lb, int ub)
{
  if (lb < ub)
  {
    int loc = partition(arr, lb, ub);
    sorting(arr, lb, loc-1);
    sorting(arr, loc+1, ub);
  }
  
}

int main()
{
    int arr[] = {9, 3, 5, 1, 8, 4, 2, 7, 6};
    int size = sizeof(arr)/sizeof(arr[0]);
    sorting(arr, 0, size-1);
    
    printf("Sorted array\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d  ",arr[i]);
    }

    return 0;
}