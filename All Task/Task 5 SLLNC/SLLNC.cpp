#include <bits/stdc++.h>

// Node struct untuk merepresentasikan node dalam linked list
struct Node {
    int data;
    Node* next;
};

// Class LinkedList untuk mengelola linked list
class LinkedList {
private:
    Node* head;

public:
    // Constructor
    LinkedList() {
        head = nullptr;
    }

    // Destructor
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    // Function untuk menambahkan data ke linked list
    void addData(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }

        std::cout << "Data " << value << " berhasil ditambahkan ke linked list." << std::endl;
    }

    // Function untuk melihat data dalam linked list
    void viewData() {
        if (head == nullptr) {
            std::cout << "Linked list kosong." << std::endl;
        } else {
            Node* current = head;
            std::cout << "Data dalam linked list: ";
            while (current != nullptr) {
                std::cout << current->data << " ";
                current = current->next;
            }
            std::cout << std::endl;
        }
    }

    // Function untuk menghapus data tertentu dalam linked list
    void deleteData(int value) {
        if (head == nullptr) {
            std::cout << "Linked list kosong. Tidak ada data yang dihapus." << std::endl;
            return;
        }

        Node* current = head;
        Node* prev = nullptr;
        bool found = false;

        while (current != nullptr) {
            if (current->data == value) {
                found = true;
                break;
            }
            prev = current;
            current = current->next;
        }

        if (found) {
            if (prev == nullptr) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
            std::cout << "Data " << value << " berhasil dihapus dari linked list." << std::endl;
        } else {
            std::cout << "Data " << value << " tidak ditemukan dalam linked list." << std::endl;
        }
    }

    // Function untuk mencari data dalam linked list (ber-Head)
    bool searchData(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // Function untuk mencari data dalam linked list (ber-Head dan Tail)
    bool searchDataBidirectional(int value) {
        Node* current = head;
        Node* tail = nullptr;
        while (current != nullptr) {
            if (current->data == value) {
                return true;
            }
            tail = current;
            current = current->next;
        }
        current = tail;
        while (current != nullptr) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // Function untuk menyisipkan node setelah data tertentu
    void insertAfter(int afterValue, int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == afterValue) {
                Node* newNode = new Node;
                newNode->data = value;
                newNode->next = current->next;
                current->next = newNode;
                std::cout << "Data " << value << " berhasil disisipkan setelah " << afterValue << "." << std::endl;
                return;
            }
            current = current->next;
        }
        std::cout << "Data " << afterValue << " tidak ditemukan dalam linked list. Data tidak disisipkan." << std::endl;
    }

    // Function untuk menyisipkan node sebelum data tertentu
    void insertBefore(int beforeValue, int value) {
        if (head == nullptr) {
            std::cout << "Linked list kosong. Data tidak disisipkan." << std::endl;
            return;
        }

        if (head->data == beforeValue) {
            Node* newNode = new Node;
            newNode->data = value;
            newNode->next = head;
            head = newNode;
            std::cout << "Data " << value << " berhasil disisipkan sebelum " << beforeValue << "." << std::endl;
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            if (current->next->data == beforeValue) {
                Node* newNode = new Node;
                newNode->data = value;
                newNode->next = current->next;
                current->next = newNode;
                std::cout << "Data " << value << " berhasil disisipkan sebelum " << beforeValue << "." << std::endl;
                return;
            }
            current = current->next;
        }

        std::cout << "Data " << beforeValue << " tidak ditemukan dalam linked list. Data tidak disisipkan." << std::endl;
    }
};

// Function untuk menampilkan menu
void displayMenu() {
    std::cout << "Menu: " << std::endl;
    std::cout << "1. Tambah Data" << std::endl;
    std::cout << "2. Lihat Data" << std::endl;
    std::cout << "3. Hapus Data" << std::endl;
    std::cout << "4. Cari Data (Ber-Head)" << std::endl;
    std::cout << "5. Cari Data (Ber-Head dan Tail)" << std::endl;
    std::cout << "6. Sisipkan Node Setelah Data Tertentu" << std::endl;
    std::cout << "7. Sisipkan Node Sebelum Data Tertentu" << std::endl;
    std::cout << "8. Keluar" << std::endl;
    std::cout << "Masukkan pilihan Anda: ";
}

int main() {
    LinkedList linkedList;
    int choice;

    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int data;
                std::cout << "Masukkan data yang ingin ditambahkan: ";
                std::cin >> data;
                linkedList.addData(data);
                break;
            }
            case 2:
                linkedList.viewData();
                break;
            case 3: {
                int data;
                std::cout << "Masukkan data yang ingin dihapus: ";
                std::cin >> data;
                linkedList.deleteData(data);
                break;
            }
            case 4: {
                int data;
                std::cout << "Masukkan data yang ingin dicari: ";
                std::cin >> data;
                if (linkedList.searchData(data)) {
                    std::cout << "Data ditemukan dalam linked list (ber-Head)." << std::endl;
                } else {
                    std::cout << "Data tidak ditemukan dalam linked list (ber-Head)." << std::endl;
                }
                break;
            }
            case 5: {
                int data;
                std::cout << "Masukkan data yang ingin dicari: ";
                std::cin >> data;
                if (linkedList.searchDataBidirectional(data)) {
                    std::cout << "Data ditemukan dalam linked list (ber-Head dan Tail)." << std::endl;
                } else {
                    std::cout << "Data tidak ditemukan dalam linked list (ber-Head dan Tail)." << std::endl;
                }
                break;
            }
            case 6: {
                int afterValue, value;
                std::cout << "Masukkan data setelah data yang ingin disisipkan: ";
                std::cin >> afterValue;
                std::cout << "Masukkan data yang ingin disisipkan: ";
                std::cin >> value;
                linkedList.insertAfter(afterValue, value);
                break;
            }
            case 7: {
                int beforeValue, value;
                std::cout << "Masukkan data sebelum data yang ingin disisipkan: ";
                std::cin >> beforeValue;
                std::cout << "Masukkan data yang ingin disisipkan: ";
                std::cin >> value;
                linkedList.insertBefore(beforeValue, value);
                break;
            }
            case 8:
                std::cout << "Terima kasih telah menggunakan program ini. Sampai jumpa!" << std::endl;
                break;
            default:
                std::cout << "Pilihan tidak valid. Silakan coba lagi." << std::endl;
                break;
        }
    } while (choice != 8);

    return 0;
}
