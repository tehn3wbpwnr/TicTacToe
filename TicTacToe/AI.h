#pragma once

int generateNum();
void AIturn(char board[], char xo);
bool isVsAi();

//WIP funcs
int checkAIScore(char board[]);
bool isMovesLeft(char board[]);
int miniMax(char board[], int depth, bool isMax);
int bestAITurn(char board[]);