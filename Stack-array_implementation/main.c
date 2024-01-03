//program to implement stack using array.

#include<stdio.h>
#include<stdlib.h>
int stack[5];
int top = -1;

//function to push element in the stack.
void push()
{
   int num;
   printf("Enter the element: ");
   scanf("%d", &num);
   if (top == 4)
   {
      printf("Stack is full");
   }
   else
   {
      top++;
      stack[top] = num;
   } 
}

//function to pop element from stack.
void pop()
{
   if (top == -1)
   {
      printf("Stack is empty\n");
   }
   else
   {
     int item;
     item = stack[top];
     top--;
     printf("item %d poped\n", item);
   }
}

//function to find peek element.
void peek()
{
   if (top == -1)
   {
      printf("Stack is empty\n");
   }
   else
   {
      printf("%d\n",stack[top]);
   }
}

//function to display stack.
void display()
{
   int i;
   for(i = top; i >= 0; i--)
   {
      printf("%d  ", stack[i]);
   }
}

//function to check if stack full.
void isEmpty()
{
   if(top == -1)
      printf("True\n");
   else
      printf("False\n");
}

//function to check if stack empty.
void isFull()
{
   if(top == 4)
      printf("True\n");
   else
      printf("False\n");
}

int main(){
   int choice, a;
   do
   {
      printf("Enter\n1.Push\n2.pop\n3.peek\n4.display\n5.check if stack empty\n6.check if stack full\n>> ");
      scanf("%d", &choice);
      switch (choice)
      {
      case 1:
         push();
         break;
      case 2:
         pop();
         break;
      case 3:
         peek();
         break;
      case 4:
         display();
         break;
      case 5:
         isEmpty();
         break;
      case 6: 
         isFull();
         break;
      }
      printf("\nPress 1 for repeat the operation : ");
      scanf("%d", &a);
   } while (a == 1);
   return 0;
}