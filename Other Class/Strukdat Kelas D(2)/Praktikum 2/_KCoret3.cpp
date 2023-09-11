#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MOD 1000000007

struct node {
    long long int data;
    struct node *left;
    struct node *right;
};

struct node* createNode(long long int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* insert(struct node* root, long long int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

int search(struct node* root, long long int value) {
    if (root == NULL) {
        return 0;
    }
    if (root->data == value) {
        return 1;
    }
    else if (root->data > value) {
        return search(root->left, value);
    }
    else {
        return search(root->right, value);
    }
}

long long int powMod(long long int a, long long int b, long long int mod) {
    long long int result = 1;
    a = a % mod;
    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % mod;
        }
        b = b / 2;
        a = (a * a) % mod;
    }
    return result;
}

int main() {
    struct node *root = NULL;
    long long int num;
    long long int a = 0;
    long long int b = 0;
    long long int duplicateNum = 0;

    while (scanf("%lld", &num) == 1) {
        if (search(root, num) == 1) {
            duplicateNum = num;
            break;
        }

        if (num % 2 == 0) {
            a = num;
        }
        else if (num % 2 != 0) {
            b = num;
        }

        root = insert(root, num);
    }

    if (duplicateNum == 0) {
        printf("Tidak ada duplikat\n");
    } 
    else {
        long long int result = powMod(a, b, MOD);
        printf("%lld\n", result);
    }

    return 0;
}
