

#include <iostream>
#include <string>
#include "Protos.h"
using namespace std;
int main()
{
    //intitialize board array
    char board[9] = {};
    resetGame(board);


    intro(board);
    cout << "Player 1(X) enter your name: ";
    string player1;
    cin >> player1;
    cout << "Player 2(O) enter your name: ";
    string player2;
    cin >> player2;

    char square;
    bool resume = true;

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


        //player 2 turn
        square = getGuess(player2,board);

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
}