#include "data_io.h"

void input(double *data, int n) {
    for (double *p = data; p - data < n; p++) {
        if (scanf("%lf", p) != 1) {
            printf("n/a");
            exit(1);
        }
    }
}

void output(double *data, int n) {
    for (double *p = data; p - data < n; p++) {
        printf("%lf ", *p);
    }
}
