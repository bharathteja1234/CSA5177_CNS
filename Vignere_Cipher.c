#include <stdio.h>
#include <string.h>
#include <ctype.h>
void vigenereEncrypt(char *plaintext, char *keyword) {
    int plaintextLen = strlen(plaintext);
    int keywordLen = strlen(keyword);
    for (int i = 0; i < plaintextLen; i++) {
        if (isalpha(plaintext[i])) {
            char key = keyword[i % keywordLen];
            int shift = toupper(key) - 'A';
            if (islower(plaintext[i])) {
                plaintext[i] = (plaintext[i] - 'a' + shift) % 26 + 'a';
            } else {
                plaintext[i] = (plaintext[i] - 'A' + shift) % 26 + 'A';
            }
        }
    }
}
void vigenereDecrypt(char *ciphertext, char *keyword) {
    int ciphertextLen = strlen(ciphertext);
    int keywordLen = strlen(keyword);
    
    for (int i = 0; i < ciphertextLen; i++) {
        if (isalpha(ciphertext[i])) {
            char key = keyword[i % keywordLen];
            int shift = toupper(key) - 'A';
            
            if (islower(ciphertext[i])) {
                ciphertext[i] = (ciphertext[i] - 'a' - shift + 26) % 26 + 'a';
            } else {
                ciphertext[i] = (ciphertext[i] - 'A' - shift + 26) % 26 + 'A';
            }
        }
    }
}
int main() {
    char plaintext[] = "HELLOWORLD";
    char keyword[] = "KEY";
    printf("Original Text: %s\n", plaintext);
    vigenereEncrypt(plaintext, keyword);
    printf("Encrypted Text: %s\n", plaintext);
    vigenereDecrypt(plaintext, keyword);
    printf("Decrypted Text: %s\n", plaintext);
    return 0;
}

