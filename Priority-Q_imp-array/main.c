//program to implement priority Queue.

#include <stdio.h>
#include<stdlib.h>

    struct priorityQue
    {
     int data;
     int priority;
    }pq[5];
    int rear = -1;

//function to check if Queue is empty.
int isEmty()
{
    if (rear == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }  
}

//function to check if the Queue is full.
int isFull()
{
    if (rear == 4)
    {
        return 1;
    }
    else
    {
        return 0;
    }    
}

//function to insert element in Queue.
void insert(int ele, int p)
{
    if (!isFull())
    {
        rear++;
        pq[rear].data = ele;
        pq[rear].priority = p;
    }
    else
    {
        printf("Priority Queue is full");
    }
}

//function to get hieghest priority.
int getHieghestP()
{
    if (!isEmty)
    {
        int p = -1;
        for (int i = 0; i <= rear; i++)
        {
            if (pq[i].priority > p)
            {
                p = pq[i].priority;
            }
        } 
        return p;
    }
}

//function to delete hieghest priority element.
int deleteHieghestP()
{
    int i, p, ele;
    p = getHieghestP();
    for (i = 0; i <= rear; i++)
    {
        if (pq[i].priority == p)
        {
            ele = pq[i].data;
            break;
        } 
    }
    if (i < rear)
    {
        for (int j = i; j < rear; j++)
        {
            pq[j].data = pq[j+1].data;
            pq[j].priority = pq[j+1].priority;
        }
    } 
    rear--;
    return ele;
}

//function to display the Queue.
void display()
{
    printf("\n Priority Queue is\n");
    for (int i = 0; i <= rear; i++)
    {
       printf("| ele = %d - priority = %d |", pq[i].data, pq[i].priority);
       printf("\n");
    }
    printf("\n");
}

int main()
{
    int a, ele, p, choice, prior;
    do
    {
       printf("Enter :\n1.Insert element.\n2.Get hieghest priority.\n3.Delete hieghest priority element.\n4.display.\n>> ");
       scanf("%d", &choice);
    
        switch (choice)
        {
        case 1:
          if (isFull())
          {
            printf("Queue is full\n");
          }
          else
          {
            printf("Enter the element: ");
            scanf("%d",&ele);
            printf("Enter the priority: ");
            scanf("%d",&p);
            insert(ele,p);
          }
          break;
        case 2:
          prior = getHieghestP();
          printf("Hieghest priority is %d ", prior);
          break;
        case 3: 
          if (isEmty())
          {
            printf("Queue is Empty\n");
          }
          else
          {
            deleteHieghestP();
          }
          break;
        case 4:
        if (isEmty())
        {
            printf("Queue is empty\n");
        }
        else
        {
           display();
        }
          break;
    }
      printf("\nEnter 1 for more operation : ");
      scanf("%d", &a);
    } while (a == 1);
   
    return 0;
}