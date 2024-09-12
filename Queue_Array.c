#include <stdio.h>
#include <stdlib.h>

int *queue;
int front = 0;
int rear = -1;
int size = 0;
int capacity;

int isFull()
{
    return size == capacity;
}

int isEmpty()
{
    return size == 0;
}

void enqueue()
{
    int value;
    if (isFull())
    {
        printf("Queue Overflow! Cannot enqueue more elements.\n");
    }
    else
    {
        printf("Enter the value to enqueue: ");
        scanf("%d", &value);
        rear = (rear + 1) % capacity;
        queue[rear] = value;
        size++;
        printf("%d enqueued to the queue.\n", value);
    }
}

void dequeue()
{
    if (isEmpty())
    {
        printf("Queue Underflow! No elements to dequeue.\n");
    }
    else
    {
        printf("%d dequeued from the queue.\n", queue[front]);
        front = (front + 1) % capacity;
        size--;
    }
}

void display()
{
    if (isEmpty())
    {
        printf("Queue is empty!\n");
    }
    else
    {
        printf("Queue elements are:\n");
        for (int i = 0; i < size; i++)
        {
            printf("%d\n", queue[(front + i) % capacity]);
        }
    }
}

int main()
{
    printf( "\n\nKartik Garg \nEnrolment Number - 01813203123 \n");
    printf( "IT - 1\nShift 1\n\n\n");

    int choice;

    printf("Enter the capacity of the queue: ");
    scanf("%d", &capacity);

    queue = (int *)malloc(capacity * sizeof(int));
    if (queue == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

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
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting...\n");
            free(queue);
            exit(0);
            break;
        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
