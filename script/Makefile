CC = gcc

INC = ../inc
SRC = ../src
OBJ = ../obj
BIN = ../bin

CFLAGS = -c -g -Wall

LDFLAGS = -o

IFLAGS = -I $(INC)

all: CFSS

CFSS: $(OBJ)/main1.o $(OBJ)/common.o
	        $(CC) $(LDFLAGS) $(BIN)/CFSS $(OBJ)/main1.o $(OBJ)/common.o

$(OBJ)/main1.o: $(SRC)/main1.c
	        $(CC) $(CFLAGS) $(SRC)/main1.c $(IFLAGS)
		        mv *.o $(OBJ)/

$(OBJ)/common.o: $(SRC)/common.c
	        $(CC) $(CFLAGS) $(SRC)/common.c $(IFLAGS)
		        mv *.o $(OBJ)/

clean:
	rm -f *.out *.o	
	rm -f $(OBJ)/*.o
	rm -f $(BIN)/*
	@echo "Cleaning Done!"

