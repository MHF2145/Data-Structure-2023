#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int Value;
    int Index = 1;
    Node* Left = nullptr;
    Node* Right = nullptr;
};

class BinaryTree {
public:
    Node* Root = nullptr;

    void insert(int Value) {
        Node** Tree = &Root;
        while (*Tree) {
            if ((*Tree)->Value < Value) {
                Tree = &(*Tree)->Right;
            }
            else if ((*Tree)->Value > Value) {
                (*Tree)->Index++;
                Tree = &(*Tree)->Left;
            }
            else {
                return;
            }
        }
        *Tree = new Node{ Value };
    }

    int search(int Value) {
        int sumCounter = 0;
        Node* Tree = Root;
        while (Tree) {
            if (Tree->Value == Value) {
                return sumCounter + Tree->Index;
            }
            else if (Tree->Value < Value) {
                sumCounter += Tree->Index;
                Tree = Tree->Right;
            }
            else {
                Tree = Tree->Left;
            }
        }
        return 0;
    }
};

int main() {
    BinaryTree tree;
    vector<int> search;
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        char cmd;
        int x;
        cin >> cmd >> x;
        if (cmd == 'T') {
            tree.insert(x);
        }
        else if (cmd == 'L') {
            search.push_back(tree.search(x));
        }
    }
    for (auto query : search) {
        cout << query << endl;
    }
    return 0;
}
