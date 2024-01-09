//program to implement the Priority Queue using Linked List.
#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    int priority;
    struct node *next;
};
struct node *head = NULL, *temp;

//function to enqueue element.
void enqueue()
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newnode -> data);
    printf("Enter the priority: ");
    scanf("%d", &newnode -> priority);
    newnode -> next = NULL;
    if (head == NULL)
    {
        head = newnode;
    }
    else if (head -> priority < newnode -> priority)
    {
        newnode -> next = head;
        head = newnode;
    }
    else
    {
        temp = head;
        while (temp -> next != NULL && temp -> priority > newnode -> priority)
        {
            temp = temp -> next;
        }
        newnode -> next = temp -> next;
        temp -> next = newnode;
    }
}

//function to dequeue element.
void dequeue()
{
    temp = head;
    if (head == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        head = temp -> next;
        free(temp);
    }
}

//function to display the Queue.
void display()
{
    temp = head;
    while (temp != NULL)
    {
        printf("|element = %d and priority = %d |", temp -> data, temp -> priority);
        printf("\n");
        temp = temp -> next;
    }
    printf("\n");
}

int main()
{
    int a, choice;
    do
    {
       printf("Enter :\n1.enqueue an element.\n2.dequeue an element.\n3.display.\n>> ");
       scanf("%d", &choice);
    
        switch (choice)
        {
        case 1:
          enqueue();
          break;
        case 2:
          dequeue();
          break;
        case 3:
          display();
          break;
    }
      printf("\nEnter 1 for more operation : ");
      scanf("%d", &a);
    } while (a == 1);
   
    return 0;
}