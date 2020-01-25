
all: freqlib.so frequency

frequency: main.o freqlib.so
	gcc -Wall -o frequency main.o ./freqlib.so
freqlib: freqlib.so

freqlib.so: frequency.o
	gcc -shared -o freqlib.so frequency.o

main.o: main.c frequency.h
	gcc -Wall -fPIC -g -c main.c
.PHONY: clean all freqlib

frequency.o: frequency.c frequency.h
	gcc -Wall -fPIC -g -c frequency.c

clean: 
	rm -f *.o *.so frequency