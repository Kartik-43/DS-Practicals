#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int search(int arr[], int start, int end, int value)
{
    for (int i = start; i <= end; i++)
    {
        if (arr[i] == value)
        {
            return i;
        }
    }
    return -1;
}

Node *buildTree(int preorder[], int inorder[], int inorderStart, int inorderEnd, int *preorderIndex)
{
    if (inorderStart > inorderEnd)
    {
        return NULL;
    }

    int rootValue = preorder[*preorderIndex];
    (*preorderIndex)++;

    Node *root = createNode(rootValue);

    if (inorderStart == inorderEnd)
    {
        return root;
    }

    int inorderIndex = search(inorder, inorderStart, inorderEnd, rootValue);

    root->left = buildTree(preorder, inorder, inorderStart, inorderIndex - 1, preorderIndex);
    root->right = buildTree(preorder, inorder, inorderIndex + 1, inorderEnd, preorderIndex);

    return root;
}

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void printTree(Node *root, int space)
{
    if (root == NULL)
    {
        return;
    }

    space += 10;

    printTree(root->right, space);

    printf("\n");
    for (int i = 10; i < space; i++)
    {
        printf(" ");
    }
    printf("%d\n", root->data);

    printTree(root->left, space);
}

void freeTree(Node *root)
{
    if (root != NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

void readArray(int arr[], int size)
{
    printf("Enter %d elements: ", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
}

#include<stdio.h>

int main()
{
    printf( "\n\nKartik Garg \nEnrolment Number - 01813203123 \n");
    printf( "IT - 1\nShift 1\n\n\n");

    int size;

    printf("Enter the number of nodes in the tree: ");
    scanf("%d", &size);

    int preorde[size];
    int inorde[size];

    printf("\nEnter Preorder traversal:\n");
    readArray(preorde, size);

    printf("\nEnter Inorder traversal:\n");
    readArray(inorde, size);

    int preorderIndex = 0;
    Node *root = buildTree(preorde, inorde, 0, size - 1, &preorderIndex);

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preorder(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorder(root);
    printf("\n");

    printf("Tree Structure:\n");
    printTree(root, 0);

    freeTree(root);

    return 0;
}
