#include<stdio.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5
void prepareTable(char key[], char table[SIZE][SIZE]) {
    int i, j, k = 0;
    int isPresent[26] = {0}; 
    
    for (i = 0; i < strlen(key); i++) {
        if (key[i] == 'j') 
            key[i] = 'i';
        if (!isPresent[key[i] - 'a']) {
            table[k / SIZE][k % SIZE] = key[i];
            isPresent[key[i] - 'a'] = 1;
            k++;
        }
    }
    
    for (i = 0; i < 26; i++) {
        if (i != ('j' - 'a') && !isPresent[i]) {
            table[k / SIZE][k % SIZE] = i + 'a';
            k++;
        }
    }
}

void findPositions(char table[SIZE][SIZE], char a, char b, int *row1, int *col1, int *row2, int *col2) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (table[i][j] == a) {
                *row1 = i;
                *col1 = j;
            }
            if (table[i][j] == b) {
                *row2 = i;
                *col2 = j;
            }
        }
    }
}

void encrypt(char table[SIZE][SIZE], char message[], char encrypted[]) {
    int len = strlen(message);
    int i, row1, col1, row2, col2;

    for (i = 0; i < len; i += 2) {
        char a = message[i];
        char b = (i + 1 < len) ? message[i + 1] : 'x';

        findPositions(table, a, b, &row1, &col1, &row2, &col2);

        if (row1 == row2) {
            encrypted[i] = table[row1][(col1 + 1) % SIZE];
            encrypted[i + 1] = table[row2][(col2 + 1) % SIZE];
        } else if (col1 == col2) {
            encrypted[i] = table[(row1 + 1) % SIZE][col1];
            encrypted[i + 1] = table[(row2 + 1) % SIZE][col2];
        } else {
            encrypted[i] = table[row1][col2];
            encrypted[i + 1] = table[row2][col1];
        }
    }
}

int main() {
    char key[26];
    char table[SIZE][SIZE];
    char message[1000];
    char encrypted[1000];

    printf("Enter the key (alphabets only): ");
    scanf("%s", key);

    printf("Enter the message to encrypt (alphabets only): ");
    scanf("%s", message);
    for (int i = 0; i < strlen(key); i++) {
        key[i] = tolower(key[i]);
    }

    prepareTable(key, table);
    encrypt(table, message, encrypted);

    printf("Encrypted message: %s\n", encrypted);

    return 0;
}

