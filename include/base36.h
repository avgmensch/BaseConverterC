#ifndef BASE36_H
#define BASE36_H

/**
 * Convert a number `base36` to a decimal number.
 * @param base36 Representation of the number in base-36.
 * @returns Numeric value of `base36` in base-10.
 * @returns `-1` if `base36` is neither from 0-9, a-z nor A-Z.
 */
int base36_to_dec(char base36);

/**
 * Convert a number `base10` to a base-36 number.
 * @param base36 Representation of the number in base-10.
 * @returns Numeric value of `base10` in base-36 (upper base).
 * @returns `(char)0` if `base10` is not from 0-35.
 */
char dec_to_base36(int base10);

#endif