#include <stdio.h>

int front = -1, rear = -1;
#define SIZE 5
int que_arr[SIZE];

void insert()
{
    if (rear == SIZE - 1)
    {
        printf("Queue overflow\n");
        return;
    }
    else
    {
        rear++;
        printf("Enter the element: ");
        scanf("%d", &que_arr[rear]);

        if (front == -1)
            front++;
    }
}

void del()
{
    if (front == -1 || front > rear)
    {
        printf("Queue underflow\n");
        front = rear = -1;
    }
    else
    {
        printf("Element being deleted: %d\n", que_arr[front]);
        front++;
    }
}

int main()
{
    del();
    insert();
    insert();
    del();
    del();
    del();
    insert();
    insert();
    insert();
    insert();
    insert();
    insert();
    return 0;
}
