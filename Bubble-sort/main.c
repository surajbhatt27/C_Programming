//program of bubble sort.

#include<stdio.h>

//function for bubble sort.
void sorting(int arr[], int n)
{
    int temp;
    for (int i = 0; i < n-1; i++)
    {
        int flag = 0;
        for (int j = 0; j < n-1-i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
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