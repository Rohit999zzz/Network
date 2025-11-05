#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to generate repeated key to match message length
void generateKey(char key[], char message[], char newKey[]) {
    int keyLen = strlen(key);
    int msgLen = strlen(message);
    for (int i = 0, j = 0; i < msgLen; i++, j++) {
        if (j == keyLen)
            j = 0;
        newKey[i] = tolower(key[j]);
    }
    newKey[msgLen] = '\0';
}

// Function to encrypt using Polyalphabetic (Vigenere) Cipher
void encrypt(char message[], char key[], char cipherText[]) {
    for (int i = 0; message[i] != '\0'; i++) {
        cipherText[i] = ((message[i] - 'a') + (key[i] - 'a')) % 26 + 'a';
    }
    cipherText[strlen(message)] = '\0';
}

// Function to decrypt using Polyalphabetic (Vigenere) Cipher
void decrypt(char cipherText[], char key[], char plainText[]) {
    for (int i = 0; cipherText[i] != '\0'; i++) {
        plainText[i] = ((cipherText[i] - key[i] + 26) % 26) + 'a';
    }
    plainText[strlen(cipherText)] = '\0';
}

int main() {
    char message[] = "wearediscoveredsaveyourself";
    char key[] = "deceptive";
    char newKey[100], cipherText[100], decryptedText[100];

    // Convert plaintext and key to lowercase
    for (int i = 0; message[i]; i++) message[i] = tolower(message[i]);
    for (int i = 0; key[i]; i++) key[i] = tolower(key[i]);

    generateKey(key, message, newKey);

    encrypt(message, newKey, cipherText);
    decrypt(cipherText, newKey, decryptedText);

    printf("Plaintext:  %s\n", message);
    printf("Key:        %s\n", newKey);
    printf("Encrypted:  %s\n", cipherText);
    printf("Decrypted:  %s\n", decryptedText);

    return 0;
}
