#include <stdio.h>
#define MAX 5

int deque[MAX], front = -1, rear = -1;

void insertFront(int val)
{
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
        return;
    if (front == -1)
        front = rear = 0;
    else
        front = (front - 1 + MAX) % MAX;
    deque[front] = val;
}

void insertRear(int val)
{
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
        return;
    if (rear == -1)
        front = rear = 0;
    else
        rear = (rear + 1) % MAX;
    deque[rear] = val;
}

void deleteFront()
{
    if (front == -1)
        return;
    front == rear ? (front = rear = -1) : (front = (front + 1) % MAX);
}

void deleteRear()
{
    if (rear == -1)
        return;
    front == rear ? (front = rear = -1) : (rear = (rear - 1 + MAX) % MAX);
}

void display()
{
    if (front == -1)
        return;
    for (int i = front;; i = (i + 1) % MAX)
    {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
    }
    printf("\n");
}

int main()
{
    insertRear(10);
    insertRear(20);
    insertFront(5);
    insertFront(1);
    display();
    deleteFront();
    deleteRear();
    display();
    return 0;
}
