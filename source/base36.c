#include "base36.h"

// For more information on how these functions work, please refer to the ASCII table
// and how C handles characters. https://en.cppreference.com/w/cpp/language/ascii

int base36_to_dec_digit(char base36)
{
    // 0 - 9 (decimal)
    if (base36 >= '0' && base36 <= '9')
    {
        return base36 - '0';
    }
    // a (10) - z (35) (lower case)
    else if (base36 >= 'a' && base36 <= 'z')
    {
        return base36 - 'a' + 10;
    }
    // A (10) - Z (35) (upper case)
    else if (base36 >= 'A' && base36 <= 'Z')
    {
        return base36 - 'A' + 10;
    }
    // Default case
    return -1;
}

char dec_to_base36_digit(int base10)
{
    // 0 - 9 (decimal)
    if (base10 >= 0 && base10 <= 9)
    {
        return '0' + base10;
    }
    // A (10) - Z (35) (hexadecimal)
    else if (base10 >= 10 && base10 <= 35)
    {
        return 'A' + base10 - 10;
    }
    // Default case
    return (char)0;
}