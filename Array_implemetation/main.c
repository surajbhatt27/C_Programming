//program to implement Array.
#include<stdio.h>

int main()
{
    int size;
    int arr[100];
    printf("Enter the size of the array: ");
    scanf("%d",&size);
    printf("Enter the array element: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("You have Entered : ");
    for (int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
    }
    
    return 0;
}