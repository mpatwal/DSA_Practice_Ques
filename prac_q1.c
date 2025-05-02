#include <stdio.h>
#include <string.h>

int main()
{
    char *str = "Hello World";
    int len = strlen(str); // this gives 11

    for (int i = 0; i < len; i++)
    {
        printf("%c", str[i]);
    }

    printf("\n");
    return 0;
}
