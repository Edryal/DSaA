#include <stdio.h>

void avgAndSum();
void smallestOdd();
void inputEqualsAddition();
void matchingValues();
void aboveDiagonal();

/* Second variant from task sheet */
int main() {
    /* Sum and average of all elements */
    avgAndSum();

    /* Smallest 3 odd elements */
    smallestOdd();

    /* input = value + value */
    inputEqualsAddition();

    /* Values that match in 2 arrays */
    matchingValues();

    /* Values below the top-left to bottom-right diagonal */
    aboveDiagonal();
    printf("\n");
}

void avgAndSum() {
    int sum = 0;
    int vec[] = { 5, 2, 7, 6, 5, 3 };
    int length = sizeof(vec) / sizeof(vec[0]);

    printf("\n[ Sum & Avg ]\n");
    for (int i = 0; i < length; i++)
        printf("%d ", vec[i]);

    for (int i = 0; i < length; i++)
        sum += vec[i];

    printf("\nSum: %d", sum);
    printf("\nAvg: %f", (double) sum / length);
}

void smallestOdd() {
    int vec[] = { 3, 5, 1, 8, 9, 2, 7, 10, 11, 0 };
    int length = sizeof(vec) / sizeof(vec[0]);

    printf("\n\n[ Smallest 3 odd elements ]\n");
    int sort[length];
    for (int i = 0; i < length; i++)
        sort[i] = vec[i];

    int index, swap;
    for (int i = 0; i < length - 1; i++) {
        index = i;
        for (int j = i + 1; j < length; j++)
            if (sort[j] < sort[index])
                index = j;

        swap = sort[i];
        sort[i] = sort[index];
        sort[index] = swap;
    }

    for (int i = 0; i < length; i++)
        printf("%d ", vec[i]);

    printf("\nSmallest: ");
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (count > 2) break;
        if (sort[i] % 2 == 1) {
            printf("%d ", sort[i]);
            count++;
        }
    }
}

void inputEqualsAddition() {
    int vec[] = { 4, 2, 3, 5, 1, 3, 8 };
    int length = sizeof(vec) / sizeof(vec[0]);
    int input;

    printf("\n\n[ Input equals to 2 values added ]\n");
    for (int i = 0; i < length; i++)
        printf("%d ", vec[i]);

    printf("\nEnter value: ");
    scanf("%d", &input);
    for (int i = 0; i < length - 1; i++)
        for (int j = i + 1; j < length; j++)
            if (vec[i] + vec[j] == input)
                printf("\n[%d, %d] at index [%d, %d]", vec[i], vec[j], i, j);
}

void matchingValues() {
    int vec1[] = { 2, 3, 1, 7 };
    int vec2[] = { 3, 5, 8, 2, 4, 6 };
    int length1 = sizeof(vec1) / sizeof(vec1[0]);
    int length2 = sizeof(vec2) / sizeof(vec2[0]);

    printf("\n\n[ Matching values ]\n");
    for (int i = 0; i < length1; i++)
        printf("%d ", vec1[i]);

    printf("\n");
    for (int i = 0; i < length2; i++)
        printf("%d ", vec2[i]);

    printf("\nMatch: ");
    for (int i = 0; i < length1; i++)
        for (int j = 0; j < length2 - 1; j++) {
            if (vec1[i] == vec2[j])
                printf("%d ", vec1[i]);
        }
}

void belowDiagonal() {
    int vec[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    printf("\n\n[ Values above diagonal ]\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            printf("%d ", vec[i][j]);
        printf("\n");
    }

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (i < j)
                printf("\n%d at [%d, %d]", vec[i][j], i, j);
}