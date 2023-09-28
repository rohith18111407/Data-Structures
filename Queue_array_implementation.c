#include <stdio.h>
#include <stdlib.h>
#define N 5

void enqueue(int queue[],int val,int *front,int *rear)
{
    if(*rear==N-1)
        printf("\nOverflow\n");
    else if(*front==-1 && *rear==-1)
    {
        *front=*rear=0;
        queue[*rear]=val;
        printf("\n%d added to Queue\n",val);
    }
    else
    {
        (*rear)++;
        queue[*rear]=val;
        printf("\n%d added to Queue\n",val);
    }
}

int dequeue(int queue[],int *front,int *rear)
{
    int val=0;
    if(*front==-1 && *rear==-1)
        return -1;
    else if(*front==*rear)
    {
        val=queue[*front];
        *front=*rear=-1;
        return val;
    }
    else
    {
        val=queue[*front];
        (*front)++;
        return val;
    }
}

void display(int queue[],int *front,int *rear)
{
    printf("\nDisplaying values:\n");
    if(*front==-1 && *rear==-1)
        printf("\nQueue is Empty\n");
    else
    {
        for(int i=*front;i<(*rear)+1;i++)
            printf("%d ",queue[i]);
        printf("\n");        
    }
}

int peek(int queue[],int *front)
{
    if(*front==-1)
        return -1;
    else
        return queue[*front];
}

void main()
{
    int queue[N],*front,*rear,choice=0,val=0;
    front=(int*)malloc(sizeof(int));
    rear=(int*)malloc(sizeof(int));
    *front=*rear=-1;
    do
    {
        printf("\n---------------Menu-----------------\n");
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Peek\n5.Exit\n");
        printf("\nEnter the choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter the data you want to insert: ");
                scanf("%d",&val);
                enqueue(queue,val,front,rear);
                break;
            case 2:
                val=dequeue(queue,front,rear);
                if(val==-1)
                    printf("\nUnderflow\n");
                else
                    printf("\nDequeued value is: %d\n",val);
                break;
            case 3:
                display(queue,front,rear);
                break;
            case 4:
                val=peek(queue,front);
                if(val==-1)
                    printf("\nQueue is Empty\n");
                else
                    printf("\nPeek value is: %d\n",val);
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid Choice\n");
        }
    } while (choice!=5);
}