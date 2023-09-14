
EXE = pancake 
CC = g++
OBJECTS = main.o 
LFLAGS = 
CFLAGS = 

$(EXE):		$(OBJECTS)
		$(CC) $(CFLAGS) -o $(EXE) $(OBJECTS) $(LFLAGS) 

main.o: 	main.cpp stackType.h queueType.h
		$(CC) $(CFLAGS) -c main.cpp 

clean:
		rm -rf $(EXE) $(OBJECTS) *~

