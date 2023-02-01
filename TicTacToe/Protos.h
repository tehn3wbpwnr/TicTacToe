#pragma once
//function protos
void intro(char board[]);
void displayBoard(char board[]);
void insertIntoBoard(char square, char board[], char xo);
bool checkWin(char board[]);
bool playAgain(std::string player);
char getGuess(std::string player, char board[]);
void resetGame(char board[]);