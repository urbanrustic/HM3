#include "add.h"


int find_largest(int array[], int length) {

    int numb = INT_MIN;
    for (int i = 0; i < length; i++) {
        if (array[i] > numb) {
            numb = array[i];
        }
    }

    return numb;
}

int radixSort(int array[], int length) {

    int i, temp_sort[length], numeric = 1;
    int largestNum = find_largest(array, length);

    clock_t start, end;
    start = clock();

    while (largestNum / numeric > 0) {
        int quantity[10] = { 0 };
        for (i = 0; i < length; i++) {
            quantity[(array[i] / numeric) % 10]++;
        }
        // printArray(bucket, 10);
        // printf("\n");
        for (i = 1; i < 10; i++) {
            quantity[i] += quantity[i - 1];
        }
        // printArray(bucket, 10);
        // printf("\n");
        for (i = length - 1; i >= 0; i--) {
            temp_sort[--quantity[(array[i] / numeric) % 10]] = array[i];
        }
        // printArray(semiSorted, length);
        // printf("\n");
        for (i = 0; i < length; i++) {
            array[i] = temp_sort[i];
        }
        numeric *= 10;
    }

    end = clock();
    printf("Время затраченное на сортировку: %lf\n", (double)(end-start)/(CLOCKS_PER_SEC));

    printArray(array, length);

    return 0;
}
