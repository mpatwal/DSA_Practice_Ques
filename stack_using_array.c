#include <stdio.h>
int stk[5];
int top = -1, n = 5;
void push()
{
    if (top == n - 1)
    {
        printf("Overflow\n");
    }
    else
    {
        top++;
        printf("enter value to be insert ");
        scanf("%d", &stk[top]);
    }
}
void pop()
{
    if (top == -1)
    {
        printf("underflow\n");
    }
    else
    {
        printf("element being deleted %d\n", stk[top]);
        top--;
    }
}
void main()
{
    pop();
    push();
    push();
    pop();
    push();
    push();
    pop();
    pop();
    pop();
    pop();
}
