#include <stdio.h>

unsigned char sbox[16] = {
    0x6, 0xB, 0x0, 0x4,
    0xD, 0x1, 0x8, 0xA,
    0x3, 0x7, 0x9, 0xE,
    0xF, 0xC, 0x5, 0x2};

void print_state(const char *label, unsigned char *state)
{
    printf("%s: ", label);
    for (int i = 0; i < 4; i++)
        printf("%02x ", state[i]);
    printf("\n");
}

void sub_bytes(unsigned char *state)
{
    for (int i = 0; i < 4; i++)
    {
        state[i] = sbox[state[i] & 0x0F];
    }
}

void shift_rows(unsigned char *state)
{
    unsigned char temp = state[1];
    state[1] = state[3];
    state[3] = temp;
}

void mix_columns(unsigned char *state)
{
    unsigned char temp[4];
    temp[0] = state[0] ^ state[1];
    temp[1] = state[1] ^ state[2];
    temp[2] = state[2] ^ state[3];
    temp[3] = state[3] ^ state[0];
    for (int i = 0; i < 4; i++)
        state[i] = temp[i];
}

void add_round_key(unsigned char *state, unsigned char *key)
{
    for (int i = 0; i < 4; i++)
    {
        state[i] ^= key[i];
    }
}

int main()
{
    unsigned char state[4], key[4];

    printf("Enter 4-byte block (0–15 each):\n");
    for (int i = 0; i < 4; i++)
    {
        printf("Byte %d: ", i + 1);
        scanf("%hhu", &state[i]);
    }

    printf("Enter 4-byte key (0–15 each):\n");
    for (int i = 0; i < 4; i++)
    {
        printf("Key %d: ", i + 1);
        scanf("%hhu", &key[i]);
    }

    print_state("Initial Block", state);

    add_round_key(state, key);
    print_state("After AddRoundKey", state);

    sub_bytes(state);
    print_state("After SubBytes", state);

    shift_rows(state);
    print_state("After ShiftRows", state);

    mix_columns(state);
    print_state("After MixColumns", state);

    print_state("Final Encrypted Block", state);

    return 0;
}
