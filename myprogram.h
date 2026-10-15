#ifndef MYPROGRAM_H
#define MYPROGRAM_H

/* Sum the odd integers from 1 through n (inclusive). Requires 0 <= n <= 100. */
int sum_of_odds(int n);

/* Count the even elements, including zero. Requires 1 <= count <= 100. */
int count_even_numbers(const int *array, int count);

/* Return the smallest element. Requires 1 <= count <= 100. */
int smallest_number(const int *array, int count);

/* Count decimal digits. Zero has one digit. Requires 0 <= number <= 1000000. */
int count_digits(int number);

/* Convert 'a' through 'z' to uppercase; return other characters unchanged.
 * Assume an ASCII-compatible character set. */
char uppercase_letter(char letter);

#endif
