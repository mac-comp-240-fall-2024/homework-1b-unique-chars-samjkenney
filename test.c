/*
 * TODO: Add an appropriate descriptive comment here
  Author: Sam Kenney
 */

#include <stdio.h>    // printf
#include <stdbool.h>  // to define a boolean type and true, false
#include <string.h>   // strcpy  to copy a string
#include <assert.h>


// declaration of function from hasUniqueChars.c
bool hasUniqueChars(char * inputStr);


int main() {

  // ------------------------------------------------------------
  // Examples of declaring string constants
  /* Example 1 */
  char string1[] = "A string declared as an array.\n";

  /* Example 2 */
  char *string2 = "A string declared as a pointer.\n";

  /* Example 3 */
  char string3[128];   // can copy in up to 127 characters
                       // chose 128 because it is a multiple of 8 bytes
  strcpy(string3, "A string constant copied in.\n");

  // You can uncomment these to see how the strings were initialized above.
  // Then you can comment these out again once you see that the 
  // strings were created correctly
  // printf ("%s", string1);
  // printf ("%s", string2);
  // printf ("%s", string3);

  // -------------------------------------------------------------
  // Thorough and exhaustive tests of hasUniqueChars()  
  bool ok;    // holds the result of hasUniqueChars(); used in asserts
  
  // Test 1: a test case that should return false because characters are duplicated
  strcpy(string3, "This should fail (l and s and i and h)");
  ok = hasUniqueChars(string3);
  assert(!(ok));
  
  // Test 2: This should be true and not fail, but won't work until you
  // complete the hasUniqueChars() function
  strcpy(string3, "abcdefghij");
  ok = hasUniqueChars(string3);
  assert(ok);
  
// tests all printable characters without duplicates
//tests Aa-Zz
  strcpy(string3, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
  ok = hasUniqueChars(string3);
  assert(ok);

//tests special characters
  strcpy(string3, "!#$&()*+,-./<=>?@={|}~")
  ok = hasUniqueChars(string3);
  assert(ok);

//tests no duplicates
  strcpy(string3, "The quick brown fox jumped over the lazy dog.");
  ok = hasUniqueChars(string3);
  assert(ok);

//tests duplicates of letters
  strcpy(string3, "Racecar taco cat!");
  ok = hasUniqueChars(string3);
  assert(!(ok));

//tests duplicates of special characters
  strcpy(string3, "Howdy!!!");
  ok = hasUniqueChars(string3);
  assert(!(ok));

//tests just spaces
  strcpy(string3, " ");
  ok = hasUniqueChars(string3);
  assert(ok);

//tests high amount of characters
  strcpy(string3, "This is a collaborative assignment: I encourage you to work in pairs! However, your pair should take turns working on your own");
  ok = hasUniqueChars(string3);
  assert(!(ok));
// some non-printing characters

  // NOTE: if you add a \n to any tests, this should cause the
  //       exit failure given. Keep this test last so you can check 
  //       that others pass or fail as you expect them to.
  // strcpy(string3, "a b cc\n");
  // ok = hasUniqueChars(string3);
  // other examples that should fail that you can place in strings
  // are \0 or \t or \r
  // See problem description for more details about escape sequences
  
  return 0;
}