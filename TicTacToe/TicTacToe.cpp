

#include <iostream>
#include <string>
#include "Protos.h"
using namespace std;
int main()
{
    intro();
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
        //get input
        cout << player1 << "Select your square: ";
        square = getGuess();
    }
}