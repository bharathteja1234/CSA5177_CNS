#include <stdio.h>
#include <string.h>
void encryptRailFence(char *message, int rails) {
    int messageLength = strlen(message);

    char railFence[rails][messageLength];

    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < messageLength; j++) {
            railFence[i][j] = ' ';
        }
    }

    int row = 0;
    int direction = 1; // 1 for down, -1 for up

    for (int i = 0; i < messageLength; i++) {
        railFence[row][i] = message[i];

        if (row == 0) {
            direction = 1; 
        } else if (row == rails - 1) {
            direction = -1; 
        }

        row += direction;
    }

    printf("Encrypted Message: ");
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < messageLength; j++) {
            if (railFence[i][j] != ' ') {
                printf("%c", railFence[i][j]);
            }
        }
    }
    printf("\n");
}

int main() {
    char message[100];
    int rails;

    printf("Enter the message to encrypt: ");
    gets(message);

    printf("Enter the number of rails: ");
    scanf("%d", &rails);

    encryptRailFence(message, rails);

    return 0;
}
