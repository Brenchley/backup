#include <stdio.h>
#include <stdlib.h>


typedef struct Queue{
	int capacity;// maximum elements that can be held by the queue
	int size;// The current size of the queue
	int front;//index of the first elements(where we remove the elements)
	int rear;//index of the last elements (where we add the elements)
	int *elements;// pointer to the array of elements
}Queue;

//function to take argument the max number of elements
Queue * createQueue (int maxElements)
{
	// create a queue

	Queue *Q;

	Q = (Queue *)malloc(sizeof(Queue));//memory allocation of  the queue Q

	//initialize its properties

	Q-> elements = (int *)malloc (sizeof(int)*maxElements);
	Q -> size = 0;
	Q -> capacity = maxElements;
	Q -> front = 0;
	Q -> rear = -1;

	//return pointer
	return Q;
}
//removing rlements from queue
void dequeue(Queue *Q){
	// If Queue size is zero then it is empty
	if(Q->size == 0){

		printf("Queue is empty\n");
	}
	else
	{
		Q -> size--;// the size of queue reduces by one
		Q -> front++; //removing an elements is equivalent to increamenting

		if( Q -> front == Q ->capacity){
			Q -> front =0;
		}
	}
}

int front(Queue *Q){
	if(Q->size == 0){
		printf("Queue is empty\n");
		exit(0);
	}
	return Q->elements [Q->front];// return elements which is at the front
}
void enqueue(Queue *Q, int element){

	//if queue is full
	if(Q->size == Q->capacity)
	{
		printf("Queue is full\n");
	}
	else
	{
		Q->size++;
		Q->rear = Q->rear + 1;
		if(Q-> rear == Q -> capacity){
			Q->rear =0;
		}
		// insert elements at the back
		Q -> elements [Q->rear] = element;
	}
}
int main(){

	Queue *Q = createQueue(7);
	enqueue (Q,5);
	enqueue (Q,1);
	enqueue (Q,3);
	enqueue (Q,4);
	printf ("front elements is %d\n", front(Q));
	enqueue (Q,5);
	dequeue(Q);
	dequeue(Q);
	dequeue(Q);
	printf ("front elements is %d\n", front(Q));

}