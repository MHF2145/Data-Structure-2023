#ifndef A0_COURSE_DB_H_
#define A0_COURSE_DB_H_

typedef struct {
    char NRP[11];
} Participant;

typedef struct {
    char code[6];
    Participant participants[100];
    unsigned short participantCount;
} Course;

void ReadDBFrom(const char* path, Course* courses, int coursesCount);
void PrintCourseParticipants(Course* courses, int coursesCount);

#endif // A0_COURSE_DB_H_