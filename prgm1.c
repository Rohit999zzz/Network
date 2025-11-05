#include <stdio.h>

// Function to perform Caesar cipher encryption or decryption
void caesar(char text[], int shift) {
    for (int i = 0; text[i] != '\0'; ++i) {
        if (text[i] >= 'a' && text[i] <= 'z')  // for lowercase letters
            text[i] = 'a' + (text[i] - 'a' + shift + 26) % 26;
        else if (text[i] >= 'A' && text[i] <= 'Z')  // for uppercase letters
            text[i] = 'A' + (text[i] - 'A' + shift + 26) % 26;
    }
}

int main() {
    char message[] = "hello how are u";
    int key = 3;  // shift value

    printf("Original message: %s\n", message);

    // Encrypt the message
    caesar(message, key);
    printf("Encrypted message: %s\n", message);

    // Decrypt the message (by shifting in opposite direction)
    caesar(message, -key);
    printf("Decrypted message: %s\n", message);

    return 0;
}
