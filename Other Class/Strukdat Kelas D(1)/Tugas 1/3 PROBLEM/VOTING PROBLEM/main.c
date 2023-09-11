#include "header.h"

int main() {
    void initialize(PersonData[], int, FILE *);
    VoteCount processVotes(PersonData[], int, FILE *, FILE *);
    void printResults(PersonData[], int, VoteCount, FILE *);
    PersonData candidate[MaxCandidates+1];
    VoteCount count;
    FILE *in = fopen("votes.txt", "r");
    FILE *out = fopen("results.txt", "w");
    initialize(candidate, MaxCandidates, in);
    count = processVotes(candidate, MaxCandidates, in, out);
    printResults(candidate, MaxCandidates, count, out);
    fclose(in);
    fclose(out);
} //end main