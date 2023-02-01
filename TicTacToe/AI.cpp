#include <iostream>
#include <string>
#include <regex>
#include <cstdlib>
#include "Protos.h"

using namespace std;

int generateNum()
{
	int num =(rand() % 9);
	return num;
}

void AIturn(char board[], char xo)
{
    cout << "AI turn: " << endl;
    while (true)
    {
        int square = generateNum();
        if (board[square] != 'X' && board[square] != 'O')
        {
            board[square] = xo;
            return;
        }
    }
}

bool isVsAi()
{

    cout << "Enter yes (y/Y) to play vs ai" << endl;
    if (getYesNo())
    {
        return true;
    }

    else return false;

}

//WIP Learning about minimax algorithm to write AI that is unbeatable

//used to check if there are moves left to try, will be called recursively into the minimax algorithm
bool isMovesLeft(char board[])
{
    for (int i = 0; i < 9; i++)
    {
        if(board[i] != 'X' && board[i] != 'O')
        {
            return true;
        }
    }
    return false;
}

//modify the check win state to return a value from -10 to +10 to check for victory instead
//this is used to evaluate possible moves by the ai
int checkAIScore(char board[])
{
    //horizontal win con
    if (board[0] == board[1] && board[1] == board[2] ||
        board[3] == board[4] && board[4] == board[7] ||
        board[6] == board[6] && board[6] == board[8])
    {
        if (board[0] == 'O' || board[3] == 'O' || board[6] == 'O')
        {
            return 10;
        }
        else
        {
            return -10;
        }
    }

    //vertical win con
    else if (board[0] == board[3] && board[3] == board[6] ||
        board[1] == board[4] && board[4] == board[7] ||
        board[2] == board[5] && board[5] == board[8])
    {
        if (board[0] == 'O' || board[1] == 'O' || board[2] == 'O')
        {
            return 10;
        }
        else
        {
            return -10;
        }
    }

    //diagonal win con
    else if (board[0] == board[4] && board[4] == board[8] ||
             board[2] == board[4] && board[4] == board[6])
    {
        if (board[0] == 'O' || board[2] == 'O')
        {
            return 10;
        }
        else
        {
            return -10;
        }
    }
    else return 0;
}

//This is the minimax function, this function will be used recurisvely to plot out moves by the ai and select which is best

int miniMax(char board[], bool isMax)
{
    //during recursive calls check to see the weighting of move made
    int score = checkAIScore(board);

    //winning game states
    if (score == 10)
    {
        return score;
    }

    else if (score == -10)
    {
        return score;
    }

    //tie game state
    if (isMovesLeft(board) == false)
    {
        return 0;
    }

    //recursive loop
    //maximizer
    if (isMax)
    {
        int bestScore = -100;
        for (int i = 0; i < 9; i++)
        {
            //is spot empty?
            if (board[i] != 'X' && board[i] != 'O')
            {
                char temp = board[i];
                board[i] = 'O'; //assign move
                bestScore = max(bestScore, miniMax(board, !isMax));

                //undo move
                board[i] = temp;
            }
        }
        return bestScore;
    }

    //minimizer
    else
    {
        int minScore = 100;
        for (int i = 0; i < 9; i++)
        {
            //is spot empty?
            if (board[i] != 'X' && board[i] != 'O')
            {
                char temp = board[i];
                board[i] = 'X'; //assign move
                minScore = min(minScore, miniMax(board, !isMax));

                //undo move
                board[i] = temp;
            }
        }
        return minScore;
    }

}



    // This function is what is used to actually call start the ai's turn, and is used to find the index of the best move

int bestAITurn(char board[])
{
    int move = -1;
    int bestScore = -100;

    for (int i = 0; i < 9; i++)
    {
        //make move
        if (board[i] != 'X' && board[i] != 'O')
        {
            char temp = board[i];
            board[i] = 'O';

            int moveScore = miniMax(board, false);

            //undo move
            board[i] = temp;

            if (moveScore > bestScore)
            {
                bestScore = moveScore;
                move = i;
            }
        }
    }

    return move;
}

