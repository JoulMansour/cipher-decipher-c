# caesar-cipher-cli

A small C command-line tool that encrypts/decrypts text files using a Caesar cipher (shift by `k`).
- Supports lowercase and uppercase letters
- Keeps non-letter characters unchanged
- Handles negative and large shifts (mod 26)
- Includes built-in unit tests

## Build
```bash
gcc -Wall -Wextra -std=c99 main.c cipher.c tests.c -o cipher

## Run
./cipher cipher <k> <input_file> <output_file>
./cipher decipher <k> <input_file> <output_file>
