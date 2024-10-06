#include <stdio.h>

struct node {
	int value;
	struct node* ptr;
};
typedef struct node Node;

int main() {
	Node a;
	Node b;
	a.value = 100;
	b.value = 200;
	a.ptr = &b;
	b.ptr = &a;
}