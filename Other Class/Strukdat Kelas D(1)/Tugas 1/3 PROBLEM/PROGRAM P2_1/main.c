#include "header.h"

int main() {
    Student pupil[MaxStudents];
    char aName[MaxNameBuffer];
    void getString(FILE *, char[]);
    int getData(FILE *, Student[]);
    int search(char[], Student[], int);
    void sort(Student[], int);
    void printStudent(Student);
    void getString(FILE *, char[]);
    FILE * in = fopen("input.txt", "r");
    if (in == NULL) {
        printf("Error opening file: %s.\n", strerror(errno));
        exit(1);
    }
    int numStudents = getData(in, pupil);
    if (numStudents == 0) {
        printf("No data supplied for students");
        exit(1);
    }
    printf("\n");
    for (int h = 0; h < numStudents; h++) printStudent(pupil[h]);
    printf("\n");
    getString(in, aName);
    while (strcmp(aName, "END") != 0) {
        int ans = search(aName, pupil, numStudents);
        if (ans == -1) printf("%s not found\n", aName);
        else printf("%s found at location %d\n", aName, ans);
        getString(in, aName);
    }
    sort(pupil, numStudents);
    printf("\n");
    for (int h = 0; h < numStudents; h++) printStudent(pupil[h]);
 } //end main
