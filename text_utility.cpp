#include "text_utility.h"
#include <cctype>  
#include <cstring> 
int wordCount(const char* str) {
    if (str == nullptr || str[0] == '\0') return 0;

    int count = 0;
    bool inWord = false;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (!isspace(str[i])) {
            if (!inWord) {
                count++;
                inWord = true;
            }
        } else {
            inWord = false;
        }
    }

    return count;
}

int charCount(const char* str) {
    if (str == nullptr) return 0;
    int count = 0;
    while (str[count] != '\0') count++;
    return count;
}

void countVowelsAndConsonants(const char* str, int& vowels, int& consonants) {
    vowels = 0;
    consonants = 0;

    if (str == nullptr) return;

    for (int i = 0; str[i] != '\0'; ++i) {
        char c = tolower(str[i]);
        if (isalpha(c)) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                vowels++;
            else
                consonants++;
        }
    }
}

void reverseString(char* str) {
    if (str == nullptr) return;
    int len = strlen(str);
    for (int i = 0; i < len / 2; ++i) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

bool isPalindrome(const char* str) {
    if (str == nullptr) return false;
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        while (!isalnum(str[left]) && str[left] != '\0') left++;
        while (!isalnum(str[right]) && right > left) right--;
        if (tolower(str[left]) != tolower(str[right])) return false;
        left++;
        right--;
    }
    return true;
}

void toUpperCase(char* str) {
    if (str == nullptr) return;
    for (int i = 0; str[i] != '\0'; ++i) {
        str[i] = toupper(str[i]);
    }
}

void toLowerCase(char* str) {
    if (str == nullptr) return;
    for (int i = 0; str[i] != '\0'; ++i) {
        str[i] = tolower(str[i]);
    }
}

int substringCount(const char* str, const char* substr) {
    if (str == nullptr || substr == nullptr) return 0;
    int count = 0;
    int len1 = strlen(str);
    int len2 = strlen(substr);

    for (int i = 0; i <= len1 - len2; ++i) {
        if (strncmp(&str[i], substr, len2) == 0)
            count++;
    }
    return count;
}