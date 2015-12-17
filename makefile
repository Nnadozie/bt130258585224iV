CC=gcc
CFLAGS=-I.
DEPS = feedInputQueue.h multiplexer.h inputQueue.h externVariables.h
OBJ = feedInputQueue.o multiplexer.o inputQueue.o testInputQueue.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

inputQueue: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
