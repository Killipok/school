CC=gcc
CFLAGS=-Wall -Wextra -Werror

all: state_sort

state_sort: state_sort.o 
	@$(CC)  state_sort.o -o  ../build/Quest_1

cipher.o: cipher.c 
	@$(CC) $(CFLAGS) -c state_sort.c -D Quest_1 -o state_sort.o


rebuild: clean all

clean:
	rm -f *.o ../build/Quest_1