#include<stdio.h>
#include<stdlib.h>

#define size 7

typedef struct Node{
    int data;
    Node *next;
};

Node *arr[size];

void init()
{   
    int i;
    for(i = 0; i < size; i++)
        arr[i] = NULL;
}

void insert(int value){
    int key = value % size;
    Node *baru, *bantu;
    baru = (Node*)malloc(sizeof(Node));
    baru->data = value;
    baru->next = NULL;
    if(arr[key] == NULL){   
        arr[key] = baru;
        arr[key]->next = NULL;
    }
    else{   
        bantu = arr[key];
        while(bantu->next != NULL) 
            bantu = bantu->next;
        bantu->next = baru;
    }
    printf("%d masuk pada arr[%d]\n", value,key);
}

void del(int value)
{
    int key = value % size;
    Node *hapus, *bantu, *bantuPrev;
    if(arr[key] != NULL){
        bantu = arr[key];
        bantuPrev = NULL;
        while(bantu->data != value && bantu->next != NULL){
            bantuPrev = bantu;
            bantu = bantu->next;
        }
        if(bantu->data == value){
            hapus = bantu;
            if(bantuPrev != NULL)
                bantuPrev->next = hapus->next;
            if(hapus == arr[key])
                arr[key] = hapus->next;
            hapus->next = NULL;
            free(hapus);
        }
        else
            printf("%d not present in the hash table\n",value);
    }
    else
        printf("%d not present in the hash table\n",value);
        
}

void search(int value)
{
    int key = value % size;
    Node *bantu;
    bantu = arr[key];
    while(bantu->data != value && bantu->next != NULL){
        bantu = bantu->next;
    }
    if(bantu->data == value)
        printf("Search Found\n");
    else
        printf("Search Not Found\n");
}

void print()
{
    int i;
    Node *bantu;
    for(i = 0; i < size; i++){
        bantu = arr[i];
        printf("arr[%d] = ",i);
        while(bantu != NULL){
            printf("%d->",bantu->data);
            bantu = bantu->next;
        }
        printf("NULL\n");
    }
        
}

int main()
{
    init();
    insert(10); //key = 10 % 7 ==> 3
    insert(4);  //key = 4 % 7  ==> 4
    insert(2);  //key = 2 % 7  ==> 2
    insert(3);  //key = 3 % 7  ==> 3 (collision)

    printf("Hash table\n");
    print();
    printf("\n");

    printf("Deleting value 10..\n");
    del(10);
    printf("After the deletion hash table\n");
    print();
    printf("\n");

    printf("Deleting value 5..\n");
    del(5);
    printf("After the deletion hash table\n");
    print();
    printf("\n");

    printf("Searching value 4..\n");
    search(4);
    printf("Searching value 10..\n");
    search(10);

    return 0;
}