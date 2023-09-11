#include <cstddef>
#include <sstream>
#include <stdexcept>

template <typename T>
class BinarySearchTree {
private:
    template <typename U>
    struct BSTNode {
        U data;
        BSTNode<U>* left;
        BSTNode<U>* right;
    };

    BSTNode<T>* _create_node(const T& value);
    static int _default_compare(const T& value1, const T& value2);
    BSTNode<T>* _get_reference(BSTNode<T>* rootNode, const T& value);

    void _clear(BSTNode<T>* rootNode);

    BSTNode<T>* m_root;
    std::size_t m_size;
    int (*_compare)(const T& value1, const T& value2);


public:
    BinarySearchTree(int (*compare)(const T&, const T&) = _default_compare);
    
    void insert(const T& value);

    bool contains(const T& value) const;
    const T& search(const T& value);

    int getHeight(int value);
    ~BinarySearchTree();
};


template <typename T>
BinarySearchTree<T>::BSTNode<T>* BinarySearchTree<T>::_create_node(const T& value) {
    BSTNode<T>* newNode = new BSTNode<T>();
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

template <typename T>
int BinarySearchTree<T>::_default_compare(const T& value1, const T& value2) {
    if (value1 < value2) {
        return -1;
    }
    else if (value1 > value2) {
        return 1;
    }
    else {
        return 0;
    }
}

template <typename T>
BinarySearchTree<T>::BSTNode<T>* BinarySearchTree<T>::_get_reference(BSTNode<T>* rootNode, const T& value) {
    if (rootNode == nullptr) {
        throw std::runtime_error("Element not found.");
    }

    BSTNode<T>* cursor = rootNode;
    while (cursor != nullptr) {
        if (_compare(value, cursor->data) < 0) {
            cursor = cursor->left;
        }
        else if (_compare(value, cursor->data) > 0) {
            cursor = cursor->right;
        }
        else {
            return cursor;
        }
    }

    throw std::runtime_error("Element not found.");
}

template <typename T>
void BinarySearchTree<T>::_clear(BSTNode<T>* rootNode) {
    if (rootNode != nullptr) {
        _clear(rootNode->left);
        _clear(rootNode->right);
        delete rootNode;
    }
}

template <typename T>
BinarySearchTree<T>::BinarySearchTree(int (*compare)(const T&, const T&)) {
    m_root = nullptr;
    _compare = compare;
    m_size = 0;
}

template <typename T>
void BinarySearchTree<T>::insert(const T& value) {
    BSTNode<T> *newNode = _create_node(value);

    if (m_root == nullptr) {
        m_root = newNode;
    }
    else {
        BSTNode<T>* cursor = m_root;
        BSTNode<T>* insertPos = m_root;
        while (cursor != nullptr) {
            insertPos = cursor;
            if (_compare(value, cursor->data) <= 0) {
                cursor = cursor->left;
            }
            else {
                cursor = cursor->right;
            }
        }
        if (_compare(value, insertPos->data) <= 0) {
            insertPos->left = newNode;
        }
        else {
            insertPos->right = newNode;
        }
    }
    
    m_size++;
}

template <typename T>
bool BinarySearchTree<T>::contains(const T& value) const {
    if (m_root == nullptr) {
        return false;
    }
    
    BSTNode<T>* cursor = m_root;
    while (cursor != nullptr) {
        if (_compare(value, cursor->data) < 0) {
            cursor = cursor->left;
        }
        else if (_compare(value, cursor->data) > 0) {
            cursor = cursor->right;
        }
        else {
            return true;
        }
    }
    return false;
}

template <typename T>
const T& BinarySearchTree<T>::search(const T& value) {
    return _get_reference(m_root, value)->data;
}


template <typename T>
int BinarySearchTree<T>::getHeight(int value) {    
    BSTNode<T>* cursor = m_root;
    int height = 0;
    while (cursor != nullptr) {
        if (_compare(value, cursor->data) < 0) {
            cursor = cursor->left;
            height++;
        }
        else if (_compare(value, cursor->data) > 0) {
            cursor = cursor->right;
            height++;
        }
        else {
            return height;
        }
    }
    return -1;
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {
    _clear(m_root);
}

#include <iostream>
#include <vector>
using namespace std;

int main() {
    BinarySearchTree<int> bst;

    int N;
    cin >> N;
    
    int Ni;
    for (int i = 0; i < N; i++) {
        cin >> Ni;
        bst.insert(Ni);
    }

    int M;
    cin >> M;
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        int h = bst.getHeight(a) - bst.getHeight(b);
        if (h > 0) {
            cout << h << endl;
        }
        else if (h < 0) {
            cout << -h << endl;
        }
        else {
            cout << "Galaxy berada pada tingkat yang sama" << endl;
        }
    }
}