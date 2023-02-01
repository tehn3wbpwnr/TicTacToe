#include <iostream>
#include <string>
#include <regex>
#include <stdlib.h>

using namespace std;


void intro(char board[])
{
    cout << "Welcome to TicTacToe!" << endl;
    cout << "Players will take turns entering which square to mark, as shown below" << endl << endl;
    cout << " " << board[0] << " " << "|" << " " << board[1] << " " << "|" << " " << board[2] << " " << endl;
    cout << "-----------" << endl;
    cout << " " << board[3] << " " << "|" << " " << board[4] << " " << "|" << " " << board[5] << " " << endl;
    cout << "-----------" << endl;
    cout << " " << board[6] << " " << "|" << " " << board[7] << " " << "|" << " " << board[8] << " " << endl << endl;


}

bool playAgain(string player)
{
    cout << player << " Wins!" << endl;
    cout << "Would you like to play again? (y/n)" << endl;
    string answer;
    while (true)
    {
        cin >> answer;
        const string regexInput = answer;
        regex r("[yYnN]");
        if (answer.length() == 1 && regex_match(regexInput, r))
        {
            if (answer[0] == 'y' || answer[0] == 'Y')
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        cout << "Invalid character, please try again" << endl;
    }
}

char getGuess(string player, char board[])
{
    cout << player << " select your square: ";
    string input = "";
    char ch;
    while (true)
    {
        cin >> input;
        const string regexInput = input;
        regex r("[1-9]");
        if (input.length() == 1 && regex_match(regexInput,r) && board[input[0]-49] != 'X' || board[input[0]-49] != 'O')
        {
            ch = input[0];
            return ch;
        }
        else
        cout << "Invalid character, please try again" << endl;
    }
}


void insertIntoBoard(char square, char board[], char xo)
{
    int pos = square - 49; //subtract 49 against ascii value to get index of position
    board[pos] = xo;
}


bool checkWin(char board[])
{
    //horizontal win con
    if (board[0] == board[1] && board[1] == board[2] ||
        board[3] == board[4] && board[4] == board[7] ||
        board[6] == board[6] && board[6] == board[8])
    {
        return true;
    }

    //vertical win con
    else if (board[0] == board[3] && board[3] == board[6] ||
        board[1] == board[4] && board[4] == board[7] ||
        board[2] == board[5] && board[5] == board[8])
    {
        return true;
    }

    //diagonal win con
    else if (board[0] == board[4] && board[4] == board[8] ||
        board[2] == board[4] && board[4] == board[6])
        return true;

    else return false;
}

void displayBoard(char board[])
{
    //char board[9] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ' };
    cout << " " << board[0] << " " << "|" << " " << board[1] << " " << "|" << " " << board[2] << " " << endl;
    cout << "-----------" << endl;
    cout << " " << board[3] << " " << "|" << " " << board[4] << " " << "|" << " " << board[5] << " " << endl;
    cout << "-----------" << endl;
    cout << " " << board[6] << " " << "|" << " " << board[7] << " " << "|" << " " << board[8] << " " << endl;
}

void resetGame(char board[])
{
    for (int i = 0; i <= sizeof board; i++)
    {
        board[i] = (char)(i + 49);
    }
}