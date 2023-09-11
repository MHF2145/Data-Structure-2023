#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CourseDB.h"

void ReadDBFrom(const char* path, Course* courses, int coursesCount)
{
    FILE* dbFile = fopen(path, "r");

    if (!dbFile) {
        fprintf(stderr, "ERROR: File does not exist.");
        exit(EXIT_FAILURE);
    }

    unsigned short* participantCount = (unsigned short*)malloc(coursesCount * sizeof(unsigned short));
    for (int i = 0; i < coursesCount; i++) {
        participantCount[i] = 0;
    }

    while (1) {
        Participant temp_Participant;
        char* temp_ParticipantCourses = (char*)malloc((coursesCount + 1) * sizeof(char));

        fscanf(dbFile, "%s", temp_Participant.NRP);
        if (strcmp(temp_Participant.NRP, "END") == 0) {
            free(temp_ParticipantCourses);
            break;
        }
        fscanf(dbFile, "%s", temp_ParticipantCourses);

        for (int i = 0; i < coursesCount; i++) {
            if (temp_ParticipantCourses[i] == '1') {
                strcpy(courses[i].participants[participantCount[i]].NRP, temp_Participant.NRP);
                participantCount[i]++;
            }
        }

        free(temp_ParticipantCourses);
    }

    for (int i = 0; i < coursesCount; i++) {
        courses[i].participantCount = participantCount[i];
    }

    free(participantCount);
    fclose(dbFile);
}

void PrintCourseParticipants(Course* courses, int coursesCount)
{
    for (int i = 0; i < coursesCount; i++) {
        printf("Participants for Course %s (%d participants):\n", courses[i].code, courses[i].participantCount);
        for (int j = 0; j < courses[i].participantCount; j++) {
            printf("NRP: %s\n", courses[i].participants[j].NRP);
        }
        printf("\n");
    }
}