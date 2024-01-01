//program to delete element from the Linked List.

#include <stdio.h>
#include<stdlib.h>

    struct node
    {
     int data;
     struct node* next;
     struct node* prev;
    };
    struct node *head, *temp, *newnode, *tail;
 
//function for creating the list.   
void create()
{
  int num;
  head = NULL; 
  do
  {
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data: ");
    scanf("%d", &newnode -> data);
    newnode -> next = NULL;
    newnode -> prev = NULL;
    if(head == NULL)
    {
        head = tail = newnode;
    }
    else
    {
       tail -> next = newnode;
       newnode -> prev = tail;
       tail = newnode;
    }

    printf("Press 1 for another node: ");
    scanf("%d", &num);
    }while(num == 1); 
}

//function to display the list.
void display()
{
    temp = head;
    while(temp != 0)    
    {
        printf("%d  ", temp -> data);
        temp = temp -> next;
    }
}

//function for deletion from begining.
void delFromBeg()
{
    temp = head;
    head = temp -> next;
    head -> prev = NULL;
    free(temp);
}

//function for deletion from end.
void delFromEnd()
{
    temp = tail;
    tail = temp -> prev;
    tail -> next = NULL;
    free(temp);
}

//function for deletion from the specific position.
void delFromPos()
{
   int i = 1, pos;
   printf("Enter the postion for deletion : ");
   scanf("%d", &pos);
   temp = head;
   while(i < pos) 
   {
      temp = temp -> next;
      i++;
   }
   temp -> next -> prev = temp -> prev;
   temp -> prev -> next = temp -> next;
   free(temp);
}

//function to reverse the list.
void reverse()
{
  struct node *current, *nextnode;
  current = head;
  while(current != NULL)
  {
    nextnode = current -> next;
    current -> next = current -> prev;
    current -> prev = nextnode;
    current = nextnode;
  }
  current = head;
  head = tail;
  tail = head;
}

int main()
{
    int a,  choice;
    printf("Let's create doubly list first : ");
    create();

    do
    {
       printf("Enter :\n1.deletion from beggning.\n2.deletion from end\n3.deletion from specific position\n4.reverse the list.\n>> ");
       scanf("%d", &choice);
    
        switch (choice)
        {
        case 1:
          delFromBeg();
          break;
        case 2:
          delFromEnd();
          break;
        case 3: 
          delFromPos();
          break;
        case 4:
          reverse();
          break;
    }
      printf("Enter 1 for more operation : ");
      scanf("%d", &a);
    } while (a == 1);

    printf("The list after operation is : ");
    display();
    
    return 0;
}