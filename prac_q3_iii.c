#include <stdio.h>

int main()
{
    char ch1, ch2;
    char e1, e2, d1, d2;
    int a, b, x, y;

    // Key is fixed: [[3,3],[2,5]]
    // Inverse key: [[15,17],[20,9]]

    printf("Enter 2 capital letters (e.g. HI): ");
    scanf(" %c %c", &ch1, &ch2);

    // Convert letters to numbers (A=0, B=1, ..., Z=25)
    a = ch1 - 'A';
    b = ch2 - 'A';

    // Encryption: [x] = 3a + 3b, [y] = 2a + 5b (mod 26)
    x = (3 * a + 3 * b) % 26;
    y = (2 * a + 5 * b) % 26;

    // Convert back to letters
    e1 = x + 'A';
    e2 = y + 'A';

    printf("Encrypted: %c%c\n", e1, e2);

    // Decryption: a = 15x + 17y, b = 20x + 9y (mod 26)
    a = (15 * x + 17 * y) % 26;
    b = (20 * x + 9 * y) % 26;

    // Convert back to letters
    d1 = a + 'A';
    d2 = b + 'A';

    printf("Decrypted: %c%c\n", d1, d2);

    return 0;
}
