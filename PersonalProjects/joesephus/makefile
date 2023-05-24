EXE = prog4
CC = g++
OBJECTS =  main.o 
LFLAGS = 
CFLAGS = 

$(EXE):	$(OBJECTS)
		$(CC) $(CFLAGS) -o $(EXE) $(OBJECTS) $(LFLAGS) 


main.o: 	main.cpp josephus.h exception.h 
		$(CC) $(CFLAGS) -c main.cpp 

clean:
		rm -rf $(EXE) $(OBJECTS) *~

