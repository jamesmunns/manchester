CC=gcc

CFLAGS=-c -Wall

all: demo

demo: demo.o manchester.o
	$(CC) demo.o manchester.o -o demo

demo.o:
	$(CC) $(CFLAGS) src/demo.c

manchester.o:
	$(CC) $(CFLAGS) src/manchester.c

clean:
	rm *.o demo

run: all
	./demo < doc/sample_data.txt
