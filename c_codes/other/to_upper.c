#include <stdio.h>
#include <ctype.h>

void convertToUpperCase(char *sPtr);//function prototype
void printCharaters(char *sPtr);
int main(void){
	char string[] = "cHaRaCters and $32.98";// initializing char array

	printf("The string before conversion is: %s\n", string);

	convertToUpperCase(string);

	printf("The string after conversion is: %s\n", string );

	printCharaters(string);
}

void convertToUpperCase(char *sPtr)
{
	while (*sPtr != '\0'){ // current character is not '\O'
		*sPtr = toupper(*sPtr);
		++sPtr;
	}// end while
}// end function 

void printCharaters(char *sPtr){
	for( ; *sPtr != '\0'; ++sPtr){
		sPtr = tolower(*sPtr);
	}
	printf("%s\n",*sPtr );

}