#include <stdio.h>

int main() {
    double a, b;
    if (scanf("%lf %lf", &a, &b) == 2)
        ;
    else {
        printf("n/a");
        return 1;
    }

    if (a * a + b * b < 25)
        printf("GOTCHA");
    else
        printf("MISS");
    return 0;
}
