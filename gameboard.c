#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int** makeBoard(int cols, int rows) {
	int** gameboard = (int**) malloc(rows * sizeof(int*));
	for (int i = 0; i < rows; ++i) {
		gameboard[i] = (int*)malloc(cols * sizeof(char));
	}
	return gameboard;
}

int** initiateBoard(int** gameboard, int cols, int rows) { //sets each element to a space (' ') 
	for(int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			gameboard[i][j] = ' ';
		}
	}
	return gameboard;
}

void printBoard(int** gameboard, int cols, int rows) {
       	for(int j = (cols-1); j>=0; --j) {
		for (int i = 0; i < rows; ++i) {
			printf("%c ", gameboard[i][j]);
		}
		printf("\n");
	}
	int numberOfSigns = (2 * rows) - 1;
	for (int k = 0; k < numberOfSigns; ++k) {
		printf("=");
	}
	printf("\n");
}

bool placeRedCoin(int** gameboard, int col, int cols, int rows) {
	if(gameboard[col][cols-1] != ' ') {
		printf("Column %d is full\n", col);
		return false;
	}	
	for (int j = 0; j < rows; ++j) {
		if(gameboard[col][j] == ' ') {
			gameboard[col][j] = 'R';
			break;
		}
	}
	return true;
}

bool placeYellowCoin(int** gameboard, int col, int cols) {
	if(gameboard[col][cols-1] != ' ') {
                printf("Column %d is full\n", col);
                return false;
        }
	for (int j = 0; j < (sizeof(gameboard[col])/sizeof(char)); ++j) {
                if(gameboard[col][j] == ' ') {
                        gameboard[col][j] = 'Y';
			break;
                }
	}
	return true;
}

void checkHorizontally(int** gameboard, int cols, int rows) {
	for (int i = 0; i < cols; ++i) {
		for (int j = 0; j < rows - 3; ++j) {
		       if (gameboard[j][i] == 'R' && gameboard[j][i] == gameboard[j+1][i] && gameboard[j][i] == gameboard[j+2][i]
			   && gameboard[j][i] == gameboard[j+3][i]) {
			       printf("Game over: red wins.\n");
			       exit(0);
		       }
		       else if (gameboard[j][i] == 'Y' && gameboard[j][i] == gameboard[j+1][i] && gameboard[j][i] == gameboard[j+2][i]
                           && gameboard[j][i] == gameboard[j+3][i]) {
			       printf("Game over: yellow wins.\n");
			       exit(0);
		    	}
		       
		}
	}
}
void checkVertically(int** gameboard, int cols, int rows) {
	for(int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols - 3; ++j) {
			if(gameboard[i][j] == 'R' && gameboard[i][j] == gameboard[i][j+1] && gameboard[i][j] == gameboard[i][j+2]
			   && gameboard[i][j] == gameboard[i][j+3]) {
				printf("Game over: red wins.\n");
				exit(0);
			}
			else if(gameboard[i][j] == 'Y' && gameboard[i][j] == gameboard[i][j+1] && gameboard[i][j] == gameboard[i][j+2]
                           && gameboard[i][j] == gameboard[i][j+3]) {
				printf("Game over: yellow wins.\n");
				exit(0);
			}
		}
	}
}

void checkDiagonally(int** gameboard, int cols, int rows) {
	for (int i = 0; i < rows - 3; ++i) {
		for (int j = 0; j < cols - 3; ++j) {
			if(gameboard[i][j] == 'R' && gameboard[i][j] == gameboard[i+1][j+1] && gameboard[i][j] == gameboard[i+2][j+2]
			   && gameboard[i][j] == gameboard[i+3][j+3]) {
				printf("Game over: red wins.\n");
				exit(0);
			}
			else if(gameboard[i][j] == 'Y' && gameboard[i][j] == gameboard[i+1][j+1] && gameboard[i][j] == gameboard[i+2][j+2]
                	         && gameboard[i][j] == gameboard[i+3][j+3]) {
				printf("Game over: yellow wins.\n");
				exit(0);
			}
		}
	}
	for(int i = 0; i < rows-3; ++i) {
		for(int j = sizeof(gameboard[0])/sizeof(char) - 1; j > cols-3; --j) {
			if(gameboard[i][j] == 'R' && gameboard[i][j] == gameboard[i+1][j-1] && gameboard[i][j] == gameboard[i+2][j-2]
			   && gameboard[i][j] == gameboard[i+3][j-3]) {
				printf("Game over: red Wins.\n");
				exit(0);
			}
			else if(gameboard[i][j] == 'Y' && gameboard[i][j] == gameboard[i+1][j-1] && gameboard[i][j] == gameboard[i+2][j-2]
                           && gameboard[i][j] == gameboard[i+3][j-3]) {
				printf("Game over: yellow wins.\n");
				exit(0);
			}
		}
	}
}


	
