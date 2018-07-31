#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gameboard.h"

int main(void) {
	int cols = 0;
	int rows = 0;
	int userColumn = 0;
	printf("Enter the number of rows and columns of your gameboard: ");
	scanf("%d %d", &cols, &rows);
	if(cols < 4 || rows < 4) {
		return 0;
	}
	int const MAX_INPUTS = cols * rows;
	int inputCounter = 0;
	int** gameboard = makeBoard(cols, rows);
	initiateBoard(gameboard, cols, rows);
	printBoard(gameboard, cols, rows);
	while (1) {
		printf("Enter column for red coin: ");
		scanf("%d", &userColumn);
		inputCounter++;
		if(userColumn >= rows) {
			return 0;
		}
		bool redfull = placeRedCoin(gameboard, userColumn, cols, rows);
		printBoard(gameboard, cols, rows);
		while(!redfull) {
			printf("Enter column for red coin: ");
			scanf("%d", &userColumn);
			if (userColumn >= rows) {
				return 0;
			}
			redfull = placeRedCoin(gameboard, userColumn, cols, rows);
			printBoard(gameboard, cols, rows);
		}	
		checkHorizontally(gameboard, cols, rows);
		checkVertically(gameboard, cols, rows);
		checkDiagonally(gameboard, cols, rows);
		if(inputCounter == MAX_INPUTS) {
			printf("Game over: tie.\n");
			return 0;
		}
		printf("Enter column for yellow coin: ");
		inputCounter++;
		scanf("%d", &userColumn);
		if(userColumn >= rows) {
			return 0;
		}
		bool yellowfull =  placeYellowCoin(gameboard, userColumn, cols);
		printBoard(gameboard, cols, rows);
                while(!yellowfull) {
                        printf("Enter column for yellow coin: ");
                        scanf("%d", &userColumn);
                        if (userColumn >= rows) {
                                return 0;
                        }
                        yellowfull = placeYellowCoin(gameboard, userColumn, cols);
                        printBoard(gameboard, cols, rows);
                }
		checkHorizontally(gameboard,cols, rows);
		checkVertically(gameboard, cols, rows);
		checkDiagonally(gameboard, cols, rows);
		if(inputCounter == MAX_INPUTS) {
			printf("Game over: tie.\n");
			return 0;
		}
		
	}

}
