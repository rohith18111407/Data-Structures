#include <stdio.h>
#include <stdlib.h>
#define MAX 5;

int stack_full(int *top,int n)
{
    if(*top==n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int stack_empty(int *top)
{
    if(*top==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int pop(int *stack,int *top)
{
    int data;
    if(stack_empty(top)==1)
    {
        return -1;
    }
    else
    {
        (*top)--;
        data=stack[*top];
        return data;
    }
}

void push(int *stack,int data,int *top,int n)
{
    if(stack_full(top,n)==1)
    {
        printf("\nOverflow, Stack is full...\n");
    }
    else
    {
        stack[*top]=data;
        printf("\n %d pushed at position %d\n",stack[*top],*top);
        (*top)++;
    }
    printf("\n");
}

int peek(int *top,int *stack)
{
    if(stack_empty(top)==1)
        return -1;
    else
        return stack[(*top)-1];
}

void show(int *top,int *stack)
{
    printf("\nDisplaying the values in the stack...\n");
    for(int i=(*top)-1;i>=0;i--)
        printf("%d\n",stack[i]);
    if(top==0)
        printf("\nStack is empty...\n");
    printf("\n");
}

void main()
{
    int stack[5],n=5,val=0,choice=0;
    int *top=(int *)malloc(sizeof(int));
    *top=0;
    do
	{
		printf("\nChoices :\n1.Push\n2.Pop\n3.Show\n4.Stack Is_full\n5.Stack Is_empty\n6.Peek\n7.Exit\n");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				printf("\nEnter the value you want to push: ");
				scanf("%d",&val);
				push(stack,val,top,n);
				break;
			case 2:
                val=pop(stack,top);
                if(val==-1)
                    printf("\nUnderflow, Stack is empty...\n");
                else
				    printf("\nPopped value is: %d \n",val);
                printf("\n");
				break;
			case 3:
				show(top,stack);
				break;
			case 4:
				val=stack_full(top,n);
                if(val==1)
                    printf("\nStack is full...\n");
                else
                    printf("\nStack is not full...\n");
                printf("\n");
				break;
			case 5:
				val=stack_empty(top);
                if(val==1)
                    printf("\nStack is empty...\n");
                else
                    printf("\nStack is not empty...\n");
                printf("\n");
				break;
            case 6:
                val=peek(top,stack);
                if(val==-1)
                    printf("\nUnderflow, Stack is empty\n");
                else
                    printf("Peek value = %d\n",val);
                printf("\n");
                break;
			case 7:
				exit(0);
			default:
				printf("\nInvalid choice!!!");
		}
	}while(choice!=7);
}
