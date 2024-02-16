#include <stdio.h>

int del(int x);

int main() {
    int x;
    if (scanf("%d", &x) == 1) {
        if (x < 0) x = -x;
    } else {
        printf("n/a");
        return 1;
    }

    printf("%d", del(x));

    return 0;
}

int del(int x) {
    int result = x;
    for (int i = x - 1; i > 1; i--) {
        int temp = x;
        while (temp >= i) {
            temp -= i;
        }
        if (temp == 0 && del(i) == i) {
            result = i;
            break;
        }
    }
    return result;
}
