#include <stdio.h>
#include <string.h>
#include <ctype.h>

void createMatrix(char key[], char mat[5][5]) {
    int used[26] = {0}, i = 0, j = 0;
    used['J' - 'A'] = 1;
    for (int k = 0; k < strlen(key); k++) {
        char c = toupper(key[k]);
        if (c < 'A' || c > 'Z') continue;
        if (!used[c - 'A']) {
            mat[i][j++] = c; used[c - 'A'] = 1;
            if (j == 5) { i++; j = 0; }
        }
    }
    for (char c = 'A'; c <= 'Z'; c++) {
        if (!used[c - 'A']) {
            mat[i][j++] = c; used[c - 'A'] = 1;
            if (j == 5) { i++; j = 0; }
        }
    }
}

void findPos(char mat[5][5], char a, char b, int pos[]) {
    if (a == 'J') a = 'I'; if (b == 'J') b = 'I';
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) {
            if (mat[i][j] == a) { pos[0] = i; pos[1] = j; }
            if (mat[i][j] == b) { pos[2] = i; pos[3] = j; }
        }
}

void encrypt(char text[], char mat[5][5]) {
    int len = strlen(text);
    for (int i = 0; i < len; i++) text[i] = toupper(text[i]);
    for (int i = 0; i < len; i += 2) {
        if (text[i] == text[i + 1]) {
            memmove(&text[i + 1], &text[i], len - i);
            text[i + 1] = 'X'; len++;
        }
    }
    if (len % 2 != 0) text[len++] = 'Z';
    text[len] = '\0';

    int pos[4];
    for (int i = 0; i < len; i += 2) {
        findPos(mat, text[i], text[i + 1], pos);
        if (pos[0] == pos[2]) {
            text[i] = mat[pos[0]][(pos[1] + 1) % 5];
            text[i + 1] = mat[pos[2]][(pos[3] + 1) % 5];
        } else if (pos[1] == pos[3]) {
            text[i] = mat[(pos[0] + 1) % 5][pos[1]];
            text[i + 1] = mat[(pos[2] + 1) % 5][pos[3]];
        } else {
            text[i] = mat[pos[0]][pos[3]];
            text[i + 1] = mat[pos[2]][pos[1]];
        }
    }
    printf("Encrypted text: %s\n", text);
}

int main() {
    char key[50], text[100], mat[5][5];

    printf("Enter key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';  // remove newline

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';  // remove newline

    createMatrix(key, mat);
    encrypt(text, mat);
    return 0;
}
