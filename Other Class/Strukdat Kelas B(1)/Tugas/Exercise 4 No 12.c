#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int num;
	struct node *next;
} Node, *NodePtr;

NodePtr makeNode(int n) {
	NodePtr np = (NodePtr) malloc(sizeof (Node));
	np->num = n;
	np->next = NULL;
	return np;
}
 
NodePtr linkCircular(int n) {

	NodePtr first, np, makeNode(int);
	first = np = makeNode(1); 
	
	for (int h = 2; h <= n; h++) { 
		np->next = makeNode(h);
		np = np->next;
	}

	np->next = first;
	return first;
}

NodePtr playGame(NodePtr first, int x, int m) {
	NodePtr prev, curr = first;

	for (int h = 1; h <= x; h++) {
		for (int c = 1; c < m; c++) {
			prev = curr;
			curr = curr->next;
		}
		
		prev->next = curr->next;
		free(curr);
		curr = prev->next;
	}
	return curr;
}

int main() {
	NodePtr curr;
	int n, m;
	scanf("%d %d", &n, &m);

	curr = linkCircular(n);
	curr = playGame(curr, n-1, m);
	printf("%d\n", curr->num);
}