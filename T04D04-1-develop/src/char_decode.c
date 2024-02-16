#include <stdio.h>

void codder();
void decoder();

int main() {
    int command;
    if (scanf("%d", &command) == 1 && (command == 0 || command == 1)) {
        if (command == 0) {
            codder();

        } else
            decoder();
    } else
        printf("n/a");

    return 0;
}

void codder() {
    char temp, space;
    scanf("%c", &space);
    while (scanf("%c", &temp) == 1 && scanf("%c", &space) == 1 && space != 10) {
        if (space != ' ') {
            printf("n/a");
            return;
        }
        printf("%X%c", temp, space);
    }
    printf("%X%c", temp, space);
}

void decoder() {
    char space;
    int number;
    scanf("%c", &space);
    while (scanf("%X", &number) == 1 && scanf("%c", &space) == 1 && space != 10 && number < 256) {
        if (space != ' ') {
            printf("n/a");
            return;
        }
        printf("%c%c", number, space);
    }
    if (number < 256)
        printf("%c", number);
    else
        printf("n/a");
}