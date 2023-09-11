#include <stdio.h>
#include <stdlib.h>

struct Node {
    char type;
    int ukuran;
};

int itung(struct Node** mantap, int N, int M, int K, int J) {
    if (K < 0 || K >= N || J < 0 || J >= M || mantap[K][J].type != 'K') {
        return 0;
    }

    int ukuran = mantap[K][J].ukuran;
    mantap[K][J].type = 'X'; 

    ukuran += itung(mantap, N, M, K - 1, J); // Atas
    ukuran += itung(mantap, N, M, K, J - 1); // Kiri
    ukuran += itung(mantap, N, M, K, J + 1); // Kanan
    ukuran += itung(mantap, N, M, K + 1, J); // Bawah

    return ukuran;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    struct Node** mantap = (struct Node**)malloc(N * sizeof(struct Node*));
    for (int i = 0; i < N; i++) {
        mantap[i] = (struct Node*)malloc(M * sizeof(struct Node));
    }

    int i = 0;
    while (i < N) {
        int j = 0;
        while (j < M) {
            char t;
            int s;
            scanf(" %c %d", &t, &s);
            mantap[i][j].type = t;
            mantap[i][j].ukuran = s;
            j++;
        }
        i++;
    }

    int ukuranTerbesar = 0;

    int K = 0;
    while (K < N) {
        int J = 0;
        while (J < M) {
            if (mantap[K][J].type == 'K') {
                int ukuranKavling = itung(mantap, N, M, K, J);
                ukuranTerbesar = (ukuranKavling > ukuranTerbesar) ? ukuranKavling : ukuranTerbesar;
            }
            J++;
        }
        K++;
    }

    printf("%d\n", ukuranTerbesar);

    int k = 0;
    while (k < N) {
        free(mantap[k]);
        k++;
    }
    free(mantap);

    return 0;
}
