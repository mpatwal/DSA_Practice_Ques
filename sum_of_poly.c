#include <stdlib.h>
#include <stdio.h>

struct Poly {
    int coffi, power;
    struct Poly *next;
};

struct Poly *Poly_1 = NULL, *Poly_2 = NULL, *Result = NULL;

void Create_Poly_1() {
    struct Poly *node, *t;
    int i;
    for (i = 1; i <= 3; i++) {
        node = (struct Poly *)malloc(sizeof(struct Poly));
        printf("\nEnter power & coefficient: ");
        scanf("%d %d", &node->power, &node->coffi);
        node->next = NULL;
        if (Poly_1 == NULL)
            Poly_1 = node;
        else {
            t = Poly_1;
            while (t->next != NULL)
                t = t->next;
            t->next = node;
        }
    }
}

void Create_Poly_2() {
    struct Poly *node, *t;
    int i;
    for (i = 1; i <= 3; i++) {
        node = (struct Poly *)malloc(sizeof(struct Poly));
        printf("\nEnter power & coefficient: ");
        scanf("%d %d", &node->power, &node->coffi);
        node->next = NULL;
        if (Poly_2 == NULL)
            Poly_2 = node;
        else {
            t = Poly_2;
            while (t->next != NULL)
                t = t->next;
            t->next = node;
        }
    }
}

void Traversal_Poly_1() {
    struct Poly *t = Poly_1;
    while (t != NULL) {
        printf("\n %d x^%d", t->coffi, t->power);
        t = t->next;
    }
}

void Traversal_Poly_2() {
    struct Poly *t = Poly_2;
    while (t != NULL) {
        printf("\n %d x^%d", t->coffi, t->power);
        t = t->next;
    }
}

void Display_Resultant_Poly() {
    struct Poly *t = Result;
    while (t != NULL) {
        printf("\n %d x^%d", t->coffi, t->power);
        t = t->next;
    }
}

void Add_Poly() {
    struct Poly *t1 = Poly_1, *t2 = Poly_2, *node, *t;

    while ((t1 != NULL) && (t2 != NULL)) {
        node = (struct Poly *)malloc(sizeof(struct Poly));
        node->next = NULL;

        if (t1->power > t2->power) {
            node->power = t1->power;
            node->coffi = t1->coffi;
            t1 = t1->next;
        } else if (t2->power > t1->power) {
            node->power = t2->power;
            node->coffi = t2->coffi;
            t2 = t2->next;
        } else { 
            node->power = t1->power;
            node->coffi = t1->coffi + t2->coffi;
            t1 = t1->next;
            t2 = t2->next;
        }

        if (Result == NULL) {
            Result = node;
        } else {
            t = Result;
            while (t->next != NULL)
                t = t->next;
            t->next = node;
        }
    }

    // Append remaining nodes of longer polynomial
    if (t1 != NULL) {
        t = Result;
        while (t->next != NULL)
            t = t->next;
        t->next = t1;
    }
    if (t2 != NULL) {
        t = Result;
        while (t->next != NULL)
            t = t->next;
        t->next = t2;
    }
}

int main() {
    int Choice;

    do {
        printf("\n 1. Create Polynomial 1");
        printf("\n 2. Create Polynomial 2");
        printf("\n 3. Display Polynomial 1");
        printf("\n 4. Display Polynomial 2");
        printf("\n 5. Add 2 Polynomials");
        printf("\n 6. Display Resultant Polynomial");
        printf("\n 7. Exit");
        printf("\n Enter your choice: ");
        scanf("%d", &Choice);

        switch (Choice) {
            case 1:
                Create_Poly_1();
                break;
            case 2:
                Create_Poly_2();
                break;
            case 3:
                Traversal_Poly_1();
                break;
            case 4:
                Traversal_Poly_2();
                break;
            case 5:
                Add_Poly();
                break;
            case 6:
                Display_Resultant_Poly();
                break;
            case 7:
                break;
            default:
                printf("\n Please choose a valid option");
        }
    } while (Choice != 7);

    return 0;
}
