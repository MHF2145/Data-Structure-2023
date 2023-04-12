#include <stdlib.h>
#include <stdio.h>
#include <iostream>

// Node structure
struct StackNode
{
    int data;
    StackNode *next;
};

/* Structure of Stack using List */
struct Stack
{
    StackNode *_top;
    unsigned _size;

    void init()
    {
        _size = 0;
        _top = nullptr;
    }

    bool isEmpty() {
        return (_top == nullptr);
    }

    void push(int value)
    {
        StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
        if (newNode) {
            _size++;
            newNode->data = value;

            if (isEmpty()) newNode->next = NULL;
            else newNode->next = _top;
            _top = newNode;
        }
    }

    void pop()
    {
        if (!isEmpty()) {
            StackNode *temp = _top;
            _top = _top->next;
            free(temp);
            _size--;
        }
    }

    int top()
    {
        if (!isEmpty())
            return _top->data;
        exit(-1);
    }
};


int main() {
	int angka, a, discarded[100], b = 0;

	do {
		scanf("%d", &angka);
		Stack st;
		for(a = angka; a > 0; a--) {
			st.push(a);
		}
		while(!st.isEmpty()){
			discarded[b] = st.top();
			b++;
            std::cout << st.top() << std::endl;
	        st.pop();
    	}
    	for(a = 0; a < angka; a++) {
    		printf("%d", discarded[a]);
		}
	} while (angka > 0);
	return 0;
}
