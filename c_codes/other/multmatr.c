# include <stdio.h>

int main(void){

	int i, j,k,n;
	int matrix_a[5][5];
	int matrix_b[5][5];
	int matrix_c[5][5];
	int sum = 0;

	int row_1, column_1, row_2, column_2 = 0;

	printf("Enter the size of matrix 1:\n");
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


	printf("Enter the size of matrix 2:\n");
	scanf("%d%d", &row_2, &column_2);

	// enter values of matrix two
	printf("Enter values of matrix 2\n");
	for(i = 0; i < row_2; ++i){
		for (j = 0; j < column_2; ++j)
		{
			printf("[%d][%d]: ",i,j);
			scanf("%d",&n);
			matrix_b[i][j] = n;
		}
	}

	if (column_1 != row_2)
	{
		for (i = 0; i < column_1; ++i){
			for (j = 0; j < row_2; ++j){

				// loop to multiply values of two matrices and add them to one value
				for (k = 0; k < row_1; ++k){
					sum += matrix_a[i][k] * matrix_b[k][j];
				matrix_c[i][j] = sum;
				}
			}
		}
	}
	else{
		printf("Make sure the number of columns in the 1st matrix equal to the number of rows in the 2nd:\n");
	}

	printf("The product of the two matrixces is:\n");
	for(i = 0; i < row_1; ++i){
		for(j = 0; j < column_2; ++j){
			printf("%d ",matrix_c[i][j]);
		}
		printf("\n");
	}
	return 0;

}