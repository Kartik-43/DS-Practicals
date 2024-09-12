#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void push(struct Node **top, int value)
{
    struct Node *newNode = createNode(value);
    newNode->next = *top;
    *top = newNode;
    printf("%d pushed onto the stack.\n", value);
}

void pop(struct Node **top)
{
    if (*top == NULL)
    {
        printf("Stack Underflow! No elements to pop.\n");
    }
    else
    {
        struct Node *temp = *top;
        *top = (*top)->next;
        printf("%d popped from the stack.\n", temp->data);
        free(temp);
    }
}

void show(struct Node *top)
{
    if (top == NULL)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("Stack elements are:\n");
        struct Node *temp = top;
        while (temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

int main()
{
    printf( "\n\nKartik Garg \nEnrolment Number - 01813203123 \n");
    printf( "IT - 1\nShift 1\n\n\n");

    struct Node *top = NULL;
    int choice, value;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Show\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to push: ");
            scanf("%d", &value);
            push(&top, value);
            break;
        case 2:
            pop(&top);
            break;
        case 3:
            show(top);
            break;
        case 4:
            printf("Exiting...\n");
            while (top != NULL)
            {
                struct Node *temp = top;
                top = top->next;
                free(temp);
            }
            exit(0);
            break;
        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
