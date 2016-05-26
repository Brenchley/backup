#include <stdio.h>
#define MAXSIZE 5

typedef struct stack{

	int stk[MAXSIZE]; //declare size of stack to MAXSIZE
	int top; // index of elements
	
}STACK ;

STACK s;

// prototypes

int push(); //function to add to the stack
int pop(); //function to remove from stack
int display(); //function to display the stack


int main(){
	int choice;
	int option = 1;
	s.top = - 1; //index of element when the stack is empty

	printf("STACK OPERATION \n");
	while (option)
	{
		printf("1 to push\n");
		printf("2 to pop\n");
		printf("3 to display\n");
		printf("4 to exit\n");

		printf("Please enter your choice\n");
		scanf ("%d", &choice);

		switch(choice)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:	
				break;
				
		}
		printf("Do you want to continue(Type 0 or 1)?\n");
		scanf ("%d", &option);
	}
	
}

// adding element to the stack
int push(){
	int num;

	if (s.top == (MAXSIZE -1 ))//check if stack is full
	{

		printf("Stack is full!!\n");
		return;
	}
	else
	{
		printf("Enter the element to be pushed \n");
		scanf("%d", &num);
		s.top = s.top + 1; // increase index of stack by 1
		s.stk[s.top] = num;// make value of index s.top to be num
	}
	return;
}

//poping an element from stack

int pop(){
	int num;

	if ( s.top == -1)// check is stack is empty
	{
		printf("Stack is empty, can't remove any element\n");

		return(s.top);
	}
	else
	{
		num = s.stk[s.top]; //initilize variable num to the element present in the top index

		printf("poped element is %d\n", num );
		s.top = s.top - 1; //decreament index of stack by 1 
	}
	return num;
}

int display(){

	int i;

	if(s.top == -1){
		printf("Stack is empty\n");
	}
	else{
		printf("The stack has  ....\n");
		for (i = s.top; i >= 0; i--)// loop through the entire stack
		{
			printf("%d\n", s.stk[i]);
		}
	}
	printf("\n");
}