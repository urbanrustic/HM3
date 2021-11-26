#include "add.h"
#define STEP 10


int find_largest(int *array, int length) {

    int numb = INT_MIN;
    for (int i = 0; i < length; i++) {
        if (array[i] > numb) {
            numb = array[i];
        }
    }

    return numb;
}

int radixSort(int *array, int length) {

    int i, numeric = 1;
    int *temp_sort = (int*)malloc(sizeof(int)*length); 
    int largestNum = find_largest(array, length);

    clock_t start, end;
    start = clock();

    while (largestNum / numeric > 0) {
        int quantity[10] = { 0 }; // 0, 1, 2, 4, 5, 6, 7, 8, 9
        for (i = 0; i < length; i++) {
            quantity[(array[i] / numeric) % STEP]++;
        }
        printArray(quantity, 10);
        for (i = 1; i < 10; i++) {
            quantity[i] += quantity[i - 1];
        }
        printArray(quantity, 10);
        for (i = length - 1; i >= 0; i--) {
            temp_sort[--quantity[(array[i] / numeric) % STEP]] = array[i];
        }
        printArray(temp_sort, length);
        for (i = 0; i < length; i++) {
            array[i] = temp_sort[i];
        }
        numeric *= STEP;
    }

    end = clock();
    printf("Время затраченное на сортировку: %lf\n", (double)(end-start)/(CLOCKS_PER_SEC));
    free(temp_sort);
    printArray(array, length);

    return 0;
}
