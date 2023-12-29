//program to reverse singly linked list.

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

//function to reverse the list.

void reverse()
{
    struct node *prevNode, *currentNode, *nextNode;
    currentNode = nextNode = head;
    prevNode = NULL;
    while (nextNode != NULL)
    {
        nextNode = nextNode -> next;
        currentNode -> next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    head = prevNode;
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
    reverse();
    printf("The list is: ");
    display();
   return 0;
}