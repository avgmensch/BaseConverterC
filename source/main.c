#include <stdio.h>
#include "base36.h"

int main()
{
    printf("FROM | BASE-36 | BASE-10\n");
    for (int i = 0; i <= 35; i++)
    {
        printf("%4i | ", i);
        char base36 = dec_to_base36(i);
        printf("      %c | ", base36);
        int dec = base36_to_dec(base36);
        printf("%7i\n", dec);
    }
    return 0;
}