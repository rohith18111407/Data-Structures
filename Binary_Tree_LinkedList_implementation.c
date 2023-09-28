#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left,*right;
};

struct node* create()
{
    int x;
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data (Enter -1 for no node): ");
    scanf("%d",&x);
    if(x==-1)
        return 0;
    newnode->data=x;
    printf("\nEnter the left child of %d: ",x);
    newnode->left=create();
    printf("\nEnter the right child of %d: ",x);
    newnode->right=create();
    return newnode;
}

void preorder(struct node *root)
{
    if(root==0)
        return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node *root)
{
    if(root==0)
        return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void postorder(struct node *root)
{
    if(root==0)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

void main()
{
    struct node *root;
    root=0;
    root=create();
    printf("\nPreorder is:\n");
    preorder(root);
    printf("\nInorder is:\n ");
    inorder(root);
    printf("\nPostorder is:\n");
    postorder(root);
}