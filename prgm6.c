#include <stdio.h>
#include <string.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>

int main() {
    RSA *userB = RSA_generate_key(2048, RSA_F4, NULL, NULL);  // User B key pair
    unsigned char msg[] = "HELLO USER B", enc[256], dec[256];

    // Encryption at User A (using B’s public key)
    int elen = RSA_public_encrypt(strlen((char*)msg), msg, enc, userB, RSA_PKCS1_PADDING);

    // Decryption at User B (using B’s private key)
    int dlen = RSA_private_decrypt(elen, enc, dec, userB, RSA_PKCS1_PADDING);
    dec[dlen] = '\0';

    printf("Encrypted message: ");
    for (int i = 0; i < elen; i++) printf("%02x", enc[i]);
    printf("\nDecrypted message: %s\n", dec);

    RSA_free(userB);
    return 0;
}

gcc -o rsa_example rsa_example.c -lssl –lcrypto
