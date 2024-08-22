#include <stdio.h> // printf
#include "converter.h"

// TODO: remove
#include <stdlib.h>

int main()
{
    char *invalid_str = (char*)malloc(sizeof(char)*6);
    invalid_str[0] = '<';
    invalid_str[1] = 'F';
    invalid_str[2] = ',';
    invalid_str[3] = 'F';
    invalid_str[4] = '.';
    invalid_str[5] = '\0';
    clean_base36_string_in_place(&invalid_str);
    printf("%s\n", invalid_str);
    return 0;
}