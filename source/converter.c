#include <stdlib.h> // malloc NULL EXIT_FAILURE free
#include <math.h> // pow log
#include <string.h> // strlen
#include "converter.h"
#include "base36.h"

Number *new_number(int base, int length, char *number)
{
    Number *ptr = (Number*)malloc(sizeof(Number));
    if (ptr == NULL) exit(EXIT_FAILURE);
    ptr->base = base;
    if (length == -1) ptr->length = strlen(number);
    else ptr->length = length;
    ptr->number = number;
    return ptr;
}

void del_number(Number *ptr)
{
    free(ptr->number);
    free(ptr);
}

int64_t any_base_to_dec(Number *num)
{
    int digit_worth = num->length - 1;
    int64_t result = 0;
    for (int i = 0; i < num->length; i++)
        result += base36_to_dec_digit(num->number[i]) * pow(num->base, digit_worth--);
    return result;
}

int digits_in_new_base(int64_t number_base10, int new_base)
{
    if (number_base10 == 0) return 1;
    return (int)(log(number_base10) / log(new_base)) + 1;
}

Number *dec_to_any_base(int64_t num10, int new_base)
{
    int length = digits_in_new_base(num10, new_base);
    char *char_array = (char*)malloc(sizeof(char) * (length + 1));
    if (char_array == NULL) exit(EXIT_FAILURE);
    char_array[length] = '\0';
    Number *num_n = new_number(new_base, length, char_array);
    while (num10 != 0)
    {
        int64_t remainder_b10 = num10 % new_base;
        num_n->number[--length] = dec_to_base36_digit(remainder_b10);
        num10 /= new_base;
    }
    return num_n;
}