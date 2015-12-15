CC=gcc
CFLAGS=-I.
DEPS = feedInputQueue.h inputQueue.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

inputQueue: feedInputQueue.o inputQueue.o testInputQueue.o 
	gcc -o inputQueue feedInputQueue.o inputQueue.o testInputQueue.o  -I.
