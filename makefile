CC = gcc
AR=ar
FLAGS = -Wall -fPIC -g

all: isort txtfind

isort.o: isort.c
	$(CC) $(FLAGS) -c isort.c

txtfind.o: txtfind.c
	$(CC) $(FLAGS) -c txtfind.c


isort: isort.o
	$(CC) $(FLAGS) -o isort isort.o

txtfind: txtfind.o
	$(CC) $(FLAGS) -o txtfind txtfind.o

clean:
	rm -f  isort txtfind *.o


.PHONY: clean all