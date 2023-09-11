#include <stdio.h>
#define MAX_STUDENTS 100

struct Student {
    int id;
    int cs20a;
    int cs21a;
    int cs29a;
    int cs30a;
    int cs35a;
    int cs36a;
};

int main() {
    // Open input file
    FILE *in_file = fopen("registration.txt", "r");
    if (in_file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Read student data into array of structs
    struct Student students[MAX_STUDENTS];
    int num_students = 0;
    while (fscanf(in_file, "%d %d %d %d %d %d %d", &students[num_students].id,
                  &students[num_students].cs20a, &students[num_students].cs21a,
                  &students[num_students].cs29a, &students[num_students].cs30a,
                  &students[num_students].cs35a, &students[num_students].cs36a) == 7) {
        num_students++;
    }

    // Open output files for each course
    FILE *cs20a_file = fopen("CS20a.txt", "w");
    FILE *cs21a_file = fopen("CS21a.txt", "w");
    FILE *cs29a_file = fopen("CS29a.txt", "w");
    FILE *cs30a_file = fopen("CS30a.txt", "w");
    FILE *cs35a_file = fopen("CS35a.txt", "w");
    FILE *cs36a_file = fopen("CS36a.txt", "w");
    if (cs20a_file == NULL || cs21a_file == NULL || cs29a_file == NULL ||
        cs30a_file == NULL || cs35a_file == NULL || cs36a_file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Write registration numbers to appropriate course file
    for (int i = 0; i < num_students; i++) {
        if (students[i].cs20a) {
            fprintf(cs20a_file, "%d\n", students[i].id);
        }
        if (students[i].cs21a) {
            fprintf(cs21a_file, "%d\n", students[i].id);
        }
        if (students[i].cs29a) {
            fprintf(cs29a_file, "%d\n", students[i].id);
        }
        if (students[i].cs30a) {
            fprintf(cs30a_file, "%d\n", students[i].id);
        }
        if (students[i].cs35a) {
            fprintf(cs35a_file, "%d\n", students[i].id);
        }
        if (students[i].cs36a) {
            fprintf(cs36a_file, "%d\n", students[i].id);
        }
    }

    // Close input and output files
    fclose(in_file);
    fclose(cs20a_file);
    fclose(cs21a_file);
    fclose(cs29a_file);
    fclose(cs30a_file);
    fclose(cs35a_file);
    fclose(cs36a_file);

    return 0;
}
