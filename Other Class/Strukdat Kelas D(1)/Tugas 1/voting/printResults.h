// printResults.h
void printResults(PersonData person[], int max, VoteCount c, FILE *out)
{
    int getLargest(PersonData[], int, int);
    fprintf(out, "\nNumber of voters: %d\n", c.valid + c.spoilt);
    fprintf(out, "Number of valid votes: %d\n", c.valid);
    fprintf(out, "Number of spoilt votes: %d\n", c.spoilt);
    fprintf(out, "\nCandidate Score\n\n");
    for (int h = 1; h <= max; h++)
        fprintf(out, "%-15s %3d\n", person[h].name, person[h].numVotes);
    fprintf(out, "\nThe winner(s)\n");
    int win = getLargest(person, 1, max);
    int winningVote = person[win].numVotes;
    for (int h = 1; h <= max; h++)
        if (person[h].numVotes == winningVote)
            fprintf(out, "%s\n", person[h].name);
} // end printResults