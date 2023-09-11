#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 100

struct Stack {
    char data[MAX_LEN];
    int top;
};

void push(struct Stack* stack, char c) {
    if (stack->top == MAX_LEN - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->data[++stack->top] = c;
}

char pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack->data[stack->top--];
}

bool isPalindrome(char* word) {
    int len = strlen(word);
    struct Stack stack;
    stack.top = -1;

    // Push each character of the input word onto the stack
    for (int i = 0; i < len; i++) {
        push(&stack, word[i]);
    }

    // Pop each character from the stack and append it to a new string
    char newWord[MAX_LEN];
    int i = 0;
    while (stack.top != -1) {
        newWord[i++] = pop(&stack);
    }
    newWord[i] = '\0';

    // Compare the new string with the original input word
    if (strcmp(word, newWord) == 0) {
        return true;
    }
    return false;
}

int main() {
    char word[MAX_LEN];
    printf("Enter a word: ");
    scanf("%s", word);
    if (isPalindrome(word)) {
        printf("%s is a palindrome.\n", word);
    } else {
        printf("%s is not a palindrome.\n", word);
    }
    return 0;
}
