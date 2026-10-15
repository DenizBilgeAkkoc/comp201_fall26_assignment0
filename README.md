# Assignment 0: Functions, Compilation, and Linking

Complete the five TODOs in `myprogram.c` until `make test` passes.
Then answer the two build questions below. You need a C compiler and Make.

## Files

| File | Responsibility |
| --- | --- |
| `main.c` | Provided input/output code that calls your functions. |
| `myprogram.c` | Your five function implementations. |
| `myprogram.h` | Declarations and contracts for your functions. |
| `mylibrary.c` | Provided implementation of the reusable `is_even()` helper. |
| `mylibrary.h` | Declaration of `is_even()`. |
| `Makefile` | Commands for compiling, linking, and testing. |
| `test/` | Inputs (`.test-in`) and expected outputs (`.test-cmp`). |

Edit only `myprogram.c`. Keep the function names and parameters unchanged.
`const int *array` means your function can read the array but must not modify
its elements. You do not need dynamic memory allocation for this assignment.

## Exercises

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

## Build and run

Run these commands inside this folder:

```sh
make
./assignment0
make test
```

The first input is the task number. Tasks 1 and 4 then read one integer;
tasks 2 and 3 read an array length followed by that many integers;
task 5 reads one non-whitespace character.

For example, input `2 5 -2 0 3 8 5` should produce `3` after implementation.
Prompts and the even/odd input description appear on standard error (`stderr`).
Only the answer appears on standard output (`stdout`), which the tests compare.

The starter builds, but its unfinished functions produce failing tests and
unused-parameter warnings. After completing the tasks, all ten tests should
pass and the build should have no warnings. Passing the examples is not a
replacement for following each function's full contract.

`make clean` removes generated object files and the executable.

## Compilation and linking exercise

Before using Make, try these equivalent commands:

```sh
gcc -std=c99 -Wall -Wextra -c main.c -o main.o
gcc -std=c99 -Wall -Wextra -c myprogram.c -o myprogram.o
gcc -std=c99 -Wall -Wextra -c mylibrary.c -o mylibrary.o
gcc main.o myprogram.o mylibrary.o -o assignment0
```

The first three commands **compile** source files into object files (`.o`).
The last command **links** them into an executable. A header declares a
function's name and types; including it does not supply the function's body.
That body is compiled from `mylibrary.c` and supplied through `mylibrary.o`.
Do not include `.c` files with `#include`.

`main.c` already calls `is_even()` to describe numeric input. Your first two
exercises reuse the same helper for their calculations.

Answer these two questions in your submission:

1. What does `-c` do, and which files does each compilation command produce?
2. Try `gcc main.o myprogram.o -o assignment0`. Copy the relevant error and
   explain why including `mylibrary.h` does not prevent it. Restore the build
   by running the complete linking command above.

Submit your completed `myprogram.c` and your two written answers.
