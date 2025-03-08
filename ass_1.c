#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;
void create(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    head = newNode;
}
void insLast(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void insBeg(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}
void insAfter(int data, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;
    newNode->data = data;
    while (temp != NULL && temp->data != value)
    {
        temp = temp->next;
    }
    if (temp != NULL)
    {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}
void insBefore(int data, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;
    newNode->data = data;
    if (head != NULL && head->data == value)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        while (temp != NULL && temp->next != NULL && temp->next->data != value)
        {
            temp = temp->next;
        }
        if (temp != NULL && temp->next != NULL)
        {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}
void delLast()
{
    if (head == NULL)
        return;
    struct Node *temp = head;
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}
void delBeg()
{
    if (head == NULL)
        return;
    struct Node *temp = head;
    head = head->next;
    free(temp);
}
void delAfter(int value)
{
    struct Node *temp = head;
    while (temp != NULL && temp->data != value)
    {
        temp = temp->next;
    }
    if (temp != NULL && temp->next != NULL)
    {
        struct Node *toDelete = temp->next;
        temp->next = temp->next->next;
        free(toDelete);
    }
}
void delBefore(int value)
{
    struct Node *temp = head;
    if (temp != NULL && temp->next != NULL && temp->next->data == value)
    {
        head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->next != NULL && temp->next->next != NULL && temp->next->next->data != value)
    {
        temp = temp->next;
    }
    if (temp != NULL && temp->next != NULL && temp->next->next != NULL)
    {
        struct Node *toDelete = temp->next;
        temp->next = temp->next->next;
        free(toDelete);
    }
}
void display()
{
    struct Node *temp = head;
    if (temp == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main()
{
    create(10);
    insLast(20);
    insBeg(5);
    insAfter(15, 10);
    insBefore(25, 20);
    display();
    delLast();
    display();
    delBeg();
    display();
    delAfter(15);
    display();
    delBefore(25);
    display();
    return 0;
}
