#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

void fill_array(int *array, int size);
void print_array(int array[], int size);
void sorting(int *array, int size);
void fast_sort(int *array, int size);

int main() {
    int array[SIZE] = {0};
    fill_array(array, SIZE);
    sorting(array, SIZE);
    print_array(array, SIZE);

    return 0;
}

void fill_array(int *array, int size) {
    for (int i = 0; i < size; i++) {
        if (scanf("%d", &array[i]) != 1) {
            printf("n/a");
            exit(1);
        }
    }
}

void print_array(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        printf("%d ", array[i]);
    }
    printf("%d", array[size - 1]);
}

void sorting(int *array, int size) {
    int tmp = 0;

    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
                tmp = array[j + 1];
            }
        }
    }
}
