#ifndef BASE36_H
#define BASE36_H

/**
 * Convert a digit from `base36` to decimal.
 * @param base36 Representation of the number in base-36.
 * @returns Numeric value of `base36` in base-10.
 * @returns `-1` if `base36` is neither from 0-9, a-z nor A-Z.
 */
int base36_to_dec_digit(char base36);

/**
 * Convert a number `base10` (0-35) to a base-36 digit.
 * @param base36 Representation of the number in base-10.
 * @returns Numeric value of `base10` in base-36 (upper case).
 * @returns `(char)0` if `base10` is not from 0-35.
 */
char dec_to_base36_digit(int base10);

#endif