#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to perform Hill Cipher encryption for 2x2 key matrix
void hillEncrypt(int key[2][2], char message[]) {
    int len = strlen(message);
    
    // Convert message to uppercase and remove spaces
    char clean[100];
    int k = 0;
    for (int i = 0; i < len; i++) {
        if (isalpha(message[i])) {
            clean[k++] = toupper(message[i]);
        }
    }
    clean[k] = '\0';
    
    // Ensure message length is even (pad with 'X' if needed)
    if (k % 2 != 0) {
        clean[k++] = 'X';
        clean[k] = '\0';
    }

    printf("\nCleaned message (used for encryption): %s\n", clean);

    printf("Encrypted text: ");
    for (int i = 0; i < k; i += 2) {
        int a = clean[i] - 'A';
        int b = clean[i + 1] - 'A';

        // Matrix multiplication mod 26
        int c1 = (key[0][0] * a + key[0][1] * b) % 26;
        int c2 = (key[1][0] * a + key[1][1] * b) % 26;

        printf("%c%c", c1 + 'A', c2 + 'A');
    }
    printf("\n");
}

int main() {
    int key[2][2];
    char message[100];

    printf("Enter 2x2 key matrix (4 integers):\n");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            scanf("%d", &key[i][j]);

    printf("Enter the message to encrypt: ");
    scanf(" %[^\n]", message);

    hillEncrypt(key, message);

    return 0;
}
