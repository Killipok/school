/*------------------------------------
        Здравствуй, человек!
        Чтобы получить ключ
        поработай с комментариями.
-------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
void input(int *buffer, int *length);
void output(int *buffer, int length);
int sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int length, int number, int *numbers);

/*------------------------------------
        Функция получает массив данных
        через stdin.
        Выдает в stdout особую сумму
        и сформированный массив
        специальных элементов
        (выбранных с помощью найденной суммы):
        это и будет частью ключа
-------------------------------------*/
int main() {
    int buffer[10], length, numbers[10];
    input(buffer, &length);
    int sum = sum_numbers(buffer, length);
    printf("%d \n", sum);
    int len = find_numbers(buffer, length, sum, numbers);
    output(numbers, len);
}

/*------------------------------------
        Функция должна находить
        сумму четных элементов
        с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int length) {
    int sum = 0;

    for (int i = 0; i < length; i++) {
        if (buffer[i] % 2 == 0) {
            sum = sum + buffer[i];
        }
    }

    return sum;
}

/*------------------------------------
        Функция должна находить
        все элементы, на которые нацело
        делится переданное число и
        записывает их в выходной массив.
-------------------------------------*/
int find_numbers(int *buffer, int length, int number, int *numbers) {
    int j = 0;

    for (int i = 0; i < length; i++) {
        if (buffer[i] != 0 && number % buffer[i] == 0) {
            numbers[j] = buffer[i];
            j++;
        }
    }
    return j;
}

void input(int *buffer, int *length) {
    if (scanf("%d", length) == 1) {
        for (int i = 0; i < *length; i++) {
            if (scanf("%d", &buffer[i]) != 1) {
                printf("n/a");
                exit(1);
            }
        }
    } else {
        printf("n/a");
        exit(1);
    }
}

void output(int *buffer, int length) {
    for (int i = 0; i < length - 1; i++) {
        printf("%d ", buffer[i]);
    }
    printf("%d", buffer[length - 1]);
}
