#include <stdio.h>
#include <stdlib.h>


#include<stdio.h>

int main()
{
    printf( "\n\nKartik Garg \nEnrolment Number - 01813203123 \n");
    printf( "IT - 1\nShift 1\n\n\n");

    int *arr, pos, i, n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("\nEnter %d elements:\n", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\n\nEnter the position of the element to delete (1 to %d): ", n);
    scanf("%d", &pos);

    if (pos <= 0 || pos > n)
    {
        printf("Invalid position!\n");
    }

    else
    {
        for (i = pos - 1; i < n - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        n--;

        printf("\n\nArray after deletion:\n");
        for (i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    free(arr);

    return 0;
}
