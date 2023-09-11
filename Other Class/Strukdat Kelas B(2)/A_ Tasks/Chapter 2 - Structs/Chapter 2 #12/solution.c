#include <stdio.h>
#include <string.h>
#include "CourseDB.h"

int main()
{
    Course courses[6];
    strcpy(courses[0].code, "CS20A");
    strcpy(courses[1].code, "CS21A");
    strcpy(courses[2].code, "CS29A");
    strcpy(courses[3].code, "CS30A");
    strcpy(courses[4].code, "CS35A");
    strcpy(courses[5].code, "CS36A");

    ReadDBFrom("input.txt", courses, 6);
    PrintCourseParticipants(courses, 6);

    return 0;
}