//program to insert element in array.

#include<stdio.h>

int main()
{
    int arr[50], size, pos,key;

    printf("Enter the size of the array : ");
    scanf("%d",&size);
    printf("Enter the element of the array : ");

    for(int i = 0; i < size ; i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("Enter the index (starting with 0) where you want to insert the element : ");
    scanf("%d",&pos);
    printf("Enter the element you want to insert : ");
    scanf("%d",&key);

    for (int j = size; j >= pos; j--){
        arr[j+1] = arr[j];
    }

    arr[pos] = key;
    size++;
    printf("The new array is : ");

    for(int k = 0; k < size; k++){
        printf("%d  ",arr[k]);
    }
    return 0;
}