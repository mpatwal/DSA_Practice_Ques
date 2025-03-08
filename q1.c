#include <stdio.h>

int binary_search(int arr[], int size, int element)
{
    int lo = 0, mid, hi = size - 1;
    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid] < element)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    return -1;
}
void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void freq(int arr[], int size)
{
    printf("element frequency : \n");
    int i, count;
    for (i = 0; i < size; i++)
    {
        if (i == 0 || arr[i] != arr[i - 1])
        {
            count = 1;
            while (i + 1 < size && arr[i] == arr[i + 1])
            {
                count++;
                i++;
            }
            printf("%d -> %d\n", arr[i], count);
        }
    }
}
int main()
{
    int arr[50], size, element;
    printf("enter the size of the array : ");
    scanf("%d", &size);
    printf("enter the elements of the array : \n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    bubbleSort(arr, size);
    printf("eneter element to search : ");
    scanf("%d", &element);
    int index = binary_search(arr, size, element);
    if (index != -1)
    {
        printf("element %d found at index %d.(after sorting)\n", element, index);
    }
    else
    {
        printf("element %d not found in the array.\n", element);
    }
    freq(arr, size);
    return 0;
}