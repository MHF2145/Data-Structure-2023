#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

#define MOD 1000000007

using namespace std;



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

int main()
{
	struct node *root = NULL;
	long long c;
	long long a, b = 0;
	long long duplicate = 0;
	
	while(cin>>c)
	{	
		if (search(root, c) == 1)
		{
			duplicate = c;
			break;
		}
		
		if(c % 2 == 0)
		{
			a = c;
		}
		
		else
		{
			b = c;
		}
		
		root = insert(root, c);
	}
	
	if(duplicate ==0)
	{
		cout << "Tidak ada duplikat" << endl;	
	}
	
	else 
	{
		long long int result = powMod(a, b, MOD);
		cout << result << endl;
	}
}
