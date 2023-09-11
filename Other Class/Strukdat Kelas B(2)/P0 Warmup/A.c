#include <stdio.h>

int main() {
    int Ai, N;
    int sum = 0;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &Ai);
        sum += Ai;
    }
    printf("%d %d\n", sum, N-sum);
    return 0;
}
