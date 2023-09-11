#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MaxStudents 100
#define MaxNameLength 30
#define MaxNameBuffer MaxNameLength+1

typedef struct {
    char name[MaxNameBuffer];
    int age;
    char gender;
} Student;

void printStudent(Student t);
int getData(FILE *in, Student list[]);
int search(char key[], Student list[], int n);
void sort(Student list[], int n);
void getString(FILE * in, char str[]);
char readChar(FILE * in);