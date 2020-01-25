CC=gcc
AR=ar
OBJECTS_MAIN=main.o
FLAGS= -Wall -g


all: frequency

frequency: $(OBJECTS_MAIN) libfrequency.a
	$(CC) $(FLAGS) -o frequency $(OBJECTS_MAIN) libfrequency.a

libfrequency.a: frequency.o
	$(AR) -rcs libfrequency.a frequency.c

frequency.o:frequency.c frequency.h
	$(CC) $(FLAGS) -c frequency.c

main.o: main.c frequency.h
	$(CC) $(FLAGS) -c main.c

.PHONY: clean

clean:
	rm *.a *.o frequency