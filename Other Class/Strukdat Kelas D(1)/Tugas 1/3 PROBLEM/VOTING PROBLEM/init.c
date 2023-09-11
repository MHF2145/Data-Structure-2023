#include "header.h"

void initialize(PersonData person[], int max, FILE *in) {
    char lastName[MaxNameBuffer];
    for (int h = 1; h <= max; h++) {
        fscanf(in, "%s %s", person[h].name, lastName);
        strcat(person[h].name, " ");
        strcat(person[h].name, lastName);
        person[h].numVotes = 0;
    }
} //end initialize
