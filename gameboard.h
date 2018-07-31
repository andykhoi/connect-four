#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include <stdbool.h>
int** makeBoard(int cols, int rows);

int** initiateBoard(int** gameboard, int cols, int rows);

void printBoard(int** gameboard, int cols, int rows);

bool placeRedCoin(int** gameboard, int col, int cols, int rows);

bool placeYellowCoin(int** gameboard, int col, int cols);

void checkHorizontally(int** gameboard, int cols, int rows);

void checkVertically(int** gameboard, int cols, int rows);

void checkDiagonally(int** gameboard, int cols, int rows);

#endif
