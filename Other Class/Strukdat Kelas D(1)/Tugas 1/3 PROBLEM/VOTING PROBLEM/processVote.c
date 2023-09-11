#include "header.h"

VoteCount processVotes(PersonData person[], int max, FILE *in, FILE *out) {
    VoteCount temp;
    temp.valid = temp.spoilt = 0;
    int v;
    fscanf(in, "%d", &v);
    while (v != 0) {
        if (v < 1 || v > max) {
            fprintf(out, "Invalid vote: %d\n", v);
            ++temp.spoilt;
        }else {
            ++person[v].numVotes;
            ++temp.valid;
        }
        fscanf(in, "%d", &v);
    } //end while
    return temp;
} //end processVotes