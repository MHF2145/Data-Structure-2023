// struct.h
#define MaxCandidates 7
#define MaxNameLength 30
#define MaxNameBuffer MaxNameLength + 1

typedef struct
{
    char name[MaxNameBuffer];
    int numVotes;
} PersonData;

PersonData candidate[MaxCandidates];

typedef struct
{
    int valid, spoilt;
} VoteCount;