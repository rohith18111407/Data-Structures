#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* push(struct node* top,int val)				// begin insert
{
    struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("\nCannot allocate new memory...\n");
	}
	else
	{
		newnode->data=val;
		newnode->next=top;
		top=newnode;
		printf("\nItem pushed into the stack...\n");
	}
	return top;
}

struct node* pop(struct node* top)						//begin delete
{
    int pop_value;
	struct node *temp=top;
	if(temp==NULL)
	{
		printf("\nUnderflow, List is empty...\n");
	}
	else
	{
        pop_value=top->data;
		top=top->next;
		free(temp);
		printf("\nItem popped successfully...\nPopped value = %d ",pop_value);
	}
    return top;
}

void show(struct node *top)
{
	struct node *ptr;
	ptr=top;
	if(ptr==NULL)
	{
		printf("\nNothing to print...\n");
	}
	else
	{
		printf("\nDisplaying values...");
		while(ptr!=NULL)
		{
			printf("\nData=%d\n",ptr->data);
			ptr=ptr->next;
		}
		printf("\n");
	}
}	

int peek(struct node *top)
{
    if(top==NULL)
        return 0;
    else
        return top->data;
}

void main()
{
    int val=0,choice=0;
    struct node *top=NULL;
    do
	{
		printf("\nChoices :\n1.Push\n2.Pop\n3.Show\n4.Peek\n5.Exit\n");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				printf("\nEnter the value you want to push: ");
				scanf("%d",&val);
				top=push(top,val);
				break;
			case 2:
                top=pop(top);
                printf("\n");
				break;
			case 3:
				show(top);
				break;
            case 4:
                val=peek(top);
                if(val==0)
                    printf("\nUnderflow, Stack is empty\n");
                else
                    printf("Peek value = %d\n",val);
                printf("\n");
                break;
			case 5:
				exit(0);
			default:
				printf("\nInvalid choice!!!");
		}
	}while(choice!=5);
}
