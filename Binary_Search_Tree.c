#include <stdio.h>
#include <stdlib.h>

// Define a Node structure for the BST
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node in the BST
struct Node *insert(struct Node *node, int value)
{
    if (node == NULL)
    {
        return createNode(value); // If the tree is empty, return a new node
    }

    if (value < node->data)
    {
        node->left = insert(node->left, value); // Recursively insert in the left subtree
    }
    else if (value > node->data)
    {
        node->right = insert(node->right, value); // Recursively insert in the right subtree
    }

    return node;
}

// Function to search a value in the BST
int search(struct Node *node, int value)
{
    if (node == NULL)
    {
        return 0; // Value not found
    }

    if (node->data == value)
    {
        return 1; // Value found
    }

    if (value < node->data)
    {
        return search(node->left, value); // Recursively search in the left subtree
    }
    else
    {
        return search(node->right, value); // Recursively search in the right subtree
    }
}

// Function to find the minimum value in the BST
struct Node *findMin(struct Node *node)
{
    while (node->left != NULL)
    {
        node = node->left;
    }
    return node;
}

// Function to delete a node from the BST
struct Node *deleteNode(struct Node *root, int value)
{
    if (root == NULL)
    {
        return root;
    }

    if (value < root->data)
    {
        root->left = deleteNode(root->left, value); // Traverse left subtree
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value); // Traverse right subtree
    }
    else
    {
        // Node found, now handle its deletion

        // Case 1: Node with only one child or no child
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        // Case 2: Node with two children
        struct Node *temp = findMin(root->right);          // Find the inorder successor
        root->data = temp->data;                           // Replace the node's data with successor's data
        root->right = deleteNode(root->right, temp->data); // Delete the successor
    }
    return root;
}

// Function for Inorder traversal (Left, Root, Right)
void inorder(struct Node *node)
{
    if (node == NULL)
    {
        return;
    }

    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

// Function for Preorder traversal (Root, Left, Right)
void preorder(struct Node *node)
{
    if (node == NULL)
    {
        return;
    }

    printf("%d ", node->data);
    preorder(node->left);
    preorder(node->right);
}

// Function for Postorder traversal (Left, Right, Root)
void postorder(struct Node *node)
{
    if (node == NULL)
    {
        return;
    }

    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->data);
}

int main()
{
    struct Node *root = NULL;
    int choice, value, n, i;

    // Input the entire BST
    printf("Enter the number of elements to insert in the BST: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);
        root = insert(root, value);
    }

    do
    {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert a node\n");
        printf("2. Search for a node\n");
        printf("3. Delete a node\n");
        printf("4. Display Inorder traversal\n");
        printf("5. Display Preorder traversal\n");
        printf("6. Display Postorder traversal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            printf("Value %d inserted into the BST.\n", value);
            break;

        case 2:
            printf("Enter the value to search: ");
            scanf("%d", &value);
            if (search(root, value))
            {
                printf("Value %d found in the BST.\n", value);
            }
            else
            {
                printf("Value %d not found in the BST.\n", value);
            }
            break;

        case 3:
            printf("Enter the value to delete: ");
            scanf("%d", &value);
            root = deleteNode(root, value);
            printf("Value %d deleted from the BST.\n", value);
            break;

        case 4:
            printf("Inorder traversal: ");
            inorder(root);
            printf("\n");
            break;

        case 5:
            printf("Preorder traversal: ");
            preorder(root);
            printf("\n");
            break;

        case 6:
            printf("Postorder traversal: ");
            postorder(root);
            printf("\n");
            break;

        case 7:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice! Please try again.\n");
            break;
        }
    } while (choice != 7);

    return 0;
}
