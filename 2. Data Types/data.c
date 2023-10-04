#include <stdio.h>

int main() {
    // Primitive data types
    int whole_number = 10;
    float floating_number = 10.5f; // 6 digits after floating point
    double double_number = 10.5; // 15 digits after floating point
    char letter = 'A';
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

    /*
     * %i - int
     * %f - float
     * %lf - double
     * %c - char
     * %s - string
     *
     * %.5f - only display 5 digits
    */

    printf("Integer: %i\n", whole_number);
    printf("Float: %f\n", floating_number);
    printf("Double: %lf\n", double_number);
    printf("Char: %c\n", letter);
    printf("Alphabet: %s", alphabet);
}