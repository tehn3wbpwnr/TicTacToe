#include <iostream>
#include <string>
#include <regex>
using namespace std;
void intro()
{
    cout << "Welcome to TicTacToe!" << endl;
    cout << "Players will take turns entering which square to mark, as shown below" << endl << endl;
    char board[9] = { '1','2','3','4','5','6','7','8','9' };
    cout << " " << board[0] << " " << "|" << " " << board[1] << " " << "|" << " " << board[2] << " " << endl;
    cout << "-----------" << endl;
    cout << " " << board[3] << " " << "|" << " " << board[4] << " " << "|" << " " << board[5] << " " << endl;
    cout << "-----------" << endl;
    cout << " " << board[6] << " " << "|" << " " << board[7] << " " << "|" << " " << board[8] << " " << endl << endl;
}

char getGuess()
{
    char square;
    string input = "";
    while (true)
    {
        cin >> input;
        const string regexInput = input;
        regex r("[1-9]");
        if (input.length() == 1 && regex_match(regexInput,r))
        {
            square = input[0];
            return square;
        }
        cout << "Invalid character, please try again" << endl;
    }
}

void board()
{
    char board[9] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ' };
    cout << " " << board[0] << " " << "|" << " " << board[1] << " " << "|" << " " << board[2] << " " << endl;
    cout << "-----------" << endl;
    cout << " " << board[3] << " " << "|" << " " << board[4] << " " << "|" << " " << board[5] << " " << endl;
    cout << "-----------" << endl;
    cout << " " << board[6] << " " << "|" << " " << board[7] << " " << "|" << " " << board[8] << " " << endl;
}