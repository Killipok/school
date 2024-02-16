#include <stdio.h>

int sum(int a, int b);

int main() {
    int a, b;

    if (scanf("%d %d", &a, &b) == 2)
        ;
    else {
        printf("n/a");
        return 1;
    }
    sum((int)a, (int)b);
    return 0;
}

int sum(int a, int b) {
    int sum = a + b;
    int diff = a - b;
    int multi = a * b;
    printf("%d %d %d ", sum, diff, multi);
    if (b == 0)
        printf("n/a");
    else
        printf("%d", a / b);
    return 0;
}