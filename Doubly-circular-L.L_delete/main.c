//program of delete element form the doubly circular linked list.

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

//function to delete from the beggining.
void deleteBeg()
{
  temp = head;
  head = temp -> next;
  head -> prev = tail;
  tail -> next = head;
  free(temp);
}

//function to delete from the end.
void deleteEnd()
{
   temp = tail;
   tail = temp -> prev;
   tail -> next = head;
   head -> prev = tail;
   free(temp);
}

//function to delete form the specific position.
void deleteFromPos()
{
   int i = 1, pos;
   printf("Enter the postion: ");
   scanf("%d", &pos);
   temp = head;
   while (i < pos)
   {
      temp = temp -> next;
      i++;
   }
   temp -> prev -> next = temp -> next;
   temp -> next -> prev = temp -> prev;
   free(temp);
}

int main()
{
   int choice, a;
   printf("Let's create the linked list first.\n");
   create();
   do
   {
      printf("Enter.\n1.delete from the begin.\n2.delete from the end.\n3.delete from the specific position.\n>> ");
      printf("Enter your choice: ");
      scanf("%d", &choice);
      switch (choice)
      {
      case 1:
        deleteBeg();
        break;
      case 2:
        deleteEnd();
        break;
      case 3:
        deleteFromPos();
        break;
      }
      printf("Enter 1 for more operation: ");
      scanf("%d", &a);
   } while (a == 1);
   
   printf("The list is : ");
   display();

   return 0;
}