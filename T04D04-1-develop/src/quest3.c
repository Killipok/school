#include <stdio.h>

int fibbonachi(int a);

int main() {
    int a;

    if (scanf("%d", &a) == 1 && a > 0) {
        printf("%d", fibbonachi(a));
    } else {
        printf("n/a");
    }
    return 0;
}

int fibbonachi(int a) {
    if (a == 1 || a == 2) return 1;
    return (fibbonachi(a - 1) + fibbonachi(a - 2));
}