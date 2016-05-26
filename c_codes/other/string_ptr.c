#include <stdio.h>

int maximum( int x, int y, int z); //function protype

int main(void)
{
	int number1, number2, number3; //declare the three integers to be compared

	printf("Enter three integers:\n");
	scanf("%d%d%d", &number1, &number2, &number3);

	printf("maximum is:%d\n",maximum(number1, number2, number3) );// function call

}// end main


int maximum(int x, int y, int z)
{
	int max = x;
	if (y> x){

		max = y;
	}
	if (z > max){
		max = z;
	}
	return max;
}
