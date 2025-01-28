#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
struct Queue{
    int front;
    int rear;
    int queue[SIZE];   
}Q;

void enqueue(int val);
void dequeue();
void peek();
void display();
void main()
{
    int choice,val;
    Q.front=Q.rear=-1;
    printf("main menu\n1.insert\n2.delete\n.3peek\n4.display\n5.exit\n");
    for(;;)
    {
        printf("\nenter the choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("\nenter the element to be inserted\n");
                    scanf("%d",&val);
                    enqueue(val);
                    break;
            case 2: dequeue();
                    break;
            case 3: peek();
                    break;
            case 4: display();
                    break;
            case 5: printf("!! THANK YOU!!");
                    exit(0);
            default : printf("invalid choice!!");

        }
    }
}
void enqueue(int val)
{
    if(Q.rear+1)%SIZE==Q.front)
    {
        printf("\nqueue is in overflow condition");
        return;

    }
    if(Q.front==-1&&Q.rear==-1)
    {
        Q.front=0;

    }
    Q.rear=(Q.rear+1)%SIZE;
    Q.queue[Q.rear]=val;

}

void dequeue()
{
     if(Q.front==-1&&Q.rear==-1)
    {
        printf("\nqueue is empty");

    }
    
    printf("\ndeleted element:%d",Q.queue[Q.front]);
   if(Q.front=Q.rear)
    {
        Q.front=Q.rear=-1;
        return;
    }

     Q.front=(Q.front+1)%SIZE;
}

void display()
{
   if(Q.front==-1&&Q.rear==-1)
    {
        printf("\nqueue is empty");

    }
    if(Q.front<Q.rear)
    for(int i=Q.front;i<=Q.rear;i++)
    {
        printf("%d\t",Q.queue[i]);
    }   
    else
     {
       for(int i=Q.front;i<=SIZE-1;i++)
    {
        printf("%d\t",Q.queue[i]);
    }   
    for(int i=0;i<=Q.rear;i++)
    {
        printf("%d\t",Q.queue[i]);
    }    
     }
}

void peek()
{
     if(Q.front==-1&&Q.rear==-1)
    {
        printf("\nqueue is empty");

    }
    printf("%d",Q.queue[Q.front]);
}
