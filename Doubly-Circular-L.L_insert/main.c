//program of insertion in the doubly circular linked list.

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

//function to insert at the beggining.
void insertBeg()
{
   newnode = (struct node*)malloc(sizeof(struct node));
   printf("Enter the data: ");
   scanf("%d", &newnode -> data);
   tail -> next = newnode;
   newnode -> prev = tail;
   newnode -> next = head;
   head -> prev = newnode;
   head = newnode;
}

//function to insert at the end.
void insertEnd()
{
   newnode = (struct node*)malloc(sizeof(struct node));
   printf("Enter the data: ");
   scanf("%d", &newnode -> data);
   newnode -> prev = tail;
   newnode -> next = head;
   tail -> next = newnode;
   tail = newnode;
   head -> prev = newnode;
}

//function to insert at the specific position.
void insertPos()
{
   int i = 1, pos;
   struct node *current, *nextnode;
   newnode = (struct node*)malloc(sizeof(struct node));
   printf("Enter the data: ");
   scanf("%d", &newnode -> data);
   printf("Enter the postion: ");
   scanf("%d", &pos);
   current = head;
   while (i < pos-1)
   {
      current = current -> next;
      i++;
   }
   nextnode = current -> next;
   newnode -> prev = current;
   newnode -> next = nextnode;
   current -> next = newnode;
   nextnode -> prev = newnode;
}

int main()
{
   int choice, a;
   printf("Let's create the linked list first.\n");
   create();
   do
   {
      printf("Enter.\n1.insert at the begin.\n2.insert at the end.\n3.insert at the specific position.\n>> ");
      printf("Enter your choice: ");
      scanf("%d", &choice);
      switch (choice)
      {
      case 1:
         insertBeg();
         break;
      case 2:
         insertEnd();
         break;
      case 3:
         insertPos();
         break;
      }
      printf("Enter 1 for more option: ");
      scanf("%d", &a);
   } while (a == 1);
   
   printf("The list is : ");
   display();

   return 0;
}