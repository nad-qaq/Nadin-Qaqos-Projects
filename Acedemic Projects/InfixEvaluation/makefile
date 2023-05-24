EXE = prog5 
CC = g++
OBJECTS = main.o token.o ch12-1.o
LFLAGS = 
CFLAGS = 

$(EXE):		$(OBJECTS)
		$(CC) $(CFLAGS) -o $(EXE) $(OBJECTS) $(LFLAGS) 

main.o: 	main.cpp  token.h 
		$(CC) $(CFLAGS) -c main.cpp token.cpp

token.o: 	token.cpp
		$(CC) $(CFLAGS) -c token.cpp

ch12-1.o:	ch12-1.cpp 
		$(CC) $(CFLAGS) -c ch12-1.cpp

clean:
		rm -rf $(EXE) $(OBJECTS) *~

