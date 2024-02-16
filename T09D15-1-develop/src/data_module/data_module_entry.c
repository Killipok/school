#include "../data_libs/data_io.h"
#include "data_process.h"

int main() {
    double *data = NULL;
    int n = 0;
    if (scanf("%d", &n) == 1) {
        data = (double *)malloc(n * sizeof(double));
    } else {
        printf("n/a");
        exit(1);
    }

    // Don`t forget to allocate memory !

    input(data, n);

    if (normalization(data, n))
        output(data, n);
    else
        printf("ERROR");

    free(data);
    return 0;
}
