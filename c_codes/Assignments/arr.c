 #include <stdio.h>

int main()
{
	int a[5] = {1, 2, 3, 4, 5};// declare and initialize array
	int *p = a;  // same as int*p = &a[0]

	printf("Address\t\tContents\n");

	size_t i; // counter

	for (i=0; i<5; i++)//loop to read content and address of the array
	{
		printf("%8u%5d \n",(p+i),*(p+i));
		
	}
	return 0;
}