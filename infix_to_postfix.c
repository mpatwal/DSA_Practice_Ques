#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char infix_exp[10], postfix_exp[10];
char stack[10];
int top = -1;
int is_operator(char symbol)
{
    if (symbol == '^' || symbol == '/' || symbol == '*' || symbol == '+' || symbol == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int preced(char symbol)
{
    if (symbol == '^')
    {
        return (3);
    }
    else if (symbol == '/' || symbol == '*')
    {
        return (2);
    }
    else if (symbol == '-' || symbol == '+')
    {
        return (1);
    }
    else
    {
        return (0);
    }
}

void push(char item)
{
    if (top == 9) // Fixed overflow check
    {
        printf("\nStack Overflow.\n");
    }
    else
    {
        top = top + 1;
        stack[top] = item;
    }
}

char pop()
{
    char item;

    if (top == -1)
    {
        printf("\nStack Underflow.\n");
        exit(1);
    }
    else
    {
        item = stack[top];
        top = top - 1;
        return (item);
    }
}

void InfixToPostfix()
{
    int i, j;
    char item;
    char x;

    push('(');
    i = 0;
    j = 0;
    strcat(infix_exp, ")"); // Append ')' to the input string
    item = infix_exp[i];

    while (item != '\0')
    {
        if (item == '(')
        {
            push(item);
        }
        else if (isdigit(item) || isalpha(item))
        {
            postfix_exp[j] = item;
            j++;
        }
        else if (is_operator(item) == 1)
        {
            x = pop();
            while (is_operator(x) == 1 && preced(x) >= preced(item))
            {
                postfix_exp[j] = x;
                j++;
                x = pop();
            }
            push(x);
            push(item);
        }
        else if (item == ')')
        {
            x = pop();
            while (x != '(')
            {
                postfix_exp[j] = x;
                j++;
                x = pop();
            }
        }
        else
        {
            printf("\nInvalid infix Expression.\n");
            exit(1);
        }
        i++;
        item = infix_exp[i];
    }
    if (top > 0)
    {
        printf("\nInvalid infix Expression.\n");
        exit(1);
    }

    postfix_exp[j] = '\0';
}

void main()
{
    printf("\nEnter Infix expression (max 9 characters): ");
    scanf("%9s", infix_exp); // Prevent buffer overflow

    InfixToPostfix();
    printf("Postfix Expression: ");
    puts(postfix_exp);
}
