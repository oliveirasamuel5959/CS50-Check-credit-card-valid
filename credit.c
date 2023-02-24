#include <cs50.h> // import before made libraries from CS50 Harvard course
#include <stdio.h>

void get_digits(long n);

int main(void)
{

    long n = get_long("Number: ");

    // Prints the card if its valid
    get_digits(n);
}

void get_digits(long card_num)
{
    // variable for program control
    int rem = 0, count = 1, sum = 0;
    int two_digit = 0;
    int first_num = 0, second_num = 0;


    while (card_num > 0)
    {
        rem = card_num % 10;
        card_num = card_num / 10;
        // printf("%d\n ", rem);

        /* if else condition to take the first
                and the second digit */
        if (card_num < 10 && card_num != 0)
        {
            second_num = rem;
        }
        else if (card_num < 1)
        {
            first_num = rem;
        }

        // condition to get the second-to-last digit
        if (count % 2 == 0)
        {
            rem = rem * 2;
            if (rem >= 10)
            {
                // loop to separete the digits of numbers >= 10
                while (rem > 0)
                {
                    two_digit = rem % 10;
                    rem = rem / 10;
                    sum = sum + two_digit;
                }
            }
            else
            {
                sum = sum + rem;
            }

        }
        else
        {
            sum = sum + rem;
        }

        // variable to count the number of digits
        count++;
    }

    // if remainder is equal to 0 is a valid card
    if (sum % 10 == 0)
    {
        // if else if instructions to output the credit_cards enterprises
        if (count - 1 == 15 && first_num == 3 && (second_num == 4 || second_num == 7))
        {
            printf("AMEX\n");
        }
        else if (count - 1 == 16 && (first_num == 5 && second_num != 6))
        {
            printf("MASTERCARD\n");
        }
        else if ((count - 1 == 13 || count - 1 == 16) && first_num == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
    // printf("sum: %i\nnumbers: %d\nfirst_num: %d\nsecond_num: %d\n", sum, count, first_num, second_num);

}