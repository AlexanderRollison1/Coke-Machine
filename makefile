#Alexander Rollison
#makefile for C++ Assignment 3
SRC = Code3.cpp
OBJ = $(SRC:.cpp=.o)
EXE = $(SRC:.cpp=.e)

HFILES = CokeMachine.h

CFLAGS = -g -std=c++11

all : $(EXE)
 
$(EXE): $(OBJ)
	g++ $(CFLAGS) $(OBJ) -o $(EXE) 

$(OBJ) : $(SRC) $(HFILES)
	g++ -c $(CFLAGS) $(SRC) -o $(OBJ) 

