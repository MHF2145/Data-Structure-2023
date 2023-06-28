#include <bits/stdc++.h>

struct Node
{
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    void insert(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            Node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }

        std::cout << "Data " << value << " telah ditambahkan ke dalam linked list." << std::endl;
    }

    void display()
    {
        if (head == nullptr)
        {
            std::cout << "Linked list kosong." << std::endl;
            return;
        }

        Node *temp = head;
        std::cout << "Data dalam linked list:" << std::endl;
        do
        {
            std::cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        std::cout << std::endl;
    }

    bool search(int value)
    {
        if (head == nullptr)
        {
            std::cout << "Linked list kosong." << std::endl;
            return false;
        }

        Node *temp = head;
        do
        {
            if (temp->data == value)
            {
                std::cout << "Data " << value << " ditemukan dalam linked list." << std::endl;
                return true;
            }
            temp = temp->next;
        } while (temp != head);

        std::cout << "Data " << value << " tidak ditemukan dalam linked list." << std::endl;
        return false;
    }

    void deleteNode(int value)
    {
        if (head == nullptr)
        {
            std::cout << "Linked list kosong." << std::endl;
            return;
        }

        Node *current = head;
        Node *previous = nullptr;
        bool found = false;

        // Cek apakah data yang akan dihapus adalah head
        if (current->data == value)
        {
            found = true;
            while (current->next != head)
            {
                current = current->next;
            }
            if (head == head->next)
            {
                head = nullptr;
            }
            else
            {
                current->next = head->next;
                head = head->next;
            }
            delete current;
            std::cout << "Data " << value << " telah dihapus dari linked list." << std::endl;
            return;
        }

        // Cari data yang akan dihapus
        do
        {
            previous = current;
            current = current->next;
            if (current->data == value)
            {
                found = true;
                break;
            }
        } while (current != head);

        // Hapus data jika ditemukan
        if (found)
        {
            previous->next = current->next;
            delete current;
            std::cout << "Data " << value << " telah dihapus dari linked list." << std::endl;
        }
        else
        {
            std::cout << "Data " << value << " tidak ditemukan dalam linked list." << std::endl;
        }
    }

    void insertAfter(int value, int afterValue)
    {
        if (head == nullptr)
        {
            std::cout << "Linked list kosong." << std::endl;
            return;
        }

        Node *current = head;
        bool found = false;

        do
        {
            if (current->data == afterValue)
            {
                found = true;
                break;
            }
            current = current->next;
        } while (current != head);

        if (found)
        {
            Node *newNode = new Node;
            newNode->data = value;
            newNode->next = current->next;
            current->next = newNode;
            std::cout << "Data " << value << " telah disisipkan setelah data " << afterValue << "." << std::endl;
        }
        else
        {
            std::cout << "Data " << afterValue << " tidak ditemukan dalam linked list." << std::endl;
        }
    }

    void insertBefore(int value, int beforeValue)
    {
        if (head == nullptr)
        {
            std::cout << "Linked list kosong." << std::endl;
            return;
        }

        Node *current = head;
        Node *previous = nullptr;
        bool found = false;

        // Cek apakah data yang akan disisipkan adalah head
        if (current->data == beforeValue)
        {
            found = true;
            Node *newNode = new Node;
            newNode->data = value;
            newNode->next = head;
            while (current->next != head)
            {
                current = current->next;
            }
            current->next = newNode;
            head = newNode;
            std::cout << "Data " << value << " telah disisipkan sebelum data " << beforeValue << "." << std::endl;
            return;
        }

        // Cari posisi sisipan
        do
        {
            previous = current;
            current = current->next;
            if (current->data == beforeValue)
            {
                found = true;
                break;
            }
        } while (current != head);

        // Sisipkan data jika ditemukan
        if (found)
        {
            Node *newNode = new Node;
            newNode->data = value;
            previous->next = newNode;
            newNode->next = current;
            std::cout << "Data " << value << " telah disisipkan sebelum data " << beforeValue << "." << std::endl;
        }
        else
        {
            std::cout << "Data " << beforeValue << " tidak ditemukan dalam linked list." << std::endl;
        }
    }
};

int main()
{
    LinkedList linkedList;
    int choice, value, searchData, deleteData, afterValue, beforeValue;

    while (true)
    {
        std::cout << "\n==== Menu ====" << std::endl;
        std::cout << "1. Tambah data" << std::endl;
        std::cout << "2. Lihat data" << std::endl;
        std::cout << "3. Cari data" << std::endl;
        std::cout << "4. Hapus data" << std::endl;
        std::cout << "5. Sisipkan setelah data tertentu" << std::endl;
        std::cout << "6. Sisipkan sebelum data tertentu" << std::endl;
        std::cout << "7. Keluar" << std::endl;
        std::cout << "Pilihan Anda: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Masukkan nilai yang ingin ditambahkan: ";
            std::cin >> value;
            linkedList.insert(value);
            break;
        case 2:
            linkedList.display();
            break;
        case 3:
            std::cout << "Masukkan nilai yang ingin dicari: ";
            std::cin >> searchData;
            linkedList.search(searchData);
            break;
        case 4:
            std::cout << "Masukkan nilai yang ingin dihapus: ";
            std::cin >> deleteData;
            linkedList.deleteNode(deleteData);
            break;
        case 5:
            std::cout << "Masukkan nilai yang ingin disisipkan: ";
            std::cin >> value;
            std::cout << "Masukkan data setelah nilai: ";
            std::cin >> afterValue;
            linkedList.insertAfter(value, afterValue);
            break;
        case 6:
            std::cout << "Masukkan nilai yang ingin disisipkan: ";
            std::cin >> value;
            std::cout << "Masukkan data sebelum nilai: ";
            std::cin >> beforeValue;
            linkedList.insertBefore(value, beforeValue);
            break;
        case 7:
            return 0;
        default:
            std::cout << "Pilihan tidak valid. Silakan pilih kembali." << std::endl;
        }
    }

    return 0;
}
