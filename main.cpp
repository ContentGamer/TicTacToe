#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int currentPlayerPlaying = 1;

vector<vector<string>> currentPoses = {
    {" ", " ", " "},
    {" ", " ", " "},
    {" ", " ", " "}
};

void reversePyschology(){
    if (currentPlayerPlaying == 0)
    {
        currentPlayerPlaying = 1;
    }
    else
    {
        currentPlayerPlaying = 0;
    }
}

void tictactoeBoard(){
    cout << "\n";
    cout << "--------------------" << "\n"; 
    cout << "|  " << currentPoses[0][0] << "  ||  " << currentPoses[0][1] << "  ||  " << currentPoses[0][2] << "  |" << "\n";
    cout << "--------------------" << "\n"; 
    cout << "|  " << currentPoses[1][0] << "  ||  " << currentPoses[1][1] << "  ||  " << currentPoses[1][2] << "  |" << "\n";
    cout << "--------------------" << "\n"; 
    cout << "|  " << currentPoses[2][0] << "  ||  " << currentPoses[2][1] << "  ||  " << currentPoses[2][2] << "  |" << "\n";
    cout << "--------------------" << "\n"; 
    cout << "\n";
}


bool checkWinner(string curSign){
    bool isWon = false;
    if(currentPoses[0][0] == curSign && currentPoses[1][1] == curSign && currentPoses[2][2] == curSign){
        isWon = true;
    }
    if(currentPoses[0][2] == curSign && currentPoses[1][1] == curSign && currentPoses[2][0] == curSign){
        isWon = true;
    }
    for (int i = 0; i < 3; i++)
    {
        if(currentPoses[i][0] == curSign && currentPoses[i][1] == curSign && currentPoses[i][2] == curSign){
            isWon = true;
        }
        if(currentPoses[0][i] == curSign && currentPoses[1][i] == curSign && currentPoses[2][i] == curSign){
            isWon = true;
        }
    }
    return isWon;
}

int main(){
    bool gotAlreadyFilledError = false;

    while (true)
    {
        tictactoeBoard();
        reversePyschology();
        if(gotAlreadyFilledError){
            reversePyschology();
            gotAlreadyFilledError = false;
        }
        string currentSign = "X";
        switch (currentPlayerPlaying)
        {
        case 0:
            currentSign = "X";
            break;
        case 1:
            currentSign = "O";
            break;
        }
        bool continueCode = true;
        bool continueCheckCode = true;
        int selectedRow,selectedColumn;
        cout << "\n" << "Current player playing: " << currentSign << "\n";
        cout << "\n" << "Select a row: ";
        cin >> selectedRow;
        cout << "Select a column: ";
        cin >> selectedColumn;

        selectedRow = selectedRow-1;
        selectedColumn = selectedColumn-1;

        if (continueCheckCode && selectedRow > 2)
        {
            cout << "\n" << "Unknown Number!" << endl;
            gotAlreadyFilledError = true;
            continueCode = false;
            continueCheckCode = false;
        }
        if (continueCheckCode && selectedColumn > 2)
        {
            cout << "\n" << "Unknown Number!" << endl;
            gotAlreadyFilledError = true;
            continueCode = false;
            continueCheckCode = false;
        }

        if (continueCheckCode && selectedRow < 0)
        {
            cout << "\n" << "Unknown Number!" << endl;
            gotAlreadyFilledError = true;
            continueCode = false;
            continueCheckCode = false;
        }
        if (continueCheckCode && selectedColumn < 0)
        {
            cout << "\n" << "Unknown Number!" << endl;
            gotAlreadyFilledError = true;
            continueCode = false;
            continueCheckCode = false;
        }

        if(continueCheckCode && currentPoses[selectedRow][selectedColumn] != " ") {
            cout << "\n" << "You cannot do that because its already filled!" << "\n";
            gotAlreadyFilledError = true;
            continueCode = false;
        }
        if(continueCode){
            currentPoses[selectedRow][selectedColumn] = currentSign;
            if(checkWinner(currentSign)){
                tictactoeBoard();
                cout << "\n" << "\e[1m" << currentSign << "\e[0m" << " Has won!";
                break;
            }
        }
    }
    
    return 0;
}