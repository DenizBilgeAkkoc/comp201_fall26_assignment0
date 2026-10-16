# Assignment 0

See the assignment description for submission instructions.
Complete the five TODOs in `myprogram.c`. Keep function names and parameters
unchanged, and use `is_even()` in the first two functions.

## Functions

1. **`sum_of_odds(n)`**: Add the odd integers from 1 through `n`, inclusive.
   Use `is_even()` to identify numbers to skip. For `7`, return `16`.
   For `0`, return `0`. Inputs are between 0 and 100.
2. **`count_even_numbers(array, count)`**: Use `is_even()` to count even
   elements. Zero and negative even numbers count too.
   For `[-2, 0, 3, 8, 5]`, return `3`.
3. **`smallest_number(array, count)`**: Return the smallest element.
   For `[4, -1, 7]`, return `-1`. Arrays in tasks 2 and 3 contain 1 to 100
   elements, each between -1000 and 1000.
4. **`count_digits(number)`**: Count the decimal digits using division by 10.
   For `502`, return `3`; for `0`, return `1`.
   Inputs are between 0 and 1000000.
5. **`uppercase_letter(letter)`**: Convert lowercase English letters to
   uppercase using character arithmetic, without `toupper()`.
   Leave other characters unchanged. For `'b'`, return `'B'`;
   for `'?'`, return `'?'`. Assume an ASCII-compatible character set.

## Build and test

```sh
make
./assignment0
make test
make clean
```

The starter builds but is expected to fail some tests until the TODOs are complete.
