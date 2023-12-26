//program to reverse the array.

#include<stdio.h>

int main()
{
    int arr[] = {1,2,3,4,5,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    int i = 0, j = size-1, temp;

    while (i < j)
    {
        temp = arr[i];
        arr[i]= arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
    
    printf("Reversed array is: ");

    for (int k = 0; k < size; k++)
    {
        printf("%d  ",arr[k]);
    }
     
  return 0;
}