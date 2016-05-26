/*
*Representing polynomials in an array
*/
#include <stdio.h>

typedef struct{
	int degree;
	int coef[15];	
} polynomial;

polynomial addp(polynomial a, polynomial b);
void printpoly(polynomial p);

int main(void){
	polynomial a;// create polinomial
	printf("Polynomial a :\n");
	printf("\t Enter the degree for a: ");
	scanf("%d", &a.degree);
	int powr = a.degree;
	while(powr >= 0){
		printf("\t Enter coefficient for x^%d :-",powr);
		scanf("%d",&a.coef[powr]);
		powr--;
	}
	printpoly(a);

	
	polynomial b;// create polinomial b
	printf("\n\nPolynomial b :\n");
	printf("\t Enter the degree for b: ");
	scanf("%d", &b.degree);
	int powrb = b.degree;
	while(powrb >= 0){
		printf("\t Enter coefficient for x^%d :-",powrb);
		scanf("%d",&b.coef[powrb]);
		powrb--;
	}
	printpoly(b);

	//Add the polynomials
	polynomial ans = addp(a,b);
	printf("\nSUM -> ");
	printpoly(ans);
}

polynomial addp(polynomial a, polynomial b){
	polynomial c;
	if(a.degree > b.degree){
		c.degree = a.degree;
	}else if(b.degree == a.degree){
		c.degree = a.degree;
	}else{
		c.degree = b.degree;
	}

	int i;
	for (i = 0; i < 15; i++){
		c.coef[i] = a.coef[i] + b.coef[i];
	}
	return c;
}
void printpoly(polynomial p){
	int pow = p.degree;
	while(pow > 0 ){
		printf("%dx^%d + ",p.coef[pow],pow);
		pow--;
	}
	printf("%dx^%d\n",p.coef[0],0);	
}
