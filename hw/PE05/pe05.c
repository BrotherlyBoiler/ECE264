#include <stdio.h>
#include <stdlib.h>
#include "answer05.h"

#define EX_ROW 3
#define EX_COL 4

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
   FILE *fptr = fopen(argv[1], "r");
   // readFile((char *)fptr);

   if (n == 1) {
      Find_maze_dimensions(fptr, &nrow, &ncol);
   }
   else if (n == 2) {
      int open_loc = Find_opening_location(fptr);
      printf("Open Location: %d\n", open_loc);
   }
   else if (n == 3) {
      int grass_loc = Count_grass_locations(fptr);
      printf("Grass locations count: %d\n", grass_loc);
   }
   else if (n == 4) {
      int loc_type = Get_location_type(fptr, EX_ROW, EX_COL);
      printf("Get location type: %d\n", loc_type);
   }
   else if (n == 5) {
      char *newfile = NULL;
      printf("Enter new file name: ");
      gets(newfile);
      FILE *fptr2 = fopen(argv[1], "r+");
      Represent_maze_in_one_line(newfile, fptr);
      fclose(fptr2);
   }
   fclose(fptr);
   return EXIT_SUCCESS;
}

// void readFile(char * fileName)
// {
//    FILE * fptr = fopen(fileName, "r");
// }
