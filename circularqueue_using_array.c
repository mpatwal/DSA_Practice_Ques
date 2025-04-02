#include <stdio.h>
#define max 5
int front = -1, rear = -1;
int que[max];
void insert()
{
    int item;
    printf("enter element : ");
    scanf("%d", &item);
    if ((front == 0 && rear == max - 1) || (front == rear + 1))
    {
        printf("overflow\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % max;
        }
        que[rear] = item;
    }
}
void del()
{
    if (front == -1)
    {
        printf("underflow\n");
    }
    else if (front == rear)
    {
        printf("element being deleted %d\n", que[front]);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("element being deleted %d\n", que[front]);
        front = (front + 1) % max;
    }
}
int main()
{
    del();
    insert();
    insert();
    insert();
    del();
}