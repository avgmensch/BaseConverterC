#include <stdio.h> // printf
#include "converter.h"

int main()
{
    printf("FROM | TO | BACK\n");
    for (int i = 10; i <= 270; i+=10)
    {
        printf("%i | ", i);
        Number *base_16 = dec_to_any_base(i, 16);
        printf("%s | ", base_16->number);
        int64_t base_10 = any_base_to_dec(base_16);
        printf("%li\n", base_10);
        del_number(base_16);
    }
    return 0;
}