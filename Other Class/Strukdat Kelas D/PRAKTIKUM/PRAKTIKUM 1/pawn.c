#include <stdio.h>
#include <string.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n, m;
        char r;
        scanf("%d %d %c", &n, &m, &r);

        char kartu[36][3];
        for (int i = 0; i < n; i++) {
            scanf("%s", kartu[i]);
        }

        char kartulawan[35][3];
        for (int i = 0; i < m; i++) {
            scanf("%s", kartulawan[i]);
        }

        int lawan = 0;
        for (int i = 0; i < n; i++) {
            if (kartu[i][1] == r) {
                lawan = 1;
                break;
            }
        }

        if (lawan) {
            printf("YA\n");
        } else {
            char adu = kartulawan[0][1];
            int count = 0;
            for (int i = 0; i < n; i++) {
                if (kartu[i][1] == adu) {
                    count++;
                }
            }
            if (count >= m) {
                printf("YA\n");
            } else {
                printf("TIDAK\n");
            }
        }
    }
    return 0;
}
