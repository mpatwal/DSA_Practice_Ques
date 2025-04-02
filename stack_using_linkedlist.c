#include <stdio.h>
#include <stdlib.h>

struct list
{
    int data;
    struct list *next;
};
struct list *head = NULL;
void push()
{
    struct list *node = (struct list *)malloc(sizeof(struct list));
    if (node == NULL)
    {
        printf("overflow\n");
    }
    else
    {
        printf("enter the element : \n");
        scanf("%d", &node->data);

        node->next = head;
        head = node;
    }
}

void pop()
{
    if (head == NULL)
    {
        printf("underflow\n");
    }
    else
    {
        struct list *t = head;
        printf("Popped element: %d\n", t->data);
        head = head->next;
        free(t);
    }
}
void main()
{
    pop();
    push();
    push();
    pop();
    pop();
    pop();
}
