#include <stdio.h>
#include <stdlib.h>

int weekday(int day, int month, int year);
int sum(int size, const int vec[]);
void reverse(int size, int vec[]);
int max(int size, const int vec[]);

int main() {
    int day, month, year;
    printf("[ Enter your date of birth ]\n");
    scanf("%d %d %d", &day, &month, &year);

    if ((year < 1900) || (month > 12 || month < 1) || (day > 31 || day < 1))
        exit(1);

    printf("You were born on ");
    switch (weekday(day, month, year)) {
        case 0 : printf("Saturday."); break;
        case 1 : printf("Sunday."); break;
        case 2 : printf("Monday."); break;
        case 3 : printf("Tuesday."); break;
        case 4 : printf("Wednesday."); break;
        case 5 : printf("Thursday."); break;
        case 6 : printf("Friday."); break;
    }

    int size;
    printf("\n\n[ Enter the array size ]\n");
    scanf("%d", &size);

    int vec[size];
    printf("\n[ Input ]\n");
    for (int i = 0; i < size; i++) {
        printf("vec[%d]=", i);
        scanf("%d", &vec[i]);
    }

    printf("\n[ Sum ]\n");
    printf("%d", sum(size, vec));

    reverse(size, vec);
    printf("\n\n[ Reversed array ]\n");
    for (int i = 0; i < size; i++)
        printf("%d ", vec[i]);

    int index = max(size, vec);
    printf("\n\n[ Highest value ]\n");
    printf("Index = %d, Value = %d", index, vec[index]);
    return 0;
}

// Zeller's Congruence
int weekday(int day, int month, int year) {
    if (month == 1) {
        month = 13;
        year--;
    }
    if (month == 2) {
        month = 14;
        year--;
    }
    return (day + 13 * (month + 1) / 5 + (year % 100) + (year % 100) / 4 + (year / 100) / 4 - 2 * (year / 100)) % 7;
}

int sum(int size, const int vec[]) {
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += vec[i];
    return sum;
}

void reverse(int size, int vec[]) {
    int temp, last = size - 1;
    for (int i = 0; i <= size / 2; i++) {
        temp = vec[i];
        vec[i] = vec[last];
        vec[last] = temp;
        last -= 1;
    }
}

int max(int size, const int vec[]) {
    int index, max = vec[0];
    for (int i = 1; i < size; i++) {
        if (vec[i] > max) {
            max = vec[i];
            index = i;
        }
    }
    return index;
}