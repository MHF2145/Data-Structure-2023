#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

typedef struct stackNode_t {
    char nrp[101], nama[101], judul[101];
	int d, m, y;
    struct stackNode_t *next;
} StackNode;

typedef struct stack_t {
    StackNode *_top;
    unsigned _size;
} Stack;

void stack_init(Stack *stack) 
{
    stack->_size = 0;
    stack->_top = NULL;
}

bool stack_isEmpty(Stack *stack) {
    return (stack->_top == NULL);
}

void stack_push(Stack *stack, char _nrp[], char _nama[], char _judul[], int _d, int _m, int _y) 
{
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
        stack->_size++;
        strcpy(newNode->nrp, _nrp);
        strcpy(newNode->nama, _nama);
        strcpy(newNode->judul, _judul);
        newNode->d = _d;
        newNode->m = _m;
        newNode->y = _y;
        
        if (stack_isEmpty(stack)) newNode->next = NULL;
        else newNode->next = stack->_top;

        stack->_top = newNode;
    }
}

void stack_pop(Stack *stack) 
{
    if (!stack_isEmpty(stack)) {
        StackNode *temp = stack->_top;
        stack->_top = stack->_top->next;
        free(temp);
        stack->_size--;
    }
}

unsigned stack_size(Stack *stack) {
    return stack->_size;
}

typedef struct queueNode_t {
    char nrp[101], nama[101];
    struct queueNode_t *next;
} QueueNode;

typedef struct queue_t {
    QueueNode   *_front, 
                *_rear;
    unsigned _size;
} Queue;

void queue_init(Queue *queue)
{
    queue->_size = 0;
    queue->_front = NULL;
    queue->_rear = NULL;
}

bool queue_isEmpty(Queue *queue) {
    return (queue->_front == NULL && queue->_rear == NULL);
}

void queue_push(Queue *queue, char _nrp[], char _nama[])
{
    QueueNode *newNode = (QueueNode*) malloc(sizeof(QueueNode));
    if (newNode) {
        queue->_size++;
        strcpy(newNode->nrp, _nrp);
        strcpy(newNode->nama, _nama);
        
        if (queue_isEmpty(queue))                 
            queue->_front = queue->_rear = newNode;
        else {
            queue->_rear->next = newNode;
            queue->_rear = newNode;
        }
    }
}

void queue_pop(Queue *queue)
{
    if (!queue_isEmpty(queue)) {
        QueueNode *temp = queue->_front;
        queue->_front = queue->_front->next;
        free(temp);
        
        if (queue->_front == NULL)
            queue->_rear = NULL;
        queue->_size--;
    }
}

int queue_size(Queue *queue) {
    return queue->_size;
}

int main()
{
	Stack pinjam, temp;
	Queue antri;
	stack_init(&pinjam);
	stack_init(&temp);
	queue_init(&antri);
	int n, x, y, z;
	char a[101], b[101], c[101];
	bool ada;
	
	printf("Menu\n1. Pinjam buku\n2. Antri pengembalian buku\n3. Layani pengembalian buku\n4. Daftar buku yang belum kembali\n9. Keluar\n");
	while(scanf("%d", &n))
	{
		if(n == 1)
		{
			printf("Masukkan data dengan format NRP Nama JudulBuku Tanggal(int) Bulan(int) Tahun(int)\n");
			scanf("%s %s %s %d %d %d", a, b, c, &x, &y, &z);
			stack_push(&pinjam, a, b, c, x, y, z);
		}
		else if(n == 2)
		{
			printf("Masukkan data dengan format NRP Nama\n");
			scanf("%s %s", a, b);
			queue_push(&antri, a, b);
		}
		else if(n == 3)
		{
			ada = false;
			if(queue_isEmpty(&antri)) {
				printf("Antrian kosong.\n");
				continue;
			}
			
			while(!stack_isEmpty(&pinjam))
			{
				if(strcmp(antri._front->nrp, pinjam._top->nrp) == 0 &&
				   strcmp(antri._front->nama, pinjam._top->nama) == 0)
				{
					printf("%s %s %s %d-%d-%d dilayani.\n", pinjam._top->nrp, pinjam._top->nama, pinjam._top->judul, pinjam._top->d, pinjam._top->m, pinjam._top->y);
					stack_pop(&pinjam);
					queue_pop(&antri);
					ada = true;
					break;
				}
				else
				{
					stack_push(&temp, pinjam._top->nrp, pinjam._top->nama, pinjam._top->judul, pinjam._top->d, pinjam._top->m, pinjam._top->y);
					stack_pop(&pinjam);
				}
			}
			
			if(!ada) {
				printf("NRP tidak terdaftar.\n");
				queue_pop(&antri);
			}
			
			while(!stack_isEmpty(&temp))
			{
				stack_push(&pinjam, temp._top->nrp, temp._top->nama, temp._top->judul, temp._top->d, temp._top->m, temp._top->y);
				stack_pop(&temp);
			}
		}
		else if(n == 4)
		{
			if(stack_isEmpty(&pinjam)) {
				printf("Tidak ada yang meminjam.\n");
				continue;
			}
			
			while(!stack_isEmpty(&pinjam))
			{
				stack_push(&temp, pinjam._top->nrp, pinjam._top->nama, pinjam._top->judul, pinjam._top->d, pinjam._top->m, pinjam._top->y);
				printf("%s %s %s %d-%d-%d\n", pinjam._top->nrp, pinjam._top->nama, pinjam._top->judul, pinjam._top->d, pinjam._top->m, pinjam._top->y);
				stack_pop(&pinjam);
			}
			
			while(!stack_isEmpty(&temp))
			{
				stack_push(&pinjam, temp._top->nrp, temp._top->nama, temp._top->judul, temp._top->d, temp._top->m, temp._top->y);
				stack_pop(&temp);
			}
		}
		else
		{
			while(!stack_isEmpty(&pinjam)) stack_pop(&pinjam);
			while(!queue_isEmpty(&antri)) queue_pop(&antri);
			return 0;
		}
	}
}

//	perpustakaan
//	bagian pengembalian buku
//	ada antrian mahasiswa yang akan mengembalikan buku
//	data peminjaman tersimpan dalam bentuk stack dan tersedia temporary stack
//	
//	menu
//	1. mahasiwa pinjam buku
//	2. mahasiswa datang utk pengembalian buku
//	3. layani pengembalian buku
//	4. tampilkan daftar buku yg belum kembali
//	9. keluar
//	
//	Action
//	1. disimpan data NRP, Nama, Judul buku, dan tgl pinjam ke dalam stack
//	2. dimasukkan data NRP dan Nama ke dalam queue
//	3. data paling depan dari queue diambil, cari NRP dari stack dengan bantuan temporary stack, kembalikan data dari temporary stack jika data sudah ditemukan, tampilkan data yg ditemukan dari stack
//	4. tampilkan semua data yg ada di stack, bisa menggunakan temporary stack
//	9. hapus semua data, keluar