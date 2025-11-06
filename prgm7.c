#include <stdio.h>
#include <math.h>

// Function to perform modular exponentiation
// (base^exp) % mod
long long int power(long long int base, long long int exp, long long int mod) {
    long long int result = 1;
    for (int i = 0; i < exp; i++)
        result = (result * base) % mod;
    return result;
}

int main() {
    // Commonly agreed parameters (public)
    long long int P = 23; // Prime number
    long long int G = 9;  // Primitive root of P

    // Private keys (kept secret)
    long long int a = 4; // Client's private key
    long long int b = 3; // Server's private key

    // Calculate public keys
    long long int client_public = power(G, a, P);
    long long int server_public = power(G, b, P);

    // Exchange public keys between client and server
    // Compute shared secret key on both sides
    long long int client_secret = power(server_public, a, P);
    long long int server_secret = power(client_public, b, P);

    printf("Publicly shared values:\n");
    printf("P = %lld, G = %lld\n\n", P, G);

    printf("Client's Private Key (a): %lld\n", a);
    printf("Server's Private Key (b): %lld\n\n", b);

    printf("Client's Public Key (G^a mod P): %lld\n", client_public);
    printf("Server's Public Key (G^b mod P): %lld\n\n", server_public);

    printf("Shared Secret Key computed by Client: %lld\n", client_secret);
    printf("Shared Secret Key computed by Server: %lld\n", server_secret);

    if (client_secret == server_secret)
        printf("\n✅ Secure channel established successfully!\n");
    else
        printf("\n❌ Key mismatch! Channel not secure.\n");

    return 0;
}
