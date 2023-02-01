
#include <iostream>
#include <string>
#include "Protos.h"
#include "AI.h"

using namespace std;

int main()
{
    char square;
    bool resume = true;
    bool aiFlag = false;
    //intitialize board array
    char board[9] = {};
    resetGame(board);

    //seed rand for ai
    srand((unsigned)time(NULL));

    intro(board);
    aiFlag = isVsAi();

    cout << "Player 1(X) enter your name: ";
    string player1;
    string player2;
    cin >> player1;

    if (!aiFlag)
    {
        cout << "Player 2(O) enter your name: ";
        cin >> player2;
    }
    else player2 = "AI";

    //while loop for main game
    while (resume)
    {
        //player 1 turn
        square = getGuess(player1,board);

        //insert selection into board
        insertIntoBoard(square, board, 'X');

        displayBoard(board);

        if (checkWin(board))
        {
            if (playAgain(player1))
            {
                //reset game state
                resetGame(board);
                continue;
            }
            else
                break;
        }

        //TEST ZONE

        //Best AI turn
        int i = bestAITurn(board);
        if (i >= 0)
        {
            board[i] = 'O';
        }
        displayBoard(board);
        //check win con
        if (checkWin(board))
        {
            if (playAgain(player2))
            {
                //reset game state
                resetGame(board);
                continue;
            }
            else
                break;
        }





        /*
        //human player code
        if (!aiFlag)
        {
            //player 2 turn
            square = getGuess(player2, board);

            //insert selection into board
            insertIntoBoard(square, board, 'O');

            displayBoard(board);
            //check win con
            if (checkWin(board))
            {
                if (playAgain(player2))
                {
                    //reset game state
                    resetGame(board);
                    continue;
                }
                else
                    break;
            }
        }

        //ai player code
        else
        {
            AIturn(board, 'O');
            displayBoard(board);
            //check win con
            if (checkWin(board))
            {
                if (playAgain(player2))
                {
                    //reset game state
                    resetGame(board);
                    continue;
                }
                else
                    break;
            }
        }
        */
    }
}