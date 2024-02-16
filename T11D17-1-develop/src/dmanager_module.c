#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(struct door *doors);
void sorting(struct door *doors);
void output(struct door *doors);
void status_zero(struct door *doors);

int main() {
    struct door doors[DOORS_COUNT];

    initialize_doors(doors);
    sorting(doors);
    status_zero(doors);
    output(doors);

    return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door *doors) {
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}

void sorting(struct door *doors) {
    int tmp = 0;

    for (int i = 0; i < DOORS_COUNT - 1; ++i) {
        for (int j = 0; j < DOORS_COUNT - i - 1; ++j) {
            if (doors[j].id > doors[j + 1].id) {
                tmp = doors[j].id;
                doors[j].id = doors[j + 1].id;
                doors[j + 1].id = tmp;
                tmp = doors[j + 1].id;
            }
        }
    }
}

void status_zero(struct door *doors) {
    for (int i = 0; i < DOORS_COUNT; ++i) {
        doors[i].status = 0;
    }
}

void output(struct door *doors) {
    for (int i = 0; i < DOORS_COUNT; ++i) {
        printf("%d, %d\n", doors[i].id, doors[i].status);
    }
}
