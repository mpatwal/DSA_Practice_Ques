#include <stdio.h>
int main()
{
    int arr[20], size, i, j, k, l, temp;
    printf("enter the size of the array : ");
    scanf("%d", &size);
    for (i = 0; i < size; i++)
    {
        printf("enter element : ");
        scanf("%d", &arr[i]);
    }
    for (j = 0; j < size - 1; j++)
    {
        for (k = 0; k < size - 1; k++)
        {
            if (arr[k] > arr[k + 1])
            {
                temp = arr[k];
                arr[k] = arr[k + 1];
                arr[k + 1] = temp;
            }
        }
    }
    for (l = 0; l < size; l++)
    {
        printf("%d\t", arr[l]);
    }
}