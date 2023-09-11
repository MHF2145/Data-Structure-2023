#include <stdio.h>

#define MAX_SIZE 100

struct Number {
    int data[MAX_SIZE];
    int size;
};

int binary_search(struct Number *arr, int key) {
    int low = 0, high = arr->size - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr->data[mid] == key) {
            return mid;
        } else if (arr->data[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int count_matches(struct Number *chosen, struct Number *winners) {
    int count = 0;
    for (int i = 0; i < chosen->size; i++) {
        if (binary_search(winners, chosen->data[i]) != -1) {
            count++;
        }
    }
    return count;
}

int main() {
    struct Number chosen = {{5, 9, 1, 7, 3, 8}, 6};
    struct Number winners = {{2, 3, 5, 7, 9, 10}, 6};
    int num_matches = count_matches(&chosen, &winners);
    printf("Number of matches: %d\n", num_matches);
    return 0;
}