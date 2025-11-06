#include <stdio.h>
#include <string.h>
#include <openssl/aes.h>

int main() {
    // Message to send
    unsigned char message[] = "welcome to ISE";

    // AES key (16 bytes = 128-bit)
    unsigned char key[16] = "1234567890abcdef";

    // AES initialization vector (IV) — should be same for sender and receiver
    unsigned char iv[AES_BLOCK_SIZE] = "abcdef1234567890";

    // Buffers for encryption and decryption
    unsigned char encrypted[128], decrypted[128];
    AES_KEY enc_key, dec_key;

    // Set encryption key
    AES_set_encrypt_key(key, 128, &enc_key);
    // Encrypt message
    AES_cbc_encrypt(message, encrypted, sizeof(message), &enc_key, iv, AES_ENCRYPT);

    printf("Encrypted message: ");
    for (int i = 0; i < sizeof(message); i++)
        printf("%02x", encrypted[i]);
    printf("\n");

    // Reset IV for decryption (CBC mode modifies it)
    unsigned char iv_dec[AES_BLOCK_SIZE] = "abcdef1234567890";
    AES_set_decrypt_key(key, 128, &dec_key);
    AES_cbc_encrypt(encrypted, decrypted, sizeof(message), &dec_key, iv_dec, AES_DECRYPT);

    printf("Decrypted message: %s\n", decrypted);
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <openssl/aes.h>

int main() {
    unsigned char key[16] = "1234567890abcdef";
    unsigned char iv[AES_BLOCK_SIZE] = "abcdef1234567890";
    unsigned char text[] = "welcome to ISE";
    unsigned char enc[128], dec[128];

    AES_KEY enc_key, dec_key;
    AES_set_encrypt_key(key, 128, &enc_key);
    AES_cbc_encrypt(text, enc, sizeof(text), &enc_key, iv, AES_ENCRYPT);

    printf("Encrypted: ");
    for(int i=0;i<sizeof(text);i++) printf("%02x", enc[i]);
    printf("\n");

    unsigned char iv2[AES_BLOCK_SIZE] = "abcdef1234567890";
    AES_set_decrypt_key(key, 128, &dec_key);
    AES_cbc_encrypt(enc, dec, sizeof(text), &dec_key, iv2, AES_DECRYPT);

    printf("Decrypted: %s\n", dec);
    return 0;
}

