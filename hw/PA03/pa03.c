#include <stdio.h>
#include <stdlib.h>
#include "pa_answer03.h"

int main(int argc, char *argv[])
{
   int *size;

   /* Perform inversion */
   if (agrc == 4)
   {
      if (argv[1][0] == '-' && argv[1][1] == 'i')
      {
         double **matrix = Read_matrix_from_file(argv[2], size);
         if (matrix == NULL)
         {
            fprintf(stderr, "unable to allocate space for matrix\n");
            return EXIT_FAILURE;
         }
         double **inv_mat = Invert_matrix(matrix, *size);
         if (inv_mat != NULL)
         {
            int w_success = Write_matrix_to_file(argv[3], inv_mat, *size);
            Deallocate_maze_space(matrix, *size);
            Deallocate_maze_space(inv_mat, *size);
            if (w_success)
               return EXIT_SUCCESS;
            else 
            {
               fprintf(stderr, "writing to file %s failed\n", argv[3]);
               return EXIT_FAILURE;
            }
         }
         else if (inv_mat == NULL)
         {
            Deallocate_maze_space(matrix, *size);
            Deallocate_maze_space(inv_mat, *size);
            fprintf(stderr, "the matrix is non-invertable\n");
            return EXIT_FAILURE;
         }
      }
   }

   /* Perform multiplication */
   else if (argc == 5)
   {
      if (argv[1][0] == '-' && argv[1][1] == 'm')
      {
         double **matrixa = Read_matrix_from_file(argv[2], size);
         if (matrixa == NULL)
         {
            fprintf(stderr, "unable to allocate space for matrixa\n");
            return EXIT_FAILURE;
         }
         double **matrixb = Read_matrix_from_file(argv[3], size);
         if (matrixb == NULL)
         {
            fprintf(stderr, "unable to allocate space for matrixb\n");
            return EXIT_FAILURE;
         }
         double **mul_mat = Matrix_matrix_multiply(matrixa, matrixb, *size);
         if (mul_mat != NULL)
         {
            int w_success = Write_matrix_to_file(argv[4], mul_mat, *size);
            Deallocate_maze_space(matrixa, *size);
            Deallocate_maze_space(matrixb, *size);
            Deallocate_maze_space(mul_mat, *size);
            if (w_success)
               return EXIT_SUCCESS;
            else
            {
               fprintf(stderr, "writing to file %s failed\n", argv[4]);
               return EXIT_FAILURE;
            }
         }
         else if (mul_mat == NULL)
         {
            Deallocate_maze_space(matrixa, *size);
            Deallocate_maze_space(matrixb, *size);
            Deallocate_maze_space(mul_mat, *size);
            fprintf(stderr, "matrix multiplication failed\n");
            return EXIT_FAILURE;
         }
      }
   }

   /* Computer the deviation from the identity matrix eviation */
   else if (argc == 3)
   {
      if (argv[1][0] == '-' && argv[1][1] == 'd')
      {
         double **matrix = Read_matrix_from_file(argv[2], size);
         if (matrix == NULL)
         {
            fprintf(stderr, "unable to allocate space for matrix\n");
            return EXIT_FAILURE;
         }
         double deviation = Deviation_from_identity(matrix, *size);
         Deallocate_maze_space(matrix, *size);
         if (deviation != NULL)
         {
            printf("%e\n", deviation);
            return EXIT_SUCCESS;
         }
         else
         {
            fprintf(stderr, "deviation calculation failed\n");
            return EXIT_FAILURE;
         }
      }
   }
   else
   {
      fprintf(stderr, "invalid input arguments\n");
      return EXIT_FAILURE;
   }
}
