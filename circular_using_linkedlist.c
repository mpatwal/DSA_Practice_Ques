#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} Node;

struct Node *front = NULL;
struct Node *rear = NULL;

void insert()
{
    int item;
    printf("Enter element: ");
    scanf("%d", &item);

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory Overflow\n");
        return;
    }

    newNode->data = item;
    newNode->next = NULL;

    if (front == NULL)
    {
        front = newNode;
        rear = newNode;
        rear->next = front;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }
}

void del()
{
    if (front == NULL)
    {
        printf("Queue Underflow\n");
        return;
    }

    struct Node *temp = front;
    printf("Element being deleted: %d\n", temp->data);

    if (front == rear)
    {
        front = NULL;
        rear = NULL;
    }
    else
    {
        front = front->next;
        rear->next = front;
    }

    free(temp);
}
void display()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    struct Node *temp = front;
    printf("Queue elements: ");
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
    printf("\n");
}

int main()
{
    insert();
    insert();
    insert();
    display();
    del();
    display();
    insert();
    display();
    return 0;
}
