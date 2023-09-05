#include "header.h"

int getLargest(PersonData person[], int lo, int hi) {
    //returns the index of the highest vote from person[lo] to person[hi]
    int big = lo;
    for (int h = lo + 1; h <= hi; h++)
    if (person[h].numVotes > person[big].numVotes) big = h;
    return big;
} //end getLargest