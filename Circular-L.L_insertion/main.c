//program for insertion in the Circular linked list.

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};
struct node *tail, *newnode, *temp;

//function to count the length of the list.
int length()
{
    int count = 0;
    temp = tail;
    do
    {
         temp = temp -> next;
        count++;
    } while (temp != tail);
    return count;
}

//creation of circular linked list.
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

//function to display the list.
void display()
{
    temp = tail -> next;
    do
    {
        printf("%d ", temp -> data);
        temp = temp -> next;
    } while (temp != tail -> next);
}

//function for insertion at begnning.
void insertAtBeg()
{
  newnode = (struct node*)malloc(sizeof(struct node));
  printf("Enter the data: ");
  scanf("%d", &newnode -> data); 
  newnode -> next = tail -> next;
  tail -> next = newnode;
}

//function for insertion at the end.
void insertAtEnd()
{
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newnode -> data);
    newnode -> next = tail -> next;
    tail -> next = newnode;
    tail = newnode;
}

//function for insertion at the specific postion. 
void insertAtPos()
{
    int pos, i = 1, l;
    printf("Enter the value of position: ");
    scanf("%d", &pos);
    l = length();
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newnode -> data);
    newnode -> next = 0;
    if(pos == 1)
    {
        insertAtBeg();
    }
    else if(pos == l)
    {
        insertAtEnd();
    }
    else
    {
        temp = tail -> next;
        while (i < pos -1)
        {
            temp = temp -> next;
            i++;
        }
        newnode -> next = temp -> next;
        temp -> next = newnode;
    }
}

int main()
{
    int num, choice, p;
    printf("Let's create a list first: \n");
    create();
    do
    {
       printf("Enter:\n1.insert at beginning.\n2.insert at end.\n3.insertat at specific position.\n>> ");
       scanf("%d",&choice);

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
       }
       printf("Enter 1 for more operations: \n");
       scanf("%d", &num);

    } while (num == 1);
    
    printf("The list after operation is: \n");
    display();
    p = length();
    printf("\nLength is : \n");
    printf("%d ", p);
    return 0;
}