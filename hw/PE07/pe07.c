#include <stdlib.h>
#include <stdio.h>

#include "bmp.h"

##ifndef EXIT_FAILURE
#define EXIT_FAILURE 1
#endif
##ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif

int main(int argc, char const *argv[])
{
	if (argc != 4)
	{
		fprintf(stderr, "Insufficient arguments\n");        
		return EXIT_FAILURE;
	}
	// Process top half of the image
	if (argv[1][0] == '-' && argv[1][1] == 't')
	{
		
	}
	// Process left half of the image
	else if (argv[1][0] == '-' && argv[1][1] == 'l')
	{
		
	}
	else
	{
		fprintf(stderr, "Invalid option\n");
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
