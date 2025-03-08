#include <stdio.h>
int main()
{
    int choice;
    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Transpose\n");
        printf("2. Addition\n");
        printf("3. Multiplication\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            int Arr[7][3];
            int i, j;
            for (i = 0; i < 7; i++)
            {
                printf("Enter RowNo ColNo and Value: ");
                scanf("%d %d %d", &Arr[i][0], &Arr[i][1], &Arr[i][2]);
            }
            printf("The sparse matrix is:\n");
            int matrix[7][7] = {0};
            for (i = 0; i < 7; i++)
            {
                matrix[Arr[i][0]][Arr[i][1]] = Arr[i][2];
            }
            for (i = 0; i < 7; i++)
            {
                for (j = 0; j < 7; j++)
                {
                    printf("%d ", matrix[i][j]);
                }
                printf("\n");
            }
            // Transpose
            printf("The transpose of the sparse matrix is:\n");
            int transpose[7][7] = {0};
            for (i = 0; i < 7; i++)
            {
                transpose[Arr[i][1]][Arr[i][0]] = Arr[i][2];
            }
            for (i = 0; i < 7; i++)
            {
                for (j = 0; j < 7; j++)
                {
                    printf("%d ", transpose[i][j]);
                }
                printf("\n");
            }
        }
        else if (choice == 2)
        {
            int Arr1[7][3], Arr2[7][3];
            int matrix1[7][7] = {0}, matrix2[7][7] = {0}, result[7][7] = {0};
            int i, j;
            printf("Enter elements for the first sparse matrix:\n");
            for (i = 0; i < 7; i++)
            {
                printf("Enter RowNo ColNo and Value: ");
                scanf("%d %d %d", &Arr1[i][0], &Arr1[i][1], &Arr1[i][2]);
                matrix1[Arr1[i][0]][Arr1[i][1]] = Arr1[i][2];
            }
            printf("Enter elements for the second sparse matrix:\n");
            for (i = 0; i < 7; i++)
            {
                printf("Enter RowNo ColNo and Value: ");
                scanf("%d %d %d", &Arr2[i][0], &Arr2[i][1], &Arr2[i][2]);
                matrix2[Arr2[i][0]][Arr2[i][1]] = Arr2[i][2];
            }
            // Addition
            for (i = 0; i < 7; i++)
            {
                for (j = 0; j < 7; j++)
                {
                    result[i][j] = matrix1[i][j] + matrix2[i][j];
                }
            }
            printf("The sum of the sparse matrices is:\n");
            for (i = 0; i < 7; i++)
            {
                for (j = 0; j < 7; j++)
                {
                    printf("%d ", result[i][j]);
                }
                printf("\n");
            }
        }
        else if (choice == 3)
        {
            int Arr1[7][3], Arr2[7][3];
            int matrix1[7][7] = {0}, matrix2[7][7] = {0}, result[7][7] = {0};
            int i, j, k;
            printf("Enter elements for the first sparse matrix:\n");
            for (i = 0; i < 7; i++)
            {
                printf("Enter RowNo ColNo and Value: ");
                scanf("%d %d %d", &Arr1[i][0], &Arr1[i][1], &Arr1[i][2]);
                matrix1[Arr1[i][0]][Arr1[i][1]] = Arr1[i][2];
            }
            printf("Enter elements for the second sparse matrix:\n");
            for (i = 0; i < 7; i++)
            {
                printf("Enter RowNo ColNo and Value: ");
                scanf("%d %d %d", &Arr2[i][0], &Arr2[i][1], &Arr2[i][2]);
                matrix2[Arr2[i][0]][Arr2[i][1]] = Arr2[i][2];
            }
            // multiplication
            for (i = 0; i < 7; i++)
            {
                for (j = 0; j < 7; j++)
                {
                    for (k = 0; k < 7; k++)
                    {
                        result[i][j] += matrix1[i][k] * matrix2[k][j];
                    }
                }
            }
            printf("The product of the sparse matrices is:\n");
            for (i = 0; i < 7; i++)
            {
                for (j = 0; j < 7; j++)
                {
                    printf("%d ", result[i][j]);
                }
                printf("\n");
            }
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}