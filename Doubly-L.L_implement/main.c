//Implementation of doubly Linked List.

#include <stdio.h>
#include<stdlib.h>

int main()
{
    int num;
    struct node
    {
     int data;
     struct node* next;
     struct node* prev;
    };
    struct node *head, *temp, *newnode;
    head = NULL; 
    do
    {
        
       newnode = (struct node*)malloc(sizeof(struct node));
       printf("Enter the data: ");
       scanf("%d", &newnode -> data);
       newnode -> next = NULL;
       newnode -> prev = NULL;
       if(head == NULL)
       {
         head = temp = newnode;
       }
       else
       {
        temp -> next = newnode;
        newnode -> prev = temp;
        temp = newnode;
       }

    printf("Press 1 for another node: ");
    scanf("%d", &num);

    }while(num == 1);

    printf("The Doubly List is: ");
    temp = head;
    while(temp != NULL) 
    {
        printf("%d  ", temp -> data);
        temp = temp -> next;
    }
    return 0;
}