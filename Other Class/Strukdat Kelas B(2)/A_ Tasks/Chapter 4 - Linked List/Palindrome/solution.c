#include <stdio.h>

#include "Palindome.h"

int main() {
    Word* word1 = createWord("kasurrusak");
    Word* word2 = createWord("notapalindrome");
    printWord(word1);
    printWord(word2);
    printf((checkPalindrome(word1)) ? "Palindrome\n" : "Not Palindrome\n");
    printf((checkPalindrome(word2)) ? "Palindrome\n" : "Not Palindrome\n");
    return 0;
}