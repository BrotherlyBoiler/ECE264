#include <stdio.h>
#include <stdlib.h>
#include "pa_answer02.h"

void Find_maze_dimensions(FILE *fptr, int *nrow, int *ncol);
char **Allocate_maze_space(int nrow, int ncol);
void Deallocate_maze_space(char **maze, int nrow);
char **Read_maze_from_2Dfile(FILE *fptr, int *nrow, int *ncol);
int Find_opening_location(FILE *fptr);

void Get_mowing_directions(char *mazefile, char *directionfile)
{
	int *nrow = 0,  *ncol = 0, i, j
	FILE *mptr = fopen(mazefile, "r");		// open mazefile for reading
	if (mptr == 0) {
		return;
	}
	FILE *dptr = fopen(directionfile, "w");	// open directionfile for writing
	Find_maze_dimensions(mptr, nrow, ncol);
	char **maze = Allocate_maze_space(*nrow, *ncol);
	**maze = Read_maze_from_2Dfile(mptr, nrow, ncol);
	int openloc = Find_opening_location(mptr);
	char curr, start = maze[0][openloc];
	for (i = 1; i < *nrow; ++i) {
		for (j = 0; j < *ncol; ++j) {
			while (maze[i][j] == GRASS) {
				
			}
		}
	}
	// for (i = 0; i < *nrow; ++i) {
	// 	while ()
	// }
	Deallocate_maze_space(maze, *nrow);
}

int Simulate_mowing(char *mazefile, char *directionfile, char *mowedfile)
{

}

void Find_maze_dimensions(FILE *fptr, int *nrow, int *ncol)
{
	int ch;
	*nrow = *ncol = 0;
	rewind(fptr);	// reset file pointer
	while((ch = fgetc(fptr)) != EOF) {	// count rows
		if (ch == '\n')	{
			(*nrow)++;
		}
	}
	rewind(fptr);
	while((ch = fgetc(fptr)) != '\n') {	// count columns
		(*ncol)++;
	}
}

// allocate space for nrow x ncol maze, if allocation fails, return NULL
// if allocation fails, you are also responsible for freeing the memory
// allocated before the failure

char **Allocate_maze_space(int nrow, int ncol)
{
	char **maze, 
	maze = (char **)malloc(nrow * sizeof(char *));
	if (maze == NULL) {
		return NULL;
	}
	for (int i = 0; i < nrow; i++) {
		maze[i] = (char *)malloc(ncol * sizeof(char));
		if (maze[i] == NULL) {
			free(maze);
			return NULL;
		}
	}
	return maze;
}

// free the memory used for the maze
// you may assume that maze is not NULL, and all memory addresses are valid

void Deallocate_maze_space(char **maze, int nrow) 
{
	int i;
    for(i = 0; i < nrow; i++) {
    	free(maze[i]);
    }
    free(maze);
}

/* Read maze in a multi-line file into a 2D array of characters */
/* you may assume that the maze has odd row and column counts */

char **Read_maze_from_2Dfile(FILE *fptr, int *nrow, int *ncol)
{
	*nrow = *ncol = 0;
	int i, j;
	Find_maze_dimensions(fptr, nrow, ncol);
	char **maze = Allocate_maze_space(*nrow, *ncol);
	rewind(fptr);
	for (i = 0; i < *nrow; ++i) {
		for (j = 0; i < *ncol; ++j) {
			do {
				maze[i][j] = fgetc(fptr);
			} while (maze[i][j] == '\n');
		}
	}
	return maze;
}

/* Write maze in a 2D array of characters into a multi-line file */
/* you may assume that the maze has odd row and column counts */

int Write_maze_to_2Dfile(char *filename, char **maze, int nrow, int ncol) 
{
	FILE *fptr = fopen(filename, "w");
	int i, j, wstat, wcnt = 0;
	char curr, next;
	for (i = 0; i < nrow; ++i) {
		for (j = 0; i < ncol; ++j) {
			curr = maze[i][j];
			next = maze[i][j + 1];
			if (curr == GRASS && next == CORN) {
				wcnt++;
			}
			wstat = fputc((int)curr, fptr);
			if (wstat != (int)curr) {   // failed to write
				return -1;
			}
		}
		fputc((int)'\n', fptr);   //create new row in file
		wcnt++;
	}
	fclose(fptr);
	return wcnt;
}

/* Determine the column location of the top opening */

int Find_opening_location(FILE *fptr)
{
	int ch, open = 0;
	rewind(fptr);
	while((ch = fgetc(fptr)) != GRASS) {
		open++;
	}
  return open;
}
