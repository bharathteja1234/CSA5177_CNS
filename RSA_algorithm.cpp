#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int num) {
    if (num <= 1) return 0;
    if (num <= 3) return 1;
    
    if (num % 2 == 0 || num % 3 == 0) return 0;
    
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return 0;
    }
    
    return 1;
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void generateKeys(int p, int q, int *n, int *e, int *d) {
    *n = p * q;
    int phi = (p - 1) * (q - 1);

    do {
        printf("Enter a value for 'e' (must be coprime with phi): ");
        scanf("%d", e);
    } while (gcd(*e, phi) != 1);

    for (*d = 1; (*d * *e) % phi != 1; (*d)++);
}

int rsaEncrypt(int message, int e, int n) {
    return (int)pow(message, e) % n;
}

int rsaDecrypt(int encryptedMessage, int d, int n) {
    return (int)pow(encryptedMessage, d) % n;
}

int main() {
    int p, q, n, e, d;
    
    printf("Enter two prime numbers 'p' and 'q': ");
    scanf("%d %d", &p, &q);

    if (!isPrime(p) || !isPrime(q)) {
        printf("p and q must be prime numbers.\n");
        return 1;
    }

    generateKeys(p, q, &n, &e, &d);

    int message;
    printf("Enter the message to be encrypted: ");
    scanf("%d", &message);

    printf("Original Message: %d\n", message);

    int encryptedMessage = rsaEncrypt(message, e, n);
    printf("Encrypted Message: %d\n", encryptedMessage);

    int decryptedMessage = rsaDecrypt(encryptedMessage, d, n);
    printf("Decrypted Message: %d\n", decryptedMessage);

    return 0;
}

