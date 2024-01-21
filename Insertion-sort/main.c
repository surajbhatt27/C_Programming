//program of insertion sort.

#include<stdio.h>

//function for insertion sort.
void sorting(int arr[], int n)
{
    int temp;
    for (int i = 1; i < n; i++)
    {
        temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
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