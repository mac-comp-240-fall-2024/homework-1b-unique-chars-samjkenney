/*
 * hasUniqueChars.c
 * 
 * checks if a string contains entirely unique, printable characters
 * 
 * Author: Sam Kenney
 */

#include <stdio.h>  // fprintf, printf
#include <stdlib.h> // exit() defined here
#include <string.h> // useful string operations
#include <ctype.h>  //useful character operations
#include <stdbool.h>  // to define a boolean type and true, false
                      // see https://en.wikibooks.org/wiki/C_Programming/stdbool.h

#include "binary_convert.h"


/*
 * This function is for debugging by printing out the value
 * of an input insigned long as a binary string.
 */
void seeBits(unsigned long value, char *debug_text) {
  
  // string to represent binary value of variable value
  char *bin_str;

  bin_str = ulong_to_bin_str(value);
  printf("%s%s\n", debug_text, bin_str);
  free(bin_str);
  
}



/*
 * Given an input string of chars, check for any non-printing
 * characters and print an error and exit if the string has any.
 */
void checkInvalid(char * inputStr) {
  char nextChar;
  int i;
  
  for(i = 0; i < strlen(inputStr); i++) {
    nextChar = inputStr[i];

    // if nextChar is invalid (31 or less or 127 as an ascii char code), then bail out
    if ((nextChar <= 31 ) || (nextChar == 127)) {
      fprintf(stderr, "invalid character in string\n");
      exit(EXIT_FAILURE);
    }
  }
}


/*
 *  checks if there are invalid characters in the string, then iterates over the string
 sorts between A-z characters and !-@, as well as counts for space
 uses a mask to determine the appropriate index of the character,
 then compares with checkBits string
 if one in the mask and checkBits, returns false, 
 otherwise updates the checkBits string and moves to the next character
 returns true if no duplicates are found
 
 */
bool hasUniqueChars(char * inputStr) {
  // bail out quickly if any invalid characters
  checkInvalid(inputStr);
  
  int i;   // loop counter
  
  // unsigned long can handle 64 different chars in a string
  // if a bit at a position is 1, then we have seen that character
  unsigned long checkBitsA_z = 0;   // for checking A through z and {|}~
  unsigned long checkBitsexcl_amp =0;  // for checking ! though @ 

  char nextChar;         // next character in string to check

  for(i = 0; i < strlen(inputStr); i++) {
    nextChar = inputStr[i];
    unsigned long index;
    unsigned long mask;
    if (nextChar == 32){
      //if char is a space
      continue;
    }
    if (nextChar <= 126 && nextChar >= 65){
      index = nextChar - 65;
      mask = 1l << index;
      //if char is A-z
      if (checkBitsA_z & mask){
      //if there is a one in both the mask and the checkBits
        return false;
        
      }
      else{
        //puts a one in the appropriate spot in the mask
          checkBitsA_z = checkBitsA_z | mask;
      }
    }
    if (nextChar >= 33 && nextChar <= 64){
      index = nextChar - 33;
      mask = 1l << index;
      //if ! through @
      if (checkBitsexcl_amp & mask){
        //if there is a one in both the mask and the checkBits
        return false; 
      }
      else{
        //puts a one in the appropriate spot in the mask
        checkBitsexcl_amp = checkBitsexcl_amp | mask;
      }   
    }
  }

  // if through all the characters, then no duplicates found
  return true;
  
}
