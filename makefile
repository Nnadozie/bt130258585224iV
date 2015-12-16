CC=gcc
CFLAGS=-I.
DEPS = feedInputQueue.h inputQueue.h
OBJ = feedInputQueue.o inputQueue.o testInputQueue.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

inputQueue: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
