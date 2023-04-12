#include <stdio.h>
#include <stdlib.h>


typedef struct big {
     int x;
     int y;
 } Big, *BigPtr;

int main ()
{
     Big a;
     BigPtr b = &a;
     a.x = 1;
     a.y = 2;
     b->x = 5;
     printf("%d", a.x + a.y);
     return 0;
}