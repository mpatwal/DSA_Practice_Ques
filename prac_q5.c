#include <stdio.h>

// Simplified F-function (normally it's complex with S-boxes)
unsigned int F(unsigned int x)
{
    // Just a made-up function for demo: rotates bits and adds
    return ((x << 1) | (x >> 31)) + 0xabcdef;
}

// Key schedule (for demo): normally there are 18 P-entries and 4 S-boxes
unsigned int P[18] = {
    0x243f6a88, 0x85a308d3, 0x13198a2e, 0x03707344,
    0xa4093822, 0x299f31d0, 0x082efa98, 0xec4e6c89,
    0x452821e6, 0x38d01377, 0xbe5466cf, 0x34e90c6c,
    0xc0ac29b7, 0xc97c50dd, 0x3f84d5b5, 0xb5470917,
    0x9216d5d9, 0x8979fb1b};

// Blowfish encrypt (simplified)
void blowfish_encrypt(unsigned int *L, unsigned int *R)
{
    for (int i = 0; i < 16; i++)
    {
        *L = *L ^ P[i];
        *R = *R ^ F(*L);
        // Swap L and R
        unsigned int temp = *L;
        *L = *R;
        *R = temp;
    }
    // Undo final swap
    unsigned int temp = *L;
    *L = *R;
    *R = temp;

    *R = *R ^ P[16];
    *L = *L ^ P[17];
}

int main()
{
    unsigned int left, right;

    // Example 64-bit plaintext split into 2 x 32-bits
    printf("Enter left 32-bit (hex): ");
    scanf("%x", &left);
    printf("Enter right 32-bit (hex): ");
    scanf("%x", &right);

    printf("Plaintext: %08x %08x\n", left, right);

    blowfish_encrypt(&left, &right);

    printf("Encrypted: %08x %08x\n", left, right);

    return 0;
}
