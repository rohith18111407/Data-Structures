#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next,*prev;
};

struct node* begin_insert(struct node* head,int val)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=head;
    newnode->prev=NULL;
    if(head!=NULL)
		head->prev=newnode;
    head=newnode;
    printf("\nNode inserted successfully...\n");
    return newnode;
}

struct node* reverse(struct node* head)
{
    if(head==NULL)
        printf("\nList is empty...\n");
    else
    {
        struct node *current,*nextnode,*temp=head;
        current=head;
        while(temp->next!=NULL)
            temp=temp->next;
        while(current!=NULL)
        {
            nextnode=current->next;
            current->next=current->prev;
            current->prev=nextnode;
            current=nextnode;
        }
        head=temp;
        printf("\nList has been reversed...\n");
    }
    return head;
}

void display(struct node *head)
{
    struct node *temp;
    if(head==NULL)
        printf("\nList is empty...\n");
    else
    {
        printf("\nDisplaying values...");
		for(temp=head;temp!=NULL;temp=temp->next)
		{
			printf("\nMemory=%p\tPrev=%p\tData=%d\tNext=%p",temp,temp->prev,temp->data,temp->next);
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
        printf("\nChoices:");
        printf("\n1.Insertion at the begin\n2.Reversing the list\n3.Display\n4.Exit\n");
        printf("\nEnter the choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter the data you want to insert at the head: ");
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
                printf("\nInvalid choice...\n");
        }
    } while (choice!=4);
    
}
