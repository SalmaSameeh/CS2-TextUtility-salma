#ifndef TEXT_UTILITY_H
#define TEXT_UTILITY_H

int wordCount(const char* str);
int charCount(const char* str);
void countVowelsAndConsonants(const char* str, int& vowels, int& consonants);
void reverseString(char* str);
bool isPalindrome(const char* str);
void toUpperCase(char* str);
void toLowerCase(char* str);
int substringCount(const char* str, const char* substr);

#endif