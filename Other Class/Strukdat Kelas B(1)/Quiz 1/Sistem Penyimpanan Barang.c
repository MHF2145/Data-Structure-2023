#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

typedef struct stackNode_t {
    int no;
    char name[1001];
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

void stack_push(Stack *stack, int value, char str[]) 
{
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
        stack->_size++;
        newNode->no = value;
        strcpy(newNode->name, str);
        
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

void stack_top(Stack *stack) 
{
    if (!stack_isEmpty(stack))
	{
		printf("Barang nomor %d : %s\n", stack->_top->no, stack->_top->name);
		return;
	}
    return;
}

unsigned stack_size(Stack *stack) {
    return stack->_size;
}

int main() 
{
	Stack main, temp;
	stack_init(&main);
	stack_init(&temp);
	int n, a, ada[100001];
	char b[1001];
	
	printf("Pilih aktivitas:\n1. Titip barang (nomor barang, nama barang)\n2. Ambil barang (nomor barang)\n3. Lihat tumpukan\n9. Hapus stack dan keluar\n");
	while(scanf("%d", &n))
	{
		if(n == 1)
		{
			printf("Masukan nomor dan nama barang yang ingin dititipkan:\n");
			scanf("%d %s", &a, b);
			
			if(ada[a] == 1) printf("Nomor sudah ada\n");
			else 
			{
				stack_push(&main, a, b);
				ada[a] = 1;
			}
		}
		else if(n == 2)
		{
			printf("Masukan nomor barang yang ingin diambil:\n");
			scanf("%d", &a);
			
			if(ada[a] == 0) printf("Nomor barang tidak terdaftar\n");
			else
			{
				ada[a] = 0;
				while(!stack_isEmpty(&main))
				{
					if(main._top->no == a)
					{
						stack_pop(&main);
						break;
					}
					stack_push(&temp, main._top->no, main._top->name);
					stack_pop(&main);
				}
				
				while(!stack_isEmpty(&temp))
				{
					stack_push(&main, temp._top->no, temp._top->name);
					stack_pop(&temp);
				}
			}
			
		}
		else if(n == 3)
		{
			if(stack_isEmpty(&main)) printf("Tumpukan kosong\n");
			else
			{
				while(!stack_isEmpty(&main))
				{
					stack_push(&temp, main._top->no, main._top->name);
					stack_top(&main);
					stack_pop(&main);
				}
				
				while(!stack_isEmpty(&temp))
				{
					stack_push(&main, temp._top->no, temp._top->name);
					stack_pop(&temp);
				}
			}
		}
		else
		{
			while(!stack_isEmpty(&main)) stack_pop(&main);
			return 0;
		}
	}
}