#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include "pa_answer01.h"

#define INV_SYMBOL 36

// convert a char to a number
// '0'..'9' --> 0..9
// 'a'..'z' --> 10..35
// 'A'..'Z' --> 10..35
// other characters --> INV_SYMBOL
//
int char_to_int(char c);

// you should try to re-use a majority of the algorithms in PE02
// for this programming assignment.
// However, you have to take care of endptr, base 0, and base 16
// these are the three additional things you have to deal with in
// this assignment, as compared to the str_to_long_int function
// that you wrote for PE02.
//
// it is really IMPORTANT that you extensively try out the function
// strtol on your own.

int char_to_int(char c)
{
   // what if c is '0'--'9'
    if (isdigit(c)) {
        return ((int) c - '0');
    }
   // what if c is 'a'--'z'
    else if (islower(c)) {
        return ((int) c - 'a' + 10);
    }
   // what if c is 'A'--'Z'
    else if (isupper(c)) {
        return ((int) c - 'A' + 10);
    }
   // otherwise
   return INV_SYMBOL;
}

long int my_strtol(const char *nptr, char **endptr, int base)
{
	long int ret_value = 0;  // return value
	const char *ptr = nptr;  //make shallow copy
  int neg = 1, len = 0, i;

   // if invalid base, set errno and return immediately
  if (base < 0 || base > 36 || base == 1) {
        errno = EINVAL;
        return ret_value;
    }

   // valid base, skip over white space
 	while (isspace(*ptr)) {
        ptr++;
    }

   // if encounter a sign, expect a number after that 
   // if a negative sign is encountered, change the sign
  if (ptr[0] == '+') {
      ptr++;
  }
  else if (ptr[0] == '-') {
      neg = -1;
      ptr++;
  }
   
   // the exact algorithm is not given, but these are 
   // the tasks the function has to perform:  
   //
   // determine the actual base if the base is 0
   // if it starts with '0', it is octal
   // if '0' is followed by 'x' or 'X' it is hexadecimal or base 16
   // otherwise, it is decimal
   // therefore you have to determine the actual base and the starting
   // location to perform conversion
   //
   // for bases 2 to 15, perform conversion as in PE02
   //
   // for base 16, you have to decide when the conversion should
   // start: after the optional "0x" or "0X" or immediately
   // question: if you have "0xG", what should be converted?
   //
   // for bases 17 to 36, perform conversion as in PE02
   // 
   // after you have determine the real base, and where to start,
   // perform the conversion

  // Determine actual base if input base is 0
  if (base == 0) {
    if (ptr[0] == '0' && (ptr[1] == 'x' || ptr[1] == 'X')) {
      ptr += 2;
      base = 16;
    }
    if (ptr[0] == '0' && ptr[1] != '0') {
      ptr++;
      base = 10;
    }
    else if (ptr[0] == '0') {
      ptr++;
      base = 8;
    }
  }

  //Find length of valid string
  for (i = 0; ptr[i] != '\0'; ++i) {
    if (char_to_int(ptr[i]) >= base) {  //Outside of base limits 
      break;  
    } 
    len++;
  }

  //Set *endptr to first invalid character
  if (len < 1) {
    *endptr = (char *) ptr; 
  } else {
    *endptr = (char *) (ptr + len);
  }

    //Conversion code using length of valid characters
  for (i = 0; i < len; ++i) {
    ret_value = ret_value * base + char_to_int(ptr[i]);
  }

   // clean up, set ret_value properly if the conversion went out of range
   // set errno if necessary
   // set *endptr properly if the endptr is not NULL

  if (ret_value * neg > LONG_MAX) {
    errno = ERANGE;
    ret_value = LONG_MAX;
  }
  else if (ret_value * neg < LONG_MIN) {
    errno = ERANGE;
    ret_value = LONG_MIN;
  }

  return ret_value * neg;
}
