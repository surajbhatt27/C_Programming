//program to delete element from the array.

#include <stdio.h>

int main()
{
    int arr[50], size, pos;
    
    printf("Enter the size of the array : ");
    scanf("%d",&size);
    printf("Enter the element of the array : ");
    
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the index of the element you want to delete : ")    ;
    scanf("%d",&pos);
    
    if(pos < 0 || pos >= size){
        printf("Invalid position to delete \n");
    }
    
    else 
    { 
        for(int j = pos; j < size; j++)
        {
        arr[j] = arr[j+1];
        }
    
        size--;
    
        printf("New array is : ");
    
        for(int k = 0; k < size; k++)
        {
          printf("%d  ", arr[k]);
        }
        printf("\n");
    }
    
    return 0;
}