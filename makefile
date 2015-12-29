CC=gcc
CFLAGS=-I.
DEPS = feeder.h multiplexer.h deMultiplexer.h queues.h externVariables.h
OBJ = feeder.o multiplexer.o deMultiplexer.o queues.o runRouter.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

runRouter: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
