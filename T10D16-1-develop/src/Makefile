CC=gcc
CFLAGS=-Wall -Wextra -Werror

all: strlen_tests strcmp_tests strcpy_tests strcat_tests strchr_tests clean

strlen_tests: s21_string_test_strlen.o s21_string.o 
	@$(CC) s21_string_test_strlen.o s21_string.o -o  ../build/Quest_1

strcmp_tests: s21_string_test_strcmp.o s21_string.o 
	@$(CC) s21_string_test_strcmp.o s21_string.o -o  ../build/Quest_2

strcpy_tests: s21_string_test_strcpy.o s21_string.o 
	@$(CC) s21_string_test_strcpy.o s21_string.o -o  ../build/Quest_3

strcat_tests: s21_string_test_strcat.o s21_string.o 
	@$(CC) s21_string_test_strcat.o s21_string.o -o  ../build/Quest_4

strchr_tests: s21_string_test_strchr.o s21_string.o 
	@$(CC) s21_string_test_strchr.o s21_string.o -o  ../build/Quest_5



s21_string_test_strlen.o: s21_string_test.c s21_string.h
	@$(CC) $(CFLAGS) -c s21_string_test.c -D Quest_1 -o s21_string_test_strlen.o

s21_string_test_strcmp.o: s21_string_test.c s21_string.h
	@$(CC) $(CFLAGS) -c s21_string_test.c -D Quest_2 -o s21_string_test_strcmp.o

s21_string_test_strcpy.o: s21_string_test.c s21_string.h
	@$(CC) $(CFLAGS) -c s21_string_test.c -D Quest_3 -o s21_string_test_strcpy.o

s21_string_test_strcat.o: s21_string_test.c s21_string.h
	@$(CC) $(CFLAGS) -c s21_string_test.c -D Quest_4 -o s21_string_test_strcat.o

s21_string_test_strchr.o: s21_string_test.c s21_string.h
	@$(CC) $(CFLAGS) -c s21_string_test.c -D Quest_5 -o s21_string_test_strchr.o

rebuild: clean all

clean:
	rm -f *.o