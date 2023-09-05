#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> myVector;

struct BSTNode
{
  BSTNode *left, *right;
  int key;
};

/* uniqueBST */

struct BST
{
  // Member
  BSTNode *_root;
  int _size;

  // Function
  void init()
  {
    _root = NULL;
    _size = 0;
  }

  bool isEmpty()
  {
    return _root == NULL;
  }

  bool find(int value)
  {
    BSTNode *temp = __search(_root, value);
    if (!temp)
      return false;

    if (temp->key == value)
      return true;
    else
      return false;
  }

  void findPath(int value)
  {
    while (_root != NULL)
    {
      if (value < _root->key)
      {
        printf("L");
        _root = _root->left;
      }
      else if (value > _root->key)
      {
        printf("R");
        _root = _root->right;
      }
      else
      {
        printf("S\n");
        return;
      }
    }
  }

  int findlevel(BSTNode *root, int t, int l)
  {
    if (!root)
      return 0;

    if (root->key == t)
      return l;

    int x = findlevel(root->left, t, l + 1);

    if (x != 0)
      return x;
    x = findlevel(root->right, t, l + 1);
    return x;
  }

  void insert(int value)
  {
    if (!find(value))
    {
      _root = __insert(_root, value);
      _size++;
    }
  }

  void traverseInorder()
  {
    __inorder(_root);
  }

  int getLevel(int target)
  {
    if (!_root)
      return 0;
    int l = 1;
    return findlevel(_root, target, l);
  }

private:
  // Utility Function
  BSTNode *__createNode(int value)
  {
    BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
  }

  BSTNode *__search(BSTNode *root, int value)
  {
    while (root != NULL)
    {
      if (value < root->key)
        root = root->left;
      else if (value > root->key)
        root = root->right;
      else
        return root;
    }
    return root;
  }

  BSTNode *__insert(BSTNode *root, int value)
  {
    if (root == NULL)
      return __createNode(value);

    if (value < root->key)
      root->left = __insert(root->left, value);
    else if (value > root->key)
      root->right = __insert(root->right, value);

    return root;
  }

  void __inorder(BSTNode *root)
  {
    if (root)
    {
      __inorder(root->left);
      myVector.push_back(root->key);
      __inorder(root->right);
    }
  }
};

int main()
{
  BST set;
  set.init();

  string input;
  int x;

  while (1)
  {
    cin >> input;
    if (input == "IN")
    {
      cin >> x;
      if (!set.find(x))
      {
        set.insert(x);
      }
    }
    if (input == "FD")
    {
      cin >> x;
      if (set.find(x))
      {
        cout << "on level " << set.getLevel(x) << endl;
      }
      else
      {
        cout << "no " << x << endl;
      }
    }
    if (input == "RK")
    {
      cin >> x;
      if (x > set._size)
        cout << "-1";
      else
      {
        set.traverseInorder();
        cout << myVector.at(x - 1) << endl;
        myVector.clear();
      }
    }
    if (input == "PH")
    {
      cin >> x;
      if (!set.find(x))
      {
        cout << "no " << x << endl;
      }
      else
        set.findPath(x);
    }
    if (input == "STOP")
    {
      cout << "done" << endl;
      break;
    }
  }
}