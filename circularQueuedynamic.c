#include<stdio.h>
#include<stdlib.h>
int size;
struct Queue{
    int front;
    int rear;
    int *queue;   
}Q;

void enqueue(int val);
void dequeue();
void peek();
void display();
int main()
{
    int choice,val,i;
    Q.front=Q.rear=-1;
    printf("enter the size of the array:");
    scanf("%d",&size);
    Q.queue=(int *)malloc(size*sizeof(int));

    printf("main menu\n1.insert\n2.delete\n3.peek\n4.display\n5.exit\n");
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
    return 0;
}
void enqueue(int val)
{
    if((Q.rear+1)%size==Q.front)
    {
        printf("\nqueue is in overflow condition");
        printf("reallocating memeory");
        size++;
        Q.queue=(int *)realloc(Q.queue,size*sizeof(int));

        

    }
    if(Q.front==-1)
    {
        Q.front=0;

    }
    Q.rear=(Q.rear+1)%size;
    *(Q.queue+(Q.rear))=val;

}

void dequeue()
{
     if(Q.front==-1)
    {
        printf("\nqueue is empty");
        return ;
    }else{
    
    printf("\ndeleted element:%d",*(Q.queue+(Q.front)));
    
        if(Q.front=Q.rear){
        Q.front=Q.rear=-1;
        return;
        }
    Q.front=(Q.front+1)%size;
    }
}

void display()
{
   if(Q.front==-1)
    {
        printf("\nqueue is empty");
        return ;
    }
    if(Q.front<Q.rear)
   
   if(Q.front<Q.rear)
   { for(int i=Q.front;i<=Q.rear;i++)
    {
        printf("%d\t",*(Q.queue+i));
    } }
    else{
      for(int i=Q.front;i<=size-1;i++)
    {
        printf("%d\t",*(Q.queue+i));
    } 
    for(int i=0;i<=Q.rear;i++)
    {
        printf("%d\t",*(Q.queue+i));
    }
   } }
}

void peek()
{
     if(Q.front==-1){
        printf("\nqueue is empty");
        return ;
        }
    printf("%d",*(Q.queue+(Q.front)));
}