//program to implement 2D Array.

#include <stdio.h>

int main()
{
    int a[2][3];
    printf("Enter the element of the array: ");

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            scanf("%d", &a[i][j]);
        }
    }

    printf("you entered: ");
    
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", a[i][j]);
        }
    }

    return 0;
}