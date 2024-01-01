//program to reverse  Doubly Linked list.

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
    while(temp != NULL)    {
        printf("%d  ", temp -> data);
        temp = temp -> next;
    }
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
    int choice;
    printf("Let's create doubly list first : ");
    create();

    printf("The list is : ");
    display();

    reverse();
    printf("\nReversed list is : ");
    display();
    
    return 0;
}