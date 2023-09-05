#include <iostream>

using namespace std;

struct LinkedList
{
    int data;
    LinkedList* next;
};

int length(LinkedList* atas)
{   
    if (atas == NULL) {
        return 0;
    }
    return 1 + length(atas->next);
}