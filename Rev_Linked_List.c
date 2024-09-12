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

void insertAtEnd(struct Node **head, int value)
{
    struct Node *newNode = createNode(value);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void reverseList(struct Node **head)
{
    struct Node *prev = NULL, *current = *head, *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void display(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    printf( "\n\nKartik Garg \nEnrolment Number - 01813203123 \n");
    printf( "IT - 1\nShift 1\n\n\n");

    struct Node *head = NULL;
    int choice, value;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert at End\n");
        printf("2. Display List\n");
        printf("3. Reverse List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\n\t===> Enter value to insert: ");
            scanf("%d", &value);
            insertAtEnd(&head, value);
            break;

        case 2:
            printf("\nLinked List: ");
            display(head);
            break;

        case 3:
            reverseList(&head);
            printf("\nLinked List Reversed!\n");
            break;

        case 4:
            printf("\n\nExiting...\n\n\n");
            exit(0);
            break;

        default:
            printf("Invalid choice! Try again.\n");
        }
    }


    return 0;
}
