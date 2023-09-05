#include "header.h"

void sortByVote(PersonData person[], int lo, int hi) {
    //sort person[lo..hi] in descending order by numVotes
    PersonData insertItem;
    for (int h = lo + 1; h <= hi; h++) { // process person[lo+1] to person[hi]
        // insert person h in its proper position
        insertItem = person[h];
        int k = h -1;
        while (k >= lo && insertItem.numVotes > person[k].numVotes) {
            person[k + 1] = person[k];
            --k;
        }
    person[k + 1] = insertItem;
    }
} //end sortByVote