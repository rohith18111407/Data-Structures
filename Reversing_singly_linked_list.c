//Reversing a singly linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* begin_insert(struct node* head,int val)
{
    struct node* newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=head;
    head=newnode;
    printf("\nNode inserted successfully...\n");   
    return head; 
}

struct node* reverse(struct node* head)
{
    struct node *prevnode,*currentnode,*nextnode;
    if(head==NULL)
        printf("\nList is empty...\n");
    else
    {
        prevnode=NULL;
        currentnode=nextnode=head;
        while(nextnode!=NULL)
        {
            nextnode=nextnode->next;
            currentnode->next=prevnode;
            prevnode=currentnode;
            currentnode=nextnode;
        }
        head=prevnode;
        printf("\nSingly linked list has been reversed...\n");
    }
    return head;
}

void display(struct node* head)
{
    struct node *temp=head;
    if(temp==NULL)
        printf("\nList is empty...\n");
    else
    {
        printf("\nDisplaying values...");
        while(temp!=NULL)
        {
            printf("\nMemory=%p\tData=%d\tNext=%p",temp,temp->data,temp->next);
            temp=temp->next;
        }
        printf("\n");
    }
}

void main()
{
    struct node *head=NULL;
    int choice=0,val=0;
    do
    {
        printf("Choices :");
        printf("\n1.Insertion at the begin\n2.Reversing the linked list\n3.Display\n4.Exit\n");
        printf("\nEnter the choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter the data you want to insert at head: ");
                scanf("%d",&val);
                head=begin_insert(head,val);
                break;
            case 2:
                head=reverse(head);
                break;
            case 3:
                display(head);
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice!!!\n");
        }
    } while (choice!=4);
    
}