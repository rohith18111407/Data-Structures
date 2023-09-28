#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front=NULL;
struct node *rear=NULL;

void enqueue(int val)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;
    if(rear==NULL)
        front=rear=newnode;
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
}

void display()
{
    struct node *temp=front;
    if(front==NULL && rear==NULL)
        printf("\nQueue is Empty\n");
    else
    {
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}

void dequeue()
{
    struct node *temp;
    temp=front;
    if(front==NULL)
    {
        front=rear=NULL;
        printf("\nUnderflow\n");
    }
    else
    {
        printf("\nDequeued value is: %d\n",front->data);
        front=front->next;
        free(temp);
    }
}

void peek()
{
    if(front==NULL)
    {
        front=rear=NULL;
        printf("\nQueue is Empty\n");
    }
    else
        printf("\nPeek value is: %d\n",front->data);
}

void main()
{
    int choice=0,val=0;
    do
    {
        printf("\n---------------Menu--------------\n");
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Peek\n5.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter the element you want to insert: ");
                scanf("%d",&val);
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice\n");
        }
    } while (choice!=5);
}