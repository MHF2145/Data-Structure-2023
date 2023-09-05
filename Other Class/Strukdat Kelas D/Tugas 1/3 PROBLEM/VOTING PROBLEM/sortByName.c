#include "header.h"

void sortByName(PersonData person[], int lo, int hi) {
    //sort person[lo..hi] in alphabetical order by name
    PersonData insertItem;
    for (int h = lo + 1; h <= hi; h++) { // process person[lo+1] to person[hi]
        // insert person j in its proper position
        insertItem = person[h];
        int k = h -1;
        while (k > 0 && strcmp(insertItem.name, person[k].name) < 0) {
            person[k + 1] = person[k];
            --k;
        }
    person[k + 1] = insertItem;
    }
} //end sortByName