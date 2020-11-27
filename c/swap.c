#include <stdio.h>

void swap(int *a, int *b) {
        int tmp = *a;
        *a = *b;
        *b = tmp;

}


int main() {
	int a = 10;
	int b = 20;

	printf("a before swapping: %d\n", a);
	printf("b before swapping: %d\n", b);
	
	swap(&a, &b);

	printf("a after swapping: %d\n", a);
	printf("b after swapping: %d\n", b);

	return 0;
}

