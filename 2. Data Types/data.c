#include <stdio.h>
#include <ctype.h>
#include <string.h>

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
     * %lf - double (long float)
     * %c - char
     * %s - string
     *
     * %.5f - only display 5 digits
    */

    printf("[ Output ]");
    printf("Integer: %i\n", whole_number);
    printf("Float: %f\n", floating_number);
    printf("Double: %lf\n", double_number);
    printf("Char: %c\n", letter);
    printf("Alphabet: %s\n", alphabet);

    // Input
    char message[20];
    printf("\n[ Input ]\n");
    scanf(" %s", message);

    for (int i = 0; i < strlen(message); i++) {
        char a = message[i];
        putchar(toupper(message[i]));
        message[i] = a;
    }
}