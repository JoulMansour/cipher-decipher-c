#include <string.h>
#include <ctype.h>
#include "cipher.h"

#define BUFFER_SIZE 1024

/// IN THIS FILE, IMPLEMENT EVERY FUNCTION THAT'S DECLARED IN cipher.h.


// See full documentation in header file

void cipher (char s[], int k)
{
  char str[BUFFER_SIZE];
  int length = 0;
  k = k % 26;
  if (k < 0) {
    k += 26;
  }
  for (int i = 0; i < (int)strlen(s); i++) {
    char letter = s[i];
    if (isalpha(letter)) {
      char new_letter = letter;
      if (letter >= 'a' && letter <= 'z') {
        new_letter = (char)('a' + (letter - 'a' + k) % 26);
      }
      else if (letter >= 'A' && letter <= 'Z') {
        new_letter = (char)('A' + (letter - 'A' + k) % 26);
      }
      str[length] = new_letter;
    } else {
      str[length] = letter;
    }
    length++;
  }
  str[length] = '\0';
  strcpy(s, str);

}

// See full documentation in header file
void decipher (char s[], int k)
{
  char str[BUFFER_SIZE];
  int length = 0;
  k = k % 26;
  if (k < 0) {
    k += 26;
  }
  for (int i = 0; i < (int)strlen(s); i++) {
    char letter = s[i];
    char new_letter = letter;
    if (isalpha(letter)) {
      if (letter >= 'a' && letter <= 'z') {
        new_letter = (char)('a' + (letter - 'a' - k + 26) % 26);
      }
      else if (letter >= 'A' && letter <= 'Z') {
        new_letter = (char)('A' + (letter - 'A' - k + 26) % 26);
      }
    }
    str[length] = new_letter;
    length++;
  }
  str[length] = '\0';
  strcpy(s, str);

}


