#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char **_arr;
    unsigned _size, _capacity;
} DynamicArray;

bool dArray_isEmpty(DynamicArray *darray)
{
    return (darray->_size == 0);
}

void dArray_pushback(DynamicArray *darray, char value[])
{
    if (darray->_size + 1 > darray->_capacity) // cek penuh
    {
        unsigned it;
        darray->_capacity *= 2;
        char **newArr = (char **)malloc(sizeof(char *) * darray->_capacity);
        for (it = 0; it < darray->_size; ++it)
        {
            newArr[it] = darray->_arr[it]; // copy value array lama ke array baru
        }

        char **oldArray = darray->_arr;
        darray->_arr = newArr;
        free(oldArray); // hapus array lama
    }
    darray->_arr[darray->_size++] = value; // value baru ke index setelah terakhir
}

void dArray_popback(DynamicArray *darray)
{
    if (!dArray_isEmpty(darray))
    {
        darray->_size--;
    }
    else
        return;
}

char *dArray_back(DynamicArray *darray)
{
    if (!dArray_isEmpty(darray))
    {
        return darray->_arr[darray->_size - 1];
    }
    else
        return 0;
}

char *dArray_front(DynamicArray *darray)
{
    if (!dArray_isEmpty(darray))
    {
        return darray->_arr[0];
    }
    else
        return 0;
}

void dArray_setAt(DynamicArray *darray, unsigned index, char value[])
{
    if (!dArray_isEmpty(darray))
    {
        if (index >= darray->_size)
        {
            darray->_arr[darray->_size - 1] = value;
        }

        else
            darray->_arr[index] = value;
    }
}

char *dArray_getAt(DynamicArray *darray, unsigned index)
{
    if (!dArray_isEmpty(darray))
    {
        if (index >= darray->_size)
        {
            return darray->_arr[darray->_size - 1];
        }

        else
            return darray->_arr[index];
    }
}

void dArray_insert(DynamicArray *darray, unsigned index, char value[])
{
    unsigned it;
    char **oldArray = darray->_arr;
    if (darray->_size + 1 > darray->_capacity)
    {
        darray->_capacity *= 2;
        char **newArr = (char **)malloc(sizeof(char *) * darray->_capacity);
        for (it = 0; it < darray->_size + 1; it++)
        {
            if (it > index)
            {
                newArr[it] = darray->_arr[it - 1];
            }

            else
            {
                newArr[it] = darray->_arr[it];
            }
        }
        darray->_arr = newArr;
        free(oldArray);
    }

    else
    {
        for (it = darray->_size; it > index; it--)
        {
            darray->_arr[it] = darray->_arr[it - 1];
        }
    }
    darray->_arr[index] = value;
    darray->_size++;
}

void dArray_remove(DynamicArray *darray, unsigned index)
{
    unsigned it;
    for (it = index; it < darray->_size; it++)
    {
        darray->_arr[it] = darray->_arr[it + 1];
    }
    darray->_size--;
}

int main()
{
    DynamicArray arr;
    arr._arr = (char **)malloc(sizeof(char *) * 100);
    arr._capacity = 3;
    arr._size = 0;
    dArray_pushback(&arr, "ar");
    dArray_pushback(&arr, "bc");
    dArray_pushback(&arr, "de");
    printf("%s %s %s\n", *(arr._arr), *(arr._arr + 1), *(arr._arr + 2));
}
