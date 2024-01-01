//program to delete element from circular list.

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

//function for deletion from begnning.
void delFromBeg()
{
  temp = tail -> next;
  tail -> next = temp -> next;
  free(temp);
}

//function for deletion from the end.
void delFromEnd()
{
    struct node *current, *prev;
    current = tail -> next;
    while (current -> next != tail -> next)
    {
        prev = current;
        current = current -> next;
    }
    prev -> next = tail -> next;
    tail = prev;
    free(current);
}

//function for deletion from the specific postion. 
void deletionFromPos()
{
    int pos, i = 1, l;
    printf("Enter the value of position: ");
    scanf("%d", &pos);
    l = length();
    if(pos == 1)
    {
        delFromBeg();
    }
    else if(pos == l)
    {
        delFromEnd();
    }
    else
    {
        struct node *current, *nextnode;
        current = tail -> next;
        while (i < pos-1)
        {
            current = current -> next;
            i++;
        }
        nextnode = current -> next;
        current -> next = nextnode -> next;
        free(nextnode);
    }
}

//function to reverse the list.
void reverse()
{
    struct node *prev, * current, *nextnode;
    current = tail -> next;
    nextnode = current -> next;

    while (current != tail)
    {
        prev = current;
        current = nextnode;
        nextnode = current -> next;
        current -> next = prev;
    }
    nextnode -> next = tail;
    tail = nextnode;
}

int main()
{
    int num, choice, p;
         printf("Let's create a list first: \n");
         create();
    do
    {
        printf("Enter:\n1.delete from beginning.\n2.delete from end.\n3.delete from specific position.\n4.reverse.\n>> ");
        scanf("%d",&choice);
       switch (choice)
       {
       case 1:
         delFromBeg();
        break;
       case 2:
         delFromEnd();
         break;
       case 3:
         deletionFromPos();
         break;
       case 4:
          reverse();
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