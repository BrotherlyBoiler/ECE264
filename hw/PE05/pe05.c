#include <stdio.h>
#include <stdlib.h>
#include "answer05.h"

#define EX_ROW 3
#define EX_COL 4

int main(int argc, char *argv[])
{ 
   if (argc < 3) {
      return EXIT_FAILURE;
   }
   int nrow = EX_ROW, ncol = EX_COL;
   FILE *fptr = fopen(argv[1], "r");

   Find_maze_dimensions(fptr, &nrow, &ncol);
   printf("col: %d row: %d\n", ncol, nrow);

   int open_loc = Find_opening_location(fptr);
   printf("Open Location: %d\n", open_loc);

   int grass_loc = Count_grass_locations(fptr);
   printf("Grass locations count: %d\n", grass_loc);

   int loc_type = Get_location_type(fptr, EX_ROW, EX_COL);
   printf("Get location type: %c\n", (char)loc_type);

   Represent_maze_in_one_line(argv[2], fptr);

   fclose(fptr);
   return EXIT_SUCCESS;
}

