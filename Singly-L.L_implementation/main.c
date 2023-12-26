//program to implement singly linked list.

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head = NULL, *newnode, *temp;

//function to create the list.

void create()
{
    int num;
    do 
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("enter the data: ");
        scanf("%d", &newnode -> data);
        newnode -> next = NULL;
        if(head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp -> next = newnode;
            temp = newnode;
        }
        printf("Enter 1 for another node: ");
        scanf("%d", &num);
    }while(num == 1);
  
}

//function to display the list.

void display()
{
  temp = head;
  while (temp != NULL)
  {
    printf("%d  ",temp -> data);
    temp = temp -> next;
  }
   
}

int main()
{
    printf("Let's create a list \n");
    create();
    printf("The list is: ");
    display();
   return 0;
}