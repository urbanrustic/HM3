# Homework_3
<h1 align="center">Radix and Bubble sort</h1>
<h2 align="center">Поставленная задача</h2>
<p>Написать на языке программирования Си(С) Поразрядную и Пузырькуовую сортировку.</p>
Провести тесты сравнить скорость работы.
<i>Выволнить задание на языке программирования Си(С).</i>
<h2 align="center">Описание</h2>
<p>Поразрядная сортировка —  исходно предназначена для сортировки целых чисел, записанных цифрами. Но так как в памяти компьютеров любая информация записывается целыми числами, алгоритм пригоден для сортировки любых объектов, запись которых можно поделить на «разряды», содержащие сравнимые значения. При этом разряды могут обрабатываться в противоположных направлениях - от младших к старшим или наоборот.</p>
<h5>Алгоритм:</h5>
<p>Для начала находится самое большое число в данном массиве для определения количества разрядов. Далее  сравнение производится поразрядно: сначала сравниваются значения малого разряда (у числа 567 это будет 7) , и элементы возвращаются  в основной массив в том порядке, затем сравниваются значения следующего разряда (у числа 567 это будет 6), соседнего, и элементы либо упорядочиваются по результатам сравнения значений этого разряда внутри образованных на предыдущем проходе групп, либо переупорядочиваются в целом, но сохраняя относительный порядок в массиве, достигнутый при предыдущей сортировке. И эта операция проводится для всех разрядов.</p>
<h4>Подключаемый файл add.h</h4>


```c

#ifndef add_h
#define add_h

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int bubbleSort(int *array, int length);
int radixSort(int *array, int length);
int printArray(int *array, int length);

#endif //add_h
```


<h4>Функция для поиска наибольшего числа </h4>


```c

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

```


<h4>Представление поразрядной сортировки</h4>


```c
int radixSort(int *array, int length) {

    int i, numeric = 1;
    int *temp_sort = (int*)malloc(sizeof(int)*length); 
    int largestNum = find_largest(array, length);

    clock_t start, end;
    start = clock();

    while (largestNum / numeric > 0) {
        int quantity[10] = { 0 };
        for (i = 0; i < length; i++) {
            quantity[(array[i] / numeric) % STEP]++;
        }

        for (i = 1; i < 10; i++) {
            quantity[i] += quantity[i - 1];
        }

        for (i = length - 1; i >= 0; i--) {
            temp_sort[--quantity[(array[i] / numeric) % STEP]] = array[i];
        }

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
```


![1024](https://user-images.githubusercontent.com/81951508/143544927-b922e4ed-79bb-4fb9-bcf6-c1fe0918f20c.jpeg)

<p>Пузырьковая сортировка одна из самых простейших сортировок</p>
<h5>Алгоритм:</h5>
<p>Осуществляется многократный прогон по массиву - сначала от первого до последнего элемента, потом от первого до предпоследнего, потом от первого до третьего с конца и т.д. При прогоне сравниваются соседние элементы. Если они не упорядочены относительно друг друга, то меняются местами. В результате при каждом прогоне в конец текущего подмассива всплывает наибольший (наименьший) элемент.
</p>
<h4>Представление пузырьковой сортировки</h4>


```c
#include "add.h"
#define SWAP(type, a, b) type tmp = a; a = b; b = tmp;


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
```


![sortirovka2](https://user-images.githubusercontent.com/81951508/143545978-95f6014e-79e7-405b-914f-99dd815147b5.jpg)
<h4>Функция вывода массива</h4>


```c
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
```


<h4>Основной файл</h4>


```c
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
```


<h3 align="center">Для компиляции программы ввести make. После ввести либо make test либо ./key.out</h3>
