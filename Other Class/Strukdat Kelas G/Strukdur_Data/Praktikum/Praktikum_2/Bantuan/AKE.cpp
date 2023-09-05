#include <bits/stdc++.h>

struct Node{
    int data;
    int emas;
    struct Node *left, *right, *up;
};


Node *newNode(int value, int emas, Node *parent){
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = value;
    temp->emas = emas;
    temp->up = parent;
    temp->left = temp->right = NULL;
    
    return temp;
}

Node *insert(Node *root, int value, int emas, Node *parent){
    if(root == NULL)
        root = newNode(value, emas, parent);
    else if(value < root->data)
        root->left = insert(root->left, value, emas, root);
    else if(value > root->data)
        root->right = insert(root->right, value, emas, root);

    return root;
}

Node *search(Node *root, int value){
    if(root == NULL || root->data == value)
        return root;
    else if(value < root->data)
        return search(root->left, value);
    else if(value > root->data)
        return search(root->right, value);
}

int main(){
    int ERROR_MOVE = 0;
    int ERROR_MINE = 0;
    int ERROR_SCAN = 0;
    int TOTAL_GOLD = 0;
    int TOTAL_ROOM = 0;

    Node *root = NULL;
    int T, X;
    std::string command;
    std::cin >> T >> command >> X;
    while(X--){
        int value, emas;
        std::cin >> value >> emas;
        if(search(root, value) == NULL){
            root = insert(root, value, emas, NULL);
            TOTAL_ROOM++;
        }
        else
            ERROR_SCAN++;
        
    }

    Node *newRoot = root;
    T -= 1;
    while(T--){
        std::cin >> command;
        if(command == "SCAN"){
            std::cin >> X;
            while(X--){
                int value, emas;
                std::cin >> value >> emas;
                if(search(root, value) == NULL){
                    root = insert(root, value, emas, NULL);
                    TOTAL_ROOM++;
                }   
                else
                    ERROR_SCAN++;
            }
        }
        else if(command == "MOVE"){
            std::string dir;
            std::cin >> dir;
            if(dir[0] == 'U'){
                if(newRoot->up == NULL)
                    ERROR_MOVE++;
                else
                    newRoot = newRoot->up;
            }
            else if(dir[0] == 'L'){
                if(newRoot->left == NULL)
                    ERROR_MOVE++;
                else
                    newRoot = newRoot->left;
            }
            else if(dir[0] == 'R'){
                if(newRoot->right == NULL)
                    ERROR_MOVE++;
                else
                    newRoot = newRoot->right;
            }
        }
        else{
            if(newRoot->emas > 0){
                TOTAL_GOLD += newRoot->emas;
                newRoot->emas = 0;
            }
            else
                ERROR_MINE++;
        }
    }

    printf("ERROR MOVE: %d\nERROR MINE: %d\nERROR SCAN: %d\nTOTAL GOLD: %d\nTOTAL ROOM: %d\n",
            ERROR_MOVE, ERROR_MINE, ERROR_SCAN, TOTAL_GOLD, TOTAL_ROOM);
}