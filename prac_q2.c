#include <stdio.h>
#include <string.h>

int main()
{
    char *str = "Hello World";
    int len = strlen(str);

    printf("Original: %s\n", str);
    printf("AND with 127: ");
    for (int i = 0; i < len; i++)
    {
        printf("%c", str[i] & 127);
    }

    printf("\n OR with 127: ");
    for (int i = 0; i < len; i++)
    {
        printf("%c", str[i] | 127);
    }

    printf("\n XOR with 127: ");
    for (int i = 0; i < len; i++)
    {
        printf("%c", str[i] ^ 127);
    }

    printf("\n");
    return 0;
}
