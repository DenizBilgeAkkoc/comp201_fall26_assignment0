#include <stdio.h>
#include "myprogram.h"
#include "mylibrary.h"

int main(void)
{
    int task;
    fprintf(stderr, "Which task to run? (1-5) ");
    if (scanf("%d", &task) != 1 || task < 1 || task > 5) {
        fprintf(stderr, "Invalid task number.\n");
        return 1;
    }

    if (task == 1 || task == 4) {
        int number;
        int limit = task == 1 ? 100 : 1000000;
        fprintf(stderr, "Enter a nonnegative integer (maximum %d): ", limit);
        if (scanf("%d", &number) != 1 || number < 0 || number > limit)
            return 1;

        // A real call to the separately compiled library, even in the starter.
        // Prompts go to stderr; only the exercise answer goes to stdout.
        fprintf(stderr, "The input is %s.\n", is_even(number) ? "even" : "odd");
        if (task == 1)
            printf("%d\n", sum_of_odds(number));
        else
            printf("%d\n", count_digits(number));
    } else if (task == 2 || task == 3) {
        int count;
        int array[100];
        fprintf(stderr, "How many numbers? (1-100) ");
        if (scanf("%d", &count) != 1 || count < 1 || count > 100)
            return 1;
        fprintf(stderr, "Enter %d integers between -1000 and 1000: ", count);
        for (int i = 0; i < count; ++i) {
            if (scanf("%d", &array[i]) != 1 || array[i] < -1000 || array[i] > 1000)
                return 1;
        }
        if (task == 2)
            printf("%d\n", count_even_numbers(array, count));
        else
            printf("%d\n", smallest_number(array, count));
    } else {
        char letter;
        fprintf(stderr, "Enter one non-whitespace character: ");
        if (scanf(" %c", &letter) != 1)
            return 1;
        printf("%c\n", uppercase_letter(letter));
    }
    return 0;
}
