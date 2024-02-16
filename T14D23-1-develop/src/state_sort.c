#include <dirent.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define FILENAME "../datasets/door_state_2"

struct State {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    int status;
    int code;
};

bool read_state(FILE *file, struct State *state) { return fread(state, sizeof(struct State), 1, file) == 1; }

bool write_state(FILE *file, const struct State *state) {
    return fwrite(state, sizeof(struct State), 1, file) == 1;
}

void printf_state(struct State *state);
void printf_content(FILE *file);
void bubble_sort_file(FILE *file);

void add_content(FILE *file);

int main() {
    FILE *file = fopen(FILENAME, "rb+");
    if (file == NULL) {
        printf("n/a\n");
        return 1;
    }
    int expression;
    scanf("%d", &expression);
    switch (expression) {
        case 0:
            printf_content(file);
            break;
        case 1:
            bubble_sort_file(file);
            printf_content(file);
            break;
        case 2:
            add_content(file);
            bubble_sort_file(file);
            printf_content(file);
            break;

        default:
            printf("n/a");
            break;
    }

    fclose(file);
    return 0;
}

void printf_state(struct State *state) {
    printf("%d-%02d-%02d %02d:%02d:%02d %d %d\n", state->year, state->month, state->day, state->hour,
           state->minute, state->second, state->status, state->code);
}

void printf_content(FILE *file) {
    struct State state;
    rewind(file);
    while (read_state(file, &state)) {
        printf_state(&state);
    }
}

void bubble_sort_file(FILE *file) {
    struct State current_state, next_state;
    bool swapped;
    long state_count = 0;

    fseek(file, 0, SEEK_END);
    state_count = ftell(file) / sizeof(struct State);

    do {
        swapped = false;
        rewind(file);
        read_state(file, &current_state);
        while (read_state(file, &next_state)) {
            if (next_state.year < current_state.year ||
                (next_state.year == current_state.year && next_state.month < current_state.month) ||
                (next_state.year == current_state.year && next_state.month == current_state.month &&
                 next_state.day < current_state.day) ||
                (next_state.year == current_state.year && next_state.month == current_state.month &&
                 next_state.day == current_state.day && next_state.hour < current_state.hour) ||
                (next_state.year == current_state.year && next_state.month == current_state.month &&
                 next_state.day == current_state.day && next_state.hour == current_state.hour &&
                 next_state.minute < current_state.minute) ||
                (next_state.year == current_state.year && next_state.month == current_state.month &&
                 next_state.day == current_state.day && next_state.hour == current_state.hour &&
                 next_state.minute == current_state.minute && next_state.second < current_state.second) ||
                (next_state.year == current_state.year && next_state.month == current_state.month &&
                 next_state.day == current_state.day && next_state.hour == current_state.hour &&
                 next_state.minute == current_state.minute && next_state.second == current_state.second &&
                 next_state.status < current_state.status)) {
                fseek(file, -2 * sizeof(struct State), SEEK_CUR);
                write_state(file, &next_state);
                write_state(file, &current_state);
                swapped = true;
            }
            current_state = next_state;
        }
        state_count--;
    } while (swapped && state_count > 1);
}

void add_content(FILE *file) {
    struct State new_state;
    scanf("%d-%02d-%02d %02d:%02d:%02d %d %d\n", &new_state.year, &new_state.month, &new_state.day,
          &new_state.hour, &new_state.minute, &new_state.second, &new_state.status, &new_state.code);

    fseek(file, 0, SEEK_END);
    write_state(file, &new_state);
}
