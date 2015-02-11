#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
const int maxN = 46;

unsigned int iter_Fibonacci(unsigned int);
unsigned int Fibonacci(unsigned int);

unsigned int iter_Fibonacci(unsigned int n)
{
	if (n == 0) { return 0; }
	if (n == 1) { return 1; }
	/* can you do it with only two variables */
	unsigned int prev, curr, temp;
	int i;
	prev = 0;
	curr = 1;
	for (i = 2; i <= n; i++)
	{
		/* can you do it with only two statements */
		temp = prev + curr;
		prev = curr;
		curr = temp;
	}
	return curr;
}
unsigned int Fibonacci(unsigned int n)
{
	if (n == 0) { return 0; }
	if (n == 1) { return 1; }
	return (Fibonacci(n - 1) + Fibonacci(n - 2));
}
int main(int argc, char * argv[])
{
	int cnt;
	struct timeval t1;
	struct timeval t2;
	unsigned int f1;
	unsigned int f2;
	for (cnt = 0; cnt < maxN; cnt ++)
	{
		gettimeofday(& t1, NULL);
		f1 = Fibonacci(cnt);
		gettimeofday(& t2, NULL);
		printf("n = %2d, F1 = %10u, %9f sec",
		cnt, f1,
		(t2.tv_sec - t1.tv_sec) +
		1e-6 * (t2.tv_usec - t1.tv_usec));
		gettimeofday(& t1, NULL);
		f2 = iter_Fibonacci(cnt);
		gettimeofday(& t2, NULL);
		printf(", F2 = %10u, %9f sec\n",
		f2,
		(t2.tv_sec - t1.tv_sec) +
		1e-6 * (t2.tv_usec - t1.tv_usec));
	}
	return 0;
}