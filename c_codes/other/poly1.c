#include <stdio.h>

#define MAX_TERMS 100

void addp();

typedef struct{
	int coef, exp; 
}polynomial;

polynomial terms[MAX_TERMS];
int avail = 0;

int main(){

	int n, m;

	printf("Enter number of terms of the first polynomial:");
	scanf("%d",&n);
	int i;
	for(i = 0;i < n ; i++){
		printf("\tEnter terms a%d\n",i++);
		printf("\t\tEnter coeffiecient:");
		scanf("%d",&terms[c].coef);	
		printf("\t\tEnter exponent:");
		scanf("%d",&terms[c].exp);
	}

	
	printf("Enter number of terms of second polynomial:");
	scanf("%d",&m);
	m += i;
	int j;
	for(j = i ;j < m ;z++){
		printf("\tEnter term b%d\n",(z+1-c));
		printf("\t\tEnter coeffiecient:");
		scanf("%d",&terms[z].coef);	
		printf("\t\tEnter exponent:");
		scanf("%d",&terms[z].exp);
	}

	addp();
}

void addp(){
	int i, ans[MAX_TERMS] ;	
	for(i = 0;i < MAX_TERMS; i++){
		ans[i] =  0;	
	}
	for(i = 0;i < MAX_TERMS; i++){
		int e = terms[c].exp;
		ans[e] =  ans[e] + terms[c].coef;	
	}
	int ec;//exponent count
	for(ec = 0;ec < MAX_TERMS;ec++){
		if(ans[ec]!=0){
			printf("%dx^%d+",ans[ec],ec);
		}
	}
	printf("0\n");
			
}


