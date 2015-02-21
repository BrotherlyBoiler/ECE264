#include <stdio.h>
#include <stdlib.h>
#include "answer05.h"

// if you want to declare and define new functions, put them here
// or at the end of the file



// do not remove #ifndef and #endif in this file, otherwise the evaluation
// would fail and you would definitely get 0
// any new functions you want to create and use in this file 
// should appear above these comments or at the end of this file

#ifndef NTEST_DIMENSION

/* Determine the dimensions of the maze contain in file. */
/* The maze will always of the correct format */
/* the number of rows is stored at location pointed to by nrow */ 
/* the number of ncol is stored at location pointed to by ncol */

void Find_maze_dimensions(FILE *fptr, int *nrow, int *ncol)
{
	char ch;
	*nrow = *ncol = 0;
	while((ch = getc(fptr)) != EOF) {
		if (ch == '\n')	{
			*nrow++;
		}
	}
	while((ch = getc(fptr)) != '\n') {
		*ncol++;
	}
}

#endif /* NTEST_DIMENSION */

#ifndef NTEST_OPENLOC

/* Determine the column location of the top opening */

int Find_opening_location(FILE *fptr)
{
   return 0;
}

#endif /* NTEST_OPENLOC */

#ifndef NTEST_GRASSCNT

/* Count the number of locations with grass */
/* A location has grass if it is a space, ' ', or GRASS */

int Count_grass_locations(FILE *fptr)
{
   return 0;
}

#endif /* NTEST_GRASSCNT */

#ifndef NTEST_LOCTYPE

/* Return the type of location: CORN or GRASS */
/* Return the character stored in the file for that location */
/* The location is specified by its row-column coordinates. */
/* The coordinates are specified by row and col */

char Get_location_type(FILE *fptr, int row, int col) {
   return 0;   
}
 
#endif /* NTEST_LOCTYPE */

#ifndef NTEST_ONELINE

/* Given a filename, re-represent the maze in the file pointer fptr */
/* in a single line */
/* The return value should be the number of characters written into the */
/* the new file */
/* if the writing to a file fails, you should return -1 */ 

int Represent_maze_in_one_line(char *filename, FILE *fptr)
{
   return -1;
}

#endif /* NTEST_ONELINE */

// if you want to declare and define new functions, put them below this line
// or at the beginning of the file
