SRC = testInputQueue.c inputQueue.c feedInputQueue.c
OBJ = testInputQueue.o inputQueue.o feedInputQueue.o
PROG = inputQueue

$(PROG) : & (OBJ)
  gcc $(OBJ) -o $(PROG)
  
$(OBJ) : $(SRC)
