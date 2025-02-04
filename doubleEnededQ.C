#include<stdio.h>
#include<stdlib.h>
int size;
struct Queue{
    int front;
    int rear;
    int *queue;   
}Q;
void enqueuefront(int val);
void enqueuerear(int val);
void dequeuefront();
void dequeuerear();

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
                    enqueuefront(val);
                    break;
                     case 6: printf("\nenter the element to be inserted\n");
                    scanf("%d",&val);
                    enqueuerear(val);
                    break;
             case 2: dequeuefront();
                     break;
                      case 7: dequeuerear();
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
void enqueuefront(int val)
{
    if(Q.front==0&&Q.rear==size||Q.front==Q.rear+1)
    {
          printf("reallocating");
        size++;
        Q.queue=(int *)realloc(Q.queue,size*sizeof(int));
        
    }
    if(Q.front==-1){
        Q.front=Q.rear=0;
        *(Q.queue+  Q.front)=val;
    }
    else if(Q.front==0)
    {
        Q.front=size-1;
        *(Q.queue+  Q.front)=val;
        
    }
    else{
        Q.front--;
        *(Q.queue+  Q.front)=val;
    }
}
void enqueuerear(int val){
     if(Q.front==0&&Q.rear==size||Q.front==Q.rear+1)
    {
          printf("reallocating");
        size++;
        Q.queue=(int *)realloc(Q.queue,size*sizeof(int));
        
    }
    if(Q.rear==-1){
        Q.front=Q.rear=0;
        *(Q.queue+  Q.rear)=val;
    }
    else if(Q.rear==size-1)
    {
        Q.rear=0;
        *(Q.queue+  Q.rear)=val;
        
    }
    else{
        Q.rear++;
        *(Q.queue+  Q.rear)=val;
    }
}
void dequeuefront(){
    if( Q.front==Q.rear==-1){
        printf("empty");
        
    }
    else{
        printf("deleted element %d",*(Q.queue+Q.front));
    }
if(Q.front==Q.rear){
    Q.front=Q.rear=-1;
}
if(Q.front==size-1){
    Q.front=0;
}
else
{
    Q.front++;
}
}

void dequeuerear()
{
    if( Q.front==Q.rear==-1){
        printf("empty");
        
    }
    else{
        printf("deleted element %d",*(Q.queue+Q.rear));
    }
if(Q.front==Q.rear){
    Q.front=Q.rear=-1;
}
if(Q.rear==0){
    Q.rear=size-1;
}
else
{
    Q.rear--;
}
}


void display()
{
    int i=Q.front;
while(i!=Q.rear){
    printf("%d",*(Q.queue+i));
    i=(i+1)%size;
} printf("%d",*(Q.queue+i));

}