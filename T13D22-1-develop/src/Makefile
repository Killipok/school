CC=gcc
CFLAGS=-Wall -Wextra -Werror

all: cipher

cipher: cipher.o 
	@$(CC)  cipher.o -o  ../build/cipher

cipher.o: cipher.c 
	@$(CC) $(CFLAGS) -c cipher.c -D cipher -o cipher.o


rebuild: clean all

clean:
	rm -f *.o ../build/cipher