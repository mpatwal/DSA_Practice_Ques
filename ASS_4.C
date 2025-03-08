#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int coef;
    int power;
    struct Node *next;
};
struct Node *createNode(int coef, int power)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->coef = coef;
    newNode->power = power;
    newNode->next = NULL;
    return newNode;
}
void insert(struct Node **t, int coef, int power)
{
    struct Node *newNode = createNode(coef, power);
    if (*t == NULL)
    {
        *t = newNode;
    }
    else
    {
        struct Node *temp = *t;
        while (temp->next != NULL && temp->power > power)
        {
            temp = temp->next;
        }

        if (temp->next == NULL || temp->power < power)
        {
            newNode->next = temp->next;
            temp->next = newNode;
        }
        else if (temp->power == power)
        {
            temp->coef += coef;
            free(newNode);
        }
    }
}
void display(struct Node *t)
{
    struct Node *temp = t;
    while (temp != NULL)
    {
        if (temp->coef > 0 && temp != t)
            printf("+");
        printf("%dx^%d ", temp->coef, temp->power);
        temp = temp->next;
    }
    printf("\n");
}
struct Node *addPolynomials(struct Node *t1, struct Node *t2)
{
    struct Node *result = NULL;
    while (t1 != NULL && t2 != NULL)
    {
        if (t1->power > t2->power)
        {
            insert(&result, t1->coef, t1->power);
            t1 = t1->next;
        }
        else if (t1->power < t2->power)
        {
            insert(&result, t2->coef, t2->power);
            t2 = t2->next;
        }
        else
        {
            insert(&result, t1->coef + t2->coef, t1->power);
            t1 = t1->next;
            t2 = t2->next;
        }
    }
    while (t1 != NULL)
    {
        insert(&result, t1->coef, t1->power);
        t1 = t1->next;
    }
    while (t2 != NULL)
    {
        insert(&result, t2->coef, t2->power);
        t2 = t2->next;
    }
    return result;
}
int main()
{
    struct Node *poly1 = NULL;
    struct Node *poly2 = NULL;
    struct Node *sum = NULL;
    insert(&poly1, 34, 0);
    insert(&poly1, 5, 4);
    insert(&poly1, 2, 7);
    insert(&poly2, 21, 0);
    insert(&poly2, 12, 1);
    insert(&poly2, 2, 2);
    printf("Polynomial 1: ");
    display(poly1);

    printf("Polynomial 2: ");
    display(poly2);

    sum = addPolynomials(poly1, poly2);
    printf("Sum of Polynomials: ");
    display(sum);
    return 0;
}