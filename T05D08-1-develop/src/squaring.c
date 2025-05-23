#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == 0) {
        squaring(data, n);
        output(data, n);
    } else
        printf("n/a");

    return 0;
}

int input(int *a, int *n) {
    if (scanf("%d", n) == 1 && *n <= NMAX && *n > 0) {
        for (int *p = a; p - a < *n; p++) {
            scanf("%d", p);
        }
    } else
        return 1;
    return 0;
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        printf(" %d", *p);
    }
}

void squaring(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        *p *= *p;
    }
}
