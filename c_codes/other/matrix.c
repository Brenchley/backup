# include <stdio.h>

int main(void){
	
	int matrix_a[5][5];
	int i,j,n;
	int matrix_b[5][5];
	int row,column = 0;

//ask the user to enter size of array
	printf("Enter the size of the array:\n");
	scanf("%d%d",&row,&column);
	//printf("row->%d column->%d\n",row,column );

//ask user to enter terms of the matrix
	printf("Enter values of the matrix\n");
	for(i = 0; i < row; i++){
		for ( j = 0; j < column; j++)
		{	
			printf("[%d] [%d]: ",i,j );
			scanf("%d",&n);
			matrix_a[i][j]=n;
			//printf("Saved -> %d\n",matrix_a[i][j]);
		}

	}
// print out the matrix
	printf("Your matrix is:\n");
	for (i = 0; i < row; i++){
		for (j = 0; j < column; j++){
			printf("%d ",matrix_a[i][j]);

		}
		printf("\n");
	}
	// transposing the matrix

	for(i = 0; i < row; ++i){
		for(j = 0; j < column; ++j){
			matrix_b[j][i]=matrix_a[i][j];
		}
	}
//print out the transposed matrix
	printf("The new transposed matrix is:\n");
	for(i = 0; i < row; ++i){
		for(j = 0; j < column; ++j){
			printf("%d ",matrix_b[i][j]);
		}
		printf("\n");
	}

	
	return 0;
}

