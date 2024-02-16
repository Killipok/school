CC=gcc
CFLAGS=-Wall -Wextra -Werror

all: door_struct  

door_struct: dmanager_module.o 
	@$(CC) dmanager_module.o  -o  ../build/Quest_1

door_struct.o: dmanager_module.c door_struct.h
	@$(CC) $(CFLAGS) -c dmanager_module.c -D Quest_1 -o door_struct.o

rebuild: clean all

clean:
	rm -f *.o ../build/Quest_1

