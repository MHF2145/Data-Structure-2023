#include <stdio.h>
#include <string.h>

#define MAX_ENTRIES 100

struct entry {
    char name[50];
    char phone[20];
};

int compare_entries(const void *a, const void *b) {
    struct entry *entry1 = (struct entry*) a;
    struct entry *entry2 = (struct entry*) b;
    return strcmp(entry1->name, entry2->name);
}

int binary_search(struct entry *entries, int num_entries, char *name) {
    int left = 0;
    int right = num_entries - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        int cmp = strcmp(name, entries[mid].name);
        if (cmp == 0) {
            return mid;
        } else if (cmp < 0) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int main() {
    FILE *input_file = fopen("phonebook.txt", "r");
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;
    while (fscanf(input_file, "%s %s", entries[num_entries].name, entries[num_entries].phone) == 2
           && num_entries < MAX_ENTRIES) {
        num_entries++;
    }
    fclose(input_file);

    qsort(entries, num_entries, sizeof(struct entry), compare_entries);

    char name[50];
    while (1) {
        printf("Enter a name to look up (or q to quit): ");
        scanf("%s", name);
        if (strcmp(name, "q") == 0) {
            break; // quit
        }
        int index = binary_search(entries, num_entries, name);
        if (index >= 0) {
            printf("%s's phone number is %s\n", entries[index].name, entries[index].phone);
        } else {
            printf("Name not found\n");
        }
    }

    return 0;
}
