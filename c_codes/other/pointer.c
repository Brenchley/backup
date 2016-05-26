#include <stdio.h>

int main(){

	int x = 4;
	printf("x lives at %p\n", &x);

	int *address_of_x = &x;

	int value_stored = *(address_of_x);

	printf("Content of the address %p is %d \n", &x, value_stored);
	//change content of memory location
	*address_of_x = 99;
	printf("new value in the memory loaction: %d\n", *address_of_x );
}