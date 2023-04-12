#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct mahasiswa {
    int nrp;
    struct mahasiswa *next;
} mahasiswa;

void init(mahasiswa **p) {
    *p = NULL;
}

mahasiswa *alokasi(int nrp) {
    mahasiswa *p;
    p = (mahasiswa*) malloc(sizeof(mahasiswa));
    if (p != NULL) {
        p->next = NULL;
        p->nrp = nrp;
    }
    return p;
}

void add(mahasiswa **p, int nrp) {
    mahasiswa *newNode = alokasi(nrp); //dibentuk node baru dengan isi NRP menggunakan function alokasi
    if (*p == NULL) { // if untuk cek linked list kosong atau tudak
        *p = newNode; // jika kosong maka akan dipindahkan ke node baru
    } else {		  // tapi jika ada node maka dia akan memindahkannya ke node baru
        mahasiswa *lastNode = *p;
        while (lastNode->next != NULL) {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
    }
}

void display(mahasiswa *p) {
    printf("Data mahasiswa:\n");
    while (p != NULL) {
        printf("- NRP: %d\n", p->nrp);
        p = p->next;
    }
}

int main() {
    mahasiswa *head;
    init(&head);
    int n, nrp;
    printf("Masukkan jumlah data mahasiswa: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Masukkan NRP mahasiswa ke-%d: ", i+1);
        scanf("%d", &nrp);
        add(&head, nrp);
    }
    display(head);
    getch();
}