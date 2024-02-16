#include <math.h>
#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == 0) {
        output(data, n);
        output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));
    } else
        printf("n/a");
    return 0;
}

int input(int *a, int *n) {
    if (scanf("%d", n) == 1 && *n <= NMAX && *n > 0) {
        for (int *p = a; p - a < *n; p++) {
            if (scanf("%d", p) != 1) {
                return 1;
            }
        }

    } else
        return 1;
    return 0;
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        printf("%d ", *p);
    }
}

void squaring(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        *p *= *p;
    }
}

int max(int *a, int n) {
    int max = *a;

    for (int *p = a; p - a < n; p++) {
        if (*p > max) {
            max = *p;
        }
    }
    return max;
}

int min(int *a, int n) {
    int max = *a;

    for (int *p = a; p - a < n; p++) {
        if (*p < max) {
            max = *p;
        }
    }
    return max;
}

double mean(int *a, int n) {
    int temp = 0;

    for (int *p = a; p - a < n; p++) {
        temp += *p;
    }
    return (double)(temp) / (double)(n);
}

double variance(int *a, int n) {
    double current_mean = mean(a, n);
    double temp = 0;
    for (int *p = a; p - a < n; p++) {
        temp += pow(*p - current_mean, 2);
    }
    return temp / (double)n;
}

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("\n%d %d %lf %lf", max_v, min_v, mean_v, variance_v);
}
