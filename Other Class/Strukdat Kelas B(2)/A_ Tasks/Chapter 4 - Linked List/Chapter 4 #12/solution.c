#include <stdio.h>
#include <stdlib.h>

#include "CountOut.h"

int main() {
    int n = 7;
    int m = 9;
    Child* head = createList(n);
    int last_child = countOut(head, m);
    printf("The last remaining child is %d\n", last_child);
    return 0;
}
