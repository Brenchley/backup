# include <stdio.h>
# define MAX 1000

typedef struct {
	int row;
	int column;
	int value;
	
} term;//properties of the matrix

term sp[MAX];
term sp2[MAX];
int m1,n1, k1=0;

int main (void){

	int a[MAX][MAX];
	int i,j;


	printf("Enter the number of Rows of Martix\n");
	scanf("%d",&m1);

	printf("Enter nuber of columns of Martix\n");
	scanf("%d",&n1);

	for (i = 0; i < m1; ++i){
		for (j = 0; j < n1; ++j){

			printf("\n\t a[%d][%d]=",i,j);
			scanf("%d",&a[i][j]);
		}
	}

	printf("The matrix is:\n");

	for (i = 0; i < m1; ++i){
		for (j = 0; j < n1; ++j)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}

	printf("The sparse matrix is:\n");

	printf("\n\n\t Row  Col  Value");
	for (i = 0; i < m1; ++i){
		for (j = 0; j < n1; ++j)
		{
			if(a[i][j]){

				sp[k1].row=i;
				sp[k1].column=j;
				sp[k1].value= a[i][j];
				printf("\n\t%d\t%d\t%d", sp[k1].row, sp[k1].column, sp[k1].value);
				k1++;
			}
		}
		
	}
	printf("\n");
/*/ transposing a sparse matrix

	int sp2[10][10];

	sp[0].row = m1;
	sp[0].column = n1;

	*/
		

}
