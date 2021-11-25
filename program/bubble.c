#include "add.h"
#define SWAP(type, a, b) type tmp = a; a = b; b = tmp;


int printArray(int *array, int length) {

    if (length > 31) {
        return 0;
    }
    for (int i = 0; i < length; i++) {
        printf("[%d]", array[i]);
    }
    printf("\n");

    return 0;
}

int bubbleSort(int *array, int length) {

    clock_t start, end;
    start = clock();

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            if (array[i] < array[j]) {
                SWAP(int, array[i], array[j]);
            }
        }
    }

    end = clock();
    printf("Время затраченное на сортировку: %lf\n", (double)(end-start)/(CLOCKS_PER_SEC));

    printArray(array, length);

    return 0;
}
