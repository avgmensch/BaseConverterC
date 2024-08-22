#ifndef CONVERTER_H
#define CONVERTER_H

#include <stdint.h> // int64_t

/**
 * Remove any non base-36 characters from a string in place.
 * @param orig Pointer to the pointer to the string, that should be cleaned.
 */
void clean_base36_string_in_place(char **orig);

/** Store a number in any base from `2` to `36`. */
typedef struct Number
{
    /** Base of the number. */
    int base;
    /** Amount of digits in the number. */
    int length;
    /** String-representation of the number. */
    char *number;
} Number;

/**
 * Create a new instance `Number`. Params fill fields of the instance.
 * @param base Base of the number.
 * @param length Amount of digits (`-1` for automatic detection).
 * @param number String of characters that represent the numer in base-36.
 * @returns Pointer to new instance. Don't forget to call `del_number()`.
 */
Number *new_number(int base, int length, char *number);

/**
 * Free memory allocated by a `Number`.
 */
void del_number(Number *ptr);

/**
 * Convert a number `num` from any base to base-10.
 * @param num Number as `Number`-element.
 * @returns Base-10 representation of `num` as `int`.
 */
int64_t any_base_to_dec(Number *num);

/**
 * Calculate the amount of digits that `number_base10` will have with `new_base`.
 * @param number_base10 Base-10 representation of the number.
 * @param new_base New base the number should have.
 * @returns How many digits `number_base10` will have with `new_base` as `int`.
 */
int digits_in_new_base(int64_t number_base10, int new_base);

/**
 * Convert a number `num` from base-10 to any base.
 * @param num Number as integer (`int`) in base-10.
 * @returns Base-n representation of `num` as `Number`.
 */
Number *dec_to_any_base(int64_t num10, int new_base);

#endif