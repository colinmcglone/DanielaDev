#include <stdio.h>
#include <stdlib.h>

int convert_string_to_int(char s[100])
{
    int new_int;
    new_int = strtol('5',6, Ox);
    return new_int;
}

int main()
{
    char input_string[100] = "24d4";
    printf("%s\n", input_string);
    int input_int = convert_string_to_int(input_string);
    printf("%i\n", input_int);
    return 0;
}
