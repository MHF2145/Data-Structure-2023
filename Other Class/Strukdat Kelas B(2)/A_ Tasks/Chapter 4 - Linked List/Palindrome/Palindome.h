#ifndef A1_PALINDROME_H_
#define A1_PALINDROME_H_

typedef struct letter_t {
    char data;
    struct letter_t* next;
    struct letter_t* prev;
} Letter;

typedef struct word_t {
    struct letter_t* first;
    struct letter_t* last;
    int length;
} Word;

Word* createWord(const char* string);
void printWord(Word* word);
int checkPalindrome(Word* word);

#endif // A1_PALINDROME_H_