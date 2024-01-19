//program for linear search.

#include<stdio.h>

int main(){

   int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
   int key, flag, index;

   printf("Enter the value you wnat to search : ");
   scanf("%d",&key);

   for (int i = 0; i < 10; i++)
   {
      flag = 0;

      if (arr[i] == key)
      {
         flag++;
         index = i;
         break;
      }
      
   }

   if (flag == 0)
   {
      printf("NOt found");
   }

   else{
      printf("Element found at index %d",index);
   }
   return 0;
}