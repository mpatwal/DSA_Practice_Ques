#include <stdio.h>
#define MAX 10

int stack[MAX], top1 = -1, top2 = MAX;

void push1(int val)
{
    if (top1 + 1 == top2)
        return;
    stack[++top1] = val;
}

void push2(int val)
{
    if (top2 - 1 == top1)
        return;
    stack[--top2] = val;
}

void pop1()
{
    if (top1 >= 0)
        top1--;
}

void pop2()
{
    if (top2 < MAX)
        top2++;
}

void display()
{
    printf("Stack 1: ");
    for (int i = 0; i <= top1; i++)
    {
        printf("%d ", stack[i]);
    }

    printf("\nStack 2: ");
    for (int i = MAX - 1; i >= top2; i--)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main()
{
    push1(10);
    push1(20);
    push2(30);
    push2(40);
    display();
    pop1();
    pop2();
    display();
    return 0;
}
