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


void insertAtFront(struct Node **head, int value)
{
    struct Node *newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
    printf("\nInserted succesfully !\n");
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
    printf("\nInserted succesfully !\n");
}


void insertAtPosition(struct Node **head, int value, int position)
{
    struct Node *newNode = createNode(value);
    if (position == 1)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Invalid position!\n");
        free(newNode);
    }
    else
    {
        newNode->next = temp->next;
        temp->next = newNode;
        printf("\nInserted succesfully !\n");
    }
}


void deleteFirst(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);
    printf("\nDeleted succesfully !\n");
}


void deleteEnd(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node *temp = *head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    printf("\nDeleted succesfully !\n");
}


void deletePosition(struct Node **head, int position)
{
    if (*head == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    struct Node *temp = *head;
    if (position == 1)
    {
        *head = (*head)->next;
        free(temp);
        return;
    }
    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL)
    {
        printf("Invalid position!\n");
    }
    else
    {
        struct Node *nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        free(nodeToDelete);
        printf("\nDeleted succesfully !\n");
    }
}


void display(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    struct Node *temp = head;
    printf("Linked List: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main()
{
    printf("\n\nKartik Garg \nEnrolment Number - 01813203123 \n");
    printf("IT - 1\nShift 1\n\n\n");

    struct Node *head = NULL;
    int choice, value, position;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete First\n");
        printf("5. Delete End\n");
        printf("6. Delete Position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert at front: ");
            scanf("%d", &value);
            insertAtFront(&head, value);
            break;

        case 2:
            printf("Enter value to insert at end: ");
            scanf("%d", &value);
            insertAtEnd(&head, value);
            break;

        case 3:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            printf("Enter position: ");
            scanf("%d", &position);
            insertAtPosition(&head, value, position);
            break;

        case 4:
            deleteFirst(&head);
            break;

        case 5:
            deleteEnd(&head);
            break;

        case 6:
            printf("Enter position to delete: ");
            scanf("%d", &position);
            deletePosition(&head, position);
            break;

        case 7:
            display(head);
            break;

        case 8:
            printf("Exiting...\n");
            exit(0);
            break;

        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
