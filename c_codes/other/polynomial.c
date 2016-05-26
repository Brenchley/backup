#include <stdio.h>
#include <stdlib.h>

#define MAXDEGREE 101

typedef struct{
	int degree;
	int coef[MAXDEGREE];
	struct link * next;
} polynomial;

void addp(polynomial** polynomial_a, polynomial_b);//prototype
void createp(polynomial **);
void showp(polynomial *);

int main(void){
	int ch;
	do{
		polynomial *polynomial_a, * polynomial_b *polynomial_c;

		printf("\nCreate 1st expression\n");
		createp(&polynomial_a);
		printf("\nStored the 1st expression");
		showp(polynomial_a);

		printf("\nCreate 2nd expression\n");
		createp(&polynomial_b);
		printf("\nStored the 2nd expression\n");
		showp(polynomial_b);

		addp(&polynomial_c, polynomial_b, polynomial_a);
		showp(polynomial_c);

		printf("\nAdd two expressions? Y=1 or N =0: ");
		scanf("%d",&ch);
	}while(ch);
	return 0;
}

void createp(polynomial ** node){
	int flag;
	int coef, degree;
	polynomial * tmp_node;// to hold the temporary last address
	tmp_node =(polynomial*) malloc(sizeof(polynomial)); //creat the first nod
	*node = tmp_node;// store the head address to the refrence variable

	do{
		printf("\nEnter coef: ");
		scanf("%d", &coef);
		temp_node->coef = coef
		printf("\nEnter degree: ");
		scanf("%d", &degree);
		tmp_node->degree= degree;
		//finished storing data

		//incresing the linked on user condition
		tmp_node->next = NULL;

		//ask user to continue
		printf("\nContinue adding terms (Y=1 0r N=0)?: ");
		scanf("%d"&flag);

		//Grow the linked list on condition
        if(flag) {
            tmp_node->next = (polynomial *) malloc(sizeof(polynomial)); //Grow the list
            tmp_node = tmp_node->next;
            tmp_node->next = NULL;
        }
    } while (flag);
}
	
//show polynomial
void showp(polynomial * node){
	printf("\nThe polynomial expression is:\n");
    while(node != NULL) {
        printf("%dx^%d", node->coef, node->degree);
        node = node->next;
        if(node != NULL)
            printf(" + ");
    }
}

//add polynomial
void addp(polynomial ** result, polynomial * polynomial_a, polynomial* polynomial_b){
	polynomial * tmp_node;
	tmp_node = (polynomial *) malloc(sizeof(polynomial));
	tmp_node->next = NULL;
	*result = tmp_node;// copy the head 
}
