//program to insert element in singly linked list.

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

//function to insert element at beginnig.

void insertBeg()
{
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("enter the data: ");
    scanf("%d", &newnode -> data);
    newnode -> next = head;
    head = newnode;
}

//function to insert element at end.

void insertEnd()
{
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("enter the data: ");
    scanf("%d", &newnode -> data);
    newnode -> next = NULL;
    temp = head;
    while (temp -> next != NULL)
    {
        temp = temp -> next;
    }
    temp -> next = newnode;
}

//function to insert at the end.

void inserAtPos()
{
    int pos, i = 1;
    printf("Enter the postion : ");
    scanf("%d",&pos);
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("enter the data: ");
    scanf("%d", &newnode -> data);
    temp = head;
    while (i < pos -1)
    {
       temp = temp -> next;
       i++;
    }
    newnode ->next = temp ->next;
    temp -> next = newnode; 
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
        printf("Enter\n1.insertion at beginning\n2.insertion at end\n3.insertion at given position.\n>>> ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            insertBeg();
            break;
        case 2:
            insertEnd();
            break;
        case 3:
            inserAtPos();
        default:
            printf("Invalid choice.\n");
            break;
        }
        printf("Press 1 for insert again.\n");
        scanf("%d",&num1);
    } while (num1 == 1);
    
    printf("The list after insertion is: ");
    display();
   return 0;
}