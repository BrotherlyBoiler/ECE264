#include <stdio.h>
#include <stdlib.h>
#include "pa_answer03.h"

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
   return NULL;
}

/* write a matrix of a given size to a file, return 1 if the write is */
/* successful, otherwise, 0 */

int Write_matrix_to_file(char *filename, double **matrix, int size)
{
   return 0;
}

/* invert a matrix of a given size */
/* if inversion is successful, return the inverse */
/* otherwise, return NULL */

double **Invert_matrix(double **matrix, int size)
{
   return NULL;
}

/* multiply two matrices of the same size */
/* if the multiplication is successful, return the results */

double **Matrix_matrix_multiply(double **matrixa, double **matrixb, int size)
{
   return NULL;
}

/* return the sum of the absolute differences between the */
/* entries of a matrix of a given size and the corresponding */
/* entries of an identity matrix of the same size */

double Deviation_from_identity(double **matrix, int size)
{
   return 0.0;
}
