#include <stdio.h>
#include <string.h>

// RC4 Encryption function
void rc4(char *key, char *data)
{
    int S[256], K[256], i, j = 0, t, k;
    int len_key = strlen(key);
    int len_data = strlen(data);

    // Key scheduling algorithm (KSA)
    for (i = 0; i < 256; i++)
    {
        S[i] = i;
        K[i] = key[i % len_key];
    }

    for (i = 0; i < 256; i++)
    {
        j = (j + S[i] + K[i]) % 256;
        t = S[i];
        S[i] = S[j];
        S[j] = t;
    }

    // Pseudo-random generation algorithm (PRGA)
    i = 0;
    j = 0;
    for (k = 0; k < len_data; k++)
    {
        i = (i + 1) % 256;
        j = (j + S[i]) % 256;
        t = S[i];
        S[i] = S[j];
        S[j] = t;
        data[k] = data[k] ^ S[(S[i] + S[j]) % 256];
    }
}

int main()
{
    char key[] = "mysecretkey";  // Custom key
    char data[] = "hello world"; // Text to encrypt

    printf("Original text: %s\n", data);

    rc4(key, data); // Encrypt the data using RC4

    printf("Encrypted text: ");
    for (int i = 0; i < strlen(data); i++)
    {
        printf("%02x ", (unsigned char)data[i]);
    }
    printf("\n");

    return 0;
}
