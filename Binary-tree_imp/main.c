//program to implement the binary tree.
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};
struct node *root;

//function to create the node.
struct node *create()
{
    int x;
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data(-1 for no node): ");
    scanf("%d",&x);
    if (x == -1)
    {
        return NULL;
    }
    newnode -> data = x;
    printf("Enter left child of %d " ,x);
    newnode -> left = create();
    printf("Enter the right of %d ",x);
    newnode -> right = create();
    return newnode;
}

//function for preorder traversal.
void preorder(struct node *current)
{
    if (current == NULL)
    {
       return;
    }
    printf("%d  ", current->data);
    preorder(current->left);
    preorder(current->right);
}

//function for inorder traversal.
void inorder(struct node *current)
{
    if (current == NULL)
    {
       return;
    }
    inorder(current->left);
    printf("%d  ", current->data);
    inorder(current->right);
}

//function for postorder traversal.
void postorder(struct node *current)
{
    if (current == NULL)
    {
       return;
    }
    postorder(current->left);
    postorder(current->right);
    printf("%d  ", current->data);
}

int main()
{
    root = NULL;
    root = create();
    printf("Preorder traversal is: ");
    preorder(root);
    printf("Inorder traversal is: ");
    inorder(root);
    printf("Postorder traversal is: ");
    postorder(root);
    return 0;
}