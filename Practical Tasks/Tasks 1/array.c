#include <stdio.h>
#include <math.h>
#include <string.h>

void evenNumbers();
void oddNumbers();
int factorial(int number);
double triangleArea(double a, double b, double c);
int minValue(int size, const int vec[]);
int maxValue(int size, const int vec[]);
void ascSort(int size, const int vec[]);
void addAtTheStart(int size, int vec[]);
void addAtTheEnd(int size, int vec[]);
int countVowels(char string[]);
void reverseString(char string[]);

int main() {
    /* Control Structures */
    printf("[ Even numbers from 1 to 100 ]\n");
    evenNumbers();

    printf("\n\n[ Odd numbers from 1 to 100 ]\n");
    oddNumbers();
    /* Functions */
    int number;
    printf("\n\n[ Enter a number ]\n");
    scanf("%d", &number);
    printf("%d! = %d", number, factorial(number));

    double a, b, c;
    printf("\n\n[ Input the sides of a triangle ]\n");
    scanf("%lf %lf %lf", &a, &b, &c);
    printf("Area = %lf", triangleArea(a, b, c));

    /* Arrays */
    int size;
    printf("\n\n[ Enter the array size ]\n");
    scanf("%d", &size);

    int vec[30];
    printf("\n[ Enter %d values for the array ]\n", size);
    for (int i = 0; i < size; i++)
        scanf("%d", &vec[i]);

    printf("\n[ Add value at the start ]\n");
    addAtTheStart(size++, vec);
    printf("Array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", vec[i]);

    printf("\n\n[ Add value at the end ]\n");
    addAtTheEnd(size, vec);
    size++;
    printf("Array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", vec[i]);

    printf("\n\nMin value = %d\n", minValue(size, vec));
    printf("Max value = %d\n", maxValue(size, vec));
    printf("Asc order: ");
    ascSort(size, vec);

    /* Strings */
    char string[30];
    printf("\n\n[ Enter a string ]\n");
    scanf("%s", string);
    printf("Number of vowels = %d\n", countVowels(string));
    printf("Reversed: ");
    reverseString(string);
}

void evenNumbers() {
    for (int i = 1; i < 101; i++) {
        if (i % 2 == 0)
            printf("%d ", i);
        if (i == 52)
            printf("\n");
    }
}

void oddNumbers() {
    for (int i = 1; i < 100; i++) {
        if (i % 2 != 0)
            printf("%d ", i);
        if (i == 51)
            printf("\n");
    }
}

int factorial(int number) {
    if (number < 0)
        return -1;
    if (number < 3)
        return number;
    return number * factorial(number - 1);
}

// Heron's formula
double triangleArea(double a, double b, double c) {
    // Triangle inequality
    if (!(a + b > c && b + c > a && c + a > b))
        return -1;

    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int minValue(int size, const int vec[]) {
    int minValue = vec[0];
    for (int i = 1; i < size; i++)
        if (vec[i] < minValue)
            minValue = vec[i];
    return minValue;
}

int maxValue(int size, const int vec[]) {
    int maxValue = vec[0];
    for (int i = 1; i < size; i++)
        if (vec[i] > maxValue)
            maxValue = vec[i];
    return maxValue;
}

// Selection sort
void ascSort(int size, const int vec[]) {
    int sort[size];
    for (int i = 0; i < size; i++)
        sort[i] = vec[i];

    int index, swap;
    for (int i = 0; i < size - 1; i++) {
        index = i;
        for (int j = i + 1; j < size; j++)
            if (sort[j] < sort[index])
                index = j;

        // Swap current value with index of the smallest value
        swap = sort[i];
        sort[i] = sort[index];
        sort[index] = swap;
    }

    for (int i = 0; i < size; i++)
        printf("%d ", sort[i]);
}

void addAtTheStart(int size, int vec[]) {
    int value;
    scanf("%d", &value);
    vec[size] = vec[size - 1];
    for (int i = size - 1; i > 0; i--)
        vec[i] = vec[i - 1];
    vec[0] = value;
}

void addAtTheEnd(int size, int vec[]) {
    int value;
    scanf("%d", &value);
    vec[size] = value;
}

int countVowels(char string[]) {
    int count = 0;
    char vowels[] = "aeiou";
    for (int i = 0; i < strlen(string); i++)
        for (int j = 0; j < strlen(vowels); j++)
            if (string[i] == vowels[j])
                count++;
    return count;
}

void reverseString(char string[]) {
    unsigned int length = strlen(string);
    char reversed[length];
    for (int i = 0; i < length; i++)
        reversed[i] = string[length - i - 1];
    printf("%s", reversed);
}