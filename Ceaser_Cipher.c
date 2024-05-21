#include <stdio.h>
#include<string.h>
int main() {
    char text[100];
    int shift;
    printf("Enter a string: ");
    fgets(text, sizeof(text), stdin);
    text[strlen(text) - 1] = '\0'; 
    printf("Enter shift value: ");
    scanf("%d", &shift);
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = ((text[i] - 'A' + shift) % 26) + 'A';
        } else if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = ((text[i] - 'a' + shift) % 26) + 'a';
        }
    }
    printf("Encrypted text: %s\n", text);
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = ((text[i] - 'A' - shift + 26) % 26) + 'A';
        } else if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = ((text[i] - 'a' - shift + 26) % 26) + 'a';
        }
    }
    printf("Decrypted text: %s\n", text);

    return 0;
}
