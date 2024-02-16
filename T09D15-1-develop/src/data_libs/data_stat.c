#include "data_stat.h"

double max(double *data, int n) {
    double max = *data;

    for (double *p = data; p - data < n; p++) {
        if (*p > max) {
            max = *p;
        }
    }
    return max;
}

double min(double *data, int n) {
    double max = *data;

    for (double *p = data; p - data < n; p++) {
        if (*p < max) {
            max = *p;
        }
    }
    return max;
}

double mean(double *data, int n) {
    int temp = 0;

    for (double *p = data; p - data < n; p++) {
        temp += *p;
    }
    return (double)(temp) / (double)(n);
}

double variance(double *data, int n) {
    double current_mean = mean(data, n);
    double temp = 0;
    for (double *p = data; p - data < n; p++) {
        temp += (*p - current_mean) * (*p - current_mean);
    }
    return temp / (double)n;
}

void sort(double *data, int n) {
    double tmp = 0;

    for (double i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (data[j] > data[j + 1]) {
                tmp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = tmp;
                tmp = data[j + 1];
            }
        }
    }
}