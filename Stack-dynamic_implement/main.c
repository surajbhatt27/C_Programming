//program to implement stack using linked list.

#include<stdio.h>
#include<stdlib.h>
struct node 
{
   int data;
   struct node * next;
};
struct node *top = NULL, *temp;

//function to push element in stack.
void push()
{
   struct node * newnode;
   newnode = (struct node*)malloc(sizeof(struct node));
   printf("Enter the data: ");
   scanf("%d", &newnode -> data);
   newnode -> next = top;
   top = newnode;
}

//function to pop element from stack.
void pop()
{
  temp = top;
  if (top == NULL)
  {
    printf("Stack is empty\n");
  }
  else
  {
    top = top -> next;
    printf("%d is deleted", temp -> data);
    free(temp);
  }
}

//function to find peek element.
void peek()
{
   if (top == NULL)
   {
      printf("Stack is empty");
   }
   else
   {
      printf("%d is peek", top -> data);
   }
}

//function to display.
void display()
{
   temp = top;
   if (top == NULL)
   {
      printf("Stack is empty");
   }
   else
   {
     while (temp != NULL)
     {
       printf("%d ",temp -> data);
       temp = temp -> next;
     }
   } 
   printf("\n");
}
int main(){
   int choice, a;
   do
   {
      printf("Enter\n1.Push\n2.pop\n3.peep\n4.display\n>> ");
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
      }
      printf("Press 1 for repeat the operation : ");
      scanf("%d", &a);
   } while (a == 1);

   return 0;
}