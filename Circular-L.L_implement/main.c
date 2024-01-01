//Implementation of circular linked list.

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *temp, *newnode, *tail;

//function to create a list.
void create()
{
  int a;
  tail = NULL;
  do
  {
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newnode -> data);
    if(tail == NULL)
    {
        tail = newnode;
        tail -> next = newnode;
    }
    else
    {
        newnode -> next = tail -> next;
        tail -> next = newnode;
    }
    tail = newnode;
    printf("Enter 1 for adding another node: ");
    scanf("%d", &a);
  }while(a == 1);
}

//function to display list.
void display()
{
    temp = tail -> next;
    do
    {
        printf("%d ", temp -> data);
        temp = temp -> next;
    } while (temp != tail -> next);
}

int main()
{
   printf("Let's create a Circular Linked list \n");
   create();
   printf("The list is : ");
   display();
}