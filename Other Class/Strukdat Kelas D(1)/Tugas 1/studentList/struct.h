//struct.h
#define MaxStudents 100
#define MaxNameLength 30
#define MaxNameBuffer MaxNameLength + 1

typedef struct
{
    char name[MaxNameBuffer];
    int age;
    char gender;
} Student;