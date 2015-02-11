#include <stdio.h>

void ToH(int, char, char, char);

void ToH(int n, char src, char intm, char dest)
{
	if (n == 1) 
	{
		printf("move %d from %c to %c\n", n, src, dest);
		return;
	}
	ToH(n - 1, src, dest, intm);
	printf("move %d from %c to %c\n", n, src, dest);
	ToH(n - 1, intm, src, dest);
}
int main(int argc, char ** argv)
{
	/* The last three parameters are the towers and
	   the first parameter is the number of discs
	   to be moved across the towers */
	ToH(3, 'A', 'B', 'C');
	return 0;
}