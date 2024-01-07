//program to implement the Deque using circular queue.
#include<stdio.h>
#include<stdlib.h>
int queue[5];
int front = -1, rear = -1;

//program for enqueue from front.
void enqueueFront(int x)
{
    if (front == (rear + 1)% 5)
    {
        printf("Overflow\n");
    }
    else if (front == -1 && rear == -1)
    {
       front = rear = 0;
       queue[front] = x;
    }
    else if (front == 0)
    {
        front = 4;
        queue[front] = x;
    }
    else
    {
       front--;
       queue[front] = x;
    }   
}

//function to enqueue from rear.
void enqueueRear(int x)
{
    if (front == (rear + 1)% 5)
    {
        printf("Overflow\n");
    }
    else if (front == -1 && rear == -1)
    {
       front = rear = 0;
       queue[rear] = x;
    }
    else if (rear == 4)
    {
        rear = 0;
        queue[rear] = x;
    }
    else
    {
       rear++;
       queue[rear] = x;
    }  
}

//function to dequeue from front.
void dequeueFront()
{
    if (front == -1 && rear == -1)
    {
        printf("Underflow\n");
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else if (front == 4)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}

//function for dequeue from rear.
void dequeueRear()
{
    if (front == -1 && rear == -1)
    {
        printf("Underflow\n");
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else if (rear == 0)
    {
        rear = 4;
    }
    else
    {
        rear--;
    } 
}

//function to display the Deque.
void display()
{
    int i = front;
    while (i != rear)
    {
        printf("%d  ",queue[i]);
        i = (i + 1)%5;
    }
    printf("%d  ", queue[rear]); 
    printf("\n");
}

int main()
{
    enqueueFront(1);
    enqueueFront(2);
    enqueueRear(3);
    enqueueRear(4);
    display();
    dequeueFront();
    dequeueRear();
    display();
    return 0;
}