#include <stdio.h>
#include <string.h>

#define MAX_CANDIDATES 10

int main() {
    FILE *input_file = fopen("votes.txt", "r");
    char buffer[100];
    fgets(buffer, sizeof(buffer), input_file);
    char *candidate_names[MAX_CANDIDATES];
    int num_candidates = 0;
    char *token = strtok(buffer, ",\n");
    while (token != NULL && num_candidates < MAX_CANDIDATES) {
        candidate_names[num_candidates] = strdup(token);
        num_candidates++;
        token = strtok(NULL, ",\n");
    }
    fclose(input_file);

    int vote_counts[MAX_CANDIDATES];
    for (int i = 0; i < num_candidates; i++) {
        vote_counts[i] = 0;
    }

    input_file = fopen("votes.txt", "r");
    while (fgets(buffer, sizeof(buffer), input_file) != NULL) {
        char *token = strtok(buffer, ",\n");
        for (int i = 0; i < num_candidates && token != NULL; i++) {
            if (i == 0) {
                token = strtok(NULL, ",\n");
                continue;
            }
            int vote = atoi(token);
            if (vote >= 1 && vote <= num_candidates) {
                vote_counts[vote-1]++;
            }
            token = strtok(NULL, ",\n");
        }
    }
    fclose(input_file);

    int indices[MAX_CANDIDATES];
    for (int i = 0; i < num_candidates; i++) {
        indices[i] = i;
    }
    for (int i = 0; i < num_candidates-1; i++) {
        for (int j = i+1; j < num_candidates; j++) {
            if (vote_counts[indices[i]] < vote_counts[indices[j]]
                || (vote_counts[indices[i]] == vote_counts[indices[j]]
                    && strcmp(candidate_names[indices[i]], candidate_names[indices[j]]) > 0)) {
                int temp = indices[i];
                indices[i] = indices[j];
                indices[j] = temp;
            }
        }
    }

    FILE *output_file = fopen("results.txt", "w");
    for (int i = 0; i < num_candidates; i++) {
        int index = indices[i];
        fprintf(output_file, "%s: %d\n", candidate_names[index], vote_counts[index]);
    }
    fclose(output_file);

    for (int i = 0; i < num_candidates; i++) {
        free(candidate_names[i]);
    }

    return 0;
}