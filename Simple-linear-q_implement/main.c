//program to implement simple linear queue.

#include<stdio.h>
#include<stdlib.h>
int queue[5];
int front = -1, rear = -1;

//function for enqueue.
void enqueue()
{
    int item;
    printf("Enter the data: ");
    scanf("%d", &item);
    if (rear == 4)
    {
        printf("Overflow\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = item;
    }
    else
    {
        rear++;
        queue[rear] = item;
    } 
}

//function for dequeue.
void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("Underflow\n");
    }
    else if (front = rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }  
}

//function for display the queue.
void display()
{
    if (rear == -1 && front == -1)
    {
        printf("queue is empty\n");
    }
    else
    {
        for (int i = front; i < rear; i++)
        {
            printf("%d  ", queue[i]);
        }  
        printf("\n");
    }
}

int main()
{
    int num, choice;
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
        printf("Enter 1 for more operations: ");
        scanf("%d", &num);
    } while (num == 1);
    return 0;
}