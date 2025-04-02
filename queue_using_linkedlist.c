#include <stdio.h>
#include <stdlib.h>
struct lst
{
    int data;
    struct lst *next;
};
struct lst *front = NULL;
struct lst *rear = NULL;
void in_queue()
{
    struct lst *node = (struct lst *)malloc(sizeof(struct lst));
    if (node == NULL)
    {
        printf("Overflow\n");
        return;
    }
    else
    {
        printf("Enter value \n");
        scanf("%d", &node->data);
        node->next = NULL;
        if (rear == NULL)
        {
            rear = front = node;
        }
        else
        {
            rear->next = node;
            rear = node;
        }
    }
}
void del_queue()
{
    if (front == NULL)
    {
        printf("Underflow\n");
        return;
    }
    else
    {
        struct lst *d = front;
        printf("Deleted element: %d\n", d->data);
        front = front->next;
        free(d);
        if (front == NULL)
        {
            rear = NULL;
        }
    }
}
int main()
{
    del_queue();
    in_queue();
    in_queue();
    del_queue();
    del_queue();
    del_queue();
    del_queue();

    return 0;
}
