#include <cstddef>
#include <sstream>
#include <stdexcept>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

class BinarySearchTree {
private:
    struct BSTNode {
        int data;
        BSTNode* left;
        BSTNode* right;
    };

    BSTNode* _create_node(const int value);
    static int _default_compare(const int value1, const int value2);
    BSTNode* _get_reference(BSTNode* rootNode, const int value);

    void _clear(BSTNode* rootNode);

    BSTNode* m_root;
    std::size_t m_size;
    int (*_compare)(const int value1, const int value2);


public:
    BinarySearchTree(int (*compare)(const int, const int) = _default_compare);
    
    void insert(const int value);

    bool contains(const int value) const;
    const int search(const int value);

    int getHeight(int value);
    bool aman(int value);
    vector<int>* getLevelOrder(BSTNode* root);
    ~BinarySearchTree();
};



BinarySearchTree::BSTNode* BinarySearchTree::_create_node(const int value) {
    BSTNode* newNode = new BSTNode();
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}


int BinarySearchTree::_default_compare(const int value1, const int value2) {
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


BinarySearchTree::BSTNode* BinarySearchTree::_get_reference(BSTNode* rootNode, const int value) {
    if (rootNode == nullptr) {
        throw std::runtime_error("Element not found.");
    }

    BSTNode* cursor = rootNode;
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


void BinarySearchTree::_clear(BSTNode* rootNode) {
    if (rootNode != nullptr) {
        _clear(rootNode->left);
        _clear(rootNode->right);
        delete rootNode;
    }
}


BinarySearchTree::BinarySearchTree(int (*compare)(const int, const int)) {
    m_root = nullptr;
    _compare = compare;
    m_size = 0;
}


void BinarySearchTree::insert(const int value) {
    BSTNode *newNode = _create_node(value);

    if (m_root == nullptr) {
        m_root = newNode;
    }
    else {
        BSTNode* cursor = m_root;
        BSTNode* insertPos = m_root;
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


bool BinarySearchTree::contains(const int value) const {
    if (m_root == nullptr) {
        return false;
    }
    
    BSTNode* cursor = m_root;
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


const int BinarySearchTree::search(const int value) {
    return _get_reference(m_root, value)->data;
}


int BinarySearchTree::getHeight(int value) {    
    BSTNode* cursor = m_root;
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


vector<int>* BinarySearchTree::getLevelOrder(BSTNode* root) {
    vector<int>* arr = new vector<int>;
	if (root == nullptr) {
		return arr;
    }

	queue<BSTNode*> q;
	q.push(root);
    
	while (!q.empty()) {
		BSTNode* node = q.front();
        arr->push_back(node->data);
		q.pop();

		if (node->left != nullptr) {
			q.push(node->left);
        }

		if (node->right != nullptr) {
			q.push(node->right);
        }
	}

    return arr;
}


bool BinarySearchTree::aman(int value) {
    BSTNode* node = _get_reference(m_root, value);
    if (node->left != nullptr || node->right != nullptr) {
        vector<int>* arrp = getLevelOrder(m_root);
        vector<int> arr = *arrp;
        
        int pos = -1;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == value) {
                pos = i;
                break;
            }
        }

        // for (int i = 0; i < arr.size(); i++) {
        //     cout << arr[i] << " ";
        // }
        // cout << endl;

        if (pos < arr.size() - 1 && arr.size() > 1) {
            int hh = getHeight(arr[pos]);
            int ha = getHeight(arr[pos-1]);
            int hb = getHeight(arr[pos+1]);

            // cout << arr[pos] << " " << hh << endl;
            // cout << arr[pos-1] << " " << ha << endl;
            // cout << arr[pos+1] << " " << hb << endl;

            if (hh == ha && hh == hb) {
                return true;
            }
        } 

        return false;
    }
    return false;
} 


BinarySearchTree::~BinarySearchTree() {
    _clear(m_root);
}

#include <iostream>

int main() {
    BinarySearchTree bst;
    int N;
    cin >> N;
    int Ni;
    for (int i = 0; i < N; i++) {
        cin >> Ni;
        bst.insert(Ni);
    }
    int M;
    cin >> M;
    bool yes = bst.aman(M);
    if (yes) {
        cout << "Supply aman" << endl;
    }
    else {
        cout << "Ga aman, ganti lokasi!" << endl;
    }
    return 0;
}

