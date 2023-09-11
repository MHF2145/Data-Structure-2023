#include <stdio.h>
#include "Stack.h"

int main() {
    Stack st1, st2;
    st_init(&st1);
    st_init(&st2);
    
    st_push(&st1, 420);
    st_push(&st1, 69);
    st_push(&st1, 76);
    st_push(&st1, 21);
    st_push(&st1, 46);
    st_push(&st1, 48);

 
    while(!st_empty(&st1)) {
        int temp = st_pop(&st1);
 
        while(!st_empty(&st2) && st_top(&st2) < temp) {
        	st_push(&st1, st_pop(&st2));
        }
        st_push(&st2, temp);
    }
	
    while (!st_empty(&st2)) {
        printf("%d ", st_pop(&st2));
    }

    return 0;
}