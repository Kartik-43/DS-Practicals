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

Node *insertNode(Node *root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }
    return root;
}

Node *buildTree()
{
    int data, leftData, rightData;
    Node *root = NULL;
    printf("Enter the root node value: ");
    scanf("%d", &data);
    root = createNode(data);

    Node **queue = (Node **)malloc(100 * sizeof(Node *));
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear)
    {
        Node *current = queue[front++];
        printf("Enter left child of %d (-1 for no child): ", current->data);
        scanf("%d", &leftData);
        if (leftData != -1)
        {
            current->left = createNode(leftData);
            queue[rear++] = current->left;
        }
        printf("Enter right child of %d (-1 for no child): ", current->data);
        scanf("%d", &rightData);
        if (rightData != -1)
        {
            current->right = createNode(rightData);
            queue[rear++] = current->right;
        }
    }

    free(queue);
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

void freeTree(Node *root)
{
    if (root != NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main()
{
    printf( "\n\nKartik Garg \nEnrolment Number - 01813203123 \n");
    printf( "IT - 1\nShift 1\n\n\n");
    
    Node *root = buildTree();
    int choice;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Inorder Traversal\n");
        printf("2. Preorder Traversal\n");
        printf("3. Postorder Traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Inorder Traversal: ");
            inorder(root);
            printf("\n");
            break;
        case 2:
            printf("Preorder Traversal: ");
            preorder(root);
            printf("\n");
            break;
        case 3:
            printf("Postorder Traversal: ");
            postorder(root);
            printf("\n");
            break;
        case 4:
            printf("Exiting...\n");
            freeTree(root);
            exit(0);
            break;
        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
