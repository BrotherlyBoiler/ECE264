#include <stdio.h>
#include <stdlib.h>
#include "utility.h"
#include "answer04.h"
#include <math.h>

// do not remove #ifndef and #endif in this file, otherwise the evaluation
// would fail and you would definitely get 0

#ifndef NTEST_LOG

/* n is even */
/* *fn1 and *fn2 should store F(n) and F(n-1) */
void logFibonacci(int n, unsigned long *fn1, unsigned long *fn2)
{
  // increment the recursion counter 

  Increment_counter();

  // terminating condition
  if (n == 0) *fn1 = 0;
  if (n == 1) *fn1 = 1;

  // recursion
  // you have to halve n, 
  // depending on whether n/2 is even or odd, recursively
  // call logFibonacci with appropriate parameters
  int m = n / 2;
  if (n % 2 == 0)	// m is even
  {
    *fn1 += 2 * logFibonacci(m - 1, fn1, fn2) * logFibonacci(m, fn1, fn2);	// F(n)
    *fn1 += pow(logFibonacci(m, fn1, fn2), 2);
    *fn2 += pow(logFibonacci(m - 1, fn1, fn2), 2);	// F(n - 1)
		*fn2 += pow(logFibonacci(m, fn1, fn2), 2);
  } 
  else	// m is odd
  {
    *fn1 += 2 * logFibonacci(m - 2, fn1, fn2) * logFibonacci(m - 1, fn1, fn2);	// F(n)
    *fn1 += pow(logFibonacci(m - 1, fn1, fn2), 2);
    *fn2 += pow(logFibonacci(m - 2, fn1, fn2), 2);	// F(n - 1)
		*fn2 += pow(logFibonacci(m - 1, fn1, fn2), 2);
	}
}

#endif

#ifndef NTEST_FIB

/* n is can be odd or even */
/* n is assumed to be non-negative */
/* don't have to check for that */
unsigned long Fibonacci(int n)
{
   /* for storing the results when calling logFibonacci */

   unsigned long fn1 = 0; 
   unsigned long fn2 = 0;

   /* simple cases */
   if (n == 0) return 0;
   if (n == 1) return 1;

   /* if even n, call logFibonacci with n and return fn1 */
   /* if odd n, call with n-1 or n+1, combine fn1 and fn2 as F(n) */
   if (n % 2 == 0) 
   {
     logFibonacci(n, *fn1, *fn2);
     return *fn1;
   } 
   else 
   {
     logFibonacci(n - 1, *fn1, *fn2);
     return *fn1 + *fn2;
   }
}

#endif
