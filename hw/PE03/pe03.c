#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utility.h"
#include "answer03.h"

int main(int argc, char *argv[])
{
   // initialize the counter for counting the number of recursive calls
 
   printf("Welcome to ECE264, we are working on PE03.\n\n");

   // parse the input arguments
   // the input arguments must be of the form 
   // -r number number
   // -i number number
   // for the two numbers, you can use atoi to convert argv[2] and 
   // argv[3] into integers.  Read the manual page of atoi for more details
   //
   // You don't have to check that argv[2] and argv[3] are valid numbers
   // You just have to use the numbers converted from atoi
   //
   // you should check whether you have sufficient input arguments
   // if not, return with EXIT_FAILURE immediately, you don't print answer and 
   // the counter
   //
   // you should check whether you have the correct option of 
   // "-r" or "-i"
   // if not, return with EXIT_FAILURE immediately, you don't print the answer
   // and the counter
   //
   // you should check whether lb < ub
   // if not, return with EXIT_FAILURE immediately, you don't print the answer
   // and the counter

   int answer = 0;  // you should store the guessed number in answer

   Initialize_counter();  // initialize the counter for recursion call

   /* put in your code here */















   /* put in your code above this line */
   // print the guessed number, keep this

   printf("%d\n", answer);
   
   // get the number of recursive calls and print

   printf("%d\n", Get_counter());
   return EXIT_SUCCESS;
}
