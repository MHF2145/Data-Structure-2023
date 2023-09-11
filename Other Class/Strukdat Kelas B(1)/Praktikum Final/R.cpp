#include<bits/stdc++.h>
using namespace std;

struct SListNode 
{
    int data;
    SListNode *next;
}; 

struct SinglyList
{
    SListNode *_head;
    unsigned _size;

    void init() {
        _head = NULL;
        _size = 0;
    }

    bool isEmpty() {
        return (_head == NULL);
    }

    void pushFront(int value)
    {
        SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
        if (newNode) {
            _size++;
            newNode->data = value;
            
            if (isEmpty()) newNode->next = NULL;
            else newNode->next = _head;
            _head = newNode;
        }
    }

    void pushBack(int value)
    {
        SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
        if (newNode) {
            _size++;
            newNode->data = value;
            newNode->next = NULL;
            
            if (isEmpty()) 
                _head = newNode;
            else {
                SListNode *temp = _head;
                while (temp->next != NULL) 
                    temp = temp->next;
                temp->next = newNode;
            }
        }
    }

    void popFront()
    {
        if (!isEmpty()) {
            SListNode *temp = _head;
            _head = _head->next;
            free(temp);
            _size--;
        }
    }

    void popBack()
    {
        if (!isEmpty()) {
            SListNode *nextNode = _head->next;
            SListNode *currNode = _head;

            if (currNode->next == NULL) {
                free(currNode);
                _head = NULL;
                return;
            }

            while (nextNode->next != NULL) {
                currNode = nextNode;
                nextNode = nextNode->next;
            }
            currNode->next = NULL;
            free(nextNode);
            _size--;
        }
    }

    void insertAt(int index, int value)
    {
        if (isEmpty() || index >= _size) {
            pushBack(value);
            return;
        }
        else if (index == 0) {
            pushFront(value);
            return;
        }

        SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
        if (newNode) {
            SListNode *temp = _head;
            int _i = 0;
            
            while (temp->next != NULL && _i < index-1) {
                temp = temp->next;
                _i++;
            }
            newNode->data = value;
            newNode->next = temp->next;
            temp->next = newNode;
            _size++;
        }
    }

    void removeAt(int index)
    {
        if (!isEmpty()) {
            if (index >= _size) {
                popBack();
                return;    
            }
            else if (index == 0 || index < 0) {
                popFront();
                return;
            }

            SListNode *temp = _head;
            int _i = 0;
            while (temp->next != NULL && _i < index-1) {
                temp = temp->next;
                _i++;
            }
            SListNode *nextinto = temp->next->next;
            free(temp->next);
            temp->next = nextinto;
            _size--;
        }
    }

    void remove(int value)
    {
        if (!isEmpty()) {
            SListNode *temp, *prev;
            temp = _head;

            if (temp->data == value) {
                popFront();
                return;
            }
            while (temp != NULL && temp->data != value) {
                prev = temp;
                temp = temp->next;
            }

            if (temp == NULL) return;
            prev->next = temp->next;
            free(temp);
            _size--;
        }
    }

    int front() {
        if (!isEmpty()) return _head->data;
        else exit(-1);
    }

    int back() 
    {
        if (!isEmpty()) {
            SListNode *temp = _head;
            while (temp->next != NULL)
                temp = temp->next;
            return temp->data;
        }
        else exit(-1);
    }

    int getAt(int index) {
        if (!isEmpty()) {
            SListNode *temp = _head;
            int _i = 0;
            while (temp->next != NULL && _i < index) {
                temp = temp->next;
                _i++;
            }
            return temp->data;
        }
        else exit(-1);
    }
};

void solve(SinglyList& list1, SinglyList& list2, SinglyList& res) {
    int c = 0;
    int s = 0;

    SListNode* node1 = list1._head;
    SListNode* node2 = list2._head;

    while (node1 != NULL || node2 != NULL) {
        s = c + (node1 != NULL ? node1->data : 0) + (node2 != NULL ? node2->data : 0);
        c = s / 10;
        res.pushFront(s % 10);

        if (node1 != NULL) node1 = node1->next;
        if (node2 != NULL) node2 = node2->next;
    }

    if (c > 0) res.pushFront(c);
}

int main() {
    SinglyList num1, num2, ans;
    num1.init();
    num2.init();
    ans.init();
    int n, m, a;
    cin >> n >> m;
    
    while(n--) {
    	cin >> a;
    	num1.pushFront(a);
	}
	while(m--) {
		cin >> a;
		num2.pushFront(a);
	}
	
	solve(num1, num2, ans);

    SListNode* temp = ans._head;
    while (temp != NULL) {
        cout << temp->data;
        temp = temp->next;
    }
    cout << endl;
    
    return 0;
}