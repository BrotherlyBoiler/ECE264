#include <stdio.h>

int main(int argc, char * argv[])
{
	printf("%d\n", argc);
	int cnt;
	for (cnt = 0; cnt < argc; cnt ++)
	{
		printf("%s\n", argv[cnt]);
	}

	unsigned int size = sizeof(int);
	printf("size = %d bytes\n", size);
	return 0;
}