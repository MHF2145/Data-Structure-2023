#include <stdio.h>
#include <stdlib.h>

// Struktur node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Inisialisasi head
struct Node* head = NULL;

// Fungsi untuk menambahkan elemen pada awal linked list
void tambahDepan(int newData) {
    // Mengalokasikan memori untuk node baru
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->prev = NULL;
    newNode->next = head;

    // Mengubah prev dari head menjadi newNode
    if (head != NULL)
        head->prev = newNode;

    // Mengganti head dengan newNode
    head = newNode;

    // Menambahkan 1 ke jumlah elemen pada head
    head->data++;
}

// Fungsi untuk menambahkan elemen pada akhir linked list
void tambahBelakang(int newData) {
    // Mengalokasikan memori untuk node baru
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = head;
    newNode->data = newData;
    newNode->next = NULL;

    // Jika linked list masih kosong, newNode menjadi head
    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        head->data++;
        return;
    }

    // Menemukan akhir dari linked list
    while (last->next != NULL)
        last = last->next;

    // Mengubah next dari akhir linked list menjadi newNode
    last->next = newNode;

    // Mengubah prev dari newNode menjadi last
    newNode->prev = last;

    // Menambahkan 1 ke jumlah elemen pada head
    head->data++;
}

// Fungsi untuk menghapus elemen dari linked list
void hapus(int key) {
    struct Node* temp = head;
    struct Node* prev;

    // Jika head berisi key, hapus head
    if (temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        head->prev = NULL;
        head->data--;
        return;
    }

    // Mencari node dengan key
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // Jika key tidak ditemukan
    if (temp == NULL) {
        printf("Key tidak ditemukan dalam linked list.\n");
        return;
    }

    // Mengubah next dari prev dengan next dari node yang dihapus
    prev->next = temp->next;

    // Jika node yang dihapus bukanlah terakhir, mengubah prev dari next node
    if (temp->next != NULL)
        temp->next->prev = prev;

    // Menghapus node
    free(temp);

    // Mengurangi 1 dari jumlah elemen pada head
    head->data--;
}

// Fungsi untuk melihat isi linked list
void lihat() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("Linked list kosong.\n");
        return;
    }

    printf("Isi linked list: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Fungsi untuk mengedit elemen dalam linked list
void edit(int key, int newData) {
    struct Node* temp = head;

    // Mencari node dengan key
    while (temp != NULL && temp->data != key)
        temp = temp->next;

    // Jika key tidak ditemukan
    if (temp == NULL) {
        printf("Key tidak ditemukan dalam linked list.\n");
        return;
    }

    // Mengubah data node dengan newData
    temp->data = newData;
}

// Fungsi rekursif untuk menampilkan linked list secara terbalik
void tampilTerbalikRekursif(struct Node* node) {
    if (node == NULL)
        return;

    // Memanggil fungsi rekursif untuk node berikutnya
    tampilTerbalikRekursif(node->next);

    // Menampilkan data node saat ini
    printf("%d ", node->data);
}

// Fungsi untuk menampilkan linked list secara terbalik
void tampilTerbalik() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("Linked list kosong.\n");
        return;
    }

    printf("Isi linked list (terbalik): ");
    tampilTerbalikRekursif(temp);
    printf("\n");
}

int main() {
    int pilihan, data, key;

    while (1) {
        printf("\n-- Program Double Linked List --\n");
        printf("1. Tambah Depan\n");
        printf("2. Tambah Belakang\n");
        printf("3. Hapus\n");
        printf("4. Lihat\n");
        printf("5. Edit\n");
        printf("6. Tampil Terbalik\n");
        printf("7. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("Masukkan data: ");
                scanf("%d", &data);
                tambahDepan(data);
                break;
            case 2:
                printf("Masukkan data: ");
                scanf("%d", &data);
                tambahBelakang(data);
                break;
            case 3:
                printf("Masukkan data yang ingin dihapus: ");
                scanf("%d", &key);
                hapus(key);
                break;
            case 4:
                lihat();
                break;
            case 5:
                printf("Masukkan data yang ingin diubah: ");
                scanf("%d", &key);
                printf("Masukkan data baru: ");
                scanf("%d", &data);
                edit(key, data);
                break;
            case 6:
                tampilTerbalik();
                break;
            case 7:
                exit(0);
            default:
                printf("Pilihan tidak valid.\n");
        }
    }

    return 0;
}
