#include <stdio.h>
#define MAX 10

int stack[MAX], top = -1;

void push(int patientID)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow! Cannot add more patients.\n");
        return;
    }
    stack[++top] = patientID;
}

void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow! No patients left.\n");
        return;
    }
    printf("Patient ID removed: %d\n", stack[top--]);
}

void display()
{
    if (top == -1)
    {
        printf("No patients attended yet.\n");
        return;
    }
    printf("Patients attended (Last seen first): ");
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int main()
{
    push(101);
    push(102);
    push(103);
    display();
    pop();
    display();
    push(104);
    push(105);
    display();
    return 0;
}
