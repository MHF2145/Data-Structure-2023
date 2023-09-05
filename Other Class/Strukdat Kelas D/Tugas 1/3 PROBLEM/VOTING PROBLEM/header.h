#include <stdio.h>
#include <string.h>
#define MaxCandidates 10
#define MaxNameLength 50
#define MaxNameBuffer MaxNameLength+1

typedef struct {
    char name[MaxNameBuffer];
    int numVotes;
} PersonData;

typedef struct {
    int valid, spoilt;
} VoteCount;

void initialize(PersonData person[], int max, FILE *in);
VoteCount processVotes(PersonData person[], int max, FILE *in, FILE *out);
int getLargest(PersonData person[], int lo, int hi);
void printResults(PersonData person[], int max, VoteCount c, FILE *out);
void sortByVote(PersonData person[], int lo, int hi);
void sortByName(PersonData person[], int lo, int hi);