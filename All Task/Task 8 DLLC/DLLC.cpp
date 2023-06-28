#include <bits/stdc++.h>

// Node dalam linked list
struct Node
{
    int data;
    Node *prev;
    Node *next;
};

// Kelas untuk linked list
class DoubleLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    // Constructor
    DoubleLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    // Fungsi untuk menambah data ke linked list
    void addData(int newData)
    {
        Node *newNode = new Node;
        newNode->data = newData;
        newNode->next = NULL;

        if (head == NULL)
        {
            newNode->prev = NULL;
            head = newNode;
            tail = newNode;
            head->next = head;
            head->prev = head;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
            head->prev = tail;
        }

        std::cout << "Data " << newData << " ditambahkan ke linked list." << std::endl;
    }

    // Fungsi untuk mencetak data dalam linked list
    void printData()
    {
        if (head == NULL)
        {
            std::cout << "Linked list kosong." << std::endl;
            return;
        }

        Node *current = head;

        std::cout << "Data dalam linked list: ";
        do
        {
            std::cout << current->data << " ";
            current = current->next;
        } while (current != head);

        std::cout << std::endl;
    }

    // Fungsi untuk mencari data dengan head
    bool searchDataHead(int searchData)
    {
        if (head == NULL)
        {
            std::cout << "Linked list kosong." << std::endl;
            return false;
        }

        Node *current = head;

        do
        {
            if (current->data == searchData)
            {
                std::cout << "Data ditemukan dalam linked list (dengan head)." << std::endl;
                return true;
            }
            current = current->next;
        } while (current != head);

        std::cout << "Data tidak ditemukan dalam linked list (dengan head)." << std::endl;
        return false;
    }

    // Fungsi untuk mencari data dengan head dan tail
    bool searchDataHeadTail(int searchData)
    {
        if (head == NULL)
        {
            std::cout << "Linked list kosong." << std::endl;
            return false;
        }

        Node *current = head;

        do
        {
            if (current->data == searchData)
            {
                std::cout << "Data ditemukan dalam linked list (dengan head dan tail)." << std::endl;
                return true;
            }
            current = current->next;
        } while (current != head);

        std::cout << "Data tidak ditemukan dalam linked list (dengan head dan tail)." << std::endl;
        return false;
    }

    // Fungsi untuk menghapus data tertentu dalam linked list
    void deleteData(int deleteData)
    {
        if (head == NULL)
        {
            std::cout << "Linked list kosong." << std::endl;
            return;
        }

        Node *current = head;
        Node *prevNode = NULL;

        // Mencari data yang akan dihapus
        while (current->data != deleteData)
        {
            if (current->next == head)
            {
                std::cout << "Data tidak ditemukan dalam linked list." << std::endl;
                return;
            }

            prevNode = current;
            current = current->next;
        }

        // Jika data yang akan dihapus berada pada head
        if (current == head)
        {
            head = head->next;
            tail->next = head;
            head->prev = tail;
        }
        // Jika data yang akan dihapus berada pada tail
        else if (current == tail)
        {
            prevNode->next = head;
            tail = prevNode;
            head->prev = tail;
        }
        // Jika data yang akan dihapus berada di tengah-tengah
        else
        {
            prevNode->next = current->next;
            current->next->prev = prevNode;
        }

        delete current;
        std::cout << "Data " << deleteData << " dihapus dari linked list." << std::endl;
    }

    // Fungsi untuk menampilkan data secara terbalik
    void printReverse()
    {
        if (head == NULL)
        {
            std::cout << "Linked list kosong." << std::endl;
            return;
        }

        Node *current = tail;

        std::cout << "Data dalam linked list (terbalik): ";
        do
        {
            std::cout << current->data << " ";
            current = current->prev;
        } while (current != tail);

        std::cout << std::endl;
    }
};

int main()
{
    DoubleLinkedList dll;
    int pilihan, data, searchData, deleteData;

    do
    {
        std::cout << "\nMenu:" << std::endl;
        std::cout << "1. Tambah data" << std::endl;
        std::cout << "2. Lihat data" << std::endl;
        std::cout << "3. Cari data dengan head" << std::endl;
        std::cout << "4. Cari data dengan head dan tail" << std::endl;
        std::cout << "5. Hapus data" << std::endl;
        std::cout << "6. Tampilkan data terbalik" << std::endl;
        std::cout << "0. Keluar" << std::endl;
        std::cout << "Pilih menu: ";
        std::cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            std::cout << "Masukkan data baru: ";
            std::cin >> data;
            dll.addData(data);
            break;
        case 2:
            dll.printData();
            break;
        case 3:
            std::cout << "Masukkan data yang dicari: ";
            std::cin >> searchData;
            dll.searchDataHead(searchData);
            break;
        case 4:
            std::cout << "Masukkan data yang dicari: ";
            std::cin >> searchData;
            dll.searchDataHeadTail(searchData);
            break;
        case 5:
            std::cout << "Masukkan data yang akan dihapus: ";
            std::cin >> deleteData;
            dll.deleteData(deleteData);
            break;
        case 6:
            dll.printReverse();
            break;
        case 0:
            std::cout << "Program selesai." << std::endl;
            break;
        default:
            std::cout << "Pilihan menu tidak valid." << std::endl;
        }
    } while (pilihan != 0);

    return 0;
}
