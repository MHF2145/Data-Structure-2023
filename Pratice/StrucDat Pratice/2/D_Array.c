#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct dynamicarr_t {
    int *_arr;
    unsigned _size, _capacity;
} DynamicArray;
// inisiasi dynamic array 
void dArray_init(DynamicArray *darray)
{
    darray->_capacity = 2u;
    darray->_size = 0u;
    darray->_arr = (int*) malloc(sizeof(int) * 2);
}
// cek empty dynamic array
bool dArray_isEmpty(DynamicArray *darray) {
    return (darray->_size == 0);
}
// memasukkan data dynamic array ke belakang
void dArray_pushBack(DynamicArray *darray, int value)
{
    if (darray->_size + 1 > darray->_capacity) {
        unsigned it;
        darray->_capacity *= 2;
        int *newArr = (int*) malloc(sizeof(int) * darray->_capacity);

        for (it=0; it < darray->_size; ++it)
            newArr[it] = darray->_arr[it];
        
        int *oldArray = darray->_arr;
        darray->_arr = newArr;
        free(oldArray);
    }
    darray->_arr[darray->_size++] = value;
}
// mengeluarkan data dari blkg
void dArray_popBack(DynamicArray *darray) {
    if (!dArray_isEmpty(darray)) darray->_size--;
    else return;
}
// set dynamic array ke back of the array
int dArray_back(DynamicArray *darray) {
    if (!dArray_isEmpty(darray))
        return darray->_arr[darray->_size-1];
    else return 0;
}
// set dynamic array ke front of the array
int dArray_front(DynamicArray *darray) {
    if (!dArray_isEmpty(darray))
        return darray->_arr[0];
    else return 0;
}
// set ke d array yang di inginkan
void dArray_setAt(DynamicArray *darray, unsigned index, int value)
{
    if (!dArray_isEmpty(darray)) {
        if (index >= darray->_size)
            darray->_arr[darray->_size-1] = value;
        else
            darray->_arr[index] = value;
    }
}
// mengambil data dari array yang di inginkan
int dArray_getAt(DynamicArray *darray, unsigned index)
{
    if (!dArray_isEmpty(darray)) {
        if (index >= darray->_size)
            return darray->_arr[darray->_size-1];
        else
            return darray->_arr[index];
    }
}
//memasukkan elemen baru pada posisi yang diinginkan 
void dArray_insertAt(DynamicArray *darray, unsigned index, int value) {
	if(darray->_size + 1 > darray->_capacity) {
		darray->_capacity *= 2;
	}
	int *newArr = (int*) malloc(sizeof(int) * darray->_capacity);
		
	for(int it = 0; it < index; it++) {
		newArr[it] = darray->_arr[it];
	}
	newArr[index] = value;
	for(int it = index; it < darray->_size; it++) {
		newArr[it + 1] = darray->_arr[it];
	}
		
	int *oldArray = darray->_arr;
    darray->_arr = newArr;
    free(oldArray);
    darray->_size++;
}
//menghapus elemen pada posisi yang diinginkan
void dArray_removeAt(DynamicArray *darray, unsigned index) {
	if(darray->_size - 1 <= darray->_capacity / 2) {
		darray->_capacity /= 2;
	}
	int *newArr = (int*) malloc(sizeof(int) * darray->_capacity);
	int j = 0;
	
	for(int it = 0; it < darray->_size; it++) {
		if(it == index) continue;
		newArr[j] = darray->_arr[it];
		j++;
	}
	
	int *oldArray = darray->_arr;
    darray->_arr = newArr;
    free(oldArray);
    darray->_size--;
}

int main()
{
    DynamicArray myArray;
    dArray_init(&myArray);

    // Operasi-operasi
    // myArray => [1, 2, 3, 4]
    dArray_pushBack(&myArray, 1);
    dArray_pushBack(&myArray, 2);
    dArray_pushBack(&myArray, 3);
    dArray_pushBack(&myArray, 4);
    
	// myArray => [1, 9, 2, 3, 4, 6]
    dArray_insertAt(&myArray, 4, 6);
    dArray_insertAt(&myArray, 1, 9);
    
    // myArray => [1, 9, 4, 6]
    dArray_removeAt(&myArray, 2);
    dArray_removeAt(&myArray, 2);

    for (int i = 0; i < myArray._size; ++i) {
        printf("%d ", dArray_getAt(&myArray, i));
    }
	
    printf("\n");
    printf("%d %d", myArray._size, myArray._capacity);
    return 0;
}