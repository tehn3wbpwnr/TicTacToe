#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;
void intro()
{
    char board[9] = { '1','2','3','4','5','6','7','8','9' };
    cout << " " << board[0] << " " << "|" << " " << board[1] << " " << "|" << " " << board[2] << " " << endl;
    cout << "-----------" << endl;
    cout << " " << board[3] << " " << "|" << " " << board[4] << " " << "|" << " " << board[5] << " " << endl;
    cout << "-----------" << endl;
    cout << " " << board[6] << " " << "|" << " " << board[7] << " " << "|" << " " << board[8] << " " << endl;
}

char getGuess()
{
    char square;
    string input = "";
    while (true)
    {
        getline(cin, input);
        if (input.length() == 1 && isdigit(input[0]))
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