#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Convert the entire string to lowercase
void toLowerCase(char *text)
{
    int len = strlen(text);
    for (int i = 0; i < len; i++)
    {
        text[i] = tolower(text[i]);
    }
}

// Encrypt lowercase-only string
void encrypt(char *text, int shift)
{
    int len = strlen(text);
    for (int i = 0; i < len; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            text[i] = (text[i] - 'a' + shift) % 26 + 'a';
        }
    }
}

// Decrypt lowercase-only string
void decrypt(char *text, int shift)
{
    int len = strlen(text);
    for (int i = 0; i < len; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            text[i] = (text[i] - 'a' - shift + 26) % 26 + 'a';
        }
    }
}

int main()
{
    char text[100];
    int shift;

    printf("Enter text (no spaces): ");
    scanf("%s", text);

    toLowerCase(text); // Convert to lowercase first

    printf("Enter shift value: ");
    scanf("%d", &shift);

    encrypt(text, shift);
    printf("Encrypted text: %s\n", text);

    decrypt(text, shift);
    printf("Decrypted text: %s\n", text);

    return 0;
}
