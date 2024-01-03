//implementation of the doubly circular linked list.

#include<stdio.h>
#include<stdlib.h>

struct node
{
   int data;
   struct node *next;
   struct node *prev;
};
struct node *head, *tail, *temp, *newnode;

//function for creating the list.
void create()
{
   int a;
   head = NULL;
   do
   {
      newnode = (struct node*)malloc(sizeof(struct node));
      printf("Enter the data: ");
      scanf("%d", &newnode -> data);
      if (head == NULL)
      {
         head = tail = newnode;
         head -> prev = newnode;
         head -> next = newnode;
      }
      else
      {
      newnode -> prev = tail;
      tail -> next = newnode;
      newnode -> next = head;
      head -> prev = newnode;
      tail = newnode;
      } 
      printf("Enter the 1 for more node: ");
      scanf("%d", &a);
   } while (a == 1); 
}

//function for displaying the list.
void display()
{
   temp = head;
   while (temp != tail)
   {
      printf("%d  ",temp -> data );
      temp = temp -> next;
   }
   printf("%d ", temp -> data);
}

int main()
{
    printf("Let's create a list first: \n");
    create();
    printf("The list is: ");
    display();
    return 0;
}