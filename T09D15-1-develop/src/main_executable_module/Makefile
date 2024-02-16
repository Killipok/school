CC=gcc
CFLAGS=-Wall -Wextra -Werror 

all: main_executable_module 

main_executable_module: main_executable_module.o data_io.o data_process.o decision.o data_stat.o 
	$(CC) main_executable_module.o data_io.o data_process.o decision.o data_stat.o  -o  ../../build/Quest_3

build_with_static:main_executable_module.o data_io.o data_process.o decision.o data_stat.a 
	$(CC) main_executable_module.o data_io.o data_process.o decision.o data_stat.a  -o  ../../build/Quest_5

build_with_dynamic: main_executable_module.o data_io.o decision.o data_stat.o data_process.so
	$(CC)    main_executable_module.o data_io.o decision.o data_stat.o data_process.so -Wl,-rpath,.  -o  ../../build/Quest_6 

main_executable_module.o: main_executable_module.c ../data_libs/data_io.h ../data_module/data_process.h ../yet_another_decision_module/decision.h 
	$(CC) $(CFLAGS) -c main_executable_module.c 

data_io.o: ../data_libs/data_io.c ../data_libs/data_io.h
	$(CC) $(CFLAGS) -c ../data_libs/data_io.c 

data_process.so:
	$(CC) $(CFLAGS) -fPIC -c ../data_module/data_process.c 
	$(CC) $(CFLAGS) -fPIC -c ../data_libs/data_stat.c 
	$(CC) -shared -o data_process.so data_process.o data_stat.o
	

data_process.o: ../data_module/data_process.c ../data_module/data_process.h ../data_libs/data_stat.h 
	$(CC) $(CFLAGS) -c ../data_module/data_process.c 

decision.o: ../yet_another_decision_module/decision.c ../yet_another_decision_module/decision.h ../data_libs/data_stat.h
	$(CC) $(CFLAGS) -c ../yet_another_decision_module/decision.c 



data_stat.a: data_stat.o
	ar rc data_stat.a data_stat.o

data_stat.o: ../data_libs/data_stat.c ../data_libs/data_stat.h
	$(CC) $(CFLAGS) -c ../data_libs/data_stat.c 

rebuild: clean main_executable_module

clean:
	rm -f *.o *.a *.so ../../build/*


