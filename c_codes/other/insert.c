#include <stdio.h>
#include <stdlib.h>


struct listNode{
	char data; //each listnode contains a character
	struct listNode *nextPtr;// pointer to next node
	
};// end structure listNode


typedef struct listNode ListNode; // synonym for struct listNode
typedef ListNode *ListNodePtr; // synonym for ListNode*

//prototype
void insert( ListNodePtr *sPtr, char value );
void printList( ListNodePtr currentPtr);
int isEmpty(ListNodePtr sPtr);

int main(){
	int end = 0;
	while( end != 1) {

	ListNodePtr startPtr = NULL; // initiallt there are no nodes

	char item;


	printf("Enter a character: \n");
	scanf( "%c", &item);
	insert(&startPtr, item);
	printList(startPtr);
}

}

void insert( ListNodePtr *sPtr, char value ){
	ListNodePtr newPtr; //pointer to new node
	ListNodePtr previousPtr; // pointer to previous node in list
	ListNodePtr currentPtr; //pointer to current node in list

	newPtr = malloc( sizeof( ListNode) ); // create node

	if (newPtr != NULL){
		newPtr->data = value; // place value in node
		newPtr ->nextPtr = NULL; // node does not link to another node
		previousPtr = NULL;
		currentPtr = *sPtr;

		// loop to find correct location in list
		while ( currentPtr != NULL && value > currentPtr->data ) {
			previousPtr = currentPtr; // walk to ...
			currentPtr = currentPtr->nextPtr;//... next node
		}//end while

		//insert new node at beginning of list
		if (previousPtr == NULL){
			newPtr->nextPtr = *sPtr;
			*sPtr = newPtr;
		}// end if
		else{
			previousPtr->nextPtr =newPtr;
			newPtr->nextPtr = currentPtr;
		}//end else
	}//end if
	else{
		printf("%c not inserted. No memory available.\n", value);
	}
}
int isEmpty(ListNodePtr sPtr){
	return sPtr == NULL;
}//end function isEmpty

//printList
void printList( ListNodePtr currentPtr){
	//if list is empty
	if ( isEmpty( currentPtr )){
		printf("List is empty.\n");
	}//end if 
	else{
		printf("The list is:\n");
		//while not the end of the list
		while( currentPtr != NULL){
			printf("%c --> ",currentPtr->data);
			currentPtr = currentPtr->nextPtr;
		}// end while
		printf("NULL\n");
	}
}
