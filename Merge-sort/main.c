//program of Merge sort.

#include<stdio.h>

int merge(int arr[], int lb, int mid, int ub)
{
    int arr1[50];
    int i = lb;
    int j = mid + 1;
    int k = lb;
    while (i <= mid && j <= ub)
    {
        if (arr[i] <= arr[j])
        {
            arr1[k] = arr[i];
            i++;
        }
        else
        {
            arr1[k] = arr[j];
            j++;
        }
        k++;
    }
    if (i > mid)
    {
        while (j <= ub)
        {
            arr1[k] = arr[j];
            j++;
            k++;
        }
    }
    else
    {
        while (i <= mid)
        {
            arr1[k] = arr[i];
            i++;
            k++;
        }  
    }
    for (int k = lb; k <= ub; k++)
    {
        arr[k] = arr1[k];
    }
}

//function for Merge sort.
void sorting(int arr[], int lb, int ub)
{
  if (lb < ub)
  {
    int mid = (lb + ub)/2;
    sorting(arr, lb, mid);
    sorting(arr, mid+1, ub);
    merge(arr, lb, mid, ub);
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