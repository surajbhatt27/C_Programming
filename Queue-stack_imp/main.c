//program to implement the queue using stack.

#include<stdio.h>
#include<stdlib.h>
int s1[5], s2[5];
int top1 =-1, top2 = -1;
int count = 0;

void push1(int x)
{
   if (top1 == -1)
   {
    top1 = 0;
    s1[top1] = x;
   }
   else
   {
    top1++;
    s1[top1] = x;
   }
}

void push2(int x)
{
    if (top2 == -1)
    {
        top2 = 0;
        s2[top2] = x;
    }
    else
    {
        top2++;
        s2[top2] = x;
    }
}

int pop1()
{
    int b = s1[top1];
    top1--;
    return b;
}

int pop2()
{
    int b = s2[top2];
    top2--;
    return b;
}

void enqueue(int x)
{
    if (top1 == 4)
    {
        printf("Overflow\n");
    }
    else
    {
        push1(x);
        count++;
    } 
}

void dequeue()
{
    if (top1 == -1 && top2 == -1)
    {
        printf("Underflow\n");
    }
    else
    {
        for (int i = 0; i < count; i++)
        {
            int a = pop1();
            push2(a);   
        }
    }
    pop2();
    count--;
    for (int i = 0; i < count; i++)
    {
        int a = pop2();
        push1(a);
    }  
}

void display()
{
    if (top1 == -1 && top2 == -1)
    {
        printf("Underflow\n");
    }
    else
    {
        for (int i = 0; i < count; i++)
        {
            printf("%d  ",s1[i]);
        }
        printf("\n");
    } 
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    display();
    dequeue();
    display();
    dequeue();
    display();
    return 0;
}