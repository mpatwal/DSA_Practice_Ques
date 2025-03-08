#include <stdio.h>

int main()
{
    printf(" // Enter sorted arrays // \n");

    int arr1[10], arr2[10], i, j, k, s1, s2;

    // Input for first array
    printf("Enter size of array 1: ");
    scanf("%d", &s1);
    for (i = 0; i < s1; i++)
    {
        printf("Enter element %d for array1: ", i + 1);
        scanf("%d", &arr1[i]);
    }

    // Input for second array
    printf("Enter size of array 2: ");
    scanf("%d", &s2);
    for (j = 0; j < s2; j++)
    {
        printf("Enter element %d for array2: ", j + 1);
        scanf("%d", &arr2[j]);
    }

    // Finding common elements
    printf("// Common elements //\n");
    for (i = 0; i < s1; i++)
    {
        for (j = 0; j < s2; j++)
        {
            if (arr1[i] == arr2[j])
            {
                printf("%d\t", arr1[i]);
                break; // Prevent duplicate prints if numbers repeat in arr2
            }
        }
    }

    printf("\n"); // New line for better formatting
    return 0;
}
