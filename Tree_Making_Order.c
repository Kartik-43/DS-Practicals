#include <stdio.h>
#include <stdlib.h>

// Node structure for the tree
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int height; // For AVL tree balancing
};

// Utility to create a new node
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1; // Initial height for AVL node
    return newNode;
}

// Utility to find the max of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Height of a node
int height(struct Node *node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

// Right rotate for AVL tree balancing
struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Left rotate for AVL tree balancing
struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Get the balance factor of a node for AVL tree
int getBalance(struct Node *node)
{
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

// Insert node into AVL tree
struct Node *insertAVL(struct Node *node, int value)
{
    if (node == NULL)
        return createNode(value);

    if (value < node->data)
        node->left = insertAVL(node->left, value);
    else if (value > node->data)
        node->right = insertAVL(node->right, value);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    // Balance the AVL tree if necessary
    if (balance > 1 && value < node->left->data)
        return rightRotate(node);
    if (balance < -1 && value > node->right->data)
        return leftRotate(node);
    if (balance > 1 && value > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && value < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Insert node into Binary Search Tree (BST)
struct Node *insertBST(struct Node *node, int value)
{
    if (node == NULL)
        return createNode(value);

    if (value < node->data)
        node->left = insertBST(node->left, value);
    else if (value > node->data)
        node->right = insertBST(node->right, value);

    return node;
}

// Print the tree vertically (preorder-like)
void printTree(struct Node *root, int space)
{
    if (root == NULL)
        return;

    // Increase distance between levels
    space += 5;

    // Print right child first
    printTree(root->right, space);

    // Print current node after space count
    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);

    // Print left child
    printTree(root->left, space);
}

// Utility to print inorder traversal
void inorder(struct Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Utility to print preorder traversal
void preorder(struct Node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Utility to print postorder traversal
void postorder(struct Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Reconstruct binary tree from inorder and preorder traversals
struct Node *buildBinaryTree(int inorder[], int preorder[], int inorderStart, int inorderEnd, int *preorderIndex)
{
    if (inorderStart > inorderEnd)
        return NULL;

    int rootValue = preorder[*preorderIndex];
    (*preorderIndex)++;
    struct Node *root = createNode(rootValue);

    if (inorderStart == inorderEnd)
        return root;

    int inorderIndex;
    for (inorderIndex = inorderStart; inorderIndex <= inorderEnd; inorderIndex++)
    {
        if (inorder[inorderIndex] == rootValue)
            break;
    }

    root->left = buildBinaryTree(inorder, preorder, inorderStart, inorderIndex - 1, preorderIndex);
    root->right = buildBinaryTree(inorder, preorder, inorderIndex + 1, inorderEnd, preorderIndex);

    return root;
}

int main()
{
    int choice, treeType;
    int n, i;
    int preorder[100], inorder[100], postorder[100];
    struct Node *root = NULL;

    printf("Enter the type of traversal you have:\n");
    printf("1. Preorder\n");
    printf("2. Inorder\n");
    printf("3. Postorder\n");
    scanf("%d", &choice);

    printf("Enter the number of elements in the traversal: ");
    scanf("%d", &n);

    printf("Enter the elements of the traversal:\n");
    if (choice == 1)
    {
        printf("Enter Preorder traversal: ");
        for (i = 0; i < n; i++)
            scanf("%d", &preorder[i]);
    }
    else if (choice == 2)
    {
        printf("Enter Inorder traversal: ");
        for (i = 0; i < n; i++)
            scanf("%d", &inorder[i]);
    }
    else if (choice == 3)
    {
        printf("Enter Postorder traversal: ");
        for (i = 0; i < n; i++)
            scanf("%d", &postorder[i]);
    }

    printf("What do you want to create?\n");
    printf("1. Binary Search Tree (BST)\n");
    printf("2. Binary Tree\n");
    printf("3. AVL Tree\n");
    scanf("%d", &treeType);

    switch (treeType)
    {
    case 1:
        printf("Creating a Binary Search Tree (BST)...\n");
        if (choice == 1)
        { // Preorder -> BST
            for (i = 0; i < n; i++)
                root = insertBST(root, preorder[i]);
        }
        else if (choice == 2)
        { // Inorder -> BST
            printf("Cannot build a BST with only inorder traversal.\n");
            return 0;
        }
        else if (choice == 3)
        { // Postorder -> BST
            for (i = n - 1; i >= 0; i--)
                root = insertBST(root, postorder[i]);
        }
        break;

    case 2:
        printf("Creating a Binary Tree...\n");
        if (choice == 1 && choice == 2)
        { // Preorder and Inorder required
            int preorderIndex = 0;
            root = buildBinaryTree(inorder, preorder, 0, n - 1, &preorderIndex);
        }
        else
        {
            printf("Building binary tree requires both inorder and preorder traversals.\n");
            return 0;
        }
        break;

    case 3:
        printf("Creating an AVL Tree...\n");
        if (choice == 1)
        { // Preorder -> AVL Tree
            for (i = 0; i < n; i++)
                root = insertAVL(root, preorder[i]);
        }
        else if (choice == 2)
        { // Inorder -> AVL Tree
            printf("Cannot build an AVL tree with only inorder traversal.\n");
            return 0;
        }
        else if (choice == 3)
        { // Postorder -> AVL Tree
            for (i = n - 1; i >= 0; i--)
                root = insertAVL(root, postorder[i]);
        }
        break;

    default:
        printf("Invalid choice!\n");
        return 0;
    }

    // Display the tree in a vertical format
    printf("\nTree printed vertically (top-down):\n");
    printTree(root, 0);

    return 0;
}
