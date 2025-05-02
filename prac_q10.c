#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

int main()
{
    unsigned char digest[SHA_DIGEST_LENGTH]; // SHA_DIGEST_LENGTH = 20
    char str[100];

    printf("Enter the text to hash: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline if present
    str[strcspn(str, "\n")] = 0;

    // Compute SHA-1 hash
    SHA1((unsigned char *)str, strlen(str), digest);

    // Print the result
    printf("SHA-1 hash: ");
    for (int i = 0; i < SHA_DIGEST_LENGTH; i++)
        printf("%02x", digest[i]);
    printf("\n");

    return 0;
}
