#include <stdio.h>
#include <stdlib.h> // For qsort

// Comparison function for qsort
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void findCommon(int arr1[], int m, int arr2[], int n)
{
    // Sort both arrays first
    qsort(arr1, m, sizeof(int), compare);
    qsort(arr2, n, sizeof(int), compare);

    int i = 0, j = 0;
    printf("\n Common elements in both the arrays : ");
    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
            i++;
        else if (arr1[i] > arr2[j])
            j++;
        else
        {
            printf("%d ", arr1[i]); // Print common element
            int temp = arr1[i];
            while (i < m && arr1[i] == temp)
                i++; // Skip duplicates in arr1
            while (j < n && arr2[j] == temp)
                j++; // Skip duplicates in arr2
        }
    }
    printf("\n");
}

void mergeArrays(int arr1[], int m, int arr2[], int n, int merged[])
{
    int i = 0, j = 0, k = 0;
    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
            merged[k++] = arr1[i++];
        else
            merged[k++] = arr2[j++];
    }
    while (i < m)
        merged[k++] = arr1[i++]; // Copy remaining elements
    while (j < n)
        merged[k++] = arr2[j++]; // Copy remaining elements
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr1[] = {1, 3, 7, 12, 10, 5};
    int arr2[] = {3, 4, 1, 9, 5, 6, 7};

    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);

    printf("Array 1:\n");
    for (int a = 0; a < m; a++)
    {
        printf("%d\t", arr1[a]);
    }
    printf("\nArray 2:\n");
    for (int b = 0; b < n; b++)
    {
        printf("%d\t", arr2[b]);
    }

    findCommon(arr1, m, arr2, n);

    int merged[m + n];
    mergeArrays(arr1, m, arr2, n, merged);

    printf("Merged Array: ");
    printArray(merged, m + n);

    return 0;
}
