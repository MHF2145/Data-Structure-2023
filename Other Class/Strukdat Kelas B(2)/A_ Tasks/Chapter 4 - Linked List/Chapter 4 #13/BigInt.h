#ifndef A1_BIG_INT_H_
#define A1_BIG_INT_H_

typedef struct bigIntNode_t {
    int data;
    struct bigIntNode_t* next;
} BigIntNode;

typedef struct bigInt_t {
    int length;
    BigIntNode* head;
    BigIntNode* tail;
} BigInt;

void init(BigInt* num);
void pushBack(BigInt *num, int data);
void set(BigInt* num, const char* value);
BigInt* add(BigInt* num1, BigInt* num2);
char* toString(BigInt* num);

#endif // A1_BIG_INT_H_