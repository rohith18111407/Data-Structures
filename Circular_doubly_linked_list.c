#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next,*prev;
};

struct node* begin_insert(struct node *head,int val)
{
	struct node *newnode,*temp=head;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("\nCannot allocate new memory...\n");
	}
    else if(head==NULL)
    {
        newnode->data=val;
        head=newnode;
        newnode->next=head;
		head->prev=head;
        printf("\nNode inserted successfully...\n");
    }
	else
	{
		newnode->data=val;
        while(temp->next!=head)
            temp=temp->next;
        temp->next=newnode;
		newnode->prev=temp;
		head->prev=newnode;
		newnode->next=head;
		head=newnode;
		printf("\nNode inserted successfully\n");
	}
	return head;
}

struct node* last_insert(struct node* head,int val)
{
	struct node *newnode,*temp=head;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("\nCannot allocate new memory...\n");
	}
	else
	{
		if(head==NULL)
        {
            newnode->data=val;
            head=newnode;
            newnode->next=head;
			newnode->prev=head;
            printf("\nNode inserted successfully...\n");
        }   
        else
        {
            newnode->data=val;
            while(temp->next!=head)
                temp=temp->next;
            temp->next=newnode;
			newnode->prev=temp;
			head->prev=newnode;
            newnode->next=head;
            printf("\nNode inserted successfully...\n");
        }
	}
	return head;
}

struct node* begin_delete(struct node* head)
{
	struct node *temp=head;
	if(temp==NULL)
	{
		printf("\nList is empty...\n");
	}
	else if(temp->next==temp)
	{
		free(temp);
		head=NULL;
		printf("\nOnly node in the list is deleted...\n");
	}
	else
	{
		while(temp->next!=head)
            temp=temp->next;
        temp->next=head->next;
		head->next->prev=temp;
        free(head);
        head=temp->next;
		printf("\nNode deleted successfully...\n");
	}
    return head;
}

struct node* last_delete(struct node *head)
{
	struct node *temp;
	if(head==NULL)
	{
		printf("\nNothing to delete...\n");
	}
	else if(head->next==head)
	{
		free(head);
		head=NULL;
		printf("\nOnly one node in the list is deleted...\n");
	}
	else	
	{
		temp=head;
		while(temp->next!=head)
		{
			temp=temp->next;
		}
		temp->prev->next=head;
		head->prev=temp->prev;
		free(temp);
		printf("\nLast node in the list is deleted...\n");
    }
    return head;
}

void display(struct node *head)
{
	struct node *ptr;
	ptr=head;
	if(ptr==NULL)
	{
		printf("\nNothing to print...\n");
	}
    else if(ptr->next==ptr)
    {
        printf("\nMemory=%p\tPrev=%p\tData=%d\tNext=%p",ptr,ptr->prev,ptr->data,ptr->next);
        ptr=ptr->next;
        printf("\nMemory=%p\tPrev=%p\tData=%d\tNext=%p",ptr,ptr->prev,ptr->data,ptr->next);
    }
	else
	{
		printf("\nDisplaying values...");
		while(ptr->next!=head)
		{
			printf("\nMemory=%p\tPrev=%p\tData=%d\tNext=%p",ptr,ptr->prev,ptr->data,ptr->next);
			ptr=ptr->next;
		}
        printf("\nMemory=%p\tPrev=%p\tData=%d\tNext=%p",ptr,ptr->prev,ptr->data,ptr->next);
        ptr=ptr->next;
        printf("\nMemory=%p\tPrev=%p\tData=%d\tNext=%p",ptr,ptr->prev,ptr->data,ptr->next);
		printf("\n");
	}
}	

void search(struct node *head,int val)
{
    struct node *temp=head;
    int i=0,count=0;
    if(temp==NULL)
        printf("\nList is Empty");
    else
    {
        if(temp->next==head)
        {
            if(val==temp->data)
            {
                count++;
                printf("\nValue %d is found at the position %d",val,i);
            }
        }
        else
        {
            if(val==temp->data)
            {
                count++;
                printf("\nValue %d is found at the position %d",val,i);
            }
			i++;
            temp=temp->next;
            while(temp!=head)
            {
                if(val==temp->data)
                {
                    count++;
                    printf("\nValue %d is found at the position %d",val,i);
                }
				i++;
                temp=temp->next;
            }
        }
        if(count==0)
            printf("\nThe Value %d is not found in the List",val);
        else
            printf("\nThe Value is found %d time(s)",count);
    }
}

void main()
{
    int choice=0,val=0,pos=0;
	struct node *head=NULL;
	do
	{
		printf("\nChoices :\n1.Insert at the begin\n2.Insert at the last\n3.Delete at the begin\n4.Delete at the last\n5.Search\n6.Display\n7.Exit\n");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				printf("\nEnter the value you want to insert at the beginning: ");
				scanf("%d",&val);
				head=begin_insert(head,val);
				break;
			case 2:
				printf("\nEnter the value you want to insert at the last: ");
				scanf("%d",&val);
				head=last_insert(head,val);
				break;
			case 3:
				head=begin_delete(head);
				break;
			case 4:
				head=last_delete(head);
				break;
			case 5:
				printf("\nEnter the element to search: ");
				scanf("%d",&val);
				search(head,val);
				break;
			case 6:
				display(head);
				break;
			case 7:
				exit(0);
			default:
				printf("\nInvalid choice!!!");
		}
	}while(choice!=7);
}

