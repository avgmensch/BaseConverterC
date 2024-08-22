#include <stdlib.h> // malloc free memcpy
#include <string.h> // strlen
#include "base36.h"

// For more information on how these functions work, please refer to the ASCII table
// and how C handles characters. https://en.cppreference.com/w/cpp/language/ascii

bool digit_is_base36(char s)
{
    return ((s >= '0' && s <= '9') || (s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z'));
}

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

char *sanitize_base36_string(char *orig)
{
    int orig_length = strlen(orig);
    size_t orig_size = sizeof(char) * orig_length;
    char *sanitized = (char*)malloc(orig_size);
    if (sanitized == NULL) exit(EXIT_FAILURE);
    int sanitized_length = 0;
    for (int i = 0; i < orig_length; i++)
    {
        char c = orig[i];
        if (!digit_is_base36(c)) continue;
        sanitized[sanitized_length++] = c;
    }
    char *truncated = (char*)malloc(sizeof(char) * (sanitized_length + 1));
    if (truncated == NULL) exit(EXIT_FAILURE);
    memcpy(truncated, sanitized, sanitized_length);
    truncated[sanitized_length] = '\0';
    free(sanitized);
    return truncated;
}