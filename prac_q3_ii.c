#include <stdio.h>
#include <string.h>
#include <ctype.h>

char key[] = "QWERTYUIOPASDFGHJKLZXCVBNM";

void toLower(char *text)
{
    for (int i = 0; text[i]; i++)
        text[i] = tolower(text[i]);
}

void encrypt(char *text)
{
    for (int i = 0; text[i]; i++)
        if (islower(text[i]))
            text[i] = tolower(key[text[i] - 'a']);
}

void decrypt(char *text)
{
    for (int i = 0; text[i]; i++)
        if (islower(text[i]))
            for (int j = 0; j < 26; j++)
                if (tolower(key[j]) == text[i])
                {
                    text[i] = 'a' + j;
                    break;
                }
}

int main()
{
    char text[100];

    printf("Enter text (no spaces): ");
    scanf("%s", text);

    toLower(text);
    encrypt(text);
    printf("Encrypted: %s\n", text);

    decrypt(text);
    printf("Decrypted: %s\n", text);

    return 0;
}
