#include <stdio.h>
#include <stdlib.h>

void shiftLeft(int arr[], int size, int n);
void input(int *buffer, int *length);
void output(int *buffer, int length);
int main() {
    int array[10];
    int n, length;
    input(array, &length);
    if (scanf("%d", &n) == 1) {
        shiftLeft(array, length, n);

        output(array, length);
    } else
        printf("n/a");

    return 0;
}

void shiftLeft(int arr[], int size, int n) {
    for (int i = 0; i < n; i++) {
        int temp = arr[0];  // Сохраняем первый элемент
        for (int j = 0; j < size - 1; j++) {
            arr[j] = arr[j + 1];  // Смещаем все элементы на одну позицию влево
        }
        arr[size - 1] = temp;  // Помещаем сохраненный элемент в конец
    }
}

void input(int *buffer, int *length) {
    scanf("%d", length);
    for (int i = 0; i < *length; i++) {
        if (scanf("%d", &buffer[i]) != 1) {
            printf("n/a");
            exit(1);
        }
    }
}

void output(int *buffer, int length) {
    for (int i = 0; i < length - 1; i++) {
        printf("%d ", buffer[i]);
    }
    printf("%d", buffer[length - 1]);
}
