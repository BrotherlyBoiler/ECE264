#include <errno.h>
#include <ctype.h>
#include <limits.h>
#include <stdio.h>

#include "answer02.h"

// Given a char c, return a numeric value
// '0'..'9' --> 0..9
// 'a'..'z' --> 10..35
// 'A'..'Z' --> 10..35
// for other characters, return INV_SYMBOL (see answer02.h);
//
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

// you are not allowed to change the contents at the location whose address in 
// stored in nptr (the way to interpret the type of nptr is that it is an address
// pointing to a constant char.)
//
// you have to check for whether the base in the valid range 2 through 36
// if not, set errno to EINVAL
// 
// This is a suggestion on how you should process the string
// (1)  skip over all white space
// (2)  if a +/- sign is encountered, set the polarity of the number accordingly
//      By default, the number is assumed to be positive if no sign is given.
// (3)  Convert the string until you encounter an invalid symbol for that 
//      base or when you reach the end of the string.
//
// examples (not exhaustive, of course):
//    "10a:" in base 10 is 10, in base 16 is 266, in base 36 is 1306
//    "   -10a:" in base 10 is -10, in base 16 is -266, and in base 36 is -1306 
//    " +10a:" in base 10 is 10, in base 16 is 266, in base 36 is 1306
//    "922337203685477580710304" in base 10 should return LONG_MAX, and errno 
//    should be set to ERANGE.
//    "-922337203685477580710304" in base 10 should return LONG_MIN, and errno 
//    should be set to ERANGE.
//    "garbage" should be 0 in base 10, 0 in base 16, and 35479055534 in base 36
//
long int str_to_long_int(const char *nptr, int base)
{
   long int ret_value = 0;  // return value
                            // if no conversion happens, return 0
    const char *nptr_cpy = nptr;
    int neg_num = 1, len = 0, i;
    
   // if invalid base, set errno and return immediately
    if (base < 2 || base > 36) {
        errno = EINVAL;
        return ret_value;
    }

   // valid base, skip over white space
    while (isspace(*nptr_cpy)) {
        nptr_cpy++;
    }
    
   // if encounter a sign, expect a number after that 
   // if a negative sign is encountered, the conversion must
   // produce a negative number
    if (nptr_cpy[0] == '+') nptr_cpy++;
    else if (nptr_cpy[0] == '-') {
        neg_num = -1;
        nptr_cpy++;
    }

   // now, convert the string to number
   // the conversion has to account for the +/- sign
   // need to check whether you have out-of-range ret_value 
    for (i = 0; nptr_cpy[i] != '\0'; ++i) {
        if (char_to_int(nptr_cpy[i]) >= base) {
            break;
        }
        len++;
    }
    
    for (i = 0; i < len; ++i) {
        ret_value = ret_value * base + char_to_int(nptr_cpy[i]);
    }

   // clean up before returning
   // need to set errno and ret_value correctly if the converted number 
   // is out of range
    if (ret_value * neg_num > LONG_MAX) {
        errno = ERANGE;
        ret_value = LONG_MAX;
    }
    else if (ret_value * neg_num < LONG_MIN) {
        errno = ERANGE;
        ret_value = LONG_MIN;
    }    

   return ret_value * neg_num;
}
