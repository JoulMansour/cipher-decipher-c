#include <stdio.h>
#include <stdlib.h>
#include "cipher.h"
#include "tests.h"
#include "string.h"


// your code goes here

#define ARG_ERR "The program receives 1 or 4 arguments only.\n"
#define TEST_ERR "Usage: cipher test\n"
#define COMMAND_ERR "The given command is invalid.\n"
#define SHIFT_ERR "The given shift value is invalid.\n"
#define FILE_ERR "The given file is invalid.\n"
#define NUM_1 1
#define NUM_2 2
#define NUM_3 3
#define NUM_4 4
#define NUM_5 5
#define NUM_10 10
#define NUM_48 48
#define NUM_57 57
#define NUM_1025 1025


/**
 * Thi
 * @return
 */
int run_tests() {
  if (test_cipher_non_cyclic_lower_case_positive_k()) return EXIT_FAILURE;
  if (test_cipher_cyclic_lower_case_special_char_positive_k()) {
    return EXIT_FAILURE;
  }
  if (test_cipher_non_cyclic_lower_case_special_char_negative_k()) {
    return EXIT_FAILURE;
  }
  if (test_cipher_cyclic_lower_case_negative_k()) return EXIT_FAILURE;
  if (test_cipher_cyclic_upper_case_positive_k()) return EXIT_FAILURE;
  if (test_decipher_non_cyclic_lower_case_positive_k()) return EXIT_FAILURE;
  if (test_decipher_cyclic_lower_case_special_char_positive_k()) {
    return EXIT_FAILURE;
  }
  if (test_decipher_non_cyclic_lower_case_special_char_negative_k()) {
    return EXIT_FAILURE;
  }
  if (test_decipher_cyclic_lower_case_negative_k()) return EXIT_FAILURE;
  if (test_decipher_cyclic_upper_case_positive_k()) return EXIT_FAILURE;
  return EXIT_SUCCESS;
}

int is_valid_integer(const char *str) {
  if (*str == '-') str++;
  for (const char *p = str; *p; p++) {
    if (*p < NUM_48 || *p > NUM_57) {
      return 0;
    }
  }
  return *str != '\0';
}


int main (int argc, char *argv[])
{
  if (argc != NUM_2 && argc != NUM_5) {
    fprintf(stderr, ARG_ERR);
    return EXIT_FAILURE;
  }
  if (argc == NUM_2) {
    if (strcmp(argv[NUM_1], "test") != 0) {
      fprintf(stderr, TEST_ERR);
      return EXIT_FAILURE;
    }
    return run_tests();
  }
  if (strcmp(argv[NUM_1], "cipher") != 0 && strcmp(argv[NUM_1], "decipher") != 0) {
    fprintf(stderr, COMMAND_ERR);
    return EXIT_FAILURE;
  }
  if (!is_valid_integer(argv[NUM_2])) {
    fprintf(stderr, SHIFT_ERR);
    return EXIT_FAILURE;
  }
  const int k = (int)strtol(argv[NUM_2], NULL, NUM_10);
  FILE *inputFile = fopen(argv[NUM_3], "r");
  if (!inputFile) {
    fprintf(stderr, FILE_ERR);
    return EXIT_FAILURE;
  }
  FILE *outputFile = fopen(argv[NUM_4], "w");
  if (!outputFile) {
    fclose(inputFile);
    fprintf(stderr, FILE_ERR);
    return EXIT_FAILURE;
  }
  char line[NUM_1025];
  while (fgets(line, sizeof(line), inputFile)) {
    if (strcmp(argv[NUM_1], "cipher") == 0) cipher(line, k);
    else decipher(line, k);
    fputs(line, outputFile);
  }
  fclose(inputFile);
  fclose(outputFile);
  return EXIT_SUCCESS;
}




