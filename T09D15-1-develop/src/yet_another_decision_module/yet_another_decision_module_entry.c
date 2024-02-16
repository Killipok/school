#include "../data_libs/data_io.h"
#include "decision.h"

int main() {
    double *data = NULL;
    int n = 0;
    if (scanf("%d", &n) == 1 && n > 0) {
        data = (double *)malloc(n * sizeof(double));
    } else {
        printf("n/a");
        exit(1);
    }

    input(data, n);
    if (make_decision(data, n))
        printf("YES");
    else
        printf("NO");

    free(data);
    return 0;
}
