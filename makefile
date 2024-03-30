CC = g++ # Compiler is g++
CFLAGS = -c -Wall -Wextra # Compile with all warnings and extra warnings

default: all # Typing "make" into console does default action, which is everything / all

all: movie

movie: library.o main.o # Links object files together into executable
	$(CC) -Wall -Wextra -o movie library.o main.o

library: library.cpp library.h  # compiles phonebook into object code
	$(CC) $(CFLAGS) library.cpp

main.o: main.cpp library.h  # compiles main into object code
	$(CC) $(CFLAGS) main.cpp

clean:
	$(RM) movie *.o *~
