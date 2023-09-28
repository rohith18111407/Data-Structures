#include <stdio.h>
#include <stdlib.h>
#define MAX 10;

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
        return 0;
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

int eval(char ch,int op1,int op2)
{
    switch(ch)
    {
        case '+':
            return op1+op2;
        case '-':
            return op1-op2;
        case '*':
            return op1*op2;
        case '/':
            return op1/op2;
    }
}

void main()
{
    int stack[10],n=10,choice=0,val=0,op1=0,op2=0,res=0;
    int *top=(int *)malloc(sizeof(int));
    *top=0;
    char expression[50],ch;
    printf("\nEnter the expression: ");
    scanf("%s",expression);
    for(int i=0;expression[i]!='\0';i++)
    {
        ch=expression[i];
        if(ch>='0' && ch<='9')
        {
            val=ch-'0';
            push(stack,val,top,n);
        }
        else
        {
            op2=pop(stack,top);
            op1=pop(stack,top);
            res=eval(ch,op1,op2);
            push(stack,res,top,n);
        }
    }
    val=pop(stack,top);
    printf("\nEvaluated value is: %d",val);
}
