//program to delete element in singly linked list.

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

//function to delete element from beginnig.

void deletionBeg()
{
    temp = head;
    head = temp -> next;
    free(temp);
}

//function to insert element at end.

void deletionEnd()
{
    struct node *prevNode;
    temp = head;
    while (temp -> next != NULL)
    {
        prevNode = temp;
        temp = temp ->next;
    }
    prevNode -> next = NULL;
    free(temp);
}

//function to insert at the end.

void deleteAtPos()
{
    struct node *nextNode;
    int pos, i = 1;
    printf("Enter the postion : ");
    scanf("%d",&pos);
    temp = head;
    while (i < pos -1)
    {
       temp = temp -> next;
       i++;
    }
    nextNode = temp -> next;
    temp -> next = nextNode -> next;
    free(nextNode);
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
    int num1, choice;
    printf("Let's create a list first\n");
    create();
    do
    {
        printf("Enter\n1.deletion from beginning\n2.deletion from end\n3.deletion from given position.\n>>> ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            deletionBeg();
            break;
        case 2:
            deletionEnd();
            break;
        case 3:
            deleteAtPos();
            break;
        default:
            printf("Invalid choice.\n");
            break;
        }
        printf("Press 1 for deletion again.\n");
        scanf("%d",&num1);
    } while (num1 == 1);
    
    printf("The list after deletion is: ");
    display();
   return 0;
}