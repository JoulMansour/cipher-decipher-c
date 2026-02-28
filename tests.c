#include <string.h>
#include "tests.h"
#include <stdio.h>


#define K_1 3

// See full documentation in header file
int test_cipher_non_cyclic_lower_case_positive_k ()
{
  char in[] = "abc";
  char out[] = "def";
  cipher (in, K_1);
  return strcmp (in, out) != 0;
}

// See full documentation in header file
int test_cipher_cyclic_lower_case_special_char_positive_k ()
{
  char in[] = "yb.";
  char out[] = "ad.";
  cipher (in, 2);
  return strcmp (in, out) != 0;
}

// See full documentation in header file
int test_cipher_non_cyclic_lower_case_special_char_negative_k ()
{
  char in[] = "eg.";
  char out[] = "df.";
  cipher (in, -1);
  return strcmp (in, out) != 0;
}

// See full documentation in header file
int test_cipher_cyclic_lower_case_negative_k ()
{
  char in[] = "cde";
  char out[] = "zab";
  cipher (in, -3);
  return strcmp (in, out) != 0;
}

// See full documentation in header file
int test_cipher_cyclic_upper_case_positive_k ()
{
  char in[] = "ABC";
  char out[] = "DEF";
  cipher (in, 29);
  return strcmp (in, out) != 0;
}

// See full documentation in header file
int test_decipher_non_cyclic_lower_case_positive_k ()
{
  char in[] = "def";
  char out[] = "abc";
  decipher (in, K_1);
  return strcmp (in, out) != 0;
}

// See full documentation in header file
int test_decipher_cyclic_lower_case_special_char_positive_k ()
{
  char in[] = "ad.";
  char out[] = "yb.";
  decipher (in, 2);
  return strcmp (in, out) != 0;
}

// See full documentation in header file
int test_decipher_non_cyclic_lower_case_special_char_negative_k ()
{
  char in[] = "ac.";
  char out[] = "bd.";
  decipher (in, -1);
  return strcmp (in, out) != 0;
}

// See full documentation in header file
int test_decipher_cyclic_lower_case_negative_k ()
{
  char in[] = "yza";
  char out[] = "bcd";
  decipher (in, -3);
  return strcmp (in, out) != 0;
}

// See full documentation in header file
int test_decipher_cyclic_upper_case_positive_k ()
{
  char in[] = "DEF";
  char out[] = "ABC";
  decipher (in, 29);
  return strcmp (in, out) ;
}



