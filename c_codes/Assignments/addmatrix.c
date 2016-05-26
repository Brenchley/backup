# include <stdio.h>

void printMatrix(int a[][5], int b[][5], size_t row, size_t column);//prototypes
void addMatrix(int a[][5], int b[][5], size_t row, size_t column);
int main(void){

	int i, j,n;
	int matrix_a[5][5];
	int matrix_b[5][5];

	int row_1, column_1 = 0;

	printf("Enter the size of both matrix 1 & matrix 2:\n");
	scanf("%d%d", &row_1, &column_1);

	// enter values of matrix one
	printf("Enter values of matrix 1:\n");
	for(i = 0; i < row_1; ++i){
		for (j = 0; j < column_1; ++j)
		{
			printf("[%d][%d]: ",i,j);
			scanf("%d",&n);
			matrix_a[i][j] = n;
		}
	}



	// enter values of matrix two
	printf("Enter values of matrix 2\n");
	for(i = 0; i < row_1; ++i){
		for (j = 0; j < column_1; ++j)
		{
			printf("[%d][%d]: ",i,j);
			scanf("%d",&n);
			matrix_b[i][j] = n;
		}
	}
	printMatrix(matrix_a, matrix_b, row_1, column_1);
	addMatrix(matrix_a, matrix_b, row_1, column_1);
}
void printMatrix(int a[][5],int b[][5], size_t row, size_t column){
	size_t i, j;
	printf("Matrix 1 is:\n");
	for (i = 0; i < row; ++i){
		for (j = 0; j < column; ++j)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	printf("Matrix 2 is:\n");
	for (i = 0; i < row; ++i){
		for (j = 0; j < column; ++j)
		{
			printf("%d ",b[i][j]);
		}
		printf("\n");
	}
}
void addMatrix(int a[][5],int b[][5], size_t row, size_t column){
	size_t i;//row counter
	size_t j;//column counter

	int matrix_c[5][5];

	for (i = 0; i < row; ++i){
		for ( j = 0; j < column; ++j)
		{
			matrix_c[i][j] = a[i][j] + b[i][j];
		}
	}

	printf("The sum of the two matrices is:\n");
	for(i = 0; i < row; ++i){
		for(j = 0; j < column; ++j){
			printf("%d ",matrix_c[i][j]);
		}
		printf("\n");
	}


}
	


