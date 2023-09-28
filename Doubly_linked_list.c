#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next,*prev;
};

struct node* begin_insert(struct node *head,int val)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL)
		printf("\nCannot allocate new memory...\n");
	else
	{
		newnode->data=val;
		newnode->prev=NULL;
		newnode->next=head;
		if(head!=NULL)
			head->prev=newnode;
		head=newnode;
		printf("\nNode inserted successfully...\n");
	}
	return head;
}

void insert_position(struct node* head,int pos,int val)
{
	struct node *temp,*newnode,*check=head;
	int i=0,j=0;
	if(head==NULL)
		printf("\nList is empty...\n");
	else
	{
		for(check=head;check->next!=NULL;check=check->next)			// to check whether the position entered excceds beyond the limit
			j++;
		if(pos>j)
			printf("\nInvalid position...\n");
		else if(pos==0)
			printf("\nCannot insert at the beginning...\n");
		else
		{
			for(temp=head;temp!=NULL;temp=temp->next)
			{
				if(i++==pos-1)					// inserting at the (i+1)th position
				{
					newnode=(struct node*)malloc(sizeof(struct node));
					newnode->data=val;
					newnode->next=temp->next;
					newnode->next->prev=newnode;
					temp->next=newnode;
					newnode->prev=temp;
					printf("\nNode inserted successfully...\n");
					break;
				}
			}
		}
	}
}
	
struct node *last_insert(struct node *head,int val)
{
	struct node *newnode,*temp=head;
	if(head==NULL)
		printf("\nThe list is empty...\n");
	else
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		while(temp->next!=NULL)
			temp=temp->next;
		newnode->data=val;
		newnode->next=NULL;
		newnode->prev=temp;
		temp->next=newnode;
		printf("\nNode inserted at the end successfully...\n");
	}
	return head;
}

struct node* begin_delete(struct node* head)
{
	struct node* temp;
	if(head==NULL)
		printf("\nNothing to delete...\n");
	else if(head->next==NULL)
	{
		free(head);
		head=NULL;
		printf("\nNode deleted at the begininning...\n");
	}
	else
	{
		head->next->prev=NULL;
		temp=head;
		head=head->next;
		free(temp);
		printf("\nNode deleted at the begininning...\n");
	}
	return head;
}

void delete_position(struct node *head,int pos)
{
	struct node *check=head,*temp1,*temp2;
	int i=0;
	if(head==NULL)
		printf("\nThe list is empty...\n");
	else
	{
		while(check->next!=NULL)
		{
			check=check->next;
			i++;
		}
		if(pos>i)
			printf("\nInvalid position...\n");
		else if(pos==0)
			printf("\nCannot perform deletion at the begin...\n");
		else if(pos==i)
			printf("\nCannot perform deletion at the last...\n");
		else
		{
			temp1=head;		//i and temp1 refer to same node.
			i=0;
			while(i!=pos)
			{
				temp2=temp1;
				temp1=temp1->next;
				i++;
			}
			temp2->next=temp1->next;
			temp1->next->prev=temp2;
			free(temp1);
			printf("\nNode deleted successfully...\n");
		}
	}
}

struct node* last_delete(struct node* head)
{
	struct node *temp1,*temp2;
	if(head==NULL)
		printf("\nNothing to delete...\n");
	else if(head->next==NULL)
	{
		free(head);
		head=NULL;
		printf("\nOnly node in the list is deleted...\n");
	}
	else
	{
		temp1=head;
		while(temp1->next!=NULL)
		{
			temp2=temp1;
			temp1=temp1->next;
		}
		free(temp1);
		printf("\nLast node in the list is deleted...\n");
		temp2->next=NULL;	
	}
	return head;
}

void display(struct node *head)
{
    struct node *temp;
	if(head==NULL)
		printf("\nNothing to print...\n");
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

void search(struct node *head,int val)
{
    struct node *temp=head;
    int i=0,count=0;
    if(temp==NULL)
        printf("\nList is Empty");
    else
    {
        if(temp->next==NULL)
        {
            if(val==temp->data)
            {
                count++;
                printf("\nValue %d is found at the position %d",val,i);
            }
        }
        else
        {
            while(temp!=NULL)
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
		printf("\nChoices :\n1.Insert at the begin\n2.Insert at the last\n3.Insert at the position\n4.Delete at the begin\n5.Delete at the last\n6.Delete at the position\n7.Search\n8.Display\n9.Exit\n");
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
				printf("\nEnter the position at which you want to insert:");
				scanf("%d",&pos);
				printf("\nEnter the value you want to insert: ");
				scanf("%d",&val);
				insert_position(head,pos,val);
				break;
			case 4:
				head=begin_delete(head);
				break;
			case 5:
				head=last_delete(head);
				break;
			case 6:
				printf("\nEnter the position you want to delete:");
				scanf("%d",&pos);
				delete_position(head,pos);
				break;
			case 7:
				printf("\nEnter the element to search: ");
				scanf("%d",&val);
				search(head,val);
				break;
			case 8:
				display(head);
				break;
			case 9:
				exit(0);
			default:
				printf("\nInvalid choice!!!");
		}
	}while(choice!=9);
}

