#ifndef A1_COUNT_OUT_H_
#define A1_COUNT_OUT_H_

typedef struct child_t {
    int value;
    struct child_t* next;
} Child;

Child* createList(int n);
int countOut(Child* head, int m);

#endif // A1_COUNT_OUT_H_