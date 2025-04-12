#include <ezheap.h>
#include <stdio.h>

int main() {
	ezheap_init();

	int* x = new (int);
	*x = 123;
	printf("%d\n", *x);

	int* y = new (int);
	*y = 69;
	printf("%d\n", *y);

	ezheap_destruct();
}
