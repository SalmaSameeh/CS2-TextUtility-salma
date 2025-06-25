#include <iostream>
#include "text_utility.h"

int main() {
    char sample[] = "Hello world, C++ is FUN!";
    char reversed[] = "abcde";
    char mixedCase[] = "HeLLo WoRLd!";
    char palindrome[] = "Madam";

    std::cout << "Sample text: \"" << sample << "\"\n";
    std::cout << "Word Count: " << wordCount(sample) << "\n";
    std::cout << "Character Count: " << charCount(sample) << "\n";

    int vowels = 0, consonants = 0;
    countVowelsAndConsonants(sample, vowels, consonants);
    std::cout << "Vowels: " << vowels << ", Consonants: " << consonants << "\n";

    reverseString(reversed);
    std::cout << "Reversed string: " << reversed << "\n";

    std::cout << "Is \"" << palindrome << "\" a palindrome? " << (isPalindrome(palindrome) ? "Yes" : "No") << "\n";

    toUpperCase(mixedCase);
    std::cout << "Uppercase: " << mixedCase << "\n";

    toLowerCase(mixedCase);
    std::cout << "Lowercase: " << mixedCase << "\n";

    const char* full = "abababcab";
    const char* part = "ab";
    std::cout << "Substring \"" << part << "\" occurs " << substringCount(full, part) << " times in \"" << full << "\"\n";

    return 0;
}