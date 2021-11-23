#include "add.h"


int main() {

    int *a = (int*)malloc(1*sizeof(int));
    int n = 0;
    printf("%s", "Введите длину масива: ");
    scanf("%d", &n);
    a = (int*)realloc(a, n*sizeof(int));

    int max_numb;
    printf("%s", "Введите максимальное число в массиве: ");
    scanf("%d", &max_numb);

    for (int i = 0; i < n; i++) {
        a[i] = rand()%(max_numb + 1);
    }
    
    printf("%s\n", "Массив сгенерирован");
    printArray(a, n);

    printf("%s", "Выберите метод сортировки массива( 1- Пузурьком, 2- Поразрядная ): ");
    int method_of_sort = 0;
    scanf("%d", &method_of_sort);
    switch (method_of_sort) {
    case 1:
        bubbleSort(a, n);
        break;
    case 2:
        radixSort(a, n);
        break;
    default:
        printf("%s\n", "Вы не выбрали не один из доступных методов сортировки...");
        break;
    }

    free(a);
    return 0;
}
