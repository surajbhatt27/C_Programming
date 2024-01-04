//program to implement the simple linear queue using linked list.

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *front = NULL, *rear = NULL, *newnode, *temp;

//function for enqueue.
void enqueue()
{
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newnode -> data);
    newnode -> next = NULL;
    if (front == NULL && rear == NULL)
    {
        front = rear = newnode; 
    }   
    else
    {
        rear -> next = newnode;
        rear = newnode;
    }
}

//function for dequeue.
void dequeue()
{
    if (front == NULL && rear == NULL)
    {
        printf("Queue is empty\n") ;
    } 
    else
    {
       temp = front;
       front = temp -> next;
        if (front == NULL) // If the queue becomes empty after dequeue
        {
            rear = NULL;
        }
       free(temp);
    }
}

//function for display.
void display()
{
    if (front == NULL && rear == NULL)
    {
        printf("Queue is empty\n") ;
    }  
    else
    {
        temp = front;
        while (temp != NULL)
        {
           printf("%d  ",temp -> data);
           temp = temp -> next;
        } 
        printf("\n");
    } 
}

int main()
{
    int choice, num;
    do
    {
        printf("Enter\n1.enqueue\n2.dequeue\n3.display\n>>> ");
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
        default:
            printf("Invalid choice\n");
            break;
        }
        printf("Enter 1 for more operation: ");
        scanf("%d",&num);
    } while (num == 1);
    return 0;
}