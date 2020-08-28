#include <stdio.h>
#include <stdlib.h>

//CS211 Computer Architecture - Spring 2020
//Abhay Saxena

void exponential (int n, int **matrix, int row){
								//Case 1 : 'n' = 0.
	if (n == 0){						//If exponential factor is 0,print the identity matrix.
		for (int i = 0; i < row; i++){
		matrix[i] = (int *) calloc(row, row * sizeof(int));   //Use calloc to initialize all values of matrix to 0.
			for (int j = 0; j < row; j++){
				if (i == j){			    //On the diagonal of the matrix: i == j
					matrix[i][j] = 1;	    //we set the value of matrix[i][j] to 1.
				}
			}
		}
		
		for (int i = 0; i < row; i++){				//Printing Identity Matrix.
			for (int j = 0; j < row; j++){
				if (j+1 == row){			 //Additional 'if' condition ensures a properly
					printf("%d", matrix[i][j]);	 //printed matrix.
				}
				else{
					printf("%d ", matrix[i][j]);
				}
			}
			printf("\n");
		}
		return;						    //Return after printing identity matrix.
	}
	
	if (n == 1){						//Case 2 : 'n' = 1.
		for (int i = 0; i < row; i++){			//If exponentiation factor is 1, we print back the matrix.
			for (int j = 0; j < row; j++){
				if (j+1 == row){
					printf("%d", matrix[i][j]);		//Printing Original Matrix.
				} else {
					printf("%d ", matrix[i][j]);
				}
			}
			printf("\n");
		}
		return;						//Return after printing original matrix.
	}
	
	int **result = (int **) calloc(row, row *sizeof(int*));		//Creating a result matrix.
	int **temp1 = (int **) calloc(row, row *sizeof(int*));		//Creating a temporary matrix.
	
	if (n > 1){							//Case 3 : 'n' > 1.
	
		for (int i = 0; i < row; i++){				//Stores content of matrix*matrix in 'temp'.
		temp1[i] = (int *) calloc(row, row * sizeof(int));
			for (int j = 0; j < row; j++){
				for (int k = 0; k < row; k++){
					temp1[i][j] += matrix[i][k]*matrix[k][j];
				}
			}
		}
		
		for (int i = 0; i < row; i++){				//Copies the content of temp into 'result' matrix.
		result[i] = (int *) calloc(row, row * sizeof(int));
			for (int j = 0; j < row; j++){
				result[i][j] += temp1[i][j];
			}
		}

		n--;			       //Decrements the exponentiation factor by one due to one complete operation.
		
		while (n > 1){				//The while loop repeats multiplying and overwritting matrices.
		
			for (int i = 0; i < row; i++){			//Resets all content of result to 0.
				for (int j = 0; j < row; j++){
					result[i][j] = 0;
				}
			}
			
			for (int i = 0; i < row; i++){				//Stores content of temp*matrix in result.
			result[i] = (int *) calloc(row, row * sizeof(int));
				for (int j = 0; j < row; j++){
					for (int k = 0; k < row; k++){
						result[i][j] += temp1[i][k]*matrix[k][j];
					}
				}
			}
			
			for (int i = 0; i < row; i++){			//Sets temp to 0, to be REUSED in case of n > 1.
				for (int j = 0; j < row; j++){
					temp1[i][j] = 0;
				}
			}
			
			for (int i = 0; i < row; i++){			//Copies content of result into temp, to be REUSED.
				for (int j = 0; j < row; j++){
					temp1[i][j] += result[i][j];
				}
			}
			n--;				//Decrementing exponentiaion factor after one successful operation.
		}
	}
	
	for (int i = 0; i < row; i++){					//prints out result matrix which is the final
			for (int j = 0; j < row; j++){			//after exponentiation.
				if (j+1 == row){
					printf("%d", result[i][j]);
				}
				else{
					printf("%d ", result[i][j]);
				}
			}
			printf("\n");
	}
	
	for (int i = 0; i < row; i++){
		free(result[i]);
	}
	free(result);
	
	for (int i = 0; i < row; i++){
		free(temp1[i]);
	}
	free(temp1);
	
	return;
	
}

int main(int argc, char **argv){

	int i = 0;					//Initializing two int variables to easily  
	int j = 0;					//traverse through the rows and columns.
	int **matrix;					//Pointer to the matrix.
	int row;					//int 'row' which will contain the size of the matrix.
	int n;
	
	FILE *ptr = fopen(argv[1],"r");			//File pointer to read the file.
	if (ptr == NULL){				//If file does not exist, print error and return.
		printf("error");
		return 0;
	}
	
	fscanf(ptr, "%d\n", &row);			//reads in first line of the file, which specifies the size of
							//the matrix.
							
	matrix = (int **) malloc(row*sizeof(int*));	//Creating a space allocation for the matrix's rows using malloc.
	
	while (i < row){						//While i is less than the size of the matrix,
		matrix[i] = (int *) malloc(row*sizeof(int*));		//we allocate space for a 'column' for EACH row.
			for (j = 0; j < row; j++){
				fscanf(ptr, "%d", &matrix[i][j]);	//Scans each number of the matrix stored in file
			}						//and copies it to our 'matrix' pointer at correct
		i++;							//location. 
	}								//This scan is done for (row^2) times after the
								//integer on the first line.
								
	fscanf(ptr, "%d", &n);				//The integer on the last line of the file, is the exponentiation
							//factor 'n' which is stored in the int variable 'n'.
							
	fclose(ptr);					//After we finish storing the values correctly, we close the file.
	
	exponential(n, matrix, row);			//We call the exponential helper function, providing it:
							//'n': Exponentiation factor.
							//'matrix': Pointer to the newly created matrix.
							//'row': Size of the matrix.
							
	for (int i = 0; i < row; i++){			//Free allocated space 
		free(matrix[i]);
	}
	free(matrix);
	
	return 0;
}
