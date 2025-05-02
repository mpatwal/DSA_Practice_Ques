#include <stdio.h>
#include <string.h>

// Example S-box (simple substitution)
int sbox[4][4] = {
    {1, 0, 3, 2},
    {3, 2, 1, 0},
    {0, 2, 1, 3},
    {3, 1, 3, 2}};

// Simple XOR function
int xor(int a, int b)
{
    return a ^ b;
}

// Substitute 4-bit block using S-box
int substitute(int input)
{
    int row = ((input & 0b1000) >> 2) | (input & 0b0001); // bits 1 and 4
    int col = (input & 0b0110) >> 1;                      // bits 2 and 3
    return sbox[row][col];
}

// Simple permutation: swap 1st & 3rd, 2nd & 4th bits
int permute(int input)
{
    int b1 = (input >> 3) & 1;
    int b2 = (input >> 2) & 1;
    int b3 = (input >> 1) & 1;
    int b4 = input & 1;
    return (b3 << 3) | (b4 << 2) | (b1 << 1) | b2;
}

int main()
{
    int plaintext, key;
    printf("Enter 4-bit plaintext (0-15): ");
    scanf("%d", &plaintext);

    printf("Enter 4-bit key (0-15): ");
    scanf("%d", &key);

    // Step 1: Key mixing (XOR)
    int step1 = xor(plaintext, key);
    printf("Step 1 - After XOR with key: %d\n", step1);

    // Step 2: Substitution (S-box)
    int step2 = substitute(step1);
    printf("Step 2 - After substitution: %d\n", step2);

    // Step 3: Permutation
    int step3 = permute(step2);
    printf("Step 3 - After permutation: %d\n", step3);

    printf("Encrypted output: %d\n", step3);

    return 0;
}
