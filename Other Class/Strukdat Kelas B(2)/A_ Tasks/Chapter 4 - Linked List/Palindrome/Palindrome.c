#include <malloc.h>
#include <stdio.h>
#include <string.h>

#include "Palindome.h"

Word* createWord(const char* string) {
    int len = strlen(string);
    Word* word = (Word*)malloc(sizeof(Word));
    word->first = NULL;
    word->last = NULL;
    word->length = len;

    Letter* firstLetter = (Letter*)malloc(sizeof(Letter));
    firstLetter->data = string[0];
    firstLetter->prev = NULL;

    word->first = firstLetter;
    Letter* cursor = firstLetter;
    for (int i = 1; i < len; i++) {
        Letter* newLetter = (Letter*)malloc(sizeof(Letter));
        newLetter->prev = cursor;
        newLetter->next = NULL;
        newLetter->data = string[i];
        cursor->next = newLetter;
        cursor = cursor->next;
    }
    word->last = cursor;
    return word;
}

void printWord(Word* word) {
    Letter* cursor = word->first;
    while (cursor != NULL) {
        printf("%c", cursor->data);
        cursor = cursor->next;
    }
    printf("\n");
}

int checkPalindrome(Word* word) {
    int start = 0;
    int end = word->length - 1;
    Letter* startPtr = word->first;
    Letter* endPtr = word->last;
    while (start <= end) {
        if (startPtr->data != endPtr->data) {
            return 0;
        }
        start++;
        end--;
        startPtr = startPtr->next;
        endPtr = endPtr->prev;
    }
    return 1;
}