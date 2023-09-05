#include "header.h"

int getData(FILE *in, Student list[]) {
    char temp[MaxNameBuffer];
    void getString(FILE *, char[]);
    char readChar(FILE *);
    int n = 0;
    getString(in, temp);
    while (n < MaxStudents && strcmp(temp, "END") != 0) {
        strcpy(list[n].name, temp);
        fscanf(in, "%d", &list[n].age);
        list[n].gender = readChar(in);
        n++;
        getString(in, temp);
    }
    return n;
} //end getData