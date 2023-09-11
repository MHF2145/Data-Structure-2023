#include <string.h>
#include <malloc.h>

#include "BigInt.h"

void init(BigInt* num) {
    num->head = NULL;
    num->tail = NULL;
    num->length = 0;
}

void pushBack(BigInt *num, int data) {
    BigIntNode* newNode = (BigIntNode*)malloc(sizeof(BigIntNode));
    newNode->next = NULL;
    newNode->data = data;
    if (num->tail == NULL) {
        num->head = newNode;
        num->tail = newNode;
    }
    else {
        num->tail->next = newNode;
        num->tail = newNode;
    }

    num->length++;
}

void set(BigInt* num, const char* value) {
    int newlen = strlen(value);
    int oldlen = num->length;
    if (newlen > oldlen) {
        for (int i = 0; i < newlen-oldlen ; i++) {
            pushBack(num, 0);
        }
    }

    BigIntNode* cursor = num->head;
    int index = newlen-1;
    while (cursor != NULL) {
        cursor->data = (value[index--] - '0');
        cursor = cursor->next;
    }

    num->length = newlen;
}

BigInt* add(BigInt* num1, BigInt* num2) {
    BigInt* result = malloc(sizeof(BigInt));
    result->head = NULL;
    result->tail = NULL;
    result->length = 0;

    int carry = 0, sum = 0;
    int minlen = 0, maxlen = 0;
    BigIntNode* bigger;
    BigIntNode* smaller;

    if (num1->length >= num2->length) {
        bigger = num1->head;
        smaller = num2->head;
        maxlen = num1->length;
        minlen = num2->length;
    }
    else {
        bigger = num2->head;
        smaller = num1->head;
        maxlen = num2->length;
        minlen = num1->length;
    }

    for (int i = 0; i < maxlen; i++) {
        pushBack(result, 0);
    }

    BigIntNode* res = result->head;

    for (int i = 0; i < minlen; i++) {
        sum = bigger->data + smaller->data + carry;
        res->data = sum % 10;
        carry = sum / 10;

        smaller = smaller->next;
        bigger = bigger->next;
        res = res->next;
    }

    for (int i = 0; i < maxlen-minlen; i++) {
        sum = bigger->data + carry;
        res->data = sum % 10;
        carry = sum / 10;

        bigger = bigger->next;
        res = res->next;
    }

    if (carry > 0) {
        pushBack(result, carry);
    }
    
    return result;
}

char* toString(BigInt* num) {
    char* string = (char*)malloc((num->length + 1) * sizeof(char));
    int index = num->length - 1;
    string[num->length] = '\0';

    BigIntNode* cursor = num->head;
    while (cursor != NULL) {
        string[index--] = (cursor->data) + '0';
        cursor = cursor->next;
    }

    return string;
}