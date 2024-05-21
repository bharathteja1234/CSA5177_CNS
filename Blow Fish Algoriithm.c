#include <stdio.h>
#include <stdint.h>
#include <string.h>
#define N 16
uint32_t P[N + 2];
uint32_t S[4][256];
void initialize() {
}
void encrypt(uint32_t* left, uint32_t* right) {
}

void decrypt(uint32_t* left, uint32_t* right) {
}

int main() {
    uint32_t left = 0x3243F6A8;
    uint32_t right = 0x885A308D;

    initialize();

    printf("Original: 0x%08X 0x%08X\n", left, right);

    encrypt(&left, &right);

    printf("Encrypted: 0x%08X 0x%08X\n", left, right);

    decrypt(&left, &right);

    printf("Decrypted: 0x%08X 0x%08X\n", left, right);

    return 0;
}
