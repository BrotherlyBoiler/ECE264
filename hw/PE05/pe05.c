#include <stdio.h>
#include <stdlib.h>
#include "answer05.h"

void readFile(char *);

int main(int argc, char *argv[])
{ 
   printf("Welcome to ECE264, we are working on PE05.\n\n");

   if (argc < 2) {
      return EXIT_FAILURE;
   }
   int n = atoi(argv[1]);
   if (n < 1) {
      return EXIT_FAILURE;
   }
   readFile(argv[1]);
   if (atoi(argv[2]) == 1) {
    //  Find_maze_dimensions();
   }
   return EXIT_SUCCESS;
}

void readFile(char * fileName)
{
   FILE * fptr = fopen(fileName, "r");
   int val;
   if (fptr == NULL) {
      fprintf(stderr, "cannot read file %s\n", fileName);
      return;
   }
   while (! feof(fptr)) {
      fscanf(fptr, "%d\n", &val);
      printf("%d\n", val);
   }
   fclose(fptr);
}
