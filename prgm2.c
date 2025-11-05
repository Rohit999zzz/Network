#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function to encrypt using monoalphabetic cipher
void encrypt(char plaintext[], char key[], char ciphertext[]) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        char ch = plaintext[i];
        if (isupper(ch))                 // If uppercase letter
            ciphertext[i] = key[ch - 'A'];
        else if (ch == ' ')              // Keep spaces as is
            ciphertext[i] = ' ';
        else
            ciphertext[i] = ch;          // For any other character
    }
    ciphertext[strlen(plaintext)] = '\0';
}

// Function to decrypt using monoalphabetic cipher
void decrypt(char ciphertext[], char key[], char plaintext[]) {
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        char ch = ciphertext[i];
        if (isupper(ch)) {
            // Find the index of the character in the key
            for (int j = 0; j < 26; j++) {
                if (key[j] == ch) {
                    plaintext[i] = 'A' + j;
                    break;
                }
            }
        } else if (ch == ' ')
            plaintext[i] = ' ';
        else
            plaintext[i] = ch;
    }
    plaintext[strlen(ciphertext)] = '\0';
}

int main() {
    char key[] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    char plaintext[] = "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG";
    char ciphertext[100], decrypted[100];

    printf("Original plaintext: %s\n", plaintext);

    // Encryption
    encrypt(plaintext, key, ciphertext);
    printf("Encrypted ciphertext: %s\n", ciphertext);

    // Decryption
    decrypt(ciphertext, key, decrypted);
    printf("Decrypted plaintext: %s\n", decrypted);

    return 0;
}
