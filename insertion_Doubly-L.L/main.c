//insertion in doubly Linked List.

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

//function for insertion at begining.
void insertAtBeg()
{
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data: ");
    scanf("%d", &newnode -> data);
    newnode -> prev = NULL;
    head -> prev = newnode;
    newnode -> next = head;
    head = newnode;
}

//function for insertion at end.
void insertAtEnd()
{
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data: ");
    scanf("%d", &newnode -> data);
    newnode -> next = NULL; 
    tail -> next = newnode;
    newnode -> prev = tail;
    tail = newnode; 
}

//function for insertion at the specific position.
void insertAtPos()
{
    int i = 1, pos;
    printf("Enter the postion for insertion : ");
    scanf("%d", &pos);
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data: ");
    scanf("%d", &newnode -> data);
    temp = head;
    while(i < pos -1)
    {
       temp = temp -> next;
       i++;
    }
    newnode -> prev = temp;
    newnode -> next = temp -> next;
    temp -> next -> prev = newnode;
    temp -> next = newnode;
}

//function for insertion after the position.
void insertAfterPos()
{
      int i = 1, pos;
    printf("Enter the postion for insertion : ");
    scanf("%d", &pos);
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data: ");
    scanf("%d", &newnode -> data);
    temp = head;
    while(i < pos )
    {
       temp = temp -> next;
       i++;
    }
    newnode -> prev = temp;
    newnode -> next = temp -> next;
    temp -> next -> prev = newnode;
    temp -> next = newnode; 
}

int main()
{
    int num,  choice;
    printf("Let's create doubly list first : ");
    create();

    do
    {
       printf("Enter :\n1.insertion at beggning.\n2.insertion at end\n3.insertion at specific position\n4.insertion after postion.\n>> ");
       scanf("%d", &choice);
    
        switch (choice)
        {
        case 1:
          insertAtBeg();
          break;
        case 2:
          insertAtEnd();
          break;
        case 3: 
          insertAtPos();
          break;
        case 4: 
          insertAfterPos();
          break;
    }
      printf("Enter 1 for more operation : ");
      scanf("%d", &num);
    } while (num == 1);

    printf("The list after operation is : ");
    display();
    
    return 0;
}