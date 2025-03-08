#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insert(struct Node **t, int data)
{
    struct Node *newNode = createNode(data);
    if (*t == NULL)
    {
        *t = newNode;
    }
    else
    {
        struct Node *temp = *t;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void display(struct Node *t)
{
    struct Node *temp = t;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
struct Node *mergeSortedLists(struct Node *t1, struct Node *t2)
{
    struct Node *mergedHead = NULL;
    struct Node *current = NULL;
    while (t1 != NULL && t2 != NULL)
    {
        struct Node *newNode = NULL;
        if (t1->data < t2->data)
        {
            newNode = createNode(t1->data);
            t1 = t1->next;
        }
        else if (t1->data > t2->data)
        {
            newNode = createNode(t2->data);
            t2 = t2->next;
        }
        else
        {
            newNode = createNode(t1->data);
            t1 = t1->next;
            t2 = t2->next;
        }
        if (mergedHead == NULL)
        {
            mergedHead = newNode;
            current = mergedHead;
        }
        else
        {
            current->next = newNode;
            current = current->next;
        }
    }

    while (t1 != NULL)
    {
        struct Node *newNode = createNode(t1->data);
        current->next = newNode;
        current = current->next;
        t1 = t1->next;
    }
    while (t2 != NULL)
    {
        struct Node *newNode = createNode(t2->data);
        current->next = newNode;
        current = current->next;
        t2 = t2->next;
    }
    return mergedHead;
}
int main()
{
    struct Node *list1 = NULL;
    struct Node *list2 = NULL;
    struct Node *mergedList = NULL;
    insert(&list1, 1);
    insert(&list1, 3);
    insert(&list1, 5);
    insert(&list2, 2);
    insert(&list2, 4);
    insert(&list2, 6);
    printf("List 1: ");
    display(list1);
    printf("List 2: ");
    display(list2);
    mergedList = mergeSortedLists(list1, list2);
    printf("Merged Sorted List: ");
    display(mergedList);
    return 0;
}
