#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void enqueue(Node **front, Node **rear, int value)
{
    Node *newNode = createNode(value);
    if (*rear == NULL)
    {
        *front = *rear = newNode;
    }
    else
    {
        (*rear)->next = newNode;
        *rear = newNode;
    }
    printf("%d enqueued to the queue.\n", value);
}

void dequeue(Node **front, Node **rear)
{
    if (*front == NULL)
    {
        printf("Queue Underflow! No elements to dequeue.\n");
    }
    else
    {
        Node *temp = *front;
        printf("%d dequeued from the queue.\n", temp->data);
        *front = (*front)->next;
        if (*front == NULL)
        {
            *rear = NULL;
        }
        free(temp);
    }
}

void display(Node *front)
{
    if (front == NULL)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        printf("Queue elements are:\n");
        Node *temp = front;
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

    Node *front = NULL;
    Node *rear = NULL;
    int choice, value;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to enqueue: ");
            scanf("%d", &value);
            enqueue(&front, &rear, value);
            break;
        case 2:
            dequeue(&front, &rear);
            break;
        case 3:
            display(front);
            break;
        case 4:
            printf("Exiting...\n");
            while (front != NULL)
            {
                Node *temp = front;
                front = front->next;
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
