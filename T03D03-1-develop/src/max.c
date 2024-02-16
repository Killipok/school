#include <stdio.h>

int main() {
    int a, b;
    if (scanf("%d%d", &a, &b) == 2)
        ;
    else {
        printf("n/a");
        return 1;
    }

    if (a > b)
        printf("%d", a);
    else
        printf("%d", b);
}