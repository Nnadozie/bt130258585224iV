CC = gcc
CFLAGS = -I. 

inputQueue: feedInputQueue.o inputQueue.o testInputQueue.o
	gcc -o inputQueue feedInputQueue.o inputQueue.o testInputQueue.o -I.
