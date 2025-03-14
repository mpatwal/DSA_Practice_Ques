#include <stdio.h>
void main()
{
    int front = -1, rear = -1, n, que_arr[n];
    printf("enter the sizr of the array \t : ");
    scanf("%d", &n);
}
void insert()
{
    int front = -1, rear = -1, n, que_arr[n];
    if (rear == n - 1)
    {
        printf("overflow");
    }
    else
    {
        rear++;
        printf("enter the element : \t");
        scanf("%d", que_arr[rear]);
    }
    front++;
}
void del()
{
    int front = -1, rear = -1, n, que_arr[n];
    if (front == -1 || front > rear)
    {
        printf("underflow");
    }
    else
    {
        front++;
        printf("element being deleted : ", que_arr[front]);
    }
}