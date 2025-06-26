#include <iostream>
#include <cstring>
using namespace std;

// Helper: repeat keyword to match length
void repeatKeyword(char* keyword, int len, char* repeated) {
    int keyLen = strlen(keyword);
    for (int i = 0; i < len; ++i) {
        repeated[i] = keyword[i % keyLen];
    }
    repeated[len] = '\0';
}

// Encrypt
void vigenereEncrypt(const char* plaintext, const char* keyword, char* ciphertext) {
    int len = strlen(plaintext);
    char repeatedKey[100];
    repeatKeyword((char*)keyword, len, repeatedKey);

    for (int i = 0; i < len; ++i) {
        if (isalpha(plaintext[i])) {
            char p = plaintext[i] - 'a';
            char k = repeatedKey[i] - 'a';
            ciphertext[i] = ((p + k) % 26) + 'a';
        } else {
            ciphertext[i] = plaintext[i];  // non-alpha stays the same
        }
    }
    ciphertext[len] = '\0';
}

// Decrypt
void vigenereDecrypt(const char* ciphertext, const char* keyword, char* plaintext) {
    int len = strlen(ciphertext);
    char repeatedKey[100];
    repeatKeyword((char*)keyword, len, repeatedKey);

    for (int i = 0; i < len; ++i) {
        if (isalpha(ciphertext[i])) {
            char c = ciphertext[i] - 'a';
            char k = repeatedKey[i] - 'a';
            plaintext[i] = ((c - k + 26) % 26) + 'a';
        } else {
            plaintext[i] = ciphertext[i];  // non-alpha stays the same
        }
    }
    plaintext[len] = '\0';
}

int main() {
    char plaintext[100] = "attackatdawn";
    char keyword[100] = "lemon";
    char ciphertext[100], decrypted[100];

    vigenereEncrypt(plaintext, keyword, ciphertext);
    cout << "Encrypted: " << ciphertext << endl;

    vigenereDecrypt(ciphertext, keyword, decrypted);
    cout << "Decrypted: " << decrypted << endl;

    return 0;
}