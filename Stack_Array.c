#include <stdio.h>
#include <stdlib.h>

int *stack;       
int top = -1, max;

void push()
{
    int value;
    if (top == max - 1)
    {
        printf("Stack Overflow! Cannot push more elements.\n");
    }
    else
    {
        printf("Enter the value to push: ");
        scanf("%d", &value);
        top++;
        stack[top] = value;
        printf("%d pushed onto the stack.\n", value);
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow! No elements to pop.\n");
    }
    else
    {
        printf("%d popped from the stack.\n", stack[top]);
        top--;
    }
}

void show()
{
    if (top == -1)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

int main()
{
    printf( "\n\nKartik Garg \nEnrolment Number - 01813203123 \n");
    printf( "IT - 1\nShift 1\n\n\n");

    int choice;

    printf("Enter the maximum size of the stack: ");
    scanf("%d", &max);

    stack = (int *)malloc(max * sizeof(int));

    if (stack == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

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
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            show();
            break;

        case 4:
            printf("Exiting...\n");
            free(stack);
            exit(0);

        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
