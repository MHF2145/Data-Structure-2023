#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Fungsi untuk menyisipkan anggota keluarga ke dalam BST
Node* insertNode(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else {
        root->right = insertNode(root->right, value);
    }

    return root;
}

// Fungsi untuk mencari apakah ada kombinasi yang tepat
bool findCombination(Node* root, int sum, int count) {
    if (root == nullptr) {
        return false;
    }

    // Menggunakan algoritma DFS untuk mencari kombinasi yang tepat
    if (count == 3 && sum == 0) {
        return true;
    }

    bool left = findCombination(root->left, sum - root->data, count + 1);
    bool right = findCombination(root->right, sum - root->data, count + 1);

    return left || right;
}

// Fungsi untuk mencetak output sesuai format yang diminta
void printOutput(bool found, int secretNumber) {
    if (found) {
        cout << secretNumber << " Selamat! Kalian menemukan harta karunnya" << endl;
    } else {
        cout << secretNumber << " Tidak ada kombinasi yang tepat! Bikin ulang." << endl;
    }
}

int main() {
    int N;
    cin >> N;

    vector<int> ages(N);
    for (int i = 0; i < N; i++) {
        cin >> ages[i];
    }

    int K;
    cin >> K;

    // Membentuk BST dari umur anggota keluarga
    Node* root = nullptr;
    for (int i = 0; i < N; i++) {
        root = insertNode(root, ages[i]);
    }

    // Mencari kombinasi yang tepat
    bool foundCombination = findCombination(root, K, 0);

    // Mencetak output
    printOutput(foundCombination, K);

    return 0;
}
