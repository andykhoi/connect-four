connectfour.out: connectfour.c gameboard.o 
	gcc -Wall connectfour.c gameboard.o -o connectfour.out 

gameboard.o: gameboard.c gameboard.h
	gcc -c gameboard.c gameboard.h 

clean:
	rm *.o

