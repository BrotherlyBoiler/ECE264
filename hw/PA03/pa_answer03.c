#include <stdio.h>
#include <stdlib.h>
#include "pa_answer03.h"

/* Allocate matrix space for a matrix of the specified size 
   and return it */

double **Allocate_matrix_space(int size)
{
	int i;
	double **mat = (double **)malloc(size * sizeof(double *));
	if (mat == NULL)
		return NULL;
	for (i = 0; i < size; i++) 
	{
		mat[i] = (double *)malloc(size * sizeof(double));
		if (mat[i] == NULL) 
		{
			free(mat);
			return NULL;
		}
	}
	return mat;
}

/* free the memory used for the maze */

void Deallocate_maze_space(double **matrix, int size) 
{
	int i;
    for (i = 0; i < size; i++) 
    {
    	free(matrix[i]);
    }
    free(matrix);
}

/* Find the size of the input matrix. If the first parameter
   is a 3x3 matrix the return 'size' is 3. */

void Find_matrix_size(FILE *fptr, int *size)
{
	int ch;
	*size = 0;
	rewind(fptr);	// reset file pointer
	while((ch = fgetc(fptr)) != EOF) // count rows
	{
		if (ch == '\n')
			(*size)++;
	}
}

/* Make an identity matrix of the specified size and return it. */

double **Make_identity_matrix(int size)
{
	int i, j;
	double **id_mat = Allocate_matrix_space(size);
	for (i = 0; i < size; ++i)
	{
		for (j = 0; j < size; ++j)
		{
			if (i == j) 
				id_mat[i][j] = 1;
			else 
				id_mat[i][j] = 0;
		}
	}
	return id_mat;
}

int Is_identity_matrix(double **matrix, int size)
{
	int i, j;
	for (i = 0; i < size; ++i)
	{
		for (j = 0; j < size; ++j)
		{
			if (i == j)
			{
				if (matrix[i][j] != 1)
					return 0;
			}
			else
			{
				if (!(Is_zero(matrix[i][j])))
					return 0;
			}
		}
	}
	return 1;
}

/* check whether a value is sufficiently small */
/* to be considered 0 */

int Is_zero(double value)
{
   if (value < 0) {
      value = -value;
   }
   if (value < TOL) {
      return 1;
   } else {
      return 0;
   }
}

/* read a matrix from a file, return the matrix */
/* store the size of the matrix in *size        */

double **Read_matrix_from_file(char *filename, int *size)
{
	*size = 0;
	FILE *fptr = fopen(filename, "r");
	if (fptr == NULL)
	{
		fprintf(stderr, "cannot read file %s\n", filename);
		return NULL;
	}
	Find_matrix_size(fptr, size);
	double **mat = Allocate_matrix_space(*size);
	if (mat == NULL)
	{
		fclose(fptr);
		return NULL;
	}
	rewind(fptr);
	int n_read = fread(mat, sizeof(double), (*size) * (*size), fptr);
	fprintf(stderr, "%d successfully read from file\n", n_read);
	return mat;
}

/* write a matrix of a given size to a file, return 1 if the write is */
/* successful, otherwise, 0 */

int Write_matrix_to_file(char *filename, double **matrix, int size)
{
	FILE *fptr = fopen(filename, "w");
	if (fptr == NULL)
	{
		fprintf(stderr, "cannot write file %s\n", filename);
		return 0;
	}
	int n_write = fwrite(matrix, sizeof(double), size * size, fptr);
	fprintf(stderr, "%d successfully written to file\n", n_write);
	fclose(fptr);
	if (n_write == size * size) 
		return 1;
	else 
		return 0;
}

/* invert a matrix of a given size */
/* if inversion is successful, return the inverse */
/* otherwise, return NULL */

double **Invert_matrix(double **matrix, int size)
{
	double tem = 0, temp = 0, temp1 = 0, temp2 = 0, temp4 = 0, temp5 = 0;
	int i, j, p, q;
	double **id_mat = Make_identity_matrix(size);
	if (id_mat == NULL)
	{
		fprintf(stderr, "cannot allocate space for id_mat\n");
		return NULL;
	}

	/* Find inverse matrix using Guass Jordan method. The original */
	/* matrix's values will be replaced by those of the identity */
	/* matrix and id_mat will end up storing the inverse of the */
	/* original matrix */
	
	for(i = 0; i < size; ++i)
	{
	   temp = matrix[i][i];
	   if (temp < 0)
	      temp = temp * (-1);
	   p = i;
	   for (j = i + 1; j < size; ++j)
	   {
	      if (matrix[j][i] < 0)
	         tem = matrix[j][i] * (-1);
	      else
	         tem = matrix[j][i];
	      if (temp < 0)
	         temp = temp * (-1);
	      if (tem > temp)
	      {
	         p = j;
	         temp = matrix[j][i];
	      }
	   }

	   /* Row exchange in both the matrix */
	   
	   for (j = 0; j < size; ++j)
	   {
	      temp1 = matrix[i][j];
	      matrix[i][j] = matrix[p][j];
	      matrix[p][j] = temp1;
	      temp2 = id_mat[i][j];
	      id_mat[i][j] = id_mat[p][j];
	      id_mat[p][j] = temp2;
	   }

	   /* Dividing the row by matrix[i][i] */
	   
	   temp4 = matrix[i][i];
	   for (j = 0; j < size; ++j)
	   {
	      matrix[i][j]= (double) matrix[i][j] / temp4;
	      id_mat[i][j]= (double) id_mat[i][j] / temp4;
	   }

	   /* Making other elements 0 in order to make the matrix 'matrix[][]' */
	   /* an indentity matrix and obtaining a inverse 'id_mat[][]' matrix */

	   for (q = 0; q < size; ++q)
	   {
	      if (q == i)
	         continue;
	      temp5 = matrix[q][i];
	      for (j = 0; j < size; ++j)
	      {
	         matrix[q][j] = matrix[q][j] - (temp5 * matrix[i][j]);
	         id_mat[q][j] = id_mat[q][j] - (temp5 * id_mat[i][j]);
	      }
	   }
	}

	/* Check if matrix is invertable */

	if (Is_identity_matrix(matrix, size))
		return id_mat;
	else
		return NULL;
}

/* multiply two matrices of the same size */
/* if the multiplication is successful, return the results */

double **Matrix_matrix_multiply(double **matrixa, double **matrixb, int size)
{
	int i, j, k;
	double temp = 0;
	double **mul_mat = Allocate_matrix_space(size);
	if (mul_mat == NULL)
	{
		fprintf(stderr, "cannot allocate matrix space for mul_mat\n");
		return NULL;
	}
	for (i = 0; i < size; ++i)
	{
		for (j = 0; j < size; ++j)
		{
			for (k = 0; k < size; ++k)
			{
				temp += matrixa[j][k] * matrixb[k][i];
			}
			mul_mat[j][i] = temp;
			temp = 0;
		}
	}
	return mul_mat;;
}

/* return the sum of the absolute differences between the */
/* entries of a matrix of a given size and the corresponding */
/* entries of an identity matrix of the same size */

double Deviation_from_identity(double **matrix, int size)
{
	if (matrix == NULL)
	{
		fprintf(stderr, "Deviation_from_identity: input matrix invalid\n");
		return *(double *)NULL;
	}
	int i, j;
	double deviation = 0;
	double **id_mat = Make_identity_matrix(size);
	for (i = 0; i < size; ++i)
	{
		for (j = 0; j < size; ++j)
		{
			deviation += matrix[i][j] - id_mat[i][j];
		}
	}
	Deallocate_maze_space(id_mat, size);
	return deviation;
}
