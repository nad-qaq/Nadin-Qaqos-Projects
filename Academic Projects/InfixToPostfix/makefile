EXE = prog1 
CC = g++
OBJECTS = main.o token.o
LFLAGS = 
CFLAGS = 

$(EXE):		$(OBJECTS)
		$(CC) $(CFLAGS) -o $(EXE) $(OBJECTS) $(LFLAGS) 

main.o: 	main.cpp stackType.h queueType.h token.h
		$(CC) $(CFLAGS) -c main.cpp 

token.o: 	token.cpp
		$(CC) $(CFLAGS) -c token.cpp

clean:
		rm -rf $(EXE) $(OBJECTS) *~

