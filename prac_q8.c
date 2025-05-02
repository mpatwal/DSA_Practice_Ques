#include <stdio.h>

int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to find modular inverse (for private key d)
int mod_inverse(int e, int phi)
{
    for (int d = 1; d < phi; d++)
    {
        if ((e * d) % phi == 1)
            return d;
    }
    return -1; // No inverse found
}

// Function to perform modular exponentiation (a^b mod m)
int mod_exp(int base, int exp, int mod)
{
    int result = 1;
    base = base % mod;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

int main()
{
    // Step 1: Choose two small primes
    int p = 3;
    int q = 11;

    // Step 2: Compute n and phi
    int n = p * q;               // n = 33
    int phi = (p - 1) * (q - 1); // phi = 20

    // Step 3: Choose public key e such that 1 < e < phi and gcd(e, phi) = 1
    int e = 7; // common small prime choice
    if (gcd(e, phi) != 1)
    {
        printf("Invalid e, gcd(e, phi) != 1\n");
        return 1;
    }

    // Step 4: Compute private key d
    int d = mod_inverse(e, phi);
    if (d == -1)
    {
        printf("No modular inverse found for e.\n");
        return 1;
    }

    // Display keys
    printf("Public Key:  (%d, %d)\n", e, n);
    printf("Private Key: (%d, %d)\n", d, n);

    // Step 5: Encrypt a message
    int msg;
    printf("\nEnter message to encrypt (number < %d): ", n);
    scanf("%d", &msg);

    int encrypted = mod_exp(msg, e, n);
    printf("Encrypted message: %d\n", encrypted);

    // Step 6: Decrypt the message
    int decrypted = mod_exp(encrypted, d, n);
    printf("Decrypted message: %d\n", decrypted);

    return 0;
}
