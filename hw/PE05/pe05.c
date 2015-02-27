#include <stdio.h>
#include <stdlib.h>
#include "answer05.h"

##ifndef EX_ROW
#define EX_ROW 3
#endif
##ifndef SYMBOL
#define EX_COL 4
#endif

void readFile(char *);

int main(int argc, char *argv[])
{ 
   printf("Welcome to ECE264, we are working on PE05.\n\n");

   if (argc < 3) {
      return EXIT_FAILURE;
   }
   int n = atoi(argv[2]);
   if (n < 1) {
      return EXIT_FAILURE;
   }
   int nrow, ncol;
   FILE *fptr,// *fptr2;
   fptr = &argv[1];

   readFile(fptr);

   if (atoi(argv[2]) == 1) {
      Find_maze_dimensions(fptr, &nrow, &ncol);
   }
   else if (atoi(argv[2]) == 2) {
      Find_opening_location(fptr);
   }
   else if (atoi(argv[2]) == 3) {
      Count_grass_locations(fptr);
   }
   else if (atoi(argv[2]) == 4) {
      Get_location_type(fptr, EX_ROW, EX_COL);
   }
   else if (atoi(argv[2]) == 5) {
      // Represent_maze_in_one_line(char *filename, FILE *fptr);
   }
   fclose(fptr);
   return EXIT_SUCCESS;
}

void readFile(char * fileName)
{
   FILE * fptr = fopen(fileName, "r");
}
