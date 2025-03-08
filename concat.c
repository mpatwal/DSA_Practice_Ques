#include <stdlib.h>
#include <stdio.h>

struct List
{
    int Enroll;
    struct List *next;
};

struct List *Head1 = NULL, *Head2 = NULL;

// Function prototypes
void create1();
void create2();
void concat();
void Traversal(struct List *head);

int main()
{
    create1();
    create2();

    printf("\n1st List:");
    Traversal(Head1);

    printf("\n2nd List:");
    Traversal(Head2);

    concat();

    printf("\nConcatenated List:");
    Traversal(Head1);

    return 0;
}

// Function to create the first linked list
void create1()
{
    int i;
    struct List *Node, *t;
    for (i = 1; i <= 3; i++)
    {
        Node = (struct List *)malloc(sizeof(struct List));
        printf("\nEnter element for 1st list: ");
        scanf("%d", &Node->Enroll);
        Node->next = NULL;

        if (Head1 == NULL)
            Head1 = Node;
        else
        {
            t = Head1;
            while (t->next != NULL)
                t = t->next;
            t->next = Node;
        }
    }
}

// Function to create the second linked list
void create2()
{
    int i;
    struct List *Node, *t;
    for (i = 1; i <= 4; i++)
    {
        Node = (struct List *)malloc(sizeof(struct List));
        printf("\nEnter element for 2nd list: ");
        scanf("%d", &Node->Enroll);
        Node->next = NULL;

        if (Head2 == NULL)
            Head2 = Node;
        else
        {
            t = Head2;
            while (t->next != NULL)
                t = t->next;
            t->next = Node;
        }
    }
}

// Function to concatenate the two linked lists
void concat()
{
    if (Head1 == NULL)
    { // If the first list is empty, assign Head2 to Head1
        Head1 = Head2;
        return;
    }

    struct List *t = Head1;
    while (t->next != NULL)
    {
        t = t->next;
    }
    t->next = Head2;
}

void Traversal(struct List *head)
{
    struct List *t = head;
    while (t != NULL)
    {
        printf(" %d ->", t->Enroll);
        t = t->next;
    }
    printf(" NULL\n");
